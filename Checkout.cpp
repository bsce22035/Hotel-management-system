//
// Created by abc1 on 3/19/2023.
//

#include "Checkout.h"




    void Checkout::checkout(Date &date){
        int id;
         int cnic;
        char inp;
        double am=1.0;
        int idcar=0;
        bool test=0;
        string fn,ln;

        cout<<"\nDear  Customer,please  validate by \n1:Name and cnic\n2:ID and cnic";
       cin>>inp;
     if(inp=='1'){
         cout<<"\nDear Customer, please enter following details";
       cout<<"\nenter first name ";
         cin>>fn;
        cout<<"enter last name ";
         cin>>ln;
     cout<<"enter cnic ";
     cin>>cnic;
     }
     else if(inp=='2'){
           cout<<"Dear Customer please enter your ID : ";
           cin>>id;
           cout<<"enter cnic";
           cin>>cnic;

       }else {cout<<"\nInvalid input\n ";return;}

     Customer car;


        ifstream curcus("currentcustomers.txt");
        ofstream pastcus("pastcustomers.txt",ios::app);
        ofstream temp("temp.txt");
        idcar=0;
        while(!curcus.eof()){
            curcus>>*cus;

            if(idcar!=cus->id&&cus->id!=0){
                idcar=cus->id;
             if(cus->getcnic()!=cnic){
                 temp<<*cus<<" ";
             }else {
                 pastcus<<*cus<<" ";
                 test=1;
          car=*cus;
             }


            }
        cus->setrub();
        }

        pastcus.close();
        temp.close();
        curcus.close();


        if(test){
            idcar=0;
           ifstream occr("occupiedrooms.txt");
            ofstream avar("availablerooms.txt",ios::app);
             temp.open("temp2.txt");
            while(!occr.eof()){
                occr>>*roo;
                if(idcar!=roo->id&&roo->id!=0){
                    idcar=roo->id;
                    if(roo->id!=car.rentedroomid){
                        temp<<*roo<<" ";

                    }else {



                      int testid=0;


                        ifstream file("bills.txt");
                        ofstream writer("tempf.txt");
                        Bill bill;

                        while (!file.eof()) {
                            file >> bill;
                            if (testid != bill.cusid) {
                                testid=bill.cusid;
                                if (car.id != bill.cusid) {
                                    writer << bill;
                                } else {
                                   double am=roo->dayrate;
                                   am*=car.daysrented;
                                    bill.amount+=am;
                                    cout<<"\n____________________________________________\n";
                                    cout<<"\nCustomer has a total bill of $"<<bill.amount<<endl;
                                    cout<<"\nRoom charges: $"<<am;
                                    cout<<"\nFood charges: $"<<bill.amount-am<<endl;
                                    cout<<"\n____________________________________________\n";

                                    writer<<bill;
                                }
                            }

                        }
                        writer.close();
                        file.close();
                        writer.open("bills.txt");
                        file.open("tempf.txt");
                        testid=0;
                        while (!file.eof()) {
                            file >> bill;
                            if (testid != bill.cusid) {
                                testid=bill.cusid;
                                writer << bill;
                            }
                        }


























                        avar<<*roo<<" ";



                    }}
            roo->setrub();
            }

            temp.close();
            pastcus.close();
            occr.close();

            ofstream writer("occupiedrooms.txt");
            ifstream tempreader("temp2.txt");
            idcar=0;

            while(!tempreader.eof()){
                tempreader>>*roo;
                if(roo->id!=idcar&&roo->id!=0){

                    idcar=roo->id;
                    writer<<*roo<<" ";



                }
            roo->setrub();
            }
            tempreader.close();
            writer.close();
            pastcus.open("currentcustomers.txt");
           ifstream file("temp.txt");
            while(!file.eof()){
                file>>*cus;
                  if(idcar!=cus->id&&cus->id!=0){
                      idcar=cus->id;
                      pastcus<<*cus<<" ";
                  }
                  cus->setrub();
            }
            file.close();
            pastcus.close();

            cout<<"\nThe Customer finally exited\n";
        }else cout<<"\nUnvalid name/id/cnic\n";

//        idcar=0;
//        file.close();
//        pastcus.close();
//        temp.close();

//
//        if(test==0){


//
//
//            ifstream file2("occupiedrooms.txt");
//            ofstream avaroom("availablerooms.txt",ios::app);
//            ofstream temp("temp.txt");
//            if(!temp){
//                cout<<"\nAn Error occured try again";
//                file2.close();
//                avaroom.close();
//                temp.close();
//                return;
//            }
//
//            idcar2=roo->id;
//            while(!file2.eof()){
//                file2>>*roo;
//
//                if(roo->id!=idcar2){
//                    idcar2=roo->id;
//
//                    if(roo->customerid!=id){
//                        temp<<*roo<<" ";
//
//                    }else if(roo->customerid==id){
//
//
//                        avaroom<<*roo;
//                        cout<<"\nThe Customer finally exited.\n";
//                    }
//
//
//                }}
//
//            avaroom.close();
//            file2.close();
//            temp.close();
//            remove("occupiedrooms.txt");
//


//        }else {
//            cout<<"\nThis id is not staying in the hotel\n";
//        }

        remove("temp.txt");
        remove("temp2.txt");
        remove("tempf.txt");

    }


