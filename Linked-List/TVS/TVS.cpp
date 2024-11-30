/******************************************************************************
 * Vienkrypcio saraso realizacija PER STRUKTURA / PER KLASES
******************************************************************************/
#include <iostream>
#include "TVS_Head.h"
using namespace std;
int main()
{
	int skaicius;
	int pozicija;
	bool g;
	NODE list;
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
		cout << "9. Isvalyti tiesini vienkrypti sarasa.\n";
		cout << "10. Surasti elemento pozicijas sarase.\n";
		cout << "11. Apsukti tiesini vienkrypti sarasa.\n";
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
			list.addNodeEnd(skaicius);
			cout << "\n";
			break;

		case 2:
			cout << "Elemento idejimas i saraso PRADZIA \n";
			cout << "Iveskite elemento skaiciu: ";
			cin >> skaicius;
			list.addNodeStart(skaicius);
			cout << "\n";
			break;

		case 3:
			cout << "Elemento idejimas i sarasa pagal POZICIJA \n";
			cout << "Iveskite pozicijos skaiciu: ";
			cin >> pozicija;
			cout << "Iveskite elemento skaiciu: ";
			cin >> skaicius;
			list.addNodePosition(skaicius, pozicija);
			cout << "\n";
			break;

		case 4:
			cout << "Elemento pasalinimas is saraso PRADZIOS \n";
			if (!list.isEmpty()) cout << "Pasalintas elementas: " << list.deleteNodeStart() << "\n";
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 5:
			cout << "Elemento pasalinimas is saraso GALO \n";
			if (!list.isEmpty()) cout << "Pasalintas elementas: " << list.deleteNodeEnd() << "\n";
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 6:
			cout << "Elemento pasalinimas is saraso pagal POZICIJA \n";
			cout << "Iveskite pozicijos skaiciu: ";
			cin >> pozicija;
			if (!list.isEmpty())
			{
				list.deleteNodePosition(pozicija, skaicius, g);
				if (g == true) cout << "Pasalintas elementas: " << skaicius << "\n";
			}
			else cout << "Nera saraso elementu, salinti negalima! \n";
			cout << "\n";
			break;

		case 7:
			cout << "Tiesinis vienkryptis sarasas: ";
			list.display();
			cout << "\n\n";
			break;

		case 8:
			cout << "Patikra, ar tiesinis vienkryptis sarasas yra tuscias \n";
			if (list.isEmpty()) cout << "Tiesinis vienkryptis sarasas yra TUSCIAS! \n\n";
			else cout << "Tiesinis vienkryptis sarasas yra NETUSCIAS! \n\n";
			break;

		case 9:
			cout << "Komanda isvalyti tiesini vienkrypti sarasa \n";
			cout << "Tiesinis vienkryptis sarasas isvalytas! \n\n";
			list.clear();
			break;

		case 10:
			cout << "Elemento pozicijos sarase \n";
			cout << "Iveskite ieskoma elementa: ";
			cin >> skaicius;
			list.search(skaicius);
			cout << "\n";
			break;

		case 11:
			cout << "Tiesinio vienkrypcio saraso apsukimas \n";
			if (!list.isEmpty()) cout << "TVS apsuktas! \n\n";
			else cout << "Apsukti TVS negalima, nes sarasas yra tuscias! \n\n";
			list.reverse();
			break;

		default:
			cout << "Neteisingas pasirinkimas! \n";
			break;

		}
	}

	return 0;
}

