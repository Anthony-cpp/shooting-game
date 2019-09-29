#include <stdio.h>
#include <windows.h>
#include "DxLib.h"
#include "MyWindow.h"
#include "Input.h"

MyWindow::MyWindow() {
	WINDOW_TITLE = "DxLib";
}
MyWindow::MyWindow(const TCHAR *windowTitle) {
	if (windowTitle == nullptr) {
		WINDOW_TITLE = "Dxlib";
	}
	else {
		WINDOW_TITLE = windowTitle;
	}
}

MyWindow::~MyWindow() {
	DxLib::DxLib_End();
	// OutputDebugString("DxLib was anloaded!\n");
}

void MyWindow::ErrMsgBx(const TCHAR *ErrorMsg) {
	MessageBox(
		NULL,
		TEXT(ErrorMsg),
		TEXT("ERROR"),
		MB_OK | MB_ICONERROR
	);
}

bool MyWindow::WindowInit() {
	DxLib::SetOutApplicationLogValidFlag(m_winInfo.isOutLog);
	DxLib::SetGraphMode(WIDTH, HEIGHT, 32);
	DxLib::SetMainWindowText(WINDOW_TITLE);
	DxLib::SetAlwaysRunFlag(m_winInfo.isAlwaysRun);
	DxLib::SetWindowStyleMode(m_winInfo.windowStyleMode);
	DxLib::SetWindowIconID(1);
	DxLib::SetBackgroundColor(0, 0, 0);
	DxLib::ChangeWindowMode(!m_winInfo.isFullScreen);
	DxLib::SetWindowSizeChangeEnableFlag(m_winInfo.enableSizeChange);
	if (DxLib::DxLib_Init() != 0) {
		ErrMsgBx("エラー"が発生しました。\nウィンドウの設定に失敗しました。");
		return true;
	}
	if (DxLib::SetDrawScreen(DX_SCREEN_BACK) != 0) {
		ErrMsgBx("エラー"が発生しました。\nウィンドウの設定に失敗しました。");
		DxLib::DxLib_End();
		return true;
	}
	return false;
}

void MyWindow::SetWindowInfo(WindowInfo_t windowInfo) {
	m_winInfo = windowInfo;
}
