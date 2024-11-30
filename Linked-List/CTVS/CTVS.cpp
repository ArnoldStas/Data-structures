/******************************************************************************
 * Ciklinio vienkrypcio saraso realizacija PER STRUKTURA / PER KLASES
******************************************************************************/
#include <iostream>
#include "CTVS_Head.h"
using namespace std;
int main()
{
    NODE CTVS;

    CTVS.addNodeEnd(1);
    CTVS.addNodeEnd(2);
    CTVS.addNodeEnd(3);
    CTVS.addNodeEnd(4);

    CTVS.addNodeStart(50);
    CTVS.addNodeStart(200);

    //CTVS.Display();

    //CTVS.deleteNodeStart();
    //CTVS.deleteNodeStart();

    //CTVS.Display();

    //CTVS.deleteNodeEnd();
    //CTVS.deleteNodeEnd();

    //CTVS.Display();

    //CTVS.clear();

    //CTVS.search(2);

    //CTVS.reverse();

    //CTVS.Display();

    //CTVS.addNodePosition(565,10);

    CTVS.Display();

    //CTVS.deleteNodePosition(9);
    CTVS.addNodePosition(5000, 7);

    CTVS.Display();

    return 0;
}