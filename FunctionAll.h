#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>
#include<iomanip>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Bookshop Class
class bookstore {
    private: // ไม่สามารถเข้าถึงได้จากภายนอก class
        char *title;
        float price[100];
        int stock[100];
        int Discount;
        char TitleEdit[100];
        float PriceEdit;
        int StockEdit;
        double TotalCost = 0;
        int Totalquantity = 0;
        int come = 0;
    public:
        bookstore() 
            {
                title = new char[20];
            }
        void Start();
        void Login();
        void staffLogin();
        void Register();
        void CheckUser(int,int);
        void Control_panel();
        void Control_panelForStaff();
        void Buy_book();
        void NewTemp(int);
        void Show_book();
        void Data_book(int);
        void Edit_data(int,int);
        void Edit_dataForStaff(int,int);
};

// Function to display first page
void bookstore::Start()
{
    cout << "\n";
    cout << "-----------| WELCOME TO CPE BOOKSTORE |-----------\n\n";
    cout << "------------------- Customer ------------------\n";
    cout << "\t  Press < 1 > to Login  \n";
    cout << "\t  Press < 2 > to Register  \n";
    cout << "\t  Press < 3 > to Incognito Mode  \n\n";

    cout << "------------------ Staff Only ------------------\n";
    cout << "\t  Press < 0 > to Add book to stock  \n";
}

//Function login for Staff
void bookstore::staffLogin()
{
    string name , password , n , pw;
    cout << "\n";
    cout << "\t------------ Login ------------\n";
    cout << "\tEnter is your username : ";
    cin >> name;
    cout << "\tEnter is your password : ";
    cin >> password;

    ifstream source;
    source.open("STAFFLOGIN.txt",ios::app);
    
    while(source >> n >> pw)
    {
        if(n == name && pw == password)
        {
            come = 1;
        }
    }

    source.close();

    if(come == 1)
    {
        cout << "\nLogin successfaul ++\n\n";
        cout << "Hello , " << name << " What would you like to do?\n";
        cin.get();
    }
    else
    {
        cout << "\nLogin failed , please try again.\n ";
        cin.get(); 
        staffLogin();     
    }
}

// Function Login
void bookstore::Login()
{
    string name , password , n , pw;
    cout << "\n";
    cout << "\t------------ Login ------------\n";
    cout << "\tEnter is your username : ";
    cin >> name;
    cout << "\tEnter is your password : ";
    cin >> password;

    ifstream source;
    source.open("records.txt",ios::app);
    
    while(source >> n >> pw)
    {
        if(n == name && pw == password)
        {
            come = 1;
        }
    }

    source.close();

    if(come == 1)
    {
        cout << "\nLogin successfaul ++\n\n";
        cout << "Hello , " << name << " What would you like to do?\n";
        cin.get();
    }
    else
    {
        cout << "\nLogin failed , please try again.\n ";
        cin.get(); 
        Login();     
    }
}

// Function Register
void bookstore::Register()
{
    string name , password;
    //กรอกชื่อและรหัสเพื่อสมัคร
    cout << "\n";
    cout << "\t----------- Register -----------\n";
    cout << "\tWhat is your username? : ";
    cin >> name;
    
    cout << "\tWhat is your password? : ";
    cin >> password;
    
    ofstream dest;
    dest.open("records.txt",ios::app);
    dest << name << " " << password << endl;
    
    cout << "\nSuccessful register ++ \n";
    // สมัครเสร็จเเล้ว จะไปที่หน้า first page
  
}

// Function check user
void bookstore::CheckUser(int x ,int T)
{
    if(x == 1 && T >= 5 ) Discount = 10;  // ถ้าเป็นสมาชิก เเละ ซื้อ 5 เล่มขึ้นไป ลด 10 %
    else if (x == 1 && T < 5 ) Discount = 0; // ถ้าเป็นสมาชิกเเล้วซื้อไม่ถึง  5 เล่ม ยังไม่ได้ส่วนลด
    else if (x == 0) Discount = 0; // ถ้าผู้ใช้ไม่ได้สมัครสมาชิก (เข้าใช้งาน เเบบ Incognito Mode) จะไม่ได้ส่วนลดใดๆ
}

// Function Control panel for staff
void bookstore::Control_panelForStaff()
{
    cout << "\n";
    system("cls");
    cout << "\t  Press < 1 > to Add new book" << endl;
    cout << "\t  Press < 2 > to Add old book to stock" << endl;
    cout << "\t  Press < 3 > to Exit" << endl;
}

// Function to display the menus
void bookstore::Control_panel()
{
    cout << "\n";
    cout << "\t  Press < 1 > to Buy a book" << endl;
    cout << "\t  Press < 2 > to Show all books" << endl;
    cout << "\t  Press < 3 > to Exit" << endl;

}


// Function Show all book
void bookstore::Show_book() // การแสดงข้อมูล
{   
    system("cls");
    ifstream read;
    read.open("book.txt",ios::app);
    string textline;
    int i = 1;
    int s;
    float Pr;
    cout << "\n***************************************************************************************\n";
    cout << left << setw(16) << "Number ID" << setw(42) << "Title" << setw(24) << "Price ( Bath )" << setw(0) << "Stock" << "\n";
    cout << "***************************************************************************************\n";
    while(getline(read,textline))
    {
        char title[100];
        sscanf(textline.c_str(),"%[^:]: %f %d",title,&Pr,&s);
        cout << left << setw(16) << i ;
        cout << setw(42) << title ; 
        cout << setw(24) << Pr ;
        cout << setw(0) << s ;
        price[i] = Pr;
        stock[i] = s;
        i++;
        cout << "\n\n" ;
    }
    cout << "*************************************************************************************\n";
}



void bookstore::NewTemp(int count) //รับไฟล์ต้นฉบับจาก txt เพื่อนำมา copy เฉพาะบรรทัดที่ต้องการจะแก้ไข รับ parameter คือเลขบรรทัด
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


//Function Data_book
void bookstore::Data_book(int xorder) // ข้อมูลตั้งต้น
{
    for(int i = 0 ; i != xorder; i++){
        string title;
        float price ;
        int stock;
        cin.ignore();
        ofstream write("book.txt",ios::app);
    
        cout << "\n\t---------- add a book ----------\n";
        cout << "\n\tEnter Title name : ";
        getline(cin,title);
        write << title << ":";
        
        cout << "\tEnter price : ";
        cin >> price;
        write << price << " ";
        
        cout << "\tEnter stock : ";
        cin >> stock;
        write << stock << " \n";

        cout << "\nSuccessful added a book ++ \n";
    }
}

// Function Buy book 
void bookstore::Buy_book()
{
    int quantity_buy_book;
    int bookID;
    char Answer;
    bookstore b;
    b.Show_book();

    cout << "\n\t  --------- Buy a books ---------\n";
    cout << "\nChoose the number ID of books : ";
    cin >> bookID;
    cout << "How many books do you want to buy? : ";
    cin >> quantity_buy_book;
    system("cls");


    if(quantity_buy_book <= b.stock[bookID]) // สินค้ายังเหลือ/พอดี
    {
        b.Edit_data(bookID,quantity_buy_book);
        stock[bookID] -= quantity_buy_book; // ของในคลังที่ถูกออกไปขาย
        double cost = b.price[bookID]*quantity_buy_book;
        TotalCost = TotalCost + cost;
        Totalquantity = Totalquantity + quantity_buy_book;
        cout << "\nCost : " << cost << " Bath\n"; // Cost
        cout << "-------------------------------------\n";
        cout << "\nTotal Books : " << Totalquantity;
        cout << "\nTotal cost : " << TotalCost << " Bath \n\n"; // Total cost
        cout << "-------------------------------------\n";
        cout << "Do you want to buy another book? <Y/N> :";
        cin >> Answer;
        system("cls");
        if(Answer == 'Y'){
            Buy_book();
        }else{
            b.CheckUser(come , Totalquantity);
            cout << "-------------------------------------\n";
            cout << "Total Books : " << Totalquantity << endl;
            cout << "Discount : " << b.Discount <<" %\n"; // Discount
            cout << "Discounted price : " << (TotalCost*b.Discount)/100 <<" Bath\n\n"; // Discount price
            cout << "Total cost : " << TotalCost-(TotalCost*b.Discount)/100 << " Bath \n"; // Total cost
            cout << "*****************************************\n";
            cout << "*                                       *\n";
            cout << "*            THANK YOU !!!              *\n";
            cout << "*                                       *\n";
            cout << "*****************************************\n";
        }
    }
    else
    {
        if(b.stock[bookID]== 0)
        {
            cout << "           Sorry , Sold out!!!       \n";
            cout << "-------------------------------------\n";
            cout << "Do you want to buy another book? <Y/N> :";
            cin >> Answer;
            system("cls");
            
            if(Answer == 'Y') Buy_book();
            else{
                cout << "*****************************************\n";
                cout << "*                                       *\n";
                cout << "*            THANK YOU !!!              *\n";
                cout << "*                                       *\n";
                cout << "*****************************************\n";
            }
        }
        else 
        {
            cout << "We have " << b.stock[bookID] << " book\n";
            cout << "-------------------------------------\n";
            cout << "Do you want to buy this book? <Y/N> :";
            cin >> Answer;
            if(Answer == 'Y'){
                Buy_book();
            }else{
                cout << "*****************************************\n";
                cout << "*                                       *\n";
                cout << "*            THANK YOU !!!              *\n";
                cout << "*                                       *\n";
                cout << "*****************************************\n";
            }
        }
    }
}

// Function Edit data
void bookstore::Edit_data(int numline,int quantity) //edit data รับ parameter คือเลขบรรทัดและจำนวนที่ซื้อ
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

void bookstore::Edit_dataForStaff(int numline,int quantity) 
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
            write << TitleEdit << ":" << PriceEdit << " " << StockEdit+quantity << endl; //add to stock 
        }
    }
    write.close();
    Show_book();
}
