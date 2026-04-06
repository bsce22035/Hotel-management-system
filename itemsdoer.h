//
// Created by abc1 on 3/31/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_ITEMSDOER_H
#define HOTEL_MANAGEMENTSYSTEM_ITEMSDOER_H
#include "Item.h"
#include "Bills.h"
#include <vector>
#include <fstream>
template <typename ty>
class itemsdoer {
    vector<ty> array;

public:
    itemsdoer(){
                int num=0;
                string test=" ";
                bool testa=1;
        Item car;
              ifstream file("food.txt");
        while(!file.eof()&&testa){

            file>>car;
            array.push_back(car);
            if(num-1>=0){
                if(array[num].getName()==array[num-1].getName()){
                    array.erase(array.begin()+num);
                    testa=0;
                }
            }
            num++;
        }

    }

    void removeitem(string name){
        for(int i=0;i<array.size();i++){
            if(array[i].getName()==name){
                array.erase(array.begin()+i);
                cout<<"\nDish/Drink removed succesfully\n";

            }
        }

    }


    bool  additem(Item& it){

        for(int i=0;i<array.size();i++){
            if(it.getName()==array[i].getName()){
         cout<<"\nThis Dish already exsist\n";
            return 0 ;
        }

        }
        if(it.getName().size()<4){
            cout<<"\nDish name to short ";
            return 0;
        }
        array.push_back(it);

        return 1;
    }
    void savetolist(){
        ofstream file("food.txt");

        for(int i=0;i<array.size();i++){
                 if(array[i].getName().length()>=5){
                     file<<array[i];}
        }
        file.close();
    }


    void printalldishitems(){

        for(int i=0;i<array.size();i++){
            array[i].printitem();
        }
    }
    ty getitem(int i){
        return array[i];
    }
    ty getitem(string name){
        for(int i=0;i<array.size();i++){
            if(array[i].getName()==name){
                return array[i];
            }
        }
    }





};


#endif //HOTEL_MANAGEMENTSYSTEM_ITEMSDOER_H
