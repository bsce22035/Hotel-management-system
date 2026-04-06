#include <iostream>
#include "Menu.h"

using namespace std;

#include "Room.h"
#include "Customer.h"
#include "employee.h"
#include "Adminmenu.h"
#include "Checkin.h"
#include "Checkout.h"

Menu *Menu::instance = 0;
int Room::idsetter = 0;
int Customer::idsetter = 0;
int Employee::idsetter = 0;

int main() {
    Menu *program = Menu::getinstance();
    char inp;
    while (1) {
        cout
                << "\nTo do\n1:Check in \n2:Check out\n3:Complain\n4:Get room ID\n5:Increase or decrease your days of stay\n6:Visit Resturent\na:Admin menu\ne:Exit";
        cin >> inp;

        if (inp == '1') {
            program->checkin();
        } else if (inp == '2') {
            program->checkout();
        } else if (inp == '3') {
            char inp2;
            cout
                    << "\nWhat type of complain to add\n1:add complain against Employee\n2:Add a complain against hotel facilty";
            cin >> inp2;
            if (inp2 == '1') {
                program->addempcomplain();
            } else if (inp2 == '2') {
                program->addgencomplain();
            } else cout << "\nInvalid input\n";

        } else if (inp == '4') {
            program->getroomidtoknow();
        } else if (inp == '5') {
            program->changedayofstay();
        } else if (inp == 'a') {
            program->Adminmenu();
        } else if(inp=='6'){
            program->getfood();

        }else if (inp == 'e') {
            cout << "\n|||| Good Bye ||||\n ";
            delete program;
            return 0;
        } else cout << "\nInvalid Input\n";

    }
}