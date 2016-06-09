//#include "FancyArray.cpp"
#include "FancySet.cpp"
#include "FancyStack.cpp"
#include "FancyBalancer.h"
#include "FancyExpression.h"
#include "FancyQueueCircular.cpp"
#include <vector>
#include <iomanip>
#include "FancyLinkList.cpp"

#include "superstore.h"
#include "item.h"
#include "saleperson.h"
#include "customer.h"

#define TYPE int



void main_menu() {
    cout << "1: Customer Arrived " << endl ;
    cout << "2: Salary Report " << endl ;
    cout << "3: Customers List " << endl ;
    cout << "4: Items List " << endl ;
    cout << "5: Sale Persons List " << endl ;
    cout << "0: Exit " << endl ;
}

void customer_menu () {
    cout << "1: Find Item " << endl ;
    cout << "2: Checkout " << endl ;
    cout << "3: Cancel order" << endl ;
}

void item_menu () {
    cout << "1: Add To Cart " << endl ;
    cout << "2: Cancel " << endl ;
}

bool confirm(int input, int should_be) {
    return input == should_be;
}

using namespace std;
int main()
{
    int opt;

    cout << " *********************** " << endl ;
    cout << " Welome to Super Store !" << endl ;
    cout << " *********************** " << endl ;
    cout << " *********************** " << endl ;

    SuperStore store;
    SalePerson sp0, sp1, sp2;
    sp0.Setname("Ahmed");
    sp1.Setname("ALi");
    sp2.Setname("Naeem");


    Item i0, i1, i2;
    i0.Setname("Apple");
    i1.Setname("Mango");
    i2.Setname("Orange");

    store.Getitems().insertAtBegin(i0);
    store.Getitems().insertAtBegin(i1);
    store.Getitems().insertAtBegin(i2);

    store.GetSalePersons().insertAtBegin(sp0);
    store.GetSalePersons().insertAtBegin(sp1);
    store.GetSalePersons().insertAtBegin(sp2);

    do {
        main_menu();
        cout << ">> ";
        cin  >> opt;

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input caught, try again." << endl ;
            cout << ">> ";
            cin  >> opt;
        }

        switch(opt) {
            case 1:
                {
                        Customer c;
                        string name, contact_number;
                        cout << "Enter Customer's name: " << endl ;
                        cin >> name;
                        cout << "Enter Customer's Contact Number: " << endl ;
                        cin >> contact_number;
                        c.Setname(name);
                        c.Setcontact(contact_number);
                        int SALE_PERSON_ID = 0; // This will be based on some policy;
                        store.Getcustomers().add(c);
                        store.GetSalePersons().getByIndex(SALE_PERSON_ID).Getcustomers().add(c);

                        cout << "** ** ** ** ** ** " << endl ;
                        cout << "Thank you ! Your account has bee created." << endl;
                        cout << " You will be guided by our saleperson " << endl;

                        cout << " Mr." << store.GetSalePersons().getByIndex(SALE_PERSON_ID).Getname();
                        cout << endl;
                        cout << endl;
                        cout << "** ** ** ** ** ** " << endl ;

                        cout << "Proceed and select an option from the following screen : " << endl;

                    // Enter Customer Detials

                    int inner_opt = 0;
                    do {

                        cin.clear();
                        cin.ignore(1000,'\n');
                        customer_menu();
                        cin >> inner_opt;

                        while(cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Invalid input caught, try again." << endl ;
                            cout << ">> ";
                            cin  >> opt;
                        }

                        switch (inner_opt) {
                        case 1:
                            {
                                string temp;
                                do {
                                cout << "Enter product name or type to get a list of products : " << endl;
                                cout << "(if you want to leave searching product menu press 0) : " << endl;
                                cin >> temp;
                                if(temp == "help") {

                                    cout << endl ;
                                    cout << "** ** ** ** ** ** " << endl ;
                                    cout << "Products List :" << endl ;

                                    for(int i = 0 ; i< store.Getitems().length(); i++){
                                        cout << i+1 << ".  " ;
                                        cout << store.Getitems().getByIndex(i).Getname();
                                        cout << endl;
                                    }
                                } else if(temp == "0") {

                                } else {
                                    Item i;
                                    i.Setname(temp);
                                    int index = store.Getitems().findByValue(i);

                                    if(index > -1) {
                                        cout << endl ;
                                        cout << "** ** ** ** ** ** " << endl ;
                                        cout << "You have selected :" << endl ;
                                        cout << store.Getitems().getByIndex(index).Getname();
                                        cout << endl;

                                        //item_menu();

                                    } else {
                                        cout << endl ;
                                        cout << "** ** ** ** ** ** " << endl ;
                                        cout << "Item not found !" << endl ;
                                        cout << endl;

                                    }
                                }

                                } while(temp != "0");


                            }
                        break;
                        case 2:
                            {
                                        cout << endl ;
                                        cout << "** ** ** ** ** ** " << endl ;
                                        cout << "Nice to have you on our store." << endl ;
                                        cout << "Your invoice has been generated. No: 001" << endl ;
                                        cout << endl;

                                        inner_opt = 3;
                           }
                        break;
                        case 3:
                            {
                                        cout << endl ;
                                        cout << "** ** ** ** ** ** " << endl ;
                                        cout << "Order has been cancelled on your request." << endl ;
                                        cout << "Good bye." << endl ;
                                        cout << endl;
                                        inner_opt = 3;

                            }
                        break;

                        default:
                        break;
                        }
                    } while( !(inner_opt ==  3));
                }
            break;

            case 2:
                {
                   cout << endl ;
                    cout << "** ** ** ** ** ** ** " << endl;
                    cout << " Sale Persons Listing : " << endl;
                    cout << "** ** ** ** ** ** ** " << endl;

                    cout << setw(10)  << left <<  "Serial  " ;
                    cout << setw(25) << "Name of sales person" ;
                    cout << setw(25) << "Customer Entertained | " ;
                    cout << setw(25) << "Salery | "  << endl;

                    cout << "__________________________________________________________" <<endl ;
                    for( int i = 0 ; i < store.GetSalePersons().length(); i++) {


                        cout << setw(10) ;
                        cout << left << i+1  ;
                        cout << setw(25)  ;
                        cout << left << store.GetSalePersons().getByIndex(i).Getname();
                        cout << setw(25)  ;
                        cout << store.GetSalePersons().getByIndex(i).Getcustomers().length();
                        double total = 0;
                        for(int j = 0 ; j < store.GetSalePersons().getByIndex(i).Getcustomers().length(); j++) {
                            total += 5;
                        }
                        cout << setw(25)  ;
                        cout << total << "$";
                        cout << endl ;
                    }
                    cout << "** ** ** ** ** ** ** " << endl;

                }
            break;

            case 3:
                {
                        cout << endl ;
                        cout << "** ** ** ** ** ** " << endl ;
                        cout << "Customers List :" << endl ;

                        cout << setw(20) << left << " Customer Name " << setw(20) << " Contact " << endl;
                        cout << "__________________________________________________________" <<endl ;

                        for(int i = 0 ; i< store.Getcustomers().length(); i++){
                            cout << setw(20) << left << store.Getcustomers().getByIndex(i).Getname()
                                 << setw(20) << left << store.Getcustomers().getByIndex(i).Getcontact()  << endl;
                        }
                        cout << "** ** ** ** ** ** " << endl ;


                }
            break;

            case 4:
                {

                    cout << endl ;
                    cout << "** ** ** ** ** ** " << endl ;
                    cout << "Products List :" << endl ;

                    for(int i = 0 ; i< store.Getitems().length(); i++){
                        cout << i+1 << ".  " ;
                        cout << store.Getitems().getByIndex(i).Getname();
                        cout << endl;
                    }
                }
            break;

            case 5:
                {
                    cout << endl ;
                    cout << "** ** ** ** ** ** ** " << endl;
                    cout << " Sale Persons Listing : " << endl;
                    cout << "** ** ** ** ** ** ** " << endl;

                    cout << setw(15) << "Name of Sales Person | " << endl ;
                    cout << "___________________________________________________" <<endl ;
                    for( int i = 0 ; i < store.GetSalePersons().length(); i++) {
                         //cout << i << endl ;
                         cout << i+1 << "  " ;
                         cout << store.GetSalePersons().getByIndex(i).Getname();
                         cout << endl ;
                    }
                    cout << "** ** ** ** ** ** ** " << endl;
                }
            break;

            default:
            break;
        }

    } while(opt != 0);

    cout << endl ;
    cout << "Thanks for stopping by !" << endl;
    cout << "Good Bye " << endl ;

    return 0;
}
