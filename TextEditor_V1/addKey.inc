{ (c) Nickita Guschin }
{textEditor v1}

procedure TArrayListForEditor.addKey(key:byte);
begin
t.print(20,20,t.inttostr(key)+'       ',g2d.setcolor(255,255,255));
 case key of
 10: exit;
 8 : deleteChar;
 13: newLine;
 38: cursorUp;
 40: cursorDown;
 16: begin end;
 37: cursorLeft;
 39: cursorRight;
 33: begin
      dec(scrolloffset.y);
      if scrolloffset.y<-16 then scrolloffset.y:=-16;
     end;//pagu up
 34:begin
     inc(scrolloffset.y);
      if scrolloffset.y>16 then scrolloffset.y:=16;
    end;//page down
 else
 keyDown(key);
end;//case

end;