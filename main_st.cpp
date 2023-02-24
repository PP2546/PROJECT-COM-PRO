#include "FunctionAll.h"

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
