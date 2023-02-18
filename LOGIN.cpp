#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

// Function Login
void Login()
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

        cout << "\n";
        cout << "\tPress < 1 > to Buy a book" << endl;
        cout << "\tPress < 2 > to Show all books" << endl;
        cout << "\tPress < 3 > to Exit" << endl;
    }
    else
    {
        cout << "\nLogin failed , please try again.\n ";
        cin.get(); 
        Login();     
    }
}

// Function Register
void Register()
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
    Login(); //ให้ login ต่อเลย
  
}

//Function menu
void menu(int x){
    
}


int main()
{
    int choose;
    int choose_menu;
    cout << "\n";
    cout << "-------- WELCOME TO CPE BOOKSTORE --------\n\n";
    cout << "\t  Press < 1 > to Login  \n";
    cout << "\t  Press < 2 > to Register  \n";
    cout << "\t\nWhat is your answer : ";
    cin >> choose;
    if(choose == 1) Login();
    else if(choose == 2) Register();
    else { 
        cout << "\t\nxxxxx ERROR xxxxx\n"; 
        return 0; 
    }
    
    cout << "\t\nWhat is your answer : ";
    cin >> choose_menu;
    menu(choose_menu);


    //เติม Function เลือก 1 2 3
}   
