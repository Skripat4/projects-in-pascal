
{ (c) Nickita Guschin }
{Software rendering library}

bitmap = class
private
 width,height:integer;
 widthwidth:longword;
 tableY:array of longword;
 mask:tmask;
 outrect:rect;
 img:array of byte;
     FileSs1:array of byte;
 procedure resize(w,h:integer);
 public
constructor create(w,h:integer);

function getColor(index:longword):tcolor;overload;
function getCOlor(r,g,b:byte):tcolor; overload;

function getCoord(x,y:integer):longword;

procedure drawPixel(Apos:tpoint_;color:tcolor);overload;
procedure drawPixel(kuda:rect;Opos:tpoint_;color:tcolor);overload;
procedure drawPixel(index:longword;color:tcolor);overload;

procedure line(Ax1,Ay1,Ax2,Ay2:integer; color:tcolor);overload;
procedure line(kuda:rect; Ox1,Oy1,Ox2,Oy2:integer; color:tcolor);overload;

procedure drawStrokeRect(Arect:rect;color:tcolor);overload;
procedure drawStrokeRect(kuda,Orect:rect;color:tcolor);overload;


procedure drawFillRect(Arect:rect;color:tcolor);overload;
procedure drawFillRect(kuda,Orect:rect;color:tcolor);overload;

procedure saveToBmp(name:string);

procedure resetRect;
procedure setRect(x,y,w,h:integer);overload;
procedure setRect(r:rect);overload;

procedure draw(x,y:integer);overload;             //output with selfrectangle
procedure draw(vr:rect; ax,ay:integer);overload; //rectangle output other selfrectangle

procedure convertToRGB(pngimage:tpngobject);
procedure convertToAlpha(pngimage:tpngobject);

function mixRGB(x,y,a:real):integer;
procedure drawWithMask(x,y:integer);

function getHeight:integer;
function getWidth:integer;
end;
