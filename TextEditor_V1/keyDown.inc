{ (c) Nickita Guschin }
{textEditor v1}

procedure TArrayListForEditor.keyDown(key:byte);
var
 ch:byte;temp,temp2:longword;//protectedKey:integer;
begin
  ch:=vybor_CHH(Key);
  
  temp:=bList[bFree].next;
 if iList[iString].bHead=0 then begin
   bList[bFree].value:=ch;
   bList[bFree].next:=0;
   iList[iString].bHead:=bFree;
   iList[iString].bTail:=bFree;
   bCursor:=bFree;
   bFree:=temp;
 end
 else
  if bCursor=0 then begin

      bList[bFree].next:=iList[iString].bHead;
      bList[bFree].value:=ch;
      iList[iString].bHead:=bFree;
      bCursor:=bFree;
      bFree:=temp;

  end // if beginString
   else
    begin
     temp2:=bList[bCursor].next;
     bList[bCursor].next:=bFree;
     bList[bFree].value:=ch;
     bList[bFree].next:=temp2;
     if bCursor=iList[iString].bTail then begin bCursor:=bFree;iList[iString].bTail:=bFree; end else
                                          bCursor:=bList[bCursor].next;
    bFree:=temp;
    end;
    inc(cursor_position.x,8);
end;
