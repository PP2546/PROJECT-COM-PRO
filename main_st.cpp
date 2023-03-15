#include "FunctionAll.h"

// Function for book store record
void bookstorerecord()
{
	int choice_start;
    int choice_control;
    int choice_staff;
    int order_add;
    int bookStock;
	bookstore b;

	while (1) {

		b.Start();
		cout << "\t\nWhat is your answer : ";
		cin >> choice_start;
		switch (choice_start){

		case 0:
				b.staffLogin();
                b.Control_panelForStaff();
                cout << "\nWhat is your answer : ";
		        cin >> choice_staff;
                if (choice_staff == 1) {
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
                }
                else if (choice_staff == 2) {
                    b.Show_book();
                    cout << "Which book you want to add? : ";
                    cin >> order_add;
                    cout << "How many books do you add?  : ";
                    cin >> bookStock;
                    b.Edit_dataForStaff(order_add,bookStock); 
                    exit(0);
                
                }
                else if(choice_staff == 3) exit(0);
                else {
                    cout << "\nxxxxx INVALID CHOICE xxxxx \n";
                    exit(0);
                }

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
                    cout << "\nxxxxx INVALID CHOICE xxxxx \n";
                    exit(0);
                    break;
                }
               
            }
            break;

		case 2:
			b.Register();
            break;

        case 3:
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
                    break;             
                default:
                    cout << "\nxxxxx INVALID CHOICE xxxxx \n";
                    exit(0);
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

