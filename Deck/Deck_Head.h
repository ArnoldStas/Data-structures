#include <iostream>
#include <stack>
using namespace std;

class dekas
{
private:
	int* dek;
	int size;
public:
	int front, back;
	dekas(int x) : front(-1), back(-1), dek(new int[x]), size(x) {}
	~dekas() {
		delete[] dek;
	}

	void pushBack(int skaicius)
	{
		if (isFull()) {
			cout << "Dekas yra jau uzpildytas!\n";
		}
		else {
			if (isEmpty()) {
				front = back = 0;
			}
			else {
				back = (back + 1) % size;
			}
			dek[back] = skaicius;

			/*for (int i = 0; i < size; i++) cout << dek[i] << " ";
			cout << "\n";
			cout << "Front: " << front << "\n";
			cout << "Back: " << back << "\n";
			cout << "\n";*/
		}
	}

	void pushFront(int skaicius)
	{
		if (isFull()) {
			cout << "Dekas yra jau uzpildytas!\n";
		}
		else {
			if (isEmpty()) {
				front = back = 0;
			}
			else {
				front = (front - 1 + size) % size;
			}
			dek[front] = skaicius;
		}
	}

	int popBack() {
		if (isEmpty()) {
			cout << "Dekas tuscias!\n";
			return -1;
		}
		int temp = back;
		if (front == back) {
			front = -1;
			back = -1;
		}
		else {
			back = (back - 1 + size) % size;
		}
		//cout << "Front: " << front << "\n";
		//cout << "Back: " << back << "\n";
		return dek[temp];
	}

	int popFront() {
		if (isEmpty()) {
			cout << "Dekas tuscias!\n";
			return -1;
		}
		int temp = front;
		if (front == back) {
			front = -1;
			back = -1;
		}
		else {
			front = (front + 1) % size;
		}
		//cout << "Front: " << front << "\n";
		//cout << "Back: " << back << "\n";
		return dek[temp];
	}

	int first() //FRONT()
	{
		if (!isEmpty())
		{
			return dek[front];
		}
		else
		{
			cout << "Dekas tuscias, nera jokio pirmo elemento!\n";
		}
	}

	int last() //BACK()
	{
		if (!isEmpty())
		{
			return dek[back];
		}
		else {
			cout << "Dekas tuscias, nera jokio paskutinio elemento!\n";
		}
	}

	bool isEmpty()
	{
		return front == -1;
	}

	bool isFull()
	{
		return front == (back + 1) % size;
	}
};

inline void display(dekas& dek) // KLASES ISOREJE
{
	while (!dek.isEmpty())
	{
		cout << dek.popFront() << " ";
	}
}

inline void reverse(dekas& dek) // KLASES ISOREJE
{
	stack<int> stekas;
	while (!dek.isEmpty())
	{
		stekas.push(dek.popFront());
	}
	while (!stekas.empty())
	{
		dek.pushBack(stekas.top());
		stekas.pop();
	}
}

inline void clear(dekas& dek) // KLASES ISOREJE
{
	while (!dek.isEmpty())
	{
		dek.popFront();
	}
}