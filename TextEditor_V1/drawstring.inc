{ (c) Nickita Guschin }
{textEditor v1}

procedure TArrayListFOrEditor.drawString(var xx:integer;yy:integer;color:tcolor);
 var
  jj:longword;
  count,x,i:integer;
 begin
     count:=0;
     jj:=headStack;
     while jj<>0 do
     begin
      count:=count+1;
      jj:=bList[jj].next;
      end;
     x:=xx+((count-1)*8);
     jj:=headStack;
     for i:=1 to count do
     begin
      t.print(editorArea,x+EditorBorder.w,yy-scrolloffset.y,char(bList[jj].value),color);
	    dec(x,8);
      jj:=blist[jj].next;
     end;
     xx:=xx+count*8;
     clearstack;
 end;