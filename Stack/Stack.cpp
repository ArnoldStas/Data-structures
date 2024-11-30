/******************************************************************************
 * Steko realizacija statiniu masyvu
******************************************************************************/
#include <iostream>
#include "Stack_Head.h"
using namespace std;

int main()
{
    Stekas stekas;
    int p=10000,r;
    while(p!=0){
    cout<<"Pasirinkite ka norite daryti\n";
    cout<<"0. Iseiti is programos\n";
    cout<<"1. Padeti elementa i steka\n";
    cout<<"2. Isimti elementa is steko\n";
    cout<<"3. Paziureti virsutini steko elementa\n";
    cout<<"4. Patikrinti, ar stekas tuscias\n";
    cout<<"5. Patikrinti, ar stekas pilnas\n";
    cout<<"6. Parodyti visus steko elementus\n";
    cout<<"Jusu pasirinkimas: ";
    cin>>p;
    switch(p){
        case 1:
                cout<<"Iveskite elemento reiksme ";
                cin>>r;
                stekas.push(r);
                break;
        case 2:
                cout<<"Pasalintas elementas "<<stekas.pop()<<" sekmingai\n";
                break;
        case 3:
                cout<<"Virsutinis steko elementas "<<stekas.topEl()<<endl;
                break;
        case 4:
                if(stekas.isEmpty()==true){
                    cout<<"Stekas tuscias\n";
                }else{
                    cout<<"Stekas turi elementu\n";
                }
                break;
        case 5:
                if(stekas.isFull()==true){
                    cout<<"Stekas pilnas\n";
                }else{
                    cout<<"Stekas dar turi laisvos vietos\n";
                }
                break; 
        case 6:
                cout<<"Steko elementai: ";
                stekas.display();
                break;
        default:
                cout<<"Neteisingas pasirinkimas"<<endl;
                break;
    }
    }

    return 0;
}
