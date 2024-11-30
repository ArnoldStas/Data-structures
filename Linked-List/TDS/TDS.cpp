/******************************************************************************
 * Dvikrypcio saraso realizacija PER STRUKTURA / PER KLASES
******************************************************************************/
#include <iostream>
#include "TDS_Head.h"
using namespace std;
int main()
{
	int skaicius;
	int pozicija;
	bool g;
	NODE TDS;
	while (true)
	{
		cout << "0. Iseiti is programos.\n";
		cout << "1. Prideti nauja saraso elementa gale.\n";
		cout << "2. Prideti nauja saraso elementa pradzioje.\n";
		cout << "3. Prideti nauja saraso elementa pagal pozicija.\n";
		cout << "4. Pasalinti saraso elementa pradzioje.\n";
		cout << "5. Pasalinti saraso elementa gale.\n";
		cout << "6. Pasalinti saraso elementa pagal pozicija.\n";
		cout << "7. Atspausdinti sarasa.\n";
		cout << "8. Patikra, ar sarasas yra tuscias.\n";
		cout << "9. Isvalyti tiesini dvikrypti sarasa.\n";
		cout << "10. Surasti elemento pozicijas sarase.\n";
		cout << "11. Apsukti tiesini dvikrypti sarasa.\n";
		cout << "Iveskite pasirinkimo numeri: ";
		int numeris;
		cin >> numeris;
		cout << "\n";

		switch (numeris)
		{
		case 0:
			exit(EXIT_SUCCESS);

		case 1:
			cout << "Elemento idejimas i saraso GALA \n";
			cout << "Iveskite elemento skaiciu: ";
			cin >> skaicius;
			TDS.addNodeEnd(skaicius);
			cout << "\n";
			break;

		case 2:
			cout << "Elemento idejimas i saraso PRADZIA \n";
			cout << "Iveskite elemento skaiciu: ";
			cin >> skaicius;
			TDS.addNodeStart(skaicius);
			cout << "\n";
			break;

		case 3:
			cout << "Elemento idejimas i sarasa pagal POZICIJA \n";
			cout << "Iveskite pozicijos skaiciu: ";
			cin >> pozicija;
			cout << "Iveskite elemento skaiciu: ";
			cin >> skaicius;
			TDS.addNodePosition(skaicius, pozicija);
			cout << "\n";
			break;

		case 4:
			cout << "Elemento pasalinimas is saraso PRADZIOS \n";
			if (!TDS.isEmpty()) cout << "Pasalintas elementas: " << TDS.deleteNodeStart() << "\n";
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 5:
			cout << "Elemento pasalinimas is saraso GALO \n";
			if (!TDS.isEmpty()) cout << "Pasalintas elementas: " << TDS.deleteNodeEnd() << "\n";
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 6:
			cout << "Elemento pasalinimas is saraso pagal POZICIJA \n";
			cout << "Iveskite pozicijos skaiciu: ";
			cin >> pozicija;
			if (!TDS.isEmpty())
			{
			    if (pozicija < 1 || pozicija > TDS.size) cout << "Netinkama pozicija! \n";
                else cout << "Pasalintas elementas: " << TDS.deleteNodePosition(pozicija) << "\n";
			}
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 7:
			cout << "Tiesinis dvikryptis sarasas: ";
			TDS.display();
			cout << "\n\n";
			break;

		case 8:
			cout << "Patikra, ar tiesinis dvikryptis sarasas yra tuscias \n";
			if (TDS.isEmpty()) cout << "Tiesinis dvikryptis sarasas yra TUSCIAS! \n\n";
			else cout << "Tiesinis dvikryptis sarasas yra NETUSCIAS! \n\n";
			break;

		case 9:
			cout << "Komanda isvalyti tiesini dvikrypti sarasa \n";
			cout << "Tiesinis dvikryptis sarasas isvalytas! \n\n";
			TDS.clear();
			break;

		case 10:
			cout << "Elemento pozicijos sarase \n";
			cout << "Iveskite ieskoma elementa: ";
			cin >> skaicius;
			TDS.search(skaicius);
			cout << "\n";
			break;

		case 11:
			cout << "Tiesinio dvikrypcio saraso apsukimas \n";
			if (!TDS.isEmpty()) cout << "TDS apsuktas! \n\n";
			else cout << "Apsukti TDS negalima, nes sarasas yra tuscias! \n\n";
			TDS.reverse();
			break;

		default:
			cout << "Neteisingas pasirinkimas! \n";
			break;

		}
	}

	return 0;
}