{ (c) Nickita Guschin }
{textEditor v1}
 
 {$I editor\perenosStroky.inc}

 {$I editor\cursorLeft.inc}

 {$I editor\cursorRight.inc}

 {$I editor\cursorUp.inc}

 {$I editor\cursorDown.inc}

 {$I editor\deleteChar.inc}

 {$I editor\newLine.inc}

{$I editor\keyDown.inc}

{function TArrayListForEditor.getCountLines:integer;
begin result:=countLines;end;
}

{$I editor\addKey.inc}

{$I editor\vybor_CHH.inc}

{$I editor\create.inc}

{$I editor\draw.inc}

{$I editor\mousemove.inc}

{$I editor\pushstack.inc}

{$I editor\clearstack.inc}

{$I editor\drawstring.inc}

 {$I editor\popstack.inc}


 {$I editor\searchkeyword.inc}

 {$I editor\changecolor.inc}

function TArrayListForEditor.printStack(xx,yy:integer;color:tcolor):integer;
begin
result:=0;
end;

{$I editor\symbolR.inc}
