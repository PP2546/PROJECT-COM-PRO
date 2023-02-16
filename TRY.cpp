#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
#include<string>


using namespace std;

//สร้างประเภทหนังสือ และเลือก
void CreatCategory(){
    int choice;
    int Cate[] = {0,1,2,3,4,5,6,7,8,9};
    string CateName[] = {"General","Philosophy-Psychology","Religious","Social Science","Linguistics","Science","Technology","Art",
    "Literature","Geography-History"};
    int Cate2[] = {10,20,30,40,50,60,70,80,90};

    cout << "----------------------------------\n";
    cout << "      Welcome to book store\n"; 
    cout << "  -Please choose your category-\n";
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
        system("CLS");
        cout << "Hello," << name << "\n";
        cin.get();
        CreatCategory(); //เมื่อ login เสร็จไปหน้าเลือกปรเภท
    }
    else
    {
        system("CLS");
        cout << "Invalid username or password!!\n";
        Login(); //เมื่อรหัสผิดให้เรียกใช้ตัวเองใหม่ในการ login  **ยังไม่แน่ใจว่าถ้าใส่ผิดไปเรื่อยๆมันจะเรียกใช้ตัวเองไปเรื่อยจนแลคป่าวนะ**
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
    system("CLS");
    Login(); //ให้ login ต่อเลย
  
}


int main()
{
    int choose;
    cout << "**********************************************\n";
    cout << "1.Login  \n" << "2.Register  \n" << "What is your answer : ";
    cin >> choose;
    system("CLS"); //clear console screen

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
