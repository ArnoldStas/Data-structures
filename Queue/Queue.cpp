/******************************************************************************
 * Eilės realizacija statiniu masyvu / PER KLASES
******************************************************************************/

#include <iostream>
#include "Queue_Head.h"
using namespace std;

int main()
{
	int x;
	cout << "Iveskite eilutes dydi: ";
	cin >> x;
	eile eil(x);

	while (true)
	{
		int numeris;
		int reiksme;
		cout << "Ka norite daryti su duomenu struktura - EILE? \n";
		cout << "--------------------------------------------- \n";
		cout << "0. Iseiti is programos. \n";
		cout << "1. Prideti elementa i eile (GALAS). \n";
		cout << "2. Istrinti elementa is eiles (PRADZIA). \n";
		cout << "3. Perziureti pirma elementa. \n";
		cout << "4. Perziureti paskutini elementa. \n";
		cout << "5. Patikra, ar eile yra tuscia. \n";
		cout << "6. Patikra, ar eile yra pilna. \n";
		cout << "7. Isvalyti eile, tampa tuscia. \n";
		cout << "8. Isvesti eile i ekrana. \n";
		cout << "9. Apsukti eile. \n";
		cout << "\n\n";
		cout << "Iveskite numeri: ";
		cin >> numeris;
		cout << endl;

		switch (numeris) {
		case 0:
		{
			exit(EXIT_SUCCESS);
		}
		case 1:
			cout << "Elemento idejimas \n";
			cout << "Reiksme ideti i eile: ";
			cin >> reiksme;
			eil.enqueue(reiksme);
			cout << "\n\n";
			break;

		case 2:
			cout << "Elemento istrinimas \n";
			if (!eil.isEmpty()) {
				cout << "Pasalintas elementas: " << eil.dequeue();
				cout << "\n\n";
			}
			else {
				cout << "Pasalintas elementas: - \n";
				cout << "Nera ka salinti, nes eile tuscia! \n";
				cout << "\n\n";
			}
			break;

		case 3:
			cout << "Pirmo elemento perziurejimas \n";
			cout << "Pirmas elementas: " << eil.first();
			cout << "\n\n";
			break;

		case 4:
			cout << "Paskutinio elemento perziurejimas \n";
			cout << "Paskutinis elementas: " << eil.last();
			cout << "\n\n";
			break;

		case 5:
			cout << "Patikra, ar eile yra tuscia \n";
			if (eil.isEmpty() == true) cout << "Eile tuscia! \n\n";
			else cout << "Eile netuscia! \n\n";
			break;

		case 6:
			cout << "Patikra, ar eile yra pilna \n";
			if (eil.isFull() == true) cout << "Eile pilna! \n\n";
			else cout << "Eile nepilna! \n\n";
			break;

		case 7:
			cout << "Isvalyta eile! \n";
			clear(eil);
			cout << "\n\n";
			break;

		case 8:
			cout << "Eile: ";
			display(eil);
			cout << "\n\n";
			break;

		case 9:
			cout << "Eile apsukta.";
			reverse(eil);
			cout << "\n\n";
			break;

		default:
			cout << "Neteisingas pasirinkimas! \n";
			break;
		}
	}
	return 0;
}