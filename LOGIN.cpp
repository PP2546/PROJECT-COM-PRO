#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

void Login()
{
    int come;
    string name , password , n , pw;
    cout << "\n";
    cout << "--------Login-------\n";
    cout << "Enter is your username : ";
    cin >> name;
    cout << "Enter is your password : ";
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
        cout << "Hello," << name << "!!!!!";
        cin.get();
    }
    else
    {
        cout << "###ERROR###";
        cin.get();      
    }
}


void Register()
{
    string name , password;
    //กรอกชื่อและรหัสเพื่อสมัคร
    cout << "\n";
    cout << "--------Register-------\n";
    cout << "What is your username? : ";
    cin >> name;
    
    cout << "What is your password? : ";
    cin >> password;
    
    ofstream dest;
    dest.open("records.txt",ios::app);
    dest << name << " " << password << endl;
    
    cout << "DONE!!!\n";
    Login(); //ให้ login ต่อเลย
  
}


int main()
{
    int choose;
    cout << "\n";
    cout << "--------- WELCOME TO CPE BOOKSTORE ---------\n";
    cout << "1.Login  \n" << "2.Register  \n" << "What is your answer : ";
    cin >> choose;
    if(choose == 1) Login();
    else if(choose == 2) Register();
    else cout << "SORRY,CHOOSE AGAIN BETWEEN 1 OR 2\n";
}
