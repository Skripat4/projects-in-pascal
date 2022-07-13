{ (c) Nickita Guschin }
{textEditor v1}

 tpoint2=record
  x,y:integer;
 end;
 TtstringList=record
   bHead,bTail,last,next:longword;
  end;

  
 TarrayListForEditor = class
 private
  countSpecialWords:integer;
  specialWords:array of string;
  stage:byte;  //sostoyaniy dla parsera
  headStack,tailStack:longword;

  scrollOffset:tpoint2; // sobsno text to moving in view port

  rusEng:boolean;
  g2d:pGraphicsWork; // <= ukazatel na buffer klavu mishy
  t:pfonts;
  karetka:byte;
  
////migaushiy kursor ///////////
   time_cursor:real;          //
   show_cursor:boolean;       //
   cursor_position:tpoint2;   //
////////////////////////////////
   bCursor:longword; //указатель на букву в bList'е
   iFree,bFree:longword;  //ukazateli v oblasti spiska svobodnoy pamaty
   iList:array of ttstringList;
   bList:array of record value:byte;next:longword;end;
   iCount,bCount:longword; //kolichesvto videleny bayt
   iHead,iTail:longword; // spisok strok
   iString:longword; // ukazatel na stroku;

   //Поле ввода текста
EditorArea:rect_;

//Каемка с краю
EditorBorder:rect_;

  function symbolR(q:longword):boolean; //proveraet est li razdelitelniye symboly v indekse massiva blist
  procedure pushStack(key:byte);
  procedure clearStack;
  function popStack:byte;

  function perenosStroky:boolean;
  procedure cursorLeft;
  procedure cursorRight;
  procedure cursorUp;
  procedure cursorDown;
  procedure deleteChar;
  procedure newLine;
  procedure keyDown(key:byte);

  function vybor_CHH(x:byte):byte; // для корретировки кода символа

  function searchTypeWord:byte;
  function changeColor(a:byte):tcolor;
  function printStack(xx,yy:integer;color:tcolor):integer; //getlengthstringinstack

  procedure drawString(var xx:integer;yy:integer;color:tcolor);

 public

  constructor create( graphics2d:pGraphicsWork;f:pfonts);

  procedure addKey(Key:byte); // добавляем букву в строку
  procedure draw;
  procedure mouseMove;
 end;