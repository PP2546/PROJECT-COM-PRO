#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Login()
{
    int come;
    string name , password , n , pw;
    cout << "---------Login--------\n";
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
        system("CLS");
        cout << "Hello," << name << "\n";
        cin.get();
        CreatCategory(); //เมื่อ login เสร็จไปหน้าเลือกปรเภท
    }
    else
    {
        system("CLS");
        cout << "Invalid username or password!!\n";
        Login(); //เมื่อรหัสผิดให้เรียกใช้ตัวเองใหม่ในการ login  **ยังไม่แน่ใจว่าถ้าใส่ผิดไปเรื่อยๆมันจะเรียกใช้ตัวเองไปเรื่อยจนแลครึป่าวนะครับ**
        cin.get();      
    }
}


void Register()
{
    string name , password;
    //กรอกชื่อและรหัสเพื่อสมัครบัญชี
    cout << "--------Register-------\n";
    cout << "What is your username? :: ";
    cin >> name;
    
    cout << "What is your password? :: ";
    cin >> password;
    
    ofstream dest;
    dest.open("records.txt",ios::app);
    dest << name << " " << password << endl;
    
    cout << "DONE!!!\n";
    system("CLS");
    Login(); //ให้ login ได้ต่อเลย
  
}


int main()
{
    int choose;
    cout << "**********************************************\n";
    cout << "1.Login  \n" << "2.Register  \n" << "What is your answer : ";
    cin >> choose;
    system("CLS"); //clear console screen !!!

    if(choose == 1) Login();
    else if(choose == 2) Register();
    else{
        while(choose!=1 && choose !=2){
            cout << "SORRY,CHOOSE AGAIN BETWEEN 1 OR 2\n";
            cin >> choose;
            system("CLS");
            if(choose == 1) Login();
            else if(choose == 2) Register();
        }
    }
}
