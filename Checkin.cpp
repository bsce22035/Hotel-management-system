//
// Created by abc1 on 3/19/2023.
//

#include "Checkin.h"

void Checkin::rentroom(Date &date) {
    bool test=0;
    ifstream avaroommv("availablerooms.txt");
    int idtest=0;
    while(!avaroommv.eof()){
        avaroommv>>*room;
        if(!room){
            cout<<"\nNo Room found \n";
            return;
        }
        if(idtest!=room->id){
            test=1;
            idtest=room->id;
            room->printroomdetails();
        }

    }
    avaroommv.close();

    ifstream avaroom("availablerooms.txt");
    ofstream temp("temp.txt");
    ofstream ocr("occupiedrooms.txt",ios::app);
    ofstream curcus("currentcustomers.txt",ios::app);


    if(test==0){
        cout<<"\nNo Room Available\n";
        return;
    }
    test= false;
    int id;
    int idw;
    cout<<"Dear Customer, please enter room id to BOOK ";
    cin>>id;

    while(!avaroom.eof()){
        avaroom>>*room;
        if(idtest!=room->id){
            idtest=room->id;
            if(room->id!=id){
                temp<<*room;

            }else {
                test=1;
                cus->inputdetails();
                room->daterented=date;
                room->customerid=cus->id;
                cus->rentedroomid=room->id;
                cus->checkindate=date;
                ocr<<*room;
                curcus<<*cus;
                ofstream billtext("bills.txt",ios::app);
                billtext<<cus->id<<" "<<0<<endl;
                billtext.close();

            }}}

    temp.close();
    ocr.close();
    curcus.close();
    avaroom.close();
    if(test==true){

        ifstream tempread("temp.txt");
        ofstream avawrite("availablerooms.txt");

        idtest=0;
        while(!tempread.eof()){
            tempread>>*room;
            if(idtest!=room->id){
                idtest=room->id;
                avawrite<<*room;

            }
        }

        tempread.close();
        avawrite.close();
    }else cout<<"\n|Cannot find room of this id|\n";


    remove("temp.txt");


}

