{ (c) Nickita Guschin }
{textEditor v1}

constructor TArrayListForEditor.create(graphics2d:pGraphicsWork; f:Pfonts);
var i:longword; blackcolor:tcolor;
BEGIN

countSpecialWords:=7;
setLength(specialWords,countSpecialwords);
specialWords[0]:='vec2 ';
specialWords[1]:='vec3 ';
specialWords[2]:='vec4 ';
specialWords[3]:='if ';
specialWords[4]:='int ';
specialWords[5]:='float ';
specialWords[6]:='void ';


 rusEng:=true;
 
     blackcolor.r:=0; blackcolor.g:=0; blackcolor.b:=0;
 scrollOffset.x:=50;
 scrollOffset.y:=0;

 g2d:=graphics2D;
 t:=f; // передаем класс печати DOS шрифта
 
 karetka:=50;
 cursor_position.x:=karetka; cursor_position.y:=0;
 iCount:=100;
 bCount:=256*5;
 setLength(iList,iCount);
 setLength(bList,bCount);
 for i:=1 to iCount-2 do
 begin
  iList[i].next:=i+1;
  iList[i].last:=i-1;
 end;
 iList[iCount-1].next:=0;
 iList[iCount-1].last:=iCount-2;
 iList[0].next:=0;
 iList[0].last:=0;
 iFree:=2;
 for i:=1 to bCount-2 do
  bList[i].next:=i+1;
 bList[bCount-1].next:=0;
 bList[0].next:=0;
 bFree:=1;

 iHead:=1;
 iTail:=1;
 iList[iHead].next:=0;

 bCursor:=0;

 iString:=1;


 //--> 	Задаем поле для ввода текста
		g2d.setrect(editorArea,CanvasW-30-400,10+26,400,CanvasH-80*2);

 //--> 	Рисуем прямоугольник для заголовка поля для ввода текста
		g2d.drawFillRect(g2d.setRect((Canvasw-30-400),10,400,22),g2d.setColor(181,230,29));

 //--> Точки стираем по краям прямоугольника,чтобы типа овальнее выглядело)
g2d.drawPixel(g2d.setPoint(canvasw-30-400,
															10),blackcolor);
g2d.drawPixel(g2d.setPoint(canvasw-30-400,
															10+22),blackcolor);
g2d.drawPixel(g2d.setPoint(canvasw-30,
															10),blackcolor);
g2d.drawPixel(g2d.setPoint(canvasw-30,
															10+22),blackcolor);

//--> Запись заголовка с тенькой
      t.print(CanvasW-30-400+10+2,13+2,'Shader Editor',g2d.setcolor(136,174,19));
      t.print(CanvasW-30-400+10,13,'Shader Editor',blackcolor);

g2d.setRect(editorBorder,editorArea.x,editorArea.y,48,editorArea.h);
END;