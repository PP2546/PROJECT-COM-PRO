#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

void CreatCategory(){
    int choice;
    int Cate[] = {0,1,2,3,4,5,6,7,8,9};
    string CateName[] = {"general","PSAD","sad","Social","langue","science","Techno","Art","Thau","TTher"};
    int Cate2[] = {10,20,30,40,50,60,70,80,90};

    cout << "----------------------------------\n";
    cout << "    Welcome to book store\n"; 
    cout << "----------------------------------\n";
    for(int i=0;i< 10;i++){ 
        cout << Cate[i] << "." << CateName[i] <<"\n";
    }
    cout << "----------------------------------\n";
    cout << "Please choose Category : ";
    cin >> choice;
    cout << "----------------------------------\n";
    for(int i=0;i<9;i++){
        cout << Cate[choice] << Cate2[i] << "\n";
    }
}

void Login()
{
    int come;
    string name , password , n , pw;
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
        cout << "Hello," << name << "!!!!!\n";
        cin.get();
        CreatCategory();
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
    cout << "**********************************************\n";
    cout << "1.Login  \n" << "2.Register  \n" << "What is your answer : ";
    cin >> choose;
    if(choose == 1) Login();
    else if(choose == 2) Register();
    else cout << "SORRY,CHOOSE AGAIN BETWEEN 1 OR 2\n";
}
