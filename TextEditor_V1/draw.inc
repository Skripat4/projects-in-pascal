{ (c) Nickita Guschin }
{textEditor v1}

procedure TArrayListForEditor.draw;
   const
  noName=0;
  chislo=1;
  slovo=2;
  probel=3;
  commentariy=4;
var
 i,j:longword;
 z,x,y:integer;
 blackcolor:tcolor;
 tkey:byte;
 bbbyte:byte;
BEGIN
blackcolor:=g2d.setcolor(0,0,0);
g2d.drawFillRect(editorArea,g2d.setcolor(30,30,30));

 for i:=0 to (editorArea.h-1) div 32 do //рисуем полоски
   g2d.drawFillRect(editorArea,g2d.setrect(0,i*32-scrolloffset.y,editorArea.w,16),g2d.setcolor(40,40,40));

 g2d.drawFillRect(editorBorder,g2d.setcolor(20,20,20));
 g2d.drawStrokeRect(editorArea,g2d.setcolor(128,128,128));

 //--> Точки стираем по краям прямоугольника,чтобы типа овальнее выглядело)
g2d.drawPixel(g2d.setPoint(editorArea.x,
															editorArea.y),blackcolor);
g2d.drawPixel(g2d.setpoint(editorArea.x+editorArea.w,
															editorArea.y),blackcolor);
g2d.drawPixel(g2d.setpoint(editorArea.x+editorArea.w,
															editorArea.y+editorArea.h),blackcolor);
g2d.drawPixel(g2d.setpoint(editorArea.x,
															editorArea.y+editorArea.h),blackcolor);


 i:=iHead;
 z:=1;
 y:=0;
 while i<>0 do //bezhim po strokam
  begin
   x:=0;
   t.print(editorArea,16,y-scrolloffset.y,t.inttostr(z),g2d.setcolor(56,122,170));

   stage:=noName;
   j:=iList[i].bHead;
   while j<>0 do //bezhim po stolbcam
    begin
      pushStack(bList[j].value);

      case stage of
      noName: begin if bList[j].value=32 then stage:=probel else
                    if blist[j].value=46{.} then stage:=chislo else
                    if (bList[j].value=47) and (bList[ bList[j].next ].value=47) then stage:=commentariy else
                    if symbolR(j) then

                    begin
                         t.print(editorarea,x+editorBorder.w,y,char(bList[j].value),g2d.setcolor(0,128,255));clearStack;inc(x,8);
                         end else
                    if (bList[j].value>=48) and (bList[j].value<58) then stage:=chislo else
                    stage:=slovo;

              end;
      chislo:begin  if symbolR(j) then

                   begin
                     drawString(x,y,g2d.setcolor(255,128,0));
                     t.print(editorarea,x+editorBorder.w-8,y,char(bList[j].value),g2d.setcolor(0,128,255));
                     stage:=noName;
                   end else
                    if bList[j].value>57 then stage:=slovo else
                   if bList[j].value=32 then begin drawString(x,y,g2d.setcolor(255,128,0));stage:=noName;end;  //;


                  //buffer.font.print(5,5,buffer.font.inttostr(bList[j].value),buffer.canvas.setcolor(0,128,255));
             end;
      slovo:begin
              if bList[j].value=32 then begin drawString(x,y,changeColor(searchTypeWord));stage:=noName;end
              else
              begin
              if (bList[j].value=47) and (bList[ bList[j].next ].value=47) then
               BEGIN
               bbbyte:=popStack;
               drawString(x,y,changeColor(searchTypeWord));
               pushStack(47);
               //x:=x+8;
               stage:=commentariy;
               END else
              if symbolR(j) then
               begin
               bbbyte:=popStack;
               drawString(x,y,changeColor(searchTypeWord));stage:=noName;
               t.print(editorarea,x+editorBorder.w{-8},y,char(bList[j].value),g2d.setcolor(0,128,255));
               x:=x+8;
               end;
              end;
            end;

       probel:begin
        if blist[j].value=46{.} then stage:=chislo else
        if (bList[j].value=47) and (bList[ bList[j].next ].value=47) then stage:=commentariy else
       if symbolR(j) then  //esli simvol razdelitel
       begin
       tkey:=popStack; drawString(x,y,g2d.setcolor(0,0,0));
                         t.print(editorarea,x+editorBorder.w,y,char(bList[j].value),g2d.setcolor(0,128,255));clearStack;inc(x,8);end else
                if blist[j].value<>32 then
                begin
                tkey:=popStack;
               // buffer.font.print(10,10,buffer.font.inttostr(tkey),buffer.canvas.setcolor(255,255,255));
                drawString(x,y,g2d.setcolor(0,0,0));

                 if (bList[j].value>=48) and (bList[j].value<58) then stage:=chislo else
                    stage:=slovo;

                pushStack(tkey);    
                end;

              end;
      end;//case
     j:=bList[j].next;

    end;//while j
    if headStack<>0 then begin
                          case stage of
                            chislo:drawString(x,y,g2d.setcolor(255,128,0));
                            slovo:drawString(x,y,g2d.setcolor(255,255,255));
                            commentariy:drawString(x,y,g2d.setcolor(255,255,0));
                          end;//case
                        end;
    clearStack;
   inc(z); inc(y,16);
   i:=iList[i].next;
  end;//while

time_cursor:=time_cursor+0.1;
if time_cursor>1 then begin
    time_cursor:=1-time_cursor;
    show_cursor:=not show_cursor;
end;
if show_cursor then
 t.print(editorArea,cursor_position.x-4+editorBorder.w-scrolloffset.x,cursor_position.y-scrolloffset.y,'|',g2d.setcolor(255,128,128));
END;