{ (c) Nickita Guschin }
{textEditor v1}

function TArrayListForEditor.vybor_CHH(x:byte):byte;
var
 chh:byte;
 bul:boolean;
BEGIN
 chh:=0;
 bul:=false;
 if (x=32) or (x=13) then chh:=x;
 case x of
           189,187,219,221,220,186,222,188,190,191,192:bul:=true;// -=[]\ ;',./`
           end;
           if bul then
           if keyboard[16].key=1 then
           begin
             case x of
               189{45}:chh:=95;//- _
               187{61}:chh:=43;//= +
               219:chh:=123;//[ {
               221:chh:=125;//] }
               220:chh:=124;//\ |
               186:chh:=58;//; :
               222:chh:=34;//' "
               188:chh:=60;//, <
               190:chh:=62;//. >
               191:chh:=63;// / ?
               192:chh:=126;//` ~
             end;//case shift
            end
             else
             begin
               case x of
               189:chh:=45;//- _
               187:chh:=61;//= +
               219:chh:=91;//[
               221:chh:=93;//]
               220:chh:=92;//\
               186:chh:=59;//;
               222:chh:=39;//"
               188:chh:=44; //,
               190:chh:=46;//.
               191:chh:=47;///
               192:chh:=96;//`
             end;//case
              end;
           if(x>=48)and(x<=57) then begin
           if keyboard[16].key=1 then
                             case x of
                               48:chh:=41; //)
                               49:chh:=33; //!
                               50:chh:=64; //@
                               51:chh:=35; //#
                               52:chh:=36; //$
                               53:chh:=37; //%
                               54:chh:=94; //^
                               55:chh:=38; //&
                               56:chh:=42; //*
                               57:chh:=40; //(
                             end else chh:=x;
                          end;//ciferki
				   if (x>=65) and (x<=90) then begin
           if keyboard[16].key=1 then
              chh:=x else chh:=x+32;
 end;//if bukvi Eng
result:=chh;
END;