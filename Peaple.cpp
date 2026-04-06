//
// Created by abc1 on 3/19/2023.
//

#include "Peaple.h"



void Peaple::setcnic(int cni){
    cnic=cni;
}

int Peaple::getcnic(){
    return cnic;
}

void Peaple::setdateborn(Date &datebor){
    dateborn=datebor;
}

Date  Peaple::getdateborn(){
    return dateborn;
}
