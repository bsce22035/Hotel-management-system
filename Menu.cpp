//
// Created by abc1 on 3/23/2023.
//

#include "Menu.h"

Menu::Menu() {
    int c;
    ifstream file("setup.txt");
    file >> Room::idsetter;
    file >> Employee::idsetter;
    file >> Customer::idsetter;
    file >> date;
    file.close();

    menu.fandd=&it;
    ci.cus = &cus;
    ci.room = &room;

    co.cus = &cus;
    co.roo = &room;
    menu.room = &room;
    menu.cus = &cus;

    menu.emp = &emp;
    comp.cus = &cus;
    comp.emp = &emp;

}


Menu *Menu::getinstance() {
    if (instance == nullptr) {
        instance = new Menu;
    }

    return instance;
}


void Menu::addgencomplain() {
    comp.addGeneralComplain();
}

void Menu::addempcomplain() {
    comp.addempComplain();
}

void Menu::checkin() {
    ci.rentroom(date);
}


void Menu::checkout() {
    co.checkout(date);
}


void Menu::changedayofstay() {
    char inp;
    int id;
    int cnic;

    cout << "\nValidate your authenticity by \n1:Name and cnic\n2:ID and cnic";

    cin >> inp;
    cout << "Enter your  custoper ID";
    string fname, lname;
    if (inp == '1') {
        cout << "enter first name ";
        cin >> fname;
        cout << "\nEnter last name ";
        cin >> lname;
        cout << "\nEnter cnic ";
        cin >> cnic;

    } else if (inp == '2') {
        cout << "\nID : ";
        cin >> id;
        cout << "\nEnter cnic ";
        cin >> cnic;

    } else {
        cout << "\nInvalidate Input";
        return;
    };
    bool test = 0;
    int testid = 0;
    ifstream cusf("currentcustomers.txt");
    ofstream temp("temp.txt");
    while (!cusf.eof()) {
        cusf >> cus;

        if (cus.id != testid) {
            testid = cus.id;
            if (inp == '1') {
                if (cus.fname == fname && cus.lname == lname && cus.getcnic() == cnic) {
                    int num;
                    cout << "\n1:Increase \n2:Decrease";
                    cin >> num;
                    if (num == 1) {
                        cout << "Increase ";
                        cin >> num;
                        cus.daysrented += num;
                    } else if (num == 2) {
                        cout << "\nDecrease";
                        cin >> num;
                        while (cus.daysrented - num <= 0) {
                            cout << "Unvalid enter again";
                            cin >> num;

                        }
                    } else {
                        cout << "\nUnvalid Input\n";
                        remove("temp.txt");
                        return;
                    }

                    temp << cus;
                    test = 1;

                } else temp << cus;
            } else if (inp == '2') {
                if (cus.id == id && cus.getcnic() == cnic) {
                    int num;
                    cout << "\n1:Increase \n2:Decrease";
                    cin >> num;
                    if (num == 1) {
                        cout << "Increase ";
                        cin >> num;
                    } else if (num == 2) {
                        cout << "\nDecrease";
                        cin >> num;
                        while (cus.daysrented - num <= 0) {
                            cout << "Unvalid enter again";
                            cin >> num;

                        }
                    } else {
                        cout << "\nUnvalid Input\n";
                        remove("temp.txt");
                        return;

                    }
                } else { temp << cus; }
            }
        }
    }
    temp.close();
    cusf.close();
    if (test) {
        cusf.open("temp.txt");
        temp.open("currentcustomers.txt");
        testid = 0;
        while (!cusf.eof()) {
            cusf >> cus;
            if (cus.id != testid) {
                testid = cus.id;
                temp << cus;


            }
        }
        cout << "\nSuccesfully done\n";

        cusf.close();
        temp.close();
    } else cout << "\nNO customer of  this ID/name/cnic found ";
    remove("temp.txt");

}


void Menu::Adminmenu() {
    bool test = true, test2 = true;
    string passcode, passcode2, password;
    ifstream filex("password.txt");
    filex >> passcode;
    filex >> passcode2;
    cout << "\n\nPlease enter the password ";
    cin >> password;


    if (passcode != password) {
        cout << "\nUnvalid Password ";
        cout << "\nPassword Hint " << passcode2 << endl;

        cout << "\n press any key to exit\n";
        cin >> passcode;
        return;

    }

    char inp;
    while (test) {
        cout
                << "\nWhat to do\n1:Manage Available Rooms\n2:Manage Occupied Rooms\n3:Manage Customers\n4:Manage Complains\n5:Past customer \n6:Manage Employess\n7:View Profit and bills\n8:Manage Resturent\nc:Change password\n e:exit to main menu";
        cin >> inp;
        if (inp == '1') {
            char inp2;
            test2 = 1;
            while (test2) {
                cout << "\nTo do\n1:Add room\n2:Get Room details\n3:See All available Rooms\ne:Exit to Admin menu";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.addroom();
                } else if (inp2 == '2') {
                    menu.avaroomdetails();
                } else if (inp2 == '3') {
                    menu.print_avilable_room();
                } else if (inp2 == 'e') { test2 = 0; } else cout << "\nInvalid Input\n";
            }
        } else if (inp == '2') {
            char inp2;
            test2 = 1;
            while (test2) {
                cout
                        << "\nTo do \n1:Empty Room \n2:Get data of a cutomer staying in a room\n3:Get Room data\n4:Print all occupied rooms\ne:Exit";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.emptyroom();

                } else if (inp2 == '2') {
                    menu.searchroomforcus();
                } else if (inp2 == '3') {
                    menu.occuroomdata();
                } else if (inp2 == '4') {
                    menu.seealloccurooms();
                } else if (inp2 == 'e') { test2 = 0; } else cout << "\nInvalid input\n";
            }
        } else if (inp == '5') {
            char inp2;
            test2 = 1;
            while (test2) {
                cout << "\nTo do \n1:See all past customers\n2:print past customer details\ne:Exit to Admin menu";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.printallpastcustomers();
                } else if (inp2 == '2') {
                    menu.searchpastcustomer();
                } else if (inp2 == 'e') {
                    test2 = 0;
                } else cout << "\nInvalid input";
            }

        } else if (inp == '7') {
            test2 = 1;
            char inp2;
            while (test2) {
                cout << "\nTo do \n1:View past bills\n2:View profit\ne:Exit to Admin menu";
                cin >> inp2;

                if (inp2 == '1') {
                    menu.displaypastbills();
                } else if (inp2 == '2') {
                    menu.displaytotalprofit();
                } else if (inp2 == 'e') {
                    test2 = 0;
                } else cout << "\nInvalid input\n";

            }
        } else if (inp == 'c') {
            menu.changepassword();
        } else if (inp == 'e') {
            test = 0;
        } else if (inp == '3') {

            test2 = 1;
            char inp2;
            while (test2) {
                cout << "\nTo do \n1:Get Current Customer data\n2:See all current customers\ne:Exit to Admin menu";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.searchcurrentcustomer();
                } else if (inp2 == '2') {
                    menu.printallcurrcus();
                } else if (inp2 == 'e') {
                    test2 = 0;
                } else cout << "\nInvalid input";
            }
        } else if (inp == '6') {
            test2 = 1;
            while (test2) {
                cout << "\nTo do \n1:Add emp\n2:Search an employee\n3:Display all employees\ne:Exit to Admin menu";
                char inp2;
                cin >> inp2;
                if (inp2 == '1') {
                    menu.addemp();
                } else if (inp2 == '2') {
                    menu.searchanemp();
                } else if (inp2 == '3') {
                    menu.printallemps();
                } else if (inp2 == 'e') {
                    test2 = 0;
                } else cout << "\nINvalid input\n";
            }
        } else if (inp == '4') {
            char inp2;
            bool test = 1;
            while (test) {
                cout
                        << "\nTo do\n1:1:Search Employee Complain\n2:See All general complains\n3:See all employee complains\ne:Exit to Admin menu";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.searchEmpComplain();
                } else if (inp2 == '2') {
                    menu.seeGeneralComplain();
                } else if (inp2 == '3') {
                    menu.seeEmpComplain();
                } else if (inp2 == 'e') {
                    test = 0;
                } else cout << "\nInvalid input\n";
            }
        } else if (inp == '8') {
            char inp2 = 'a';
            while (inp2 != 'e') {
                cout << "\nTo do\n1:Add New dish\n2:Remove Dish \n3: Display all dishes\ne:Exit";
                cin >> inp2;
                if (inp2 == '1') {
                    menu.addresturentitem();
                } else if (inp2 == '2') {
                    menu.removedish();
                } else if (inp2 == '3') {
                    menu.printalldishes();

                } else cout << "\nINVALID input\n";
            }
        }
    }
}

void Menu::getroomidtoknow() {
    char inp;
    bool test = 0;
    ifstream currentcus("currentcustomers.txt");
    cout << "\nKnow by \n1:name \n2:Id";
    cin >> inp;
    string fn, ln;
    int id;

    if (inp == '1') {
        cout << "enter first name ";
        cin >> fn;
        cout << "second name ";
        cin >> ln;

    } else if (inp == '2') {
        cout << "enter id";
        cin >> id;
    }

    int cn;
    int testid = 0;
    while (!currentcus.eof()) {
        currentcus >> cus;
        if (inp == '1') {
            if (testid != cus.id) {
                testid = cus.id;
                if (cus.lname == ln && cus.fname == fn) {
                    test = 1;
                    cus.printroomid();
                }
            }
        } else if (inp == '2') {
            if (id == cus.id) {
                test = 1;
                cus.printroomid();
            }
        }
    }
    if (!test) {
        cout << "\nNo Customer of this name/id\n";
    }}






void Menu::getfood() {
    itemsdoer<Item> itemfun;
    int testid = 0;
    bool test = 0;
    char inp;
    string fname, lname;
    int id,cnic;
    cout << "\nValidate your authenticity by\n1:Name\n2:Id";
    cin >> inp;
    if (inp == '1') {
        cout << "enter first name ";
        cin >> fname;
        cout << "enter last name ";
        cin >> lname;
        cout<<"\nEnter cnic ";
        cin>>cnic;
    } else if (inp == '2') {
        cout << "enter id ";
        cin >> id;
        cout<<"\nEnter cnic ";
        cin>>cnic;
    } else {
        cout << "\nInvalid Input\n ";
        return;
    }

    Customer carcus;
    ifstream file("currentcustomers.txt");
    while (!file.eof()) {
        file >> cus;
        if (testid != cus.id) {
            testid = cus.id;
            if (inp == '1') {
                if (fname == cus.fname && lname == cus.lname&&cus.getcnic()==cnic) {
                    test = 1;
                    carcus=cus;
                }
            } else if (inp == '2'&&cus.getcnic()==cnic) {
                if (id == cus.id) {
                    test = 1;
                    carcus=cus;

                }
            }
        }
    }
    file.close();
    testid=0;
    if(test) {
        cout << "\nTO Eat or drink ";
        itemfun.printalldishitems();
        string dishname("\nenter Dish/Drink to eat/drink ");
        string dname;
        cin >> dname;
        Item it = itemfun.getitem(dname);

        file.open("bills.txt");
        ofstream writer("temp.txt");
        Bill bill;

        while (!file.eof()) {
            file >> bill;
            if (testid != bill.cusid) {
                testid = bill.cusid;
                if (carcus.id != bill.cusid) {
                    writer << bill;
                } else {
                    bill.amount += it.getPrice();
                    writer << bill;
                }
            }

        }
        writer.close();
        file.close();
        writer.open("bills.txt");
        file.open("temp.txt");
        testid = 0;
        while (!file.eof()) {
            file >> bill;
            if (testid != bill.cusid) {
                testid = bill.cusid;
                writer << bill;
            }
        }

        cout << "\nEaten Dish amount of $" << it.getPrice() << endl;
    }
    if (test == 0) {
        cout << "\nNO Customer of this ID\n ";
           return;
    }



}


Menu::~Menu() {
    ofstream file("setup.txt");
    file << Room::idsetter << " " << Employee::idsetter << " " << Customer::idsetter << endl;
    file << date;
    file.close();
}