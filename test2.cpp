#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Bookshop Class
class bookstore {
private: // ไม่สามารถเข้าถึงได้จากภายนอก class
        char *title;
        float *price;
        int *stock;
public:
    bookstore() 
        {
            title = new char[20];
            price = new float;
            stock = new int;
        }
    void Start();
    void Login();
    void Register();
    void Control_panel();
    void Control_panelForStaff();
    void Buy_book(); 
    void Show_book();
    void Data_book();
    void Edit_data();
};

// Function to display first page
void bookstore::Start()
{
    cout << "\n";
    cout << "-----------| WELCOME TO CPE BOOKSTORE |-----------\n\n";
    cout << "---------------- Staff Only ----------------\n";
    cout << "\t  Press < 0 > to Add book to stock  \n\n";
    cout << "---------------- Customer ----------------\n";
    cout << "\t  Press < 1 > to Login  \n";
    cout << "\t  Press < 2 > to Register  \n";
}

// Function Login
void bookstore::Login()
{
    int come = 0;
    string name , password , n , pw;
    cout << "\n";
    cout << "\t----------- Login ----------\n";
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
        cout << "Hello , " << name << " What do you want to do?\n";
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
    cout << "\t--------- Register ---------\n";
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

void bookstore::Control_panelForStaff()
{
    cout << "\n";
    cout << "\tPress < 1 > to Add book" << endl;
    cout << "\tPress < 2 > to Exit" << endl;
}


// Function to display the menus
void bookstore::Control_panel()
{
    cout << "\n";
    cout << "\tPress < 1 > to Buy a book" << endl;
    cout << "\tPress < 2 > to Show all books" << endl;
    cout << "\tPress < 3 > to Exit" << endl;
}

// Function Show all book 
void bookstore::Show_book() // การแสดงข้อมูล
{   
    ifstream read;
    read.open("book.txt",ios::app);
    string textline;
    
    while(getline(read,textline))
    {
        char title[100];
        int stock;
        float price;
        int start = 0;
        sscanf(textline.c_str(),"%[^,], %f %d",title,&price,&stock);
        cout << "-------------------------------\n";
        cout << title << endl; 
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }
    cout << "-------------------------------\n";
}

//Function Data_book

void bookstore::Data_book() // ข้อมูลตั้งต้น
{
    string title,price,stock;
    cin.ignore();
    ofstream write("book.txt",ios::app);
    
    write << endl;
    cout << "\nEnter Title name : ";
    getline(cin,title);
    write << "Title: " << title << ", ";
    
    cout << "\nEnter price : ";
    cin >> price;
    write << price << " ";
    
    cout << "\nEnter stock : ";
    cin >> stock;
    write << stock;
    write.close();
}

// Function Buy book 
void bookstore::Buy_book()
{
    int num;
    cout << "\nEnter number of books to buy : ";
    cin >> num; // จำนวนสินค้าที่จะซื้อ

    if(num <= *stock) // สินค้ายังเหลือ/พอดี
    {
        bookstore b;
        b.Edit_data();
        //*stock -= num; // ของในคลังที่ถูกออกไปขาย
        cout << "SUCCESS!!!";
        cout << "cost : " << (*price)*num; // ราคาสินค้า
    }
    else
    {
        cout << "Sorry , Sold out"; 
    }
}

//Function Edit data
void bookstore::Edit_data()
{
    string text;
    ifstream read;
    read.open("book.txt",ios::app);

    int Title_number;
    
    vector<string> title;
    string Title;

    while(getline(read,Title))
    {
        title.push_back(Title);
    }

    read.close();

    ofstream write;
    write.open("book.txt",ios::app);
    
    Title_number--;
    
    for(int i=0;i < Title.size();i++)
    {
        if(Title != title.size())
        {
            write << title[i] << endl;
        }
        else
        {
            write << text << endl;
        }
    }

    write.close();
}





// Function for book store record
void bookstorerecord()
{
	int choice_start;
    int choice_control;
    int choice_staff;
	bookstore b;

	while (1) {

		b.Start();
		cout << "\t\nWhat is your answer : ";
		cin >> choice_start;
		switch (choice_start) {

		case 0:
            b.Data_book();
            b.Control_panelForStaff();
        case 1:
			b.Login();
            b.Control_panel();
            cout << "\t\nWhat is your answer : ";
		    cin >> choice_control;
            while (1)
            {
                switch (choice_control)
                {
                case 1:
                    b.Buy_book();
                    exit(0);
                    break;

                case 2:
                    b.Show_book();
                    exit(0);
                    break;
                
                case 3:
                    exit(0);
                    break;;
                
                default:
                    break;
                }
               
            }
            break;

		case 2:
			b.Register();
            break;

		default:
			cout << "\nxxxxx INVALID CHOICE xxxxx \n";
            exit(0);
		}
	}
}


int main()
{
	// Function Call
	bookstorerecord();

	return 0;
}
