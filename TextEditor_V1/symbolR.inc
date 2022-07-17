{ (c) Nickita Guschin }
{textEditor v1}

function TArrayListForEditor.symbolR(q:longword):boolean;
var res:boolean;
begin
res:=false;
 if (bList[q].value=44) or // ,
    (bList[q].value=40) or // (
    (bList[q].value=41) or // )
    (bList[q].value=61) or // =
    (bList[q].value=59) or // ;
    (bList[q].value=123) or // {
    (bList[q].value=125) or // }
    (bList[q].value=91) or // [
    (bList[q].value=93) or   // ]
    (bList[q].value=43) or //+
    (bList[q].value=45) or //-
    (bList[q].value=42) or //*
    (bList[q].value=47)    // /
    then res:=true;
 result:=res;
end;