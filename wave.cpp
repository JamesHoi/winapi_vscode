#include"Render.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

extern void Render(HWND hWnd,double aef);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("SineWave");
	HWND			hwnd;
	MSG				msg;
	WNDCLASS	wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = NULL;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows NT!"),szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("single dashboard"),
		WS_EX_LAYERED | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT,CW_USEDEFAULT,
		1000, 600,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int  cxClient, cyClient;
	HDC hdc;
	int length;
	TCHAR szBuffer[100];
	PAINTSTRUCT ps;
	
//	std::thread shuaxin(Paint, hwnd);
//	shuaxin.detach();

	switch (message)
	{
	case   WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
	case   WM_PAINT:
		Render(hwnd,0.8);
		return 0;
	case   WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
