{ (c) Nickita Guschin }
{textEditor v1}

PROCEDURE TarrayListForEditor.newLine;
VAR temp,temp2:longword;
BEGIN
  if bCursor=0 then
 BEGIN
   if iList[iString].last=0 then
    begin
      iHead:=iFree;
      temp:=iList[iFree].next;
      iList[iFree].next:=iString;
      iList[iFree].last:=0;
      iList[iString].last:=iFree;
      iList[Ifree].bHead:=0;
      iList[iFree].bTail:=0;
      iFree:=temp;
    end
    else
    begin
     temp:=iList[iString].last;
     temp2:=iList[iFree].next;
     iList[temp].next:=iFree;
     iList[iFree].next:=iString;
     iList[iFree].last:=temp;
     iList[iString].last:=iFree;
     iList[iFree].bHead:=0;
     iList[iFree].bTail:=0;
     iFree:=temp2;
    end;
    inc(cursor_position.y,16);
    
   END
     else
      BEGIN
      temp:=iList[iString].next;
      temp2:=iList[iFree].next;
       if bCursor=iList[iString].bTail then
        begin
          iList[iString].next:=iFree;
          iList[iFree].last:=iString;
          iList[iFree].next:=temp;
          iList[temp].last:=iFree;
          iList[iFree].bHead:=0;
          iList[iFree].bTail:=0;
          iString:=iFree;
          iFree:=temp2;
        end
        else
        begin
       // [s] - [F] - []

      iList[iFree].bTail:=iList[iString].bTail;
      iList[iFree].bHead:=bList[bCursor].next;
      iList[iString].bTail:=bCursor;
      bList[bCursor].next:=0;
      iList[iString].next:=iFree;
      iList[temp].last:=iFree;
      iList[iFree].next:=temp;
      iList[iFree].last:=iString;
      iString:=iFree;
      iFree:=temp2;
        end;
       inc(cursor_position.y,16);
       cursor_position.x:=karetka;
       bCursor:=0;
      END;
END;