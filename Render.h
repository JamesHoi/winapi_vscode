#include<Windows.h>
#include<math.h>
#include<thread>

#define PI (3.1415926)

int g_nWidth = 1000, g_nHeight = 600;
int length;
TCHAR szBuffer[100];

void Render1(HWND hWnd, double aef) {
	HDC hDC = GetDC(hWnd);		//���ϵͳ��ͼ�豸     
	HDC memDC = CreateCompatibleDC(0);	//����������ͼ�豸     
	HBITMAP bmpBack = CreateCompatibleBitmap(hDC, g_nWidth, g_nHeight);//��������λͼ��������    
	SelectObject(memDC, bmpBack);	//����������������ͼ�豸��     
	HPEN penBack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//��������    
	SelectObject(memDC, penBack);    //������ѡ����ͼ�豸��     
	HBRUSH brushBack = CreateSolidBrush(RGB(255, 255, 255));//������ˢ    
	SelectObject(memDC, brushBack);  //����ˢѡ����ͼ�豸��     
	//��������
	RECT rcClient;//����ṹ    
	GetClientRect(hWnd, &rcClient);//��ÿͻ�����    
	HBRUSH brushTemp = (HBRUSH)GetStockObject(WHITE_BRUSH);//��ÿ�����壬��ɫ��ˢ��    
	FillRect(memDC, &rcClient, brushTemp);//���ͻ�����    
	//////////////////////////////////////////////////////////////////////////    	
	HBRUSH brushObj = CreateSolidBrush(RGB(0, 255, 0));//�������廭ˢ    
	 //�򻭲���ͼ

	Rectangle(memDC, 0, 0, 300, 150 * sin(PI / 6) + 150);
	Pie(memDC, 0, 0, 300, 300, 150 * cos(PI / 6) + 150, -150 * sin(-(PI / 6)) + 150, 150 * cos(PI * 7 / 6) + 150, -150 * sin(PI * 7 / 6) + 150);
	MoveToEx(memDC, 150, 150, NULL);
	LineTo(memDC, 150 * cos(PI*aef) + 150, -150 * sin(PI*aef) + 150);
	length = wsprintf(szBuffer, "dashboard_1");
	TextOut(memDC, 110, 200, szBuffer, length);

	DeleteObject(brushObj);
	//////////////////////////////////////////////////////////////////////////    
	BitBlt(hDC, 0, 0, g_nWidth, g_nHeight, memDC, 0, 0, SRCCOPY);//���Ƶ�ϵͳ�豸����ʾ    
	DeleteObject(penBack);  //�ͷŻ�����Դ    
	DeleteObject(brushBack);//�ͷŻ�ˢ��Դ    
	DeleteObject(bmpBack);  //�ͷ�λͼ��Դ    
	DeleteDC(memDC);	    //�ͷŸ�����ͼ�豸    
	ReleaseDC(hWnd, hDC);	//�黹ϵͳ��ͼ�豸    
	Sleep(10);
}
