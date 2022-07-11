{ (c) Nickita Guschin }
{Software rendering library}

///////////////////////////////////
rect=record  x,y,w,h:integer;  end;
 //////////////////////////////////
tpoint_=record  x,y:integer;  end;
//////////////////////////////////
tcolor=record  r,g,b:byte; end;
//////////////////////////////////

GraphicsWork = class
private
 tableY:array[0..nScreenHeight-1] of longword;
public
 multable:array[0..255,0..255] of integer;
constructor create;

function setColor(r,g,b:byte):tcolor;
function getCoord(x,y:integer):longword;

procedure drawPixel(Apos:tpoint_;color:tcolor);overload;
procedure drawPixel(kuda:rect;Opos:tpoint_;color:tcolor);overload;
procedure drawPixel(Aindex:longword;color:tcolor);overload;

procedure line(Ax1,Ay1,Ax2,Ay2:integer; color:tcolor);overload;
procedure line(kuda:rect; Ox1,Oy1,Ox2,Oy2:integer; color:tcolor);overload;

procedure drawStrokeRect(Arect:rect;color:tcolor);overload;
procedure drawStrokeRect(kuda,Orect:rect;color:tcolor);overload;


procedure drawFillRect(Arect:rect;color:tcolor);overload;
procedure drawFillRect(kuda,Orect:rect;color:tcolor);overload;


procedure setRect(var a:rect; x,y,w,h:integer);overload;
function setRect(x,y,w,h:integer):rect;overload;
function setPoint(x,y:integer):tpoint_;
end;
pGraphicsWork = ^GraphicsWork;