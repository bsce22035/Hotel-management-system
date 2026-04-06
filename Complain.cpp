

#include "Complain.h"



void Complain::addempComplain() {

    char wy;
    int ide,cn;
    string name,name2;
    bool test=false;
    cout<<"Validate your authenticity by\n1:Name and cnic\n2:ID and cnic";
    cin>>wy;
    if(wy=='1'){
        cout<<"\nEnter first name ";
        cin>>name;
        cout<<"\nEnter last name ";
        cin>>name2;
        cout<<"\nEnter cnic ";
        cin>>ide;

    }else if(wy=='2'){
        cout<<"enter id ";
        cin>>ide;
        cout<<"enter cnic";
        cin>>cn;

    }
    else cout<<"\nInvalid input \n";

    ifstream file("currentcustomers.txt");


    while(!file.eof()&&!test){
        file>>*cus;
        if(wy=='2'){
            if(ide==cus->id&&cn==cus->getcnic()){
                test=true;
            }}else if(wy=='1'){
            if(name==cus->fname&&name2==cus->lname&&ide==cus->cnic){
                test=1;
            }
        }
    }
    file.close();
if(!test){
    cout<<"\nNo Customer of this Name/cnic/id found";
    return;
}
    string nam1,nam2;
  cout<<"\nEnter the employee name you want to register complaint aganist ";
  cout<<"Enter first name ";
  cin>>nam1;
  cout<<"enter last name ";
  cin>>nam2;
  test=false;
  file.open("employees.txt");
  while(!file.eof()&&!test){
      file>>*emp;
      if(emp->fname==nam1&&emp->lname==nam2){
          test=1;
      }

  }
  file.close();
  if(test==false){
      cout<<"\nNo Employee of this name \n";
      return;
  }


    ofstream my_file;

    my_file.open("employeeComplain.txt");

    my_file << "customerfirstname: " << cus->fname << endl;

    my_file << "customerlastname: " << cus->lname << endl;
    my_file << "id: " << cus->cnic << endl;

    my_file << "employeefirstname: " << emp->fname << endl;
    my_file << "employeelastname: " << emp->lname << endl;

    my_file << "employeeID: " << emp->id << endl;
    my_file << " numberofcomplaints: " << emp->numofcomps << endl;
    my_file << "Complaindescription: " << endl;cout << "Enter complain about the employees : ";
    my_file<<"Employyeeid: "<<cus->id;
    string complaint;
    cin.ignore();
    getline(cin, complaint);
    int count =0;
    for(int i=0;i<complaint.length();i++){
        if(complaint[i]==' '){
            count++;}
    }
    if(count%2==0){
        complaint+=" complain";
    }
    my_file << complaint << endl;
    cout << "Complaint added successfully" << endl;
    my_file.close();
}

void Complain::addGeneralComplain() {

    char wy;
    int ide,cn;
    string name,name2;
    bool test=false;
    cout<<"Validate your authenticity by\n1:Name and cnic\n2:ID and cnic ";
    cin>>wy;
    if(wy=='1'){
        cout<<"\nEnter first name ";
        cin>>name;
        cout<<"\nEnter last name ";
        cin>>name2;
        cout<<"\nEnter cnic ";
        cin>>ide;

    }else if(wy=='2'){
        cout<<"enter id ";
        cin>>ide;
        cout<<"enter cnic ";
        cin>>cn;
    }else cout<<"\nInvalid input \n";

    ifstream file("currentcustomers.txt");


    while(!file.eof()&&!test){
        file>>*cus;
        if(wy=='2'){
        if(ide==cus->id&&cus->getcnic()==cn){
            test=true;
        }}else if(wy=='1'){
            if(name==cus->fname&&name2==cus->lname&&ide==cus->cnic){
                cout<<"\nfound ";
                test=1;
            }
        }
    }
    file.close();

    if(test){

    ofstream my_file("GeneralComplain.txt");

        my_file<<" customer_ID: "<<cus->id<<endl;
        my_file << "customer_firstname: " << cus->fname<<" "<< endl;
        my_file << "customer_lastname: " << cus->lname<<" "<< endl;

    cout << "Enter complain about hotel: ";
    string complaint;
    cin.ignore();
    getline(cin, complaint);
        int count =0;
        for(int i=0;i<complaint.length();i++){
            if(complaint[i]==' '){
                count++;}
        }
        if(count%2==0){
            complaint+=" complain";
        }
    my_file << complaint << endl;
    cout << "Complaint added successfully" << endl;
    my_file.close();
    }else cout<<"\nInvalid name/cnic/id\n";
}
