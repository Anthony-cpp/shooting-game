#include "DxLib.h"
#include "Input.h"
#include "MyWindow.h"
#include "Timer.h"
const TCHAR WindowTitle[] = "MyWindow";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MyWindow myWin(WindowTitle);
	if (myWin.WindowInit()) return -1;
	
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !input::UpdateAll()) {
		
	}
	return 0;
}
