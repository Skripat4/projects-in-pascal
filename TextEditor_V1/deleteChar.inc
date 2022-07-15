{ (c) Nickita Guschin }
{textEditor v1}

procedure TarrayListForEditor.deleteChar;
  var temp,temp2:longword;
  begin
  if bCursor=0 then
  BEGIN
   if iString=iHead then exit
   else
   begin
     //[]-[S]

     temp:=iLIst[iString].last;
     if iList[Temp].bHead=0 then BEGIN
        iList[Temp].bHead:=iList[iString].bhead;
        iList[Temp].bTail:=iList[iString].bTail;
         bCursor:=0;
     END
     ELse
     begin
      if iList[iString].bHead=0 then BEGIN
         bCursor:=iList[temp].bTail;
      END else
      BEGIN
     bList[ iList[temp].btail ].next:=iList[iString].bHead;
     bCursor:=iList[temp].bTail;
     iLIst[temp].bTail:=iLIst[iString].bTail;
     END;
     end;
     temp2:=iList[iString].next;

     iList[temp].next:=temp2;
     iList[temp2].last:=temp;

     iList[iString].last:=0;
     iList[iString].next:=iFree;

     iList[iFree].last:=iString;
     iFree:=iString;

     iString:=temp;


     dec(cursor_position.y,16);
     cursor_position.x:=karetka;
     if bCursor<>0 then begin
     temp:=iList[iString].bHead;

     while temp<>bCursor do
      begin
        temp:=bList[temp].next;
        inc(cursor_position.x,8);
      end;//while
      if iList[iString].bHead<>0 then inc(cursor_position.x,8);
      end;
   end
   END//if bCursor=0
   else
   BEGIN
     if bCursor=iLIst[iString].bHead then
      begin
         if bCursor=iLIst[iString].bTail then
           begin

             bList[bCursor].next:=bFree;
             iList[iString].bHead:=0;
             iList[iString].bTail:=0;
             bFree:=bCursor;
             bCursor:=0;

           end
           else
           begin
             iList[iString].bHead:=bList[bCursor].next;

             bList[bCursor].next:=bFree;
             bFree:=bCursor;
             bCursor:=0;
           end;
      end
      else
      if bCursor=iLIst[iString].bTail then
       begin
         temp:=iLIst[iString].bHead;
         while bList[temp].next<>bCursor do
          temp:=bList[temp].next;
         iList[iString].bTail:=temp;

         bList[bCursor].next:=bFree;
         bFree:=bCursor;
         bList[temp].next:=0;
         bCursor:=temp;
       end
       else
       begin
         temp:=iLIst[iString].bHead;
         while bList[temp].next<>bCursor do
          temp:=bList[temp].next;
         bList[temp].next:=bList[bCursor].next;

         bList[bCursor].next:=bFree;
         bFree:=bCursor;
         bCursor:=temp;

       end;
     dec(cursor_position.x,8);
   End//if curos not equals zero

END;//8 delete