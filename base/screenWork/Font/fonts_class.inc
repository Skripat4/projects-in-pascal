
{ (c) Nickita Guschin }
{Software rendering library}

fonts = class
  private
   {Место под хранение битовых образцов букв и символов}
   bukvy : array[0..(256*8*16)-1] of byte;
   g2D:pGraphicsWork;
   r:rect;
   vid:bitmap;
   {Заполнение битовых образцов букв и символов при помощи контсанты}
   procedure makeBukvy;
   procedure makeImg;
   procedure drawSymb(r:rect;x,y:integer;symb:byte;color:tcolor);
  public
   constructor create(var graph:PGraphicsWOrk);
   function  inttostr(x:integer):string;
   procedure draw(x,y:integer);
   procedure print(ax,ay:integer; stroka:string;color:tcolor);overload;
   procedure print(ar:rect; ox,oy:integer; stroka:string;color:tcolor);overload;
  end;

PFonts = ^fonts;
