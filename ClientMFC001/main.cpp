#include <iostream>
#include <string>
#include <afxwin.h>
#include "CMainWindow.h"

class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {
		CMainWindow* mainWindow = new CMainWindow();
		m_pMainWnd = mainWindow;
		mainWindow->ShowWindow(SW_SHOW);
		mainWindow->Connect();
		return TRUE;
	}
};


BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_BN_CLICKED(2, &CMainWindow::OnButtonClicked)
END_MESSAGE_MAP()



CMyApp theApp;
