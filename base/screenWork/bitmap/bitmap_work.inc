
{ (c) Nickita Guschin }
{Software rendering library}

FUNCTION bitmap.getCoord(x,y:integer):longword;
BEGIN result:=tableY[y]+x*4; end;

CONSTRUCTOR bitmap.Create(w,h:integer);
BEGIN
 resize(w,h);
END;

FUNCTION bitmap.getColor(index:longword):tcolor;
var temp:tcolor;
BEGIN
 temp.r:=img[index+2]; temp.g:=img[index+1]; temp.b:=img[index]; result:=temp;
END;

FUNCTION bitmap.getColor(r,g,b:byte):tcolor;
var temp:tcolor;
BEGIN
 temp.r:=r; temp.g:=g; temp.b:=b; result:=temp;
END;

PROCEDURE bitmap.drawPixel(Apos:tpoint_;color:tcolor);
var coord:longword;
BEGIN
 coord:=tableY[Apos.y]+Apos.x*4;
 img[coord]:=color.b;
 img[coord+1]:=color.g;
 img[coord+2]:=color.r;
END;

PROCEDURE bitmap.drawPixel(kuda:rect;Opos:tpoint_;color:tcolor);
var coord:longword;
BEGIN
 coord:=tableY[Opos.y+kuda.y]+(Opos.x+kuda.x)*4;
 img[coord]:=color.b;
 img[coord+1]:=color.g;
 img[coord+2]:=color.r;
END;

//esche dopisat
PROCEDURE bitmap.line(Ax1,Ay1,Ax2,Ay2:integer; color:tcolor);
var temp:integer; coord:longword;
BEGIN
if ay1=ay2 then
BEGIN //horizontal

 if (ay1<0) or (ay1>=Height) then exit;
 if ax1>ax2 then begin temp:=ax1;ax1:=ax2; ax2:=temp;end;
 if (ax2<0) or (ax1>=WIdth) then exit;
 if ax1<0 then ax1:=0; if ax2>=Width then ax2:=Width-1;

 coord:=getCoord(ax1,ay1);
 for temp:=0 to (ax2-ax1) do
  begin
    img[coord]:=color.b; img[coord+1]:=color.g; img[coord+2]:=color.r;
    inc(coord,4);
  end;
END //horizontal
else
if ax1=ax2 then
BEGIN //vertical

 if (ax1<0) or (ax1>=Width) then exit;
 if ay1>ay2 then begin temp:=ay1;ay1:=ay2; ay2:=temp;end;
  if (ay2<0) or (ay1>=Height) then exit;
 if ay1<0 then ay1:=0; if ay2>=Height then ay2:=Height-1;

 coord:=getCoord(ax1,ay1);
 for temp:=0 to (ay2-ay1) do
  begin
    img[coord]:=color.b; img[coord+1]:=color.g; img[coord+2]:=color.r;
    dec(coord,WidthWIdth);
  end;
END;  //vertical
END;


PROCEDURE bitmap.line(kuda:rect; Ox1,Oy1,Ox2,Oy2:integer; color:tcolor);
var temp:integer;
BEGIN

if oy1=oy2 then
	BEGIN //HORIZONTAL
	   	if (oy1<0) or (oy1>=kuda.h) then exit;
       	if ox1>ox2 then begin temp:=ox1;oy1:=ox2; ox2:=temp;end;
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

PROCEDURE bitmap.drawStrokeRect(kuda,Orect:rect;color:tcolor);
BEGIN
 line(kuda,Orect.x,Orect.y,Orect.x+Orect.w,Orect.y,color);
 line(kuda,Orect.x,Orect.y+Orect.h,Orect.x+Orect.w,Orect.y+Orect.H,color);
 line(kuda,Orect.x,Orect.y,Orect.x,Orect.y+Orect.h,color);
 line(kuda,Orect.x+Orect.w,Orect.y,Orect.x+Orect.w,Orect.y+Orect.H,color);
END;

PROCEDURE bitmap.drawStrokeRect(Arect:rect;color:tcolor);
BEGIN
 line(Arect.x,Arect.y,Arect.x+Arect.w,Arect.y,color);
 line(Arect.x,Arect.y+Arect.h,Arect.x+Arect.w,Arect.y+Arect.H,color);
 line(Arect.x,Arect.y,Arect.x,Arect.y+arect.h,color);
 line(Arect.x+arect.w,Arect.y,Arect.x+Arect.w,Arect.y+Arect.H,color);
END;

PROCEDURE bitmap.drawFillRect(Arect:rect;color:tcolor);
VAR ax1,ax2,ay1,ay2,i,j:integer;coord,c1:longword;
BEGIN
 ax1:=Arect.x; ax2:=Arect.x+Arect.w;
 ay1:=Arect.y; ay2:=Arect.y+Arect.h;
 if (ay2<0) or (ax2<0) or (ax1>=Width) or (ay1>=Height) then exit;
 if ax1<0 then ax1:=0; if ax2>=Width then ax2:=Width-1;
 if ay1<0 then ay1:=0; if ay2>=Height then ay2:=Height-1;

 c1:=getCoord(ax1,ay1);
 for j:=0 to (ay2-ay1) do
  begin
   coord:=c1;
   for i:=0 to (ax2-ax1) do
    begin
    img[coord]:=color.b; img[coord+1]:=color.g; img[coord+2]:=color.r;
    inc(coord,4);
    end;
    dec(c1,WidthWIdth);
  end;

END;

PROCEDURE bitmap.drawFillRect(kuda,Orect:rect;color:tcolor);
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

PROCEDURE bitmap.saveToBmp(name:string);
VAR FileH:integer;
    Filess:array[0..$35] of byte;
    i,j:longword;
    dopByte:integer;
    fileSize,imageSize,xx,yy,zz:integer;
BEGIN


 dopByte:= width - (width div 4)*4;
 filesize:=$36+(width*height*3)+dopByte*height;
 imageSize:=(width*height*3)+dopByte*height;

 move(filesize,filess[2],4); //store file size
 move(width,filess[18],4);     //store width size
 move(height,filess[22],4);    //store height size
 move(imageSize,filess[34],4); //store image size

 FileH:=FileCreate(name,fmOpenWrite);
 Filess[0]:=$42; //B
 Filess[1]:=$4D; //M

 //Filess[2]:=0;// file size (header +width*height*3 +(dop*height) )
// Filess[3]:=0; Filess[4]:=0; Filess[5]:=0;

 Filess[6]:=0; Filess[7]:=0; FIless[8]:=0; Filess[9]:=0; //just zero

 Filess[10]:=$36; Filess[11]:=0; Filess[12]:=0; FIless[13]:=0; //start image data

 Filess[14]:=$28; Filess[15]:=0; Filess[16]:=0; FIless[17]:=0; // header size ($28) or 36?

 //Filess[18]:=$00; Filess[19]:=0; Filess[20]:=0; FIless[21]:=0; // width

 //Filess[22]:=$00; Filess[23]:=0; Filess[24]:=0; FIless[25]:=0; // height

 Filess[26]:=$01; Filess[27]:=0; //nb plan

 Filess[28]:=$18; Filess[29]:=0; //bpp (24)

 Filess[30]:=0; Filess[31]:=0; Filess[32]:=0; Filess[33]:=0; //compression - 0 (uncompression)

 //Filess[34]:=0; Filess[35]:=0; Filess[36]:=0; Filess[37]:=0; // image size (w*h*3+dop*h)

 for i:=$26 to $35 do Filess[i]:=0;

 FileWrite(FileH,Filess,$36); //store header in file

 setLength(Filess1,imageSize);
 i:=0;j:=0;
 for yy:=1 to height do
  begin
   for xx:=1 to width do
    BEGIN
     //move(img[j],filess[i],3);
     filess1[i]:=img[j];
     filess1[i+1]:=img[j+1];
     filess1[i+2]:=img[j+2];
     inc(j,4);
     inc(i,3);
    END;
    for zz:=1 to dopByte do
     begin
       Filess1[i]:=0;
       inc(i,1);
     end;
  end;

  filess1[0]:=255;filess1[1]:=0;filess1[2]:=0;
  fileWrite(FileH,filess1[0],imageSize);
 FileClose(FileH);

 setLength(Filess1,0);
END;


PROCEDURE bitmap.resetRect;
BEGIN
 outrect.x:=0; outrect.w:=width;
 outrect.y:=0; outrect.h:=height;
END;

PROCEDURE bitmap.setRect(x,y,w,h:integer);
BEGIN
 if x<0 then begin w:=w+x; x:=0; end;
 if x+w >=width then w:=width-x;

 if y<0 then begin h:=h+y; y:=0; end;
 if y+h >=height then h:=height-y;


 outrect.x:=x; outrect.w:=w;
 outrect.y:=y; outrect.h:=h;
END;

PROCEDURE bitmap.setRect(r:rect);
BEGIN
 setrect(r.x,r.y,r.w,r.h);
END;

procedure bitmap.draw(x,y:integer);             //output with selfrectangle
VAR temp:rect;
    bI,sI,tbi,tsi:longword;
    i,j:integer;
BEGIN
 if x<0 then begin temp.x:=outrect.x-x; temp.w:=outrect.w+x; x:=0;end else begin temp.x:=outrect.x; temp.w:=outrect.w;end;
 if y<0 then begin temp.y:=outrect.y-y; temp.h:=outrect.h+y;y:=0; end else begin temp.y:=outrect.y; temp.h:=outrect.h;end;

 if x+temp.w >=nScreenWidth then temp.w:=nScreenWidth-x;
 if y+temp.h >=nScreenHeight then temp.H:=nScreenHeight-y;

 //setRect(temp);

 sI:=((nScreenHeight-y-1)*nScreenWidth*4)+x*4;

 bI:=getCoord(temp.x,temp.y);

 for i:=1 to temp.h do
  begin
    tsi:=sI;
    tBi:=bI;
    for j:=1 to temp.w do
     begin
       screen[tsi]:=img[tbi];
       screen[tsi+1]:=img[tbi+1];
       screen[tsi+2]:=img[tbi+2];
       inc(tsi,4);
       inc(tbi,4);
     end;// j
   dec(si,screenwidth);
   dec(bi,widthwidth);
  end;//i

END;
procedure bitmap.draw(vr:rect; ax,ay:integer); //rectangle output other selfrectangle
BEGIN

END;

procedure bitmap.drawPixel(index:longword;color:tcolor);
BEGIN
 if index>=width*height*4 then exit;
 img[index]:=color.b;
 img[index+1]:=color.g;
 img[index+2]:=color.r;
END;

procedure bitmap.resize(w,h:integer);
var
 i:longword;
begin

width:=w; height:=h; widthwidth:=width*4;
setlength(img,w*h*4);
for i:=0 to w*h*4-1 do
 img[i]:=255;

setLength(tableY,height);

 for i:=Height-1 downto 0 do
  tableY[Height-i-1]:=i*Width*4;

  resetrect;
end;


PROCEDURE bitmap.convertToRGB(pngimage:tpngobject);
var
 i,i1:longword;
 xx,yy:integer;
BEGIN
 resize(pngimage.width,pngimage.height);
 i1:=getcoord(0,0);
 for yy:=0 to height-1 do
   begin
    i:=i1;
    for xx:=0 to width-1 do
     begin
      img[i]:=pRGBline(pngimage.scanline[yy])^[xx].rgbtBlue;
      img[i+1]:=pRGBline(pngimage.scanline[yy])^[xx].rgbtGreen;
      img[i+2]:=pRGBline(pngimage.scanline[yy])^[xx].rgbtRed;
      inc(i,4);
     end;  //xx
    dec(i1,widthwidth);
   end;//yy
END;

PROCEDURE bitmap.convertToAlpha( pngimage:tpngobject);
BEGIN
 mask:=tmask.create(pngimage);
 mask.convertToAlpha(pngimage);
END;

function bitmap.mixRGB(x,y,a:real):integer;
var
 res:real;
begin
res:=x*(1-a)+y*a;
if res>1 then res:=1;
if res<0 then res:=0;
 result:=round(res*255);
end;

procedure bitmap.drawWithMask(x,y:integer);
var
 temp:rect;
    bI,sI,tbi,tsi,m,m1:longword;
    i,j:integer;
    not_a:real;
begin
 if high(mask.img)=0 then draw(x,y)
 else
 begin
   if x<0 then begin temp.x:=outrect.x-x; temp.w:=outrect.w+x; x:=0;end else begin temp.x:=outrect.x; temp.w:=outrect.w;end;
 if y<0 then begin temp.y:=outrect.y-y; temp.h:=outrect.h+y;y:=0; end else begin temp.y:=outrect.y; temp.h:=outrect.h;end;

 if x+temp.w >=nScreenWidth then temp.w:=nScreenWidth-x;
 if y+temp.h >=nScreenHeight then temp.H:=nScreenHeight-y;

 //setRect(temp);

 sI:=((nScreenHeight-y-1)*nScreenWidth*4)+x*4;

 bI:=getCoord(temp.x,temp.y);
 m1:=mask.getcoord(temp.x,temp.y);
 for i:=1 to temp.h do
  begin
    tsi:=sI;
    tBi:=bI;
    m:=m1;
    for j:=1 to temp.w do
     begin
     if mask.img[m]=0 then begin
       inc(tsi,4);
       inc(tbi,4);
       inc(m);
       continue;end;
       
       not_a:=tableDiv255[mask.img[m]];

       screen[tsi]:=    mixRGB(tableDiv255[ screen[tsi] ],  tableDiv255[ img[tbi] ],  not_a);
       screen[tsi+1]:=  mixRGB(tableDiv255[ screen[tsi+1]], tableDiv255[ img[tbi+1]], not_a);
       screen[tsi+2]:=  mixRGB(tableDiv255[ screen[tsi+2]], tableDiv255[ img[tbi+2]], not_a);
       inc(tsi,4);
       inc(tbi,4);
       inc(m);
     end;// j
   dec(si,screenwidth);
   dec(bi,widthwidth);
   dec(m1,width);
  end;//i
 end;// else drawWithMask
end;

function bitmap.getHeight:integer;
 begin result:=height;end;

function bitmap.getWidth:integer;
 begin result:=width;end;
