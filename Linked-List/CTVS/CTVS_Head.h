#include <iostream>

struct node {
    int data;
    node* next;
};

class NODE 
{
    private:
node* tail;
    public:
NODE() : tail(nullptr) {}
~NODE() {clear();}
    void addNodeEnd(int value)
    {
        node* temp = new node();
        temp->data = value;
        if (tail != nullptr)
        {
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }
        else
        {
            tail = temp;
            temp->next = tail;
        }
    }

    void addNodeStart(int value)
    {
        node* temp = new node();
        temp->data = value;
        if (tail != nullptr)
        {
            temp->next = tail->next;
            tail->next = temp;
        }
        else
        {
            tail = temp;
            temp->next = tail;
        }
    }

    void addNodePosition(int value, int position)
    {
        if (tail == nullptr)
        {
            addNodeStart(value);
        }
        else if(position < 1) std::cout << "Position doesn't exist!\n";

        else
        {
            node* ride = tail;
            for (int i = 1; i<position; i++)
            {
                ride=ride->next;  
            }

            if(ride->next == tail) 
            {
                node* temp = new node();
                temp->data = value;
                temp->next = tail;
                ride->next = temp;
            }
                else if(ride == tail) addNodeStart(value);
                else
                {
                    node* temp = new node();
                    temp->data = value;
                    temp->next = ride->next;
                    ride->next = temp;
                }
        }

    }

    void deleteNodeStart()
    {
        if (tail != nullptr)
        {
            node* temp;
            temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }
        else 
        {
            std::cout <<"Can't delete elements from the start because the list is empty!\n";
        }
    }

    void deleteNodeEnd()
    {
        if (tail != nullptr)
        {
            if (tail->next == tail)
            {
                delete tail;
                tail = nullptr;
            }
            else 
            {
                node* temp;
                temp = tail->next;
                while (temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
        }
        else
        {
            std::cout <<"Can't delete elements from the end because the list is empty!\n";
        }
    }

    void deleteNodePosition(int position)
    {
        if (tail == nullptr)
        {
            std::cout << "Can't delete elements from the position because the list is empty!\n";
        }
        else if(position < 1) std::cout << "Position doesn't exist!\n";

        else
        {
            node* ride = tail;
            for (int i = 1; i < position + 1; i++)
            {
                ride = ride -> next;
            }
                node* temp = nullptr;
                temp = ride->next;

                if(ride == tail) deleteNodeEnd();
                else if(ride == tail -> next) deleteNodeStart();
                else
                {
                    ride->next = temp->next;
                    delete temp;
                }
        }
    }

    void Display()
    {
        if (!isEmpty())
        {
            node* ride;
            ride = tail->next;
            do {
                std::cout << ride->data << " ";
                ride = ride->next;
            } while (ride != tail->next);
            std::cout <<"\n";
        }
        else {
            std::cout <<"The list is empty!\n";
        }
    }

    void clear()
    {
        if (isEmpty())
        {
            std::cout <<"The list is empty, can't clear!\n";
            return;
        }

        node* temp = tail->next;
        while (temp != tail)
        {
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        delete tail;
        tail = nullptr;
    }

    void search(int value)
    {
        if (isEmpty())
        {
            std::cout <<"The list is empty, can't find number!\n";
            return;
        }

        node* ride = tail->next;
        bool is;
        for (int i = 1;; i++)
        {
            if (ride->data == value) {
                std::cout << "Number {" << value << "} position in the list: " << i <<"\n";
                is = true;
            }
            ride = ride->next;
            if (ride == tail->next) break;
        }

        if (!is) std::cout <<"The number {" << value << "} doesn't exist in the list!\n";
    }

    void reverse()
    {
        if (isEmpty())
        {
            std::cout <<"The list is empty, can't reverse!\n";
            return;
        }

        node* pre = tail;
        node* nxt = nullptr;
        node* cur = tail->next;
        node* newTail = tail->next;

        do
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        } while (cur != tail);

        tail->next = pre;
        tail = newTail;

    }

    int isEmpty()
    {
        return tail == nullptr;
    }


};