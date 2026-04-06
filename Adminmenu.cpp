
#include "Adminmenu.h"


void Adminmenu::addemp() {

    cout << "enter the employee info ";
    emp->input();
    ifstream filen("employees.txt");
    Employee test;
    while (!filen.eof()) {
        filen >> test;
        while (test.fname == emp->fname && test.lname == emp->lname) {
            cout << "\nEmployee of this name already exsist \nplease enter again\n      ";
            cout << "enter first name ";
            cin >> emp->fname;
            cout << "last name ";
            cin >> emp->lname;
        }
    }
    filen.close();
    Employee::idsetter++;
    emp->id = Employee::idsetter;
    ofstream file("employees.txt", ios::app);
    file << *emp;
    file.close();

}

void Adminmenu::printallemps() {
    int testid = 0;
    ifstream file("employees.txt");
    while (!file.eof()) {
        file >> *emp;
        if (emp->id != testid) {
            testid = emp->id;
            emp->display1();

        }
    }

    file.close();
}


void Adminmenu::searchanemp() {
    string fname;
    string lname;
    bool test = 0;
    cout << " enter the first name";
    cin >> fname;
    cout << "enter the last name ";
    cin >> lname;
    ifstream file("employees.txt");
    while (!file.eof()) {
        file >> *emp;
        if (emp->fname == fname && emp->lname == lname) {
            emp->display1();
            test = 1;
        }
    }

    if (!test) {
        cout << "\nNO Employee of this name\n";
    }
    file.close();
}

void Adminmenu::print_avilable_room() {
    bool xy = 1;
    ifstream inFile("availablerooms.txt", ios::in);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }


    int testid = 0;
    while (!inFile.eof()) {
        inFile >> *room;
        if (testid != room->id) {
            testid = room->id;
            xy = 0;
            room->printminordet();
        }
    }
    if (xy == 1) {
        cout << endl << "\nNo avilable Room \n";
    }

    inFile.close();
    return;
}


void Adminmenu::avaroomdetails() {
    ifstream inFile("availablerooms.txt", ios::in);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }


    int idw;
    cout << "\nEnter Id of the room ";
    cin >> idw;
    while (!inFile.eof()) {
        inFile >> *room;
        if (idw == room->id) {

            room->printroomdetails();
            return;
        }
    }
    cout << "\nNo Room of this ID is available\n";

}

void Adminmenu::occuroomdata() {
    ifstream inFile("occupiedrooms.txt", ios::in);

    if (!inFile) {
        cout << "Error: Could not open file." << endl;
        return;
    }


    int idw;
    cout << "\nEnter Id of the room ";
    cin >> idw;
    while (!inFile.eof()) {
        inFile >> *room;
        if (idw == room->id) {

            room->printroomdetails();
            return;
        }
    }
    cout << "\nNo Room of this ID is occupied\n";


}

void Adminmenu::seealloccurooms() {
    bool xy = 1;
    ifstream inFile("occupiedrooms.txt");


    try {

        if (!inFile) {
            cout << "Error: Could not open file." << endl;
            return;
        }


        int testid = 0;
        while (!inFile.eof()) {
            inFile >> *room;

            if (testid != room->id) {
                testid = room->id;
                xy = 0;
                room->printminordet();
            }
        }
        if (xy == 1) {
            cout << "\nNo Room ocuupuied\n";
        }
    } catch (string data) {
        cout << data;
    }
    inFile.close();
}


void Adminmenu::addroom() {
    ofstream file("availablerooms.txt", ios::app);
    cout << "\nEnter room capacity\n";
    cin >> room->capacity;
    cout << "enter room type";
    cin >> room->type;
    cout << "enter room day rate in $";
    cin >> room->dayrate;
    Room::idsetter++;
    room->id = Room::idsetter;
    file << *room;
    file.close();

    cout << "\nSuccesfully added room with ID " << room->id;
}


void Adminmenu::emptyroom() {
    int id;
    int idcar = 0, idcar2 = 0;
    bool test = 1;
    cout << "PLease enter the Room ID: ";
    cin >> id;
    ifstream file("occupiedrooms.txt");

    while (!file.eof() && test == 1) {
        file >> *room;
        if (room->id == id) {
            test = 0;
        }

    }
    file.close();
    if (test == 0) {


        ifstream file2("occupiedrooms.txt");
        ofstream avaroom("availablerooms.txt", ios::app);
        ofstream temp("temp.txt");
        if (!temp) {
            cout << "\nAn Error occured try again";
            file2.close();
            avaroom.close();
            temp.close();
            return;
        }

        idcar2 = room->id;
        while (!file2.eof()) {
            file2 >> *room;

            if (room->id != idcar2) {
                idcar2 = room->id;

                if (room->id != id) {
                    temp << *room << " ";

                } else if (room->id == id) {


                    avaroom << *room;
                    cout << "\nThe Customer finally exited.\n";
                }


            }
        }

        avaroom.close();
        file2.close();
        temp.close();
        remove("occupiedrooms.txt");
        ofstream writer("occupiedrooms.txt");
        ifstream tempreader("temp.txt");
        idcar = 0;
        idcar2 = 0;

        while (!tempreader.eof()) {
            tempreader >> *room;
            if (room->id != idcar2) {

                idcar2 = room->id;
                writer << *room << " ";


            }
        }
        tempreader.close();
        writer.close();
        file.open("currentcustomers.txt");
        ofstream pastcus("pastcustomers.txt", ios::app);
        temp.open("temp.txt");
        idcar = 0;
        while (!file.eof()) {
            file >> *cus;
            if (idcar != cus->id) {
                idcar = cus->id;
                if (cus->rentedroomid != id) {
                    temp << *cus << " ";
                } else {
                    pastcus << *cus << " ";

                }
            }
        }
        idcar = 0;
        file.close();
        pastcus.close();
        temp.close();
        pastcus.open("currentcustomers.txt");
        file.open("temp.txt");
        while (!file.eof()) {
            file >> *cus;
            if (idcar != cus->id) {
                idcar = cus->id;
                pastcus << *cus << " ";
            }
        }
        file.close();
        pastcus.close();


    } else {
        cout << "\nNo Room of this ID\n";
    }

    remove("temp.txt");

}


void Adminmenu::searchroomforcus() {
    int id, idcar;
    cout << "enter id of the room ";
    cin >> id;
    bool test = 0;

    ifstream file("occupiedrooms.txt");

    while (!file.eof()) {
        file >> *room;

        if (room->id == id) {

            test = 1;
            idcar = room->customerid;

        }

    }
    file.close();

    if (test == false) {
        cout << "\nThis room not exsist or is not occupied \n";
    } else {
        ifstream file2("currentcustomers.txt");
        while (!file2.eof()) {
            file2 >> *cus;
            cout << *cus << endl;
            if (cus->id == idcar) {
                cus->printdetails();
                test = 1;
            }


        }
        file2.close();

    }
}


void Adminmenu::printallpastcustomers() {

    ifstream file("pastcustomers.txt");
    if (!file) {
        cout << "\nError! opening the File ";
        return;
    }
    bool test = 0;
    int testid = 0;
    int ca;
    while (!file.eof()) {
        file >> *cus;
        file >> ca;
        if (testid != cus->id) {
            testid = cus->id;
            cus->minordetails();
            test = 1;
        }

    }
    if (test == false) {
        cout << "\nNo  past customer found\n";
    }
}


void Adminmenu::searchcurrentcustomer() {

    int testid = 0;
    bool test = 0;
    char inp;
    string fname, lname;
    int id;
    cout << "\nGet Data by\n1:Name\n2:Id";
    cin >> inp;
    if (inp == '1') {
        cout << "enter first name ";
        cin >> fname;
        cout << "enter last name ";
        cin >> lname;
    } else if (inp == '2') {
        cout << "enter id ";
        cin >> id;
    } else {
        cout << "\nInvalid input\n";
        return;
    }
    ifstream file("currentcustomers.txt");
    while (!file.eof()) {
        file >> *cus;
        if (testid != cus->id) {
            testid = cus->id;
            if (inp == '1') {
                if (fname == cus->fname && lname == cus->lname) {
                    test = 1;
                    cout << "\nStaying at Room " << cus->rentedroomid;
                    cus->printdetails();

                }
            } else if (inp == '2') {
                if (id == cus->id) {
                    test = 1;
                    cout << "\nStaying at Room " << cus->rentedroomid;
                    cus->printdetails();
                }
            }
        }
    }
    if (test == 0) {
        cout << "\nNO Customer of this ID/Name\n ";
    }
    file.close();
}


void Adminmenu::printallcurrcus() {
    ifstream file("currentcustomers.txt");
    if (!file) {
        cout << "\nAn error occurred ";
        return;
    }

    int testid = 0;

    while (!file.eof()) {

        file >> *cus;
        if (testid != cus->id) {
            testid = cus->id;
            cus->minordetails();
        }
    }

}

void Adminmenu::changepassword() {
    string passcode;
    string password;
    ifstream file("password.txt");
    file >> passcode;
    cout << "\nplease enter the  current password ";
    cin >> password;
    while (passcode != password) {

        cout << "\nInvalid enter password again or press e to exit";
        cin >> password;
        if (password == "e") {
            return;
        }

    }
    file.close();
    cout << "please enter the new password ";
    cin >> passcode;

    while (passcode.length() < 5) {
        cout << "\nTo short enter again";
        cin >> passcode;
    }
    cout << "enter again ";
    cin >> password;


    if (passcode != password) {
        cout << "\nPassword do not match  enter again or press e to exit ";
        cin >> password;
            if(password=="e"){

                return;
            }

    }


    cout << "\nenter password hint or press s to set " << password[0] << password[1] ;
    cin >> passcode;
    if (passcode == "s") {
        passcode = "";
        passcode += password[0];

        passcode += password[1];

    }


    ofstream filewrite("password.txt");
    filewrite << password << " " << passcode;
    filewrite.close();
    cout << "\nPassword changed succesfully \n";
}


void Adminmenu::searchpastcustomer() {

    int testid = 0;
    bool test = 0;
    char inp;
    string fname, lname;
    int id;
    cout << "\nGet Data by\n1:Name\n2:Id";
    cin >> inp;
    if (inp == '1') {
        cout << "enter first name ";
        cin >> fname;
        cout << "enter last name ";
        cin >> lname;
    } else if (inp == '2') {
        cout << "enter id ";
        cin >> id;
    } else {
        cout << "\nInvalid Input\n ";
        return;
    }

    ifstream file("pastcustomers.txt");
    while (!file.eof()) {
        file >> *cus;
        if (testid != cus->id) {
            testid = cus->id;
            if (inp == '1') {
                if (fname == cus->fname && lname == cus->lname) {
                    test = 1;
                    cout << "\nStaying at Room " << cus->rentedroomid;
                    cus->printdetails();

                }
            } else if (inp == '2') {
                if (id == cus->id) {
                    test = 1;
                    cout << "\nStaying at Room " << cus->rentedroomid;
                    cus->printdetails();
                }
            }
        }
    }
    if (test == 0) {
        cout << "\nNO Customer of this ID\n ";
    }
    file.close();

}


void Adminmenu::seeGeneralComplain() {
    string text;
    ifstream readFile("GeneralComplain.txt");
    while (!readFile.eof()) {
        getline(readFile, text);

        cout << text << endl;
    }
    readFile.close();

}

void Adminmenu::seeEmpComplain() {


    string text;
    ifstream readFile("employeeComplain.txt");
    while (!readFile.eof()) {
        getline(readFile, text);
        cout << text << endl;
    }
    readFile.close();
}

void Adminmenu::searchEmpComplain() {
    string employeeName;
    string complaint;
    bool found = false;
    ifstream inFile("employeeComplain.txt");
    string idx;
    cout << "\nEnter The employee ID ";
    cin >> idx;


    while (inFile >> employeeName >> complaint) {
        if (employeeName == "Employyeeid:" && complaint == idx) {
            cin.ignore();
            getline(cin, complaint);
            cout << complaint << endl;
            found = true;
        }
    }
    inFile.close();

    if (!found) {
        cout << "No complaints found for " << idx << endl;
    }

}

void Adminmenu::displaypastbills() {
    ifstream file("bills.txt");
    int testid = 0;
    while (!file.eof()) {

        file >> bill;
        if (bill.cusid != testid) {
            testid = bill.cusid;
            bill.print();
        }
    }

    file.close();

}

void Adminmenu::displaytotalprofit() {
    ifstream file("bills.txt");
    double profit = 0;
    int testid = 0;
    while (!file.eof()) {
        file >> bill;
        if (testid != bill.cusid) {
            testid = bill.cusid;
            profit += bill.amount;
        }
    }
    file.close();
    cout << "\nThe Total Profit is " << profit << endl;
}



void Adminmenu::addresturentitem(){
  char inp;
    cout<<"\nAdd new\n1:Dish\n2:Drink";
    cin>>inp;
    Item *it;
    if(inp=='1'){
        it=new  DishItem;

    }else if(inp=='2'){
        it=new DrinkItem;
    }else {
        cout<<"\nInvalid Input \n";
        return;
    }

        it->inputdetails();

    bool xy=fandd->additem(*it);
   if(xy) {
       fandd->savetolist();

       cout << "\nAdded Succesfully\n";
   }else cout<<"\nItem of this name already exsists ";

delete it;
}


void Adminmenu::removedish() {
    string dishname;
    cout<<"\nEntere name of the diah ";
    cin>>dishname;
    fandd->removeitem(dishname);
    fandd->savetolist();
}

void Adminmenu::printalldishes(){
    fandd->printalldishitems();
}