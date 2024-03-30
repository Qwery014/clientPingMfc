#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <afxwin.h>

using namespace boost::asio;
using namespace boost::asio::ip;

class CMainWindow : public CFrameWnd {
	CEdit Input;
	CButton Btn;

	std::string response;

	boost::asio::io_context ctx;

	tcp::resolver resolver;

	tcp::socket s;

public:
	CMainWindow();

	CString Text;

	afx_msg void OnButtonClicked();

	void Connect();

	void RequestFunc(CString Text);
	
	DECLARE_MESSAGE_MAP();
};