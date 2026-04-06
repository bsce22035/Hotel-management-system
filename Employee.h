#ifndef HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H
#define HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H
#include "Peaple.h"
#include <fstream>
class Employee:public Peaple{
public:
    static int idsetter;
    int id;
    int numofcomps;
    void seeempinfo();


    void input();


    void display1();



    friend  istream &operator>>(istream& inp,Employee &emp){
        inp>>emp.id;
        inp>>emp.fname;
        inp>>emp.lname;

        inp>>emp.cnic;

        inp>>emp.dateborn;
        return  inp;
    }

    friend  ostream &operator<<(ostream& out,Employee &emp){
        out<<emp.id<<" ";
        out<<emp.fname<<" ";
        out<<emp.lname<<" ";
        out<<emp.cnic<<" ";
        out<<emp.dateborn<<" "<<endl;
        return  out;
    }

    friend class Complain;


};



#endif //HOTEL_MANAGEMENTSYSTEM_EMPLOYEE_H
