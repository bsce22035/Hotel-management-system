//
// Created by abc1 on 3/31/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_RESTURENT_H
#define HOTEL_MANAGEMENTSYSTEM_RESTURENT_H
#include <iostream>
using namespace std;

class Item {
    string name;
    double price;
    string type;
public:

    virtual void printitem(){
        cout<<"\n__________________\n";
        cout<<type<<endl;
        cout<<"Name: "<<name;
        cout<<"\nPrice: "<<price;
        cout<<"\n_________________\n";
    };

    string gettype(){
        return type;
    }
    void settype(string aa){
        type=aa;

    }

    void  inputdetails(){
        cout<<"\nEnter name";
        cin>>name;
        cout<<"\nEnter price";
        cin>>price;

    }


    friend istream &operator>>(istream& out,Item &it){
        out>>it.name>>it.price>>it.type;
        return out;
    }

    friend ostream &operator<<(ostream& out,Item &it){
        out<<it.name<<" "<<it.price<<" "<<it.type<<endl;
        return out;
    }
    string getName()  {
        return name; }
    double getPrice()  {
        return price; }

};

class DishItem : public Item {
public:
    DishItem() {

        settype("Dish");
    }
    void printitem(){

        cout<<"\n______________________\n";
        cout<<"Dish Name: "<<getName();
        cout<<"\nPrice: $"<<getPrice();

        cout<<"\n______________________\n";
    }

};

class DrinkItem : public Item {
public:
    DrinkItem()  {

        settype("Drink");
    }
    void printitem(){

        cout<<"\n______________________\n";
        cout<<"Drink Name: "<<getName();
        cout<<"\nPrice: "<<getPrice();
        cout<<"\n______________________\n";
    }


};

#endif //HOTEL_MANAGEMENTSYSTEM_RESTURENT_H
