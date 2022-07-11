
{ (c) Nickita Guschin }
{Software rendering library}

FUNCTION GraphicsWork.getCoord(x,y:integer):longword;
BEGIN result:=tableY[y]+x*4; end;

CONSTRUCTOR GraphicsWork.Create;
VAR
 i,j:integer;
BEGIN
 for i:=nScreenHeight-1 downto 0 do
  tableY[nScreenHeight-i-1]:=i*nScreenWidth*4;

 for i:=0 to 255 do
  for j:=0 to 255 do
    multable[i,j]:=round(i*j/255);
END;

FUNCTION GraphicsWork.setColor(r,g,b:byte):tcolor;
var temp:tcolor;
BEGIN
 temp.r:=r; temp.g:=g; temp.b:=b; result:=temp;
END;

PROCEDURE GraphicsWork.drawPixel(Apos:tpoint_;color:tcolor);
var coord:longword;
BEGIN
 coord:=tableY[Apos.y]+Apos.x*4;
 screen[coord]:=color.b;
 screen[coord+1]:=color.g;
 screen[coord+2]:=color.r;
END;

PROCEDURE GraphicsWork.drawPixel(kuda:rect;Opos:tpoint_;color:tcolor);
var coord:longword;
BEGIN
 coord:=tableY[Opos.y+kuda.y]+(Opos.x+kuda.x)*4;
 screen[coord]:=color.b;
 screen[coord+1]:=color.g;
 screen[coord+2]:=color.r;
END;

PROCEDURE GraphicsWork.drawPixel(Aindex:longword;color:tcolor);
//var coord:longword;
BEGIN
 //coord:=Aindex;
 if Aindex>=nScreenWidth*nScreenHeight*4 then exit;
 screen[Aindex]:=color.b;
 screen[Aindex+1]:=color.g;
 screen[Aindex+2]:=color.r;
END;

//esche dopisat
PROCEDURE GraphicsWork.line(Ax1,Ay1,Ax2,Ay2:integer; color:tcolor);
var temp:integer; coord:longword;
BEGIN
if ay1=ay2 then
BEGIN //horizontal

 if (ay1<0) or (ay1>=nScreenHeight) then exit;
 if ax1>ax2 then begin temp:=ax1;ax1:=ax2; ax2:=temp;end;
 if (ax2<0) or (ax1>=nScreenWIdth) then exit;
 if ax1<0 then ax1:=0; if ax2>=nScreenWidth then ax2:=nScreenWidth-1;

 coord:=getCoord(ax1,ay1);
 for temp:=0 to (ax2-ax1) do
  begin
    screen[coord]:=color.b; screen[coord+1]:=color.g; screen[coord+2]:=color.r;
    inc(coord,4);
  end;
END //horizontal
else
if ax1=ax2 then
BEGIN //vertical

 if (ax1<0) or (ax1>=nScreenWidth) then exit;
 if ay1>ay2 then begin temp:=ay1;ay1:=ay2; ay2:=temp;end;
  if (ay2<0) or (ay1>=nScreenHeight) then exit;
 if ay1<0 then ay1:=0; if ay2>=nScreenHeight then ay2:=nScreenHeight-1;

 coord:=getCoord(ax1,ay1);
 for temp:=0 to (ay2-ay1) do
  begin
    screen[coord]:=color.b; screen[coord+1]:=color.g; screen[coord+2]:=color.r;
    dec(coord,screenWIdth);
  end;
END;  //vertical
END;



PROCEDURE GraphicsWork.line(kuda:rect; Ox1,Oy1,Ox2,Oy2:integer; color:tcolor);
var temp:integer;
BEGIN

if oy1=oy2 then
	BEGIN //HORIZONTAL
	   	if (oy1<0) or (oy1>=kuda.h) then exit;
       	if ox1>ox2 then begin temp:=ox1;ox1:=ox2; ox2:=temp;end;
        if (ox2<0) or (ox1>=kuda.w) then exit;
 		if ox1<0 then ox1:=0; if ox2>=kuda.h then ox2:=kuda.w{-1};
    END // HORIZONTAL
 else
if ox1=ox2 then
	BEGIN //VERTICAL
 		if (ox1<0) or (ox1>=kuda.w) then exit;

       	if oy1>oy2 then begin temp:=oy1;oy1:=oy2; oy2:=temp;end;
        if (oy2<0) or (oy1>=kuda.h) then exit;
 		if oy1<0 then oy1:=0; if oy2>=kuda.h then oy2:=kuda.h{-1};
    END; //VERTICAL

 line(ox1+kuda.x,oy1+kuda.y,ox2+kuda.x,oy2+kuda.y,color);
END;

PROCEDURE GraphicsWork.drawStrokeRect(kuda,Orect:rect;color:tcolor);
BEGIN
 line(kuda,Orect.x,Orect.y,Orect.x+Orect.w,Orect.y,color);
 line(kuda,Orect.x,Orect.y+Orect.h,Orect.x+Orect.w,Orect.y+Orect.H,color);
 line(kuda,Orect.x,Orect.y,Orect.x,Orect.y+Orect.h,color);
 line(kuda,Orect.x+Orect.w,Orect.y,Orect.x+Orect.w,Orect.y+Orect.H,color);
END;

PROCEDURE GraphicsWork.drawStrokeRect(Arect:rect;color:tcolor);
BEGIN
 line(Arect.x,Arect.y,Arect.x+Arect.w,Arect.y,color);
 line(Arect.x,Arect.y+Arect.h,Arect.x+Arect.w,Arect.y+Arect.H,color);
 line(Arect.x,Arect.y,Arect.x,Arect.y+arect.h,color);
 line(Arect.x+arect.w,Arect.y,Arect.x+Arect.w,Arect.y+Arect.H,color);
END;

PROCEDURE GraphicsWork.drawFillRect(Arect:rect;color:tcolor);
VAR ax1,ax2,ay1,ay2,i,j:integer;coord,c1:longword;
BEGIN
 ax1:=Arect.x; ax2:=Arect.x+Arect.w;
 ay1:=Arect.y; ay2:=Arect.y+Arect.h;
 if (ay2<0) or (ax2<0) or (ax1>=nScreenWidth) or (ay1>=nScreenHeight) then exit;
 if ax1<0 then ax1:=0; if ax2>=nScreenWidth then ax2:=nScreenWidth-1;
 if ay1<0 then ay1:=0; if ay2>=nScreenHeight then ay2:=nScreenHeight-1;

 c1:=getCoord(ax1,ay1);
 for j:=0 to (ay2-ay1) do
  begin
   coord:=c1;
   for i:=0 to (ax2-ax1) do
    begin
    screen[coord]:=color.b; screen[coord+1]:=color.g; screen[coord+2]:=color.r;
    inc(coord,4);
    end;
    dec(c1,screenWIdth);
  end;

END;

PROCEDURE GraphicsWork.drawFillRect(kuda,Orect:rect;color:tcolor);
VAR ax1,ax2,ay1,ay2:integer;
BEGIN
 ax1:=Orect.x; ax2:=Orect.x+Orect.w;
 ay1:=Orect.y; ay2:=Orect.y+Orect.h;
 if (ay2<0) or (ax2<0) or (ax1>=kuda.w) or (ay1>=kuda.h) then exit;
 if ax1<0 then ax1:=0; if ax2>=kuda.w then ax2:=kuda.w;
 if ay1<0 then ay1:=0; if ay2>=kuda.h then ay2:=kuda.h;

 oRect.x:=ax1+kuda.x; oRect.W:=ax2-ax1;
 oRect.y:=ay1+kuda.y; oRect.H:=ay2-ay1;
 drawFillRect(oRect,color);
END;

PROCEDURE GraphicsWork.setRect(var a:rect;x,y,w,h:integer);
BEGIN a.x:=x; a.y:=y; a.w:=w; a.h:=h; END;

FUNCTION GraphicsWOrk.setRect(x,y,w,h:integer):rect;
var temp:Rect;
BEGIN
  temp.x:=x; temp.y:=y; temp.w:=w; temp.h:=h;
  result:=temp;
END;

FUNCTION GraphicsWork.setPoint(x,y:integer):tpoint_;
VAR temp:tpoint_;
BEGIN
 temp.x:=x; temp.y:=y;
result:=temp;
END;
