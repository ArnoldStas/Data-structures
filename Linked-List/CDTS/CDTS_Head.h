#include <iostream>

struct node {
    int data;
    node* next;
    node* prev;
};

class NODE {
    private:
node* tail;
int size;
    public:
NODE() : tail(nullptr), size(0) {}
~NODE() {}

    void addNodeStart(int value)
    {
        node* temp = new node();
        temp->data = value;

        if (tail != nullptr)
        {
            temp->next = tail->next;
            temp->prev = tail;
            tail->next->prev = temp;
            tail->next = temp;
        }
        else
        {
            tail = temp;
            temp->next = tail;
            temp->prev = tail;
        }
        size = size + 1;
    }

    void addNodeEnd(int value)
    {
        node* temp = new node();
        temp->data = value;
        if (tail != nullptr)
        {
            temp->next = tail->next;
            temp->prev = tail;
            tail->next->prev = temp;
            tail->next = temp;
            tail = temp;
        }
        else {
            tail = temp;
            temp->next = tail;
            temp->prev = tail;
        }
        size = size + 1;
    }

    void addNodePosition(int value, int position)
    {

        if (position < 1) {
            std::cout << "Position doesn't exist!\n";
            return;
        }

        node* temp = new node();
        node* ride = nullptr;
        temp->data = value;
        temp->next = nullptr;
        temp->prev = nullptr;

        if (isEmpty()) {
            std::cout <<"List is empty, the element goes to the first place!\n";
            addNodeStart(value);
            return;
        }

        position = position % size;

        if (position == 0) {
            position = size;
        }

        if (position == 1) {
            addNodeStart(value);
            return;
        }

        if (position == size) {
            temp->next = tail;
            tail->prev->next = temp;
            temp->prev = tail->prev;
            tail->prev = temp;
            size = size + 1;
            return;
        }

        if (position <= size / 2) 
        {
        ride = tail->next;
        for (int i = 1; i < position - 1; i++) ride = ride->next;
        } 

        else if (position > size / 2)
        {
        ride = tail;
        for (int i = size; i > position - 1; i--) ride = ride->prev;
        }

        temp->next = ride->next;
        temp->prev = ride;
        ride->next->prev = temp;
        ride->next = temp;

        size = size + 1;
    }

    void deleteNodeStart()
    {
        if (!isEmpty())
        {
            if (tail->next != tail)
            {
                node* temp = tail->next;
                temp->next->prev = tail;
                tail->next = temp->next;
                delete temp;
            }
            else
            {
                delete tail;
                tail = nullptr;
            }
            size = size - 1;
        }
        else {
            std::cout <<"Can't delete element from the start because the list is empty!\n";
        }
    }

    void deleteNodeEnd()
    {
        if (!isEmpty())
        {
            if (tail->next != tail) 
            {
                node* temp = tail;
                tail->prev->next = tail->next;
                tail = tail->prev;
                delete temp;
            }
            else
            {
                delete tail;
                tail = nullptr;
            }
            size = size - 1;
        }
        else
        {
            std::cout <<"Can't delete element from the end because the list is empty!\n";
        }
    }

    void Display()
    {
        //std::cout <<"Size: " << size <<"\n";
        if (!isEmpty())
        {
            node* rd = tail->next;
            do
            {
                std::cout << rd->data << " ";
                rd = rd->next;
            } while (rd != tail->next);
            std::cout <<"\n";
        }
        else {
            std::cout <<"Can't display because the list is empty!\n";
        }
    }

    int isEmpty()
    {
        return tail == nullptr;
    }

    int grazinkTail()
    {
        std::cout <<"\n";
        return tail->data;
    }

};