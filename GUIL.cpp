#include <windows.h>
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>
using namespace std;
LRESULT CALLBACK WndProc(HWND,UINT , WPARAM ,LPARAM);

char textSaved1[256];
char textSaved2[256];
string id1,pass1;
int count = 1,log = 1,come = 0;
HWND textfield,button,buttonX,TextBox1,TextBox2,check,textsaved,yoyo;
string id,pass;
/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
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

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Library",WS_VISIBLE|WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,500,500,NULL,NULL,hInstance,NULL);

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
			if(count == 1){
				textfield = CreateWindow("STATIC","Login",WS_VISIBLE|WS_CHILD,100,50,100,25,hwnd,NULL,NULL,NULL);
				TextBox1 = CreateWindow("EDIT"," ",WS_BORDER|WS_CHILD|WS_VISIBLE,100,150,250,25,hwnd,NULL,NULL,NULL);
				TextBox2 = CreateWindow("EDIT"," ",WS_BORDER|WS_CHILD|WS_VISIBLE,100,200,250,25,hwnd,NULL,NULL,NULL);
				button = CreateWindow("BUTTON","Login",WS_VISIBLE|WS_CHILD|WS_BORDER,100,250,50,30,hwnd,(HMENU) 2,NULL,NULL);
				button = CreateWindow("BUTTON","Register",WS_VISIBLE|WS_CHILD|WS_BORDER,100,300,50,30,hwnd,(HMENU) 3,NULL,NULL);
			}
			else if(count == 2){
				textfield = CreateWindow("STATIC","Resgister",WS_VISIBLE|WS_CHILD,100,50,100,25,hwnd,NULL,NULL,NULL);
				TextBox1 = CreateWindow("EDIT"," ",WS_BORDER|WS_CHILD|WS_VISIBLE,100,150,250,25,hwnd,NULL,NULL,NULL);
				TextBox2 = CreateWindow("EDIT"," ",WS_BORDER|WS_CHILD|WS_VISIBLE,100,200,250,25,hwnd,NULL,NULL,NULL);
				button = CreateWindow("BUTTON","Resgister",WS_VISIBLE|WS_CHILD|WS_BORDER,100,250,80,30,hwnd,(HMENU) 1,NULL,NULL);
				button = CreateWindow("BUTTON","Login",WS_VISIBLE|WS_CHILD|WS_BORDER,100,300,50,30,hwnd,(HMENU) 3,NULL,NULL);
			}
				break;
			case WM_COMMAND:
				if(LOWORD(wParam)!=0){
					id = GetWindowText(TextBox1,textSaved1,256);
					pass = GetWindowText(TextBox2,textSaved2,256);
				}
				if(LOWORD(wParam) == 1){
        			ofstream dest;
    				dest.open("records.txt",ios::app);
   					dest << textSaved1 << textSaved2 << endl;
        			dest.close();
					MessageBox(NULL, "Resgister","Success",MB_ICONEXCLAMATION|MB_OK);
				}
				else if(LOWORD(wParam) == 2){
					string name,pw;
					ifstream read;
   					read.open("records.txt",ios::app);
    
   					while(read >> name >> pw){
						if(strcmp(textSaved1,name.c_str()) && strcmp(textSaved2,pw.c_str())){
							come = 1;
						}

					}
					if(come == 1){
							//check = CreateWindow("STATIC","Success",WS_VISIBLE|WS_BORDER|WS_CHILD,250,250,100,30,hwnd,NULL,NULL,NULL);
							MessageBox(NULL, "Success","Login",MB_ICONEXCLAMATION|MB_OK);
						}else{
							//check = CreateWindow("STATIC","Fail",WS_VISIBLE|WS_BORDER|WS_CHILD,250,250,100,30,hwnd,NULL,NULL,NULL);
							MessageBox(NULL, "Window Creation Failed!","Error",MB_ICONEXCLAMATION|MB_OK);
        				}
				}
				else if(LOWORD(wParam) == 3){
					count == 2;
					DestroyWindow(0);
					return DefWindowProc (hwnd,message,wParam,lParam);
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

