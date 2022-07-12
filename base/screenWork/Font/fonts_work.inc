
{ (c) Nickita Guschin }
{Software rendering library}

constructor fonts.create(var graph:PgraphicsWork);
begin 
  makeBukvy;
  //vid:=bitmap.create(256*8,16);
//makeImg;
  g2D:=@graph;
  g2D.setRect(r,0,0,nScreenWidth-1,nScreenHeight);
end;

procedure fonts.makeBukvy;
var
 i,j,z,yy,p:longword;
begin
 p:=0;
 for j:=0 to 15 do
  for i:=0 to 255 do
   for yy:=7 downto 0 do
    begin
      z:=alfavit[i,j] shr yy;
      if (z and 1)=1 then bukvy[p]:=1
                      else bukvy[p]:=0;
      inc(p);
    end;
end;

function fonts.inttostr(x:integer):string;
var
 otvet,otvet2:string;
 l,m:integer;
begin
 otvet:='';
 m:=x;
 if m=0 then otvet:='0';
 while m<>0 do
 begin
 l:=m mod 10;
 otvet:=otvet+char(l+48);
 m:=m div 10;
 end;
 otvet2:='';
 for l:=length(otvet) downto 1 do
  otvet2:=otvet2+otvet[l];
 result:=otvet2;
end;

procedure fonts.draw(x,y:integer);
var
 temp:rect;
temp1:tcolor;
begin
g2d.setRect(temp,0,0,8,16);
 //vid.draw(x,y);
temp1.r:=255; temp1.g:=255; temp1.b:=255;
drawSymb(temp,0,0,49,temp1);
end;

procedure fonts.makeImg;
var p,p1:longword;
    cblack,cwhite:tcolor;
begin
p1:=0;
 cblack:=vid.getColor(0,0,0);
 cwhite:=vid.getColor(255,255,255);
 for p:=0 to (256*8*16)-1 do 
  begin
    if bukvy[p]=0 then vid.drawPixel(p1,cblack) else vid.drawPixel(p1,cwhite);
    inc(p1,4);                    
                       
  end;
end;

procedure fonts.drawSymb(r:rect;x,y:integer;symb:byte;color:tcolor);
var p,p1,tp,tp1:longword;
 i,j:integer;
begin
 tp:=(symb*8)+r.x +(256*8)*r.y;
 tp1:=((nScreenHeight-y-1)*nScreenWidth+x)*4;
 for i:=r.y to r.y+r.h do
 begin
  p:=tp; p1:=tp1;
  for j:=r.x to r.x+r.w do
   begin
    if bukvy[p]=1 then begin
    g2d.drawPixel(p1,color);
    //screen[p1]:=color.b; screen[p1+1]:=color.g; screen[p1+2]:=color.r;
     end;
    inc(p);
    inc(p1,4);
   end; // for j
inc(tp,256*8);
dec(tp1,screenwidth);
end;//for i
end;

PROCEDURE fonts.print(ax,ay:integer; stroka:string;color:tcolor);
var
 i:integer;
 temp:rect;
 start,finish,tax,tay,touty:integer;
BEGIN

if ay+15 < 0 then exit;
if ay>=nScreenHeight then exit;

if ay<0 then
begin
 tay:=15-(ay*-1);
 touty:=ay*-1;
 ay:=0;
 end
 else
 begin
  tay:=15;
  touty:=0;
 end;

if ay+15 > nScreenHeight then
begin
 tay:=nScreenHeight-ay;
 touty:=0;
//ay:=oy;
end;


 g2d.setRect(temp,0,toutY,7,tay);
 tax:=ax;
 if ax<0 then begin start:=(-ax div 8)+2; ax:=((start-1)*8)+ax;end else start:=1;
 if (tax+length(stroka)*8) >=nScreenWidth then
          begin
            finish:=((nScreenWidth-tax) div 8);

          end else finish:=length(stroka);

 if start<>1 then begin
 temp.w:=ax-1; temp.x:=7-ax;
 drawSymb(temp,0,ay,byte(stroka[start-1]),g2d.setcolor(255,0,0));
 g2d.setRect(temp,0,touty,7,tay);
 end;

 if finish<>length(stroka) then begin
   tax:= tax+finish*8;
   temp.w:=nScreenWidth-abs(tax)-1;
   drawSymb(temp,tax,ay,byte(stroka[finish+1]),g2D.setcolor(0,128,255));
   g2d.setRect(temp,0,touty,7,tay);
 end;
 for i:=start to finish do
  begin
   drawSymb(temp,ax,ay,byte(stroka[i]),color);
   inc(ax,8);
  end;
END;


PROCEDURE fonts.print(ar:rect; ox,oy:integer; stroka:string;color:tcolor);
var
 i:integer;
 temp:rect;
 start,finish,tax,ax,ay,tay,touty:integer;
BEGIN
if oy+15 < 0 then exit;
if oy>=ar.h then exit;

if oy<0 then
begin
 tay:=15-(oy*-1);
 touty:=oy*-1;
 ay:=ar.y;
 end
 else
 begin
  tay:=15;
  touty:=0;
  ay:=ar.y+oy;
 end;

if oy+15 > ar.h then
begin
 tay:=ar.h-oy;
 touty:=0;
ay:=ar.y+oy;
end;




 g2d.setRect(temp,0,touty,7,tay);
 ax:=ar.x+ox;
 //ay:=ar.y+oy;
 tax:=ax;
 if ax<ar.x then begin start:=((ar.x-ax) div 8)+2; ax:=((start-1)*8)+ax;end else start:=1;
 if (tax+length(stroka)*8) >=ar.x+ar.w then
          begin
            finish:=((ar.x+ar.w-tax) div 8);

          end else finish:=length(stroka);

 if start<>1 then begin
 temp.w:=ax-ar.x-1;
 temp.x:=8-(ax-ar.x);
 drawSymb(temp,ar.x,ay,byte(stroka[start-1]),g2d.setcolor(255,0,255));
 g2d.setRect(temp,0,touty,7,tay);
 end;

 if finish<>length(stroka) then begin
   tax:= tax+finish*8;
   temp.w:=(ar.x+ar.w)-abs(tax)-1;
   drawSymb(temp,tax,ay,byte(stroka[finish+1]),g2D.setcolor(0,128,255));
   g2d.setRect(temp,0,touty,7,tay);
 end;
 for i:=start to finish do
  begin
   drawSymb(temp,ax,ay,byte(stroka[i]),color);
   inc(ax,8);
  end;
END;
