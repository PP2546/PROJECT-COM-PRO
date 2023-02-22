#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>


using namespace std;

class book //วิะีการใช้ class ตามด้วยชื่อคลาสที่เรากำหนด 
{
private: // ไม่สามารถเข้าถึงได้จากภายนอก class
        char *author;
        char *title;
        char *publisher;
        float *price;
        int *stock;
public: // เข้าได้ทุกส่วนโปรแกรม เป็นตัวสาธารณะ
        book() 
        {
            author = new char[20];
            title = new char[20];
            publisher = new char[20];
            price = new float;
            stock = new int;
        }

        void data();
        void editdata();
        void showdata();
        int search(char[],char[]);
        void bookout();
};

void book::data() // ข้อมูลตั้งต้น
{
    cin.ignore();
    cout << "\nEnter Author name : ";
    cin.getline(author,20);
    cout << "\nEnter Title name : ";
    cin.getline(title,20);
    cout << "\nEnter Publisher name : ";
    cin.getline(publisher,20);
    cout << "\nEnter price : ";
    cin >> *price;
    cout << "\nEnter stock : ";
    cin >> *stock;
}

void book::editdata() // ข้อมูลที่เปลี่ยนไป
{
    cout << "\nEnter Author name : ";
    cin.getline(author,20);
    cout << "\nEnter Title name : ";
    cin.getline(title,20);
    cout << "\nEnter Publisher name : ";
    cin.getline(publisher,20);
    cout << "\nEnter price : ";
    cin >> *price;
    cout << "\nEnter stock : ";
    cin >> *stock;
}

void book::showdata() // การแสดงข้อมูล
{
    cout << "\nEnter Author name : " << author;
    cout << "\nEnter Title name : " << title;
    cout << "\nEnter Publisher name : " << publisher;
    cout << "\nEnter price : " << *price;
    cout << "\nEnter stock : " << *stock;
}

int book::search(char a[], char b[])
{   
    if(strcmp(a,author)==0 && strcmp(b,title)==0) return 1;// เป็นฟังก์ชันที่ใช้ในการเปรียบเทียบข้อความ
    else return 0;
}

void book::bookout()
{
    int num;
    cout << "\nEnter number of books to buy : ";
    cin >> num; // จำนวนสินค้าที่จะซื้อ

    if(num <= *stock) // สินค้ายังเหลือ/พอดี
    {
        *stock -= num; // ของในคลังที่ถูกออกไปขาย
        cout << "SUCCESS!!!";
        cout << "cost : " << (*price)*num; // ราคาสินค้า
    } 
    else
    {
        cout << "Sorry , Sold out"; 
    }
}



int main()
{
    book bb;
    book *B[20];
    int i=0;
    int c;
    int t;
    int ans;
    char titlebuy[20];
    char authorbuy[20];

    while(true)
    {   
        cout << "\n       WECLOME!!!!!";
        cout << "\n*************************";
        cout << "\nMENU";
        cout << "\n1.Entry of new Book\n";
        cout << "\n2.Buy Book\n";
        cout << "\n3.Search for Book";
        cout << "\n4.Edit details of Book";
        cout << "\n5.Exit";
        cout << "\nWhat is your choice : ";
        cin >> ans;

        if(ans == 1) // หนังสือใหม่เพิ่มมา
        {
            B[i] = new book;
            B[i]->data();
            i++;
        }
        else if(ans == 2) // ซื้อหนังสือ-->ลดลง
        {
            cin.ignore();
            cout << "\nEnter Title of Book : ";
            cin.getline(titlebuy,20);
            cout << "\nEnter Author of Book : ";
            cin.getline(authorbuy,20);
            for(t=0 ; t<1 ; t++)
            {
                if(B[t]->search(titlebuy,authorbuy))
                {
                    B[t]->bookout();
                    break;
                }
            }
            if(t==1) cout << "\nThis book is not in stock";
        }
        else if(ans == 3) // หาหนังสือ
        {
            cin.ignore();
            cout << "\nEnter Title of Book : ";
            cin.getline(titlebuy,20);
            cout << "\nEnter Author of Book : ";
            cin.getline(authorbuy,20);

            for(t=0 ; t<1 ; t++)
            {
                if(B[t]->search(titlebuy,authorbuy))
                {
                    B[t]->showdata(); // แสดงข้อมูล
                    break;
                }
            }
            if(t==i) cout << "\nThis book is not in stock";
        }
        else if(ans == 4) // แก้ไขข้อมูล
        {
            cin.ignore();
            cout << "\nEnter Title of Book : ";
            cin.getline(titlebuy,20);
            cout << "\nEnter Author of Book : ";
            cin.getline(authorbuy,20);

            for(t=0 ; t<1 ; t++)
            {
                if(B[t]->search(titlebuy,authorbuy))
                {
                    B[t]->editdata();
                    break;
                }
            }
            if(t==i) cout << "\nThis book is not in stock";
        }
        else if(ans == 5) // ออก
        {
            exit(0);
        }
        cout << "Thank you for using!!";
    }

}
