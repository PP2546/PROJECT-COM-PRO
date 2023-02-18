
#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Bookshop Class
class bookstore {
public:
    void Start();
    void Login();
    void Register();
    void Control_panel();
    //void Buy_book(); 
    //void Show_book();
};

// Function to display first page
void bookstore::Start()
{
    cout << "\n";
    cout << "-------- WELCOME TO CPE BOOKSTORE --------\n\n";
    cout << "\t  Press < 1 > to Login  \n";
    cout << "\t  Press < 2 > to Register  \n";
}

// Function Login
void bookstore::Login()
{
    int come;
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

// Function to display the menus
void bookstore::Control_panel()
{
    cout << "\n";
    cout << "\tPress < 1 > to Buy a book" << endl;
    cout << "\tPress < 2 > to Show all books" << endl;
    cout << "\tPress < 3 > to Exit" << endl;
}

// Function Buy book 
// void bookstore::Buy_book(){}

// Function Show all book 
// void bookstore::Show_book(){}


// Function for book store record
void bookstorerecord()
{
	int choice_start;
    int choice_control;
	bookstore b;

	while (1) {

		b.Start();
		cout << "\t\nWhat is your answer : ";
		cin >> choice_start;
		switch (choice_start) {

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
                    /* code buy book */
                    cout << "buy book5555555555";
                    exit(0);
                    break;

                case 2:
                    /* code show book*/
                    cout << "Show book54878899";
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
 
