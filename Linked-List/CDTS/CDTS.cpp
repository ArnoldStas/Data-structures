/******************************************************************************
 * Ciklinio dvikrypcio saraso realizacija PER STRUKTURA / PER KLASES
******************************************************************************/
#include <iostream>
#include "CDTS_Head.h"
using namespace std;
int main()
{
    NODE CDVS;

    //CDVS.addNodeStart(2);
    //CDVS.addNodeStart(1);
    //CDVS.addNodeStart(200);
    //CDVS.addNodeStart(30);
    //CDVS.addNodeStart(5);
    
    //CDVS.Display();

    //CDVS.addNodeEnd(100);
    //CDVS.addNodeEnd(200);
    //CDVS.addNodeEnd(300);
    //CDVS.addNodeEnd(400);

    //CDVS.Display();

    //CDVS.deleteNodeStart();
    //CDVS.deleteNodeStart();

    //cout << CDVS.grazinkTail();
    //CDVS.deleteNodeEnd();
    //cout << CDVS.grazinkTail();

    CDVS.addNodePosition(500, 7);
    CDVS.addNodePosition(1000, 4);
    CDVS.addNodePosition(81, 3);
    CDVS.addNodePosition(50000, 16);

    CDVS.Display();

    //CDVS.addNodePosition(50, 3);
    //CDVS.addNodePosition(9000, 9);

    //CDVS.Display();

    //if (CDVS.isEmpty()) std::cout <<"The list is empty!\n";
    //else std::cout<<"The list is not empty!\n";

    return 0;
}