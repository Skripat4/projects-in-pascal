{ (c) Nickita Guschin }
{textEditor v1}

 function TarrayListForEditor.perenosStroky:boolean;
 BEGIN
  if iList[iString].next=0 then begin result:=false;exit;end;
  iString:=iList[iString].next;
  bCursor:=0;
  //ustanovka kursora vidimogo
  inc(cursor_position.y,16);
  cursor_position.x:=karetka;
  result:=true;
 END;