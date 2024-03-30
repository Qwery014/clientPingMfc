#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "CMainWindow.h"

using namespace boost::asio;
using namespace boost::asio::ip;

CMainWindow::CMainWindow() : resolver(ctx), s(ctx)
{
	Create(NULL, _T("Простое окно MFC"));

	Input.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL, CRect(50, 50, 300, 180), this, 1);
	Btn.Create(_T("Отправить"), WS_CHILD | WS_VISIBLE | WS_BORDER , CRect(320, 50, 400, 80), this, 2);
}


afx_msg void CMainWindow::OnButtonClicked()
{
	try
	{
		Input.GetWindowText(Text);

		RequestFunc(Text);

		Input.SetWindowText("");
		Input.SetFocus();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception happened: " << e.what() << std::endl;
	}
}

void CMainWindow::Connect()
{
	try {
		auto addr = resolver.resolve("127.0.0.1", "10000");

		connect(s, addr);

		//all value is read
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception happened: " << e.what() << std::endl;
	}
}

void CMainWindow::RequestFunc(CString Text)
{
	CStringA strA(Text);
	std::string str(strA);

	write(s, buffer(&str[0], str.size()));

	std::string res;
	auto count = read(s, buffer(res, res.size()));
}