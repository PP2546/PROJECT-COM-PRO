#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

void Register()
{
    string name , password;
    
    cout << "What is your name? : ";
    getline(cin,name);
    cout << "What is your password? : ";
    getline(cin,password);
    
    ofstream dest;
    dest.open("records.txt",ios::app);
    dest << name << " " << password << endl;
    
    cout << "DONE!!!\n";
  
}

void Login()
{
    int come;
    string name , password , n , pw;
    
    cout << "Enter is your name : ";
    getline(cin,name);
    cout << "Enter is your password : ";
    getline(cin,password);

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


int main()
{
    int choose;
    cout << "**********************************************\n";
    cout << "1.Login : \n" << "2.Register : \n" << "What is your answer : ";
    cin >> choose;
    if(choose == 1); Login();
    else if(choose == 2); Register();
    cout << "SORRY,CHOOSE AGAIN BETWEEN 1 OR 2\n";
}
