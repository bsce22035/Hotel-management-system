//
// Created by abc1 on 3/23/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_BILLS_H
#define HOTEL_MANAGEMENTSYSTEM_BILLS_H
#include "Customer.h"
#include <iostream>
using namespace std;
class Bill {
public:

    int cusid;
 double amount;

friend  ostream& operator<<(ostream& out,Bill& bi){
    out<<bi.cusid<<" "<<bi.amount<<endl;
    return out;
}
friend  istream& operator>>(istream& inp,Bill& bi){

    inp>>bi.cusid>>bi.amount;
    return inp;
}

void print(){
    cout<<"\n__________________________\n";
cout<<" ID:"<<cusid<<endl;
cout<<"Amount: "<<amount;
    cout<<"\n__________________________\n";

}
//void displaypastbills();
//type calculatetotalprofit();



};

//template <class  type>
//void Bills<type>::displaypastbills(){
//    type profit=0;
//    bool test=0;
//    ifstream file("pastcustomers.txt");
//    int testid=0;
//    while(!file.eof()){
//        file>>*cus;
//        file>>profit;
//
//        if(cus->id!=testid){
//            testid=cus->id;
//            cout<<endl<<"Customer ID: "<<cus->id<<endl<<"Name: "<<cus->fname<<" "<<cus->lname;
//            test=1;
//            cout<<"\nAmount paid $"<<profit;
//            cout<<"\n\n";
//        }
//    }
//    if(test== false){
//
//        cout<<"\nNO Past bills\n";
//    }
//    file.close();
//}
//
//template <class  type>
//type Bills<type>::calculatetotalprofit(){
//    totalprofit=0;
//    type profit=0;
//    int testid=0;
//    ifstream file("pastcustomers.txt");
//
//    while(!file.eof()){
//        file>>*cus;
//        file>>profit;
//        if(cus->id!=testid){
//            totalprofit+=profit;
//        }
//    }
//    file.close();
//    return  totalprofit;
//}


#endif //HOTEL_MANAGEMENTSYSTEM_BILLS_H
