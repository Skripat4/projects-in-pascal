{ (c) Nickita Guschin }
{textEditor v1}

procedure TarrayListForEditor.cursorRight;
BEGIN
 if bCursor=iList[iString].bTail then
 begin
 if not perenosStroky then exit;


 end //perenos cursor vniz
 else

  if bCursor=0 then
    if iList[iString].bHead=0 then
     begin
      if not perenosStroky then exit;
     end
     else
     begin
       bCursor:=iList[iString].bHead;
       inc(cursor_position.x,8);
     end
     else
     BEGIN
  bCursor:=bList[bCursor].next;
  inc(cursor_position.x,8);
 END;
END;//cursor right
