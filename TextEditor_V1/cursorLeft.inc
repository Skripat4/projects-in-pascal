{ (c) Nickita Guschin }
{textEditor v1}

procedure TarrayListForEditor.cursorLeft;
 var temp:longword;
 BEGIN
 if bCursor=0 then
 begin
  if iList[iString].last=0 then exit;
  iString:=iList[iString].last;
  bCursor:=iList[iString].bTail;
  //ustanovka kursora vidimogo
  dec(cursor_position.y,16);
  cursor_position.x:=karetka;
  if iList[iString].bHead<>0 then begin
                                   inc(cursor_position.x,8);
                                   temp:= iList[iString].bHead;
                                   while temp<>bcursor do
                                    begin
                                     inc(cursor_position.x,8);
                                    temp:=bList[temp].next;
                                    end;//while
                                  end;
 end //perenos cursor naverh
 else
 begin
 if bCursor=iList[iString].bHead then
  bCursor:=0
  else
 BEGIN
  temp:=iList[iString].bHead;
  while bList[temp].next<>bCursor do
   temp:=bList[temp].next;
   bCursor:=temp;
  END;

  dec(cursor_position.x,8);
 end;
END;//kursor left
