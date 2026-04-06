//
// Created by abc1 on 3/19/2023.
//

#include "Room.h"

void Room::printminordet(){
    cout<<"\n___________________________________________________";
    cout<<"\nID:"<<id;
    cout<<"\nCatrgory: "<<type<<endl;
    cout<<"________________________________________________\n";
}



void Room::printroomdetails(){          //for displaying to user
cout<<"\n__________________________________________\n";
    cout<<"\nID: "<<id;
    cout<<"\ncapacity: "<<capacity;
    cout<<"\nCategory: "<<type;
    cout<<"\nDay rate in $"<<dayrate;
    cout<<"\n__________________________________________\n";

}



Room::~Room(){

    filecar car;
    Date datecar;
    ifstream file("setup.txt");
    file>>car.num;
    file>>car.num2;
    file>>car.num3;
    file>>datecar;
    file.close();
    remove("setup.txt");
    ofstream file2("setup.txt");
    file2<<idsetter<<" "<<car.num2<<" "<<car.num3<<endl;
    file2<<datecar;
    file2.close();

}
