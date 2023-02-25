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
    int Discount;
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
        void CheckUser(int);
        void Control_panel();
        void Control_panelForStaff();
        void Buy_book(); 
        void Show_book();
        void Data_book(int);
        void Edit_data();
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

// Function Login
void bookstore::Login()
{
    int come = 0;
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
void bookstore::CheckUser(int x)
{
    if(x == 1) Discount = Discount + 15;
    else if (x == 0) Discount = 0;
}

// Function Control panel for staff
void bookstore::Control_panelForStaff()
{
    cout << "\n";
    cout << "\t  Press < 1 > to Add book" << endl;
    cout << "\t  Press < 2 > to Exit" << endl;
}

// Function to display the menus
void bookstore::Control_panel()
{
    cout << Discount << "\n";
    cout << "\t  Press < 1 > to Buy a book" << endl;
    cout << "\t  Press < 2 > to Show all books" << endl;
    cout << "\t  Press < 3 > to Exit" << endl;
}

// Function Show all book 
void bookstore::Show_book() // การแสดงข้อมูล
{   
    ifstream read;
    read.open("book.txt",ios::app);
    string textline;
    int i = 1;
    while(getline(read,textline))
    {
        char title[100];
        int stock;
        float price;
        int start = 0;
        sscanf(textline.c_str(),"%[^:]: %f %d",title,&price,&stock);
        cout << "\t  -------------------------------\n";
        cout << "\t  Number ID : " << i << endl;
        cout << "\t\t"<<title << endl; 
        cout << "\t\t  Price: " << price << " Bath" << endl;
        cout << "\t\t  Stock: " << stock << endl;
        i++;
    }
    cout << "\t  -------------------------------\n";
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
        cout << "\tTitle: " ;
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
    bookstore b;
    b.Show_book();

    cout << "\n\t  --------- Buy a books ---------\n";
    cout << "\nChoose the number ID of books : ";
    cin >> bookID;
    cout << "How many books do you want to buy? : ";
    cin >> quantity_buy_book;
    
    if(quantity_buy_book <= *stock) // สินค้ายังเหลือ/พอดี
    {
        b.Edit_data();
        *stock -= quantity_buy_book; // ของในคลังที่ถูกออกไปขาย
        cout << "\nCost : " << (*price)*quantity_buy_book << " Bath\n"; // Cost
        cout << "Discount : " << Discount <<" Bath\n" ; // Discount
        cout << "Total cost : " << ((*price)*quantity_buy_book)-Discount << " Bath \n\n"; // Total cost
        cout << "*****************************************\n";
        cout << "*                                       *\n";
        cout << "*            THANK YOU !!!              *\n";
        cout << "*                                       *\n";
        cout << "*****************************************\n";
    }
    else
    {
        cout << "Sorry , Sold out"; 
    }
}

// Function Edit data
void bookstore::Edit_data()
{
    ifstream read;
    read.open("book.txt",ios::app);

    int Title_number;
    
    vector<string> titleline;
    string Title;
    string text;
    text = Title ;

    while(getline(read,Title))
    {
        titleline.push_back(Title);
    }

    read.close();

    ofstream write;
    write.open("book.txt",ios::app);
    
    Title_number--;
    
    for(int i=0;i < Title.size();i++)
    {
        if(Title_number != titleline.size())
        {
            write << titleline[i] << endl;
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
    int order_add;
	bookstore b;

	while (1) {

		b.Start();
		cout << "\t\nWhat is your answer : ";
		cin >> choice_start;
		switch (choice_start){

		case 0:
            b.Control_panelForStaff();
            cout << "\nWhat is your answer : ";
		    cin >> choice_staff;
            if(choice_staff == 2) exit(0);

            cout << "How many orders will you add? : ";
            cin >> order_add;
            while (1)
            {   
                switch (choice_staff)
                {   
                    case 1:
                        b.Data_book(order_add);
                    case 2: 
                        exit(0);
                    default:
                        cout << "\nxxxxx INVALID CHOICE xxxxx \n";
                        exit(0);
                }
            }

        case 1:
			b.Login();
            b.CheckUser(1);
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

        case 3:
            b.Control_panel();
            b.CheckUser(0);
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
