#include <windows.h>
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include <cstdio>
using namespace std;
LRESULT CALLBACK WndProc(HWND,UINT , WPARAM ,LPARAM);

char textSaved1[256];
char textSaved2[256];
string id1,pass1;
int count = 1,log = 1,come = 0;
void AddMenu(HWND);
HWND textfield,button,buttonX,TextBox1,TextBox2,check,textsaved,yoyo;
HMENU hMenu;
string id,pass;

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd,twnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */


	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+16);
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Library",WS_OVERLAPPEDWINDOW|WS_VISIBLE|WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,750,500,NULL,NULL,hInstance,NULL);
	
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd,UINT message, WPARAM wParam,LPARAM lParam){
		switch(message){
			case WM_CREATE:
			AddMenu(hwnd);
				break;
			case WM_COMMAND:
				switch(wParam){
					case 1:
					MessageBeep(MB_OK);
					break;
				}
				break;
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			default:
				return DefWindowProc (hwnd,message,wParam,lParam);
		}
		return 0;
}   

void AddMenu(HWND hwnd){
	hMenu = CreateMenu();
	AppendMenu(hMenu,MF_STRING,1,"Home");
	SetMenu(hwnd,hMenu);
}