
/******************************************************************************
 * Deko realizacija statiniu masyvu / PER KLASES
******************************************************************************/

#include <iostream>
#include "Deck_Head.h"
using namespace std;

int main()
{
	int x;
	cout << "Iveskite deko dydi: ";
	cin >> x;
	dekas dek(x);

	while (true)
	{
		int numeris;
		int reiksme;
		cout << "Ka norite daryti su duomenu struktura - DEKAS? \n";
		cout << "--------------------------------------------- \n";
		cout << "0. Iseiti is programos. \n";
		cout << "1. Prideti elementa i deko gala. \n";
		cout << "2. Prideti elementa i deko pradzia. \n";
		cout << "3. Pasalinti elementa is deko galo. \n";
		cout << "4. Pasalinti elementa is deko pradzios. \n";
		cout << "5. Perziureti pirma elementa. \n";
		cout << "6. Perziureti galini elementa. \n";
		cout << "7. Patikra, ar dekas yra tuscias. \n";
		cout << "8. Patikra, ar dekas yra pilnas. \n";
		cout << "9. Isvesti deko elementus i ekrana. \n";
		cout << "10. Apsukti deka. \n";
		cout << "11. Isvalyti deka. \n";
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
			cout << "Elemento idejimas i GALA \n";
			cout << "Reiksme ideti i deka: ";
			cin >> reiksme;
			dek.pushBack(reiksme);
			cout << "\n\n";
			break;

		case 2:
			cout << "Elemento idejimas i PRADZIA \n";
			cout << "Reiksme ideti i deka: ";
			cin >> reiksme;
			dek.pushFront(reiksme);
			cout << "\n\n";
			break;

		case 3:
			cout << "Elemento istrinimas is GALO \n";
			if (!dek.isEmpty()) {
				cout << "Pasalintas elementas: " << dek.popBack();
				cout << "\n\n";
			}
			else {
				cout << "Pasalintas elementas: - \n";
				cout << "Nera ka salinti, nes dekas yra tuscias! \n";
				cout << "\n\n";
			}
			break;

		case 4:
			cout << "Elemento istrinimas is PRADZIOS \n";
			if (!dek.isEmpty()) {
				cout << "Pasalintas elementas: " << dek.popFront();
				cout << "\n\n";
			}
			else {
				cout << "Pasalintas elementas: - \n";
				cout << "Nera ka salinti, nes dekas yra tuscias! \n";
				cout << "\n\n";
			}
			break;

		case 5:
			cout << "Pirmo elemento perziurejimas \n";
			cout << "Pirmas elementas: " << dek.first();
			cout << "\n\n";
			break;

		case 6:
			cout << "Paskutinio elemento perziurejimas \n";
			cout << "Paskutinis elementas: " << dek.last();
			cout << "\n\n";
			break;

		case 7:
			cout << "Patikra, ar dekas yra tuscias \n";
			if (dek.isEmpty()) cout << "Dekas yra tuscias! \n";
			else cout << "Dekas yra netuscias! \n";
			break;

		case 8:
			cout << "Patikra, ar dekas yra pilnas \n";
			if (dek.isFull()) cout << "Dekas yra pilnas! \n";
			else cout << "Dekas yra nepilnas! \n";
			break;

		case 9:
			cout << "Dekas: ";
			display(dek);
			cout << "\n\n";
			break;

		case 10:
			cout << "Dekas apsuktas.";
			reverse(dek);
			cout << "\n\n";
			break;

		case 11:
			cout << "Isvalytas dekas! \n";
			clear(dek);
			cout << "\n\n";
			break;

		default:
			cout << "Neteisingas pasirinkimas! \n";
			break;
		}
	}
	return 0;
}