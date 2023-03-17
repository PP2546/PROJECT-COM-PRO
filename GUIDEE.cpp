#include <windows.h>
#include <cstdio>
#include "FunctionAll.h"
#include <sstream>
using namespace std;
LRESULT CALLBACK WndProc(HWND,UINT , WPARAM ,LPARAM);

char textSaved1[256];
char textSaved3[256];
char textSaved2[256];
float PriceEdit;
char TitleEdit[100];
string id1,pass1;
int count = 1,log = 1,come = 0,num=2,amo,TotalAmo=0,StockEdit,Discount;
int Totalcost=0;
void AddMenu(HWND);
void HomeMenu(HWND);
HWND textfield,button,buttonX,TextBox1,TextBox2,TextBox3,check,textsaved,yoyo;
HWND text1,text2;
HMENU hMenu;
string id,pass,title1[100];
float price[100];
int stock[100];
void FuncShowbook();
void buybook(int,int,HWND);
void Edit_data(int,int);
void NewTemp(int);
void CheckUser(int, int);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd,twnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Library",WS_OVERLAPPEDWINDOW|WS_VISIBLE|WS_SYSMENU
    ,CW_USEDEFAULT,CW_USEDEFAULT,750,500,NULL,NULL,hInstance,NULL);
	
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
            TextBox3 = CreateWindow("EDIT","",WS_VISIBLE|WS_BORDER|WS_CHILD,625,40,75,25,hwnd,NULL,NULL,NULL);
            text1 = CreateWindow("STATIC","NUMBER",WS_VISIBLE|WS_CHILD,625,15,75,25,hwnd,NULL,NULL,NULL);
            TextBox2 = CreateWindow("EDIT","",WS_VISIBLE|WS_BORDER|WS_CHILD,625,105,75,25,hwnd,NULL,NULL,NULL);
            text2 = CreateWindow("STATIC","AMOUNT",WS_VISIBLE|WS_CHILD,625,80,60,25,hwnd,NULL,NULL,NULL);
            button = CreateWindow("BUTTON","BUY",WS_VISIBLE|WS_CHILD|WS_BORDER,625,150,50,30,hwnd,(HMENU) 2,NULL,NULL);
			AddMenu(hwnd);
            HomeMenu(hwnd);
		    break;
			case WM_COMMAND:
                    if(LOWORD(wParam)!=0){
					GetWindowText(TextBox3,textSaved3,256);
					GetWindowText(TextBox2,textSaved2,256);
                    num = atoi(textSaved3);
                    amo = atoi(textSaved2);
				    }
				switch(wParam){
					case 1:
					    MessageBeep(MB_OK);
					break;
                    case 2:
                        buybook(num,amo,hwnd);

                    break;
                    case 3:
                        HINSTANCE hNewInstance = ShellExecute(NULL, "open", "GUIL.exe", NULL, NULL, SW_SHOWNORMAL);
						PostQuitMessage(0);
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
    AppendMenu(hMenu,MF_STRING,3,"Logout");
	SetMenu(hwnd,hMenu);
}

void FuncShowbook(){
    system("cls");
    ifstream read;
    read.open("book.txt",ios::app);
    string textline;
    int i=1;
    int s;
    float Pr;
    //cout << "\n***************************************************************************************\n";
    //cout << left << setw(16) << "Number ID" << setw(42) << "Title" << setw(24) << "Price ( Bath )" << setw(0) << "Stock" << "\n";
    //cout << "***************************************************************************************\n";
    while(getline(read,textline)){
        char title[100];
        sscanf(textline.c_str(),"%[^:]: %f %d",title,&Pr,&s);
        //cout << left << setw(16) << i ;
        //cout << setw(42) << title ; 
        //cout << setw(24) << Pr ;
        //cout << setw(0) << s ;
        title1[i] = title;
        price[i] = Pr;
        stock[i] = s;
        i++;
        count++;
        //cout << "\n\n" ;
    }
    //cout << "*************************************************************************************\n";
}

void HomeMenu(HWND hwnd){
    TextBox1 = CreateWindow("EDIT","",WS_BORDER|WS_CHILD|WS_VISIBLE|WS_VSCROLL|SS_CENTER|ES_AUTOVSCROLL|ES_MULTILINE,10,10,600,400,hwnd,NULL,NULL,NULL);
    FuncShowbook(); // call the function to read data from file and store in arrays
    stringstream ss;
    ss << "\r\n***************************************************************************************\r\n";
    ss << left << setw(16) << "Number ID" << setw(42) << "Title" << setw(24) << "Price ( Bath )" << setw(0) << "Stock" << "\r\n";
    ss << "***************************************************************************************\r\n";
    for (int i = 1; i <= count-1; i++){
        ss << left << setw(16) << i;
        ss << setw(42) << title1[i];
        ss << setw(24) << price[i];
        ss << setw(0) << stock[i];
        ss << "\r\n\r\n" ;
    }
    ss << "*************************************************************************************\r\n";
    SetWindowText(TextBox1, ss.str().c_str());
}

void buybook(int num,int amount,HWND hwnd){
    cout << num << amount;
    ifstream read;
    read.open("book.txt",ios::app);
    string TitleLine;
    int Titlelinee = 0;
    while(getline(read,TitleLine)){
        Titlelinee++;
    }
    system("cls");
    if(num > Titlelinee or num <= 0){
        MessageBox(NULL, "Fail","please try again.",MB_ICONEXCLAMATION|MB_OK);
    }
    else{
        if(amount <= stock[num]){
            string mb;
            Edit_data(num,amount);
            stock[num] -= amount;
            double cost = price[num]*amount;
            Totalcost = cost + Totalcost;
            TotalAmo = TotalAmo + amount;
            mb = "Cost = " + to_string(Totalcost) + " Bath\n\n";
            mb += "TotalBook = " + to_string(TotalAmo);
            mb += "\n\nDo you want to buy another book?";
            int result = MessageBox(NULL, mb.c_str(), "Confirmation", MB_YESNO | MB_ICONQUESTION);

            if(result == IDYES){
                SetWindowText(TextBox1,"");
                HomeMenu(hwnd);
            }
            else{
                CheckUser(1,amount);
                string k;
                k = "Totalquantity : " + to_string(TotalAmo) + "\n\n";
                k += "Discount : " + to_string(Discount) + "%\n\n";
                k += "Discounted price : " + to_string((Totalcost*Discount)/100) + " Bath\n\n";
                k += "Total cost : " + to_string(Totalcost-(Totalcost*Discount)/100) + " Bath \n";
                int re = MessageBox(NULL,k.c_str(),"Success",MB_OK);
                PostQuitMessage(0);
                HINSTANCE hNewInstance = ShellExecute(NULL, "open", "GUILeaw.exe", NULL, NULL, SW_SHOWNORMAL);
            }

        }
    }
}

void Edit_data(int numline,int quantity) //edit data รับ parameter คือเลขบรรทัดและจำนวนที่ซื้อ
{
    ifstream read;
    read.open("book.txt",ios::app);

    int Title_number = numline;
    vector<string> titleline;
    string line;

    while(getline(read,line)){
        titleline.push_back(line); //อ่านไฟล์แล้ว pushback ลงใน vector
    }
    read.close();
    NewTemp(numline);   //copy book.txt
    ofstream write("book.txt");
    Title_number--;

    
    for(int i = 0; i < titleline.size();i++){
        if(i != Title_number){
            write << titleline[i] << endl;
        } else{
            write << TitleEdit << ":" << PriceEdit << " " << StockEdit-quantity << endl;
        }
    }
    write.close();
}

void NewTemp(int count) //รับไฟล์ต้นฉบับจาก txt เพื่อนำมา copy เฉพาะบรรทัดที่ต้องการจะแก้ไข รับ parameter คือเลขบรรทัด
{
    ifstream read;
    read.open("book.txt");
    ofstream write("bookCOPY.txt");
    
    
    string textline;
    for(int i = 0;i < count;i++)
    {
        getline(read,textline);
        sscanf(textline.c_str(),"%[^:]: %f %d",TitleEdit,&PriceEdit,&StockEdit);
    }
    write << TitleEdit << ":" << PriceEdit << " " << StockEdit;
}

void CheckUser(int x ,int T){
    if(x == 1 && T >= 5 ) Discount = 10;
    else if (x == 1 && T < 5 ) Discount = 0;
    else if (x == 0) Discount = 0;
}