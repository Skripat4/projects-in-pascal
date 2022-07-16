{ (c) Nickita Guschin }
{textEditor v1}

procedure TArrayListFOrEditor.mousemove;
BEGIN
if (mouseX>EditorArea.x) and
    (mouseY>EditorArea.y) and
	(mousex<EditorArea.x+EditorArea.w) and
	(mousey<EditorArea.y+EditorArea.h) then
	begin
	//BufferZone.drawStrokeRect(EditorArea.x+2,EditorArea.y+2,EditorArea.w-6,EditorArea.h-6,255,255,0);
//--> обводим строчку на которой курсор
	  g2d.drawStrokeRect(EditorArea,g2d.setRect(1,(((MouseY-EditorArea.y+scrolloffset.y) div 16)*16)-scrolloffset.y,EditorArea.w-1,16),g2d.setcolor(255,255,0));
	end;
END;