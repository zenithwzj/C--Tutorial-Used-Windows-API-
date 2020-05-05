#include<iostream>
#include<cstdio>
#include<windows.h>
#include<bits/stdc++.h>
#define checknew 3301
#define searchc 3302
#define searchb 3303
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_CLOSE:
        {
            if(MessageBox(hwnd,"Really quit?","Confirm",MB_YESNO)==IDYES)
                DestroyWindow(hwnd);
            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        case WM_CREATE:
        {
        	CreateWindow("Button","检查更新",WS_VISIBLE|WS_CHILD|BS_PUSHBUTTON|WS_BORDER,0,0,150,50,hwnd,(HMENU)checknew,NULL,NULL);
        	CreateWindow("edit","",WS_VISIBLE|WS_CHILD|ES_MULTILINE|WS_BORDER,10,100,200,75,hwnd,(HMENU)searchc,NULL,NULL);
        	break;
		}
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd,&ps);
            FillRect(hdc,&ps.rcPaint,(HBRUSH)(COLOR_WINDOW+1));
            EndPaint(hwnd,&ps);
        }
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS wc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(WHITE_BRUSH);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "MyApplication";
    wc.lpszMenuName = NULL;
    wc.style = 0;
    RegisterClass(&wc);
    hwnd = CreateWindow("MyApplication","教程",WS_OVERLAPPEDWINDOW,0,0,500,500,NULL,NULL,hInstance,NULL);
    ShowWindow(hwnd,nShowCmd);
    UpdateWindow(hwnd);
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
