#include <iostream>
using namespace std;

int const N = 11;

class Stekas {
private:
    int mas[N];
    int top;

public:
    Stekas() {
        top = -1;
    }

    void push(int el) {
        if (!isFull()) {
            top = top + 1;
            mas[top] = el;
        } else {
            cout << "Daugiau elementu prideti negalima! \n";
        }
    }

    int pop() {
        if (!isEmpty()) {
            int temp = mas[top];
            top = top - 1;
            return temp;
        } else {
            cout << "Daugiau elementu ISSIMTI negalima! \n";
            return -1;
        }
    }

    int topEl() {
        if (!isEmpty()) {
            return mas[top];
        } else {
            cout << "Stekas tuscias! \n";
            return -1;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == N - 1);
    }

    void display() {
        int temp = top;
        while (temp >= 0) {
            cout << mas[temp] << " ";
            temp--;
        }
        cout << "\n";
    }
};