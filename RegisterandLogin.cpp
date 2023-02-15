#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

bool login ()
{
    string username , password , name , pw ;

    cout << "Enter username : " ; cin >> username ;
    cout << "Enter password : " ; cin >> password ;

    ifstream read;
    read.open("records.txt",ios::app);
    
    int i = 0;
    while(getline(read,name) && getline(read,pw))
    {
        if(name == username && pw == password)
        {   
            return true;
        }else{
            return false;
        }
        i++;
    }
    
}

int main()
{
    int c;

    cout << "HI , CUSTOMER\n" ;
    cout << "1:Register\t 2:Login\nYour answer : " ; cin >> c ;
    
    if(c == 1)
    {
        string username , password;

        cout << "WHAT IS YOUR NAME? : " ;
        cin >> username;
        cout << "WHAT IS YOUR PASSWORD? : " ;
        cin >> password;

        ofstream dest;
        dest.open("records.txt",ios::app) ;
        dest << username << endl << password ;
        dest.close();

        main();
    }else if(c == 2){
        bool status = login() ;

        if(!status)
        {
            cout << "False Login" << endl ;
            system("PAUSE") ;
            return 0 ;
        }else{
            cout << "SUCCESS!!!" << endl ;
            system("PAUSE") ;
            return 1 ;
        }
    }
}
