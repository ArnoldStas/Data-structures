#include <iostream>
#include <stack>
using namespace std;

class eile
{
private:
	int* eilute;
	int size;
public:
	int front, back;
	eile(int x) : front(-1), back(-1), eilute(new int[x]), size(x) {}
	~eile() {
		delete[] eilute;
	}

	void enqueue(int skaicius)
	{
		if (isFull()) {
			cout << "Eile yra jau uzpildyta!\n";
		}
		else {
			if (front == -1) front = 0;
			back = (back + 1) % size;
			eilute[back] = skaicius;
		}
		//cout << "\n";
		//cout << "Front: " << front << "\n";
		//cout << "Back: " << back << "\n";
		//cout << "\n";
	}

	int dequeue()
	{
		if (isEmpty()) {
			cout << "Eile tuscia!\n";
			return -1;
		}
		int temp = front;
		if (front==back)
		{
			front = -1;
			back = -1;
		}
		else {
			front = (front + 1) % size;
		}
		return eilute[temp];
	}

	int first() //FRONT()
	{
		if (!isEmpty())
		{
			return eilute[front];
		}
		else
		{
			cout << "Eilute tuscia, nera jokio pirmo elemento!\n";
		}
	}

	int last() //BACK()
	{
		if (!isEmpty())
		{
			return eilute[back];
		}
		else {
			cout << "Eilute tuscia, nera jokio paskutinio elemento!\n";
		}
	}

	bool isEmpty()
	{
		if (front == -1 && back == -1) return true;
		else return false;
	}

	bool isFull()
	{
		return (back + 1) % size == front;
	}
};

inline void display(eile& eil) // KLASES ISOREJE
{
	while (!eil.isEmpty())
	{
		cout << eil.dequeue() << " ";
	}
}

inline void reverse(eile& eil) // KLASES ISOREJE
{
	stack<int> stekas;
	while (!eil.isEmpty())
	{
		stekas.push(eil.dequeue());
	}
	while (!stekas.empty())
	{
		eil.enqueue(stekas.top());
		stekas.pop();
	}
}

inline void clear(eile& eil) // KLASES ISOREJE
{
	eil.front = -1;
	eil.back = -1;
}