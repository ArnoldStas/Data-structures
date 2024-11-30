#include <iostream>

struct node{
    int data;
    node* next;
    node* prev;
};

class NODE
{
private:
    node* head;
    node* tail;
public:
    int size;
    NODE() : head(nullptr), tail(nullptr), size(0) {}
    ~NODE() {clear();}

    void addNodeStart(int value)
    {
        node* temp = new node();
        temp->data = value;
        temp->prev = nullptr;
        if (head != nullptr) 
        {
            temp->next = head;
            head->prev = temp;
        }
        else
        {
            tail = temp;
            tail->next = nullptr;
        }
        head = temp;
        size = size + 1;
    }

    void addNodeEnd(int value)
    {
        node* temp = new node();
        temp->data = value;
        temp->next = nullptr;
        if (head != nullptr)
        {
            temp->prev = tail;
            tail->next = temp;
        }
        else
        {
            head = temp;
            head->prev = nullptr;
        }
        tail = temp;
        size = size + 1;
    }

    void addNodePosition(int value, int position)
{
    node* temp = new node();
    temp->data = value;

    if (isEmpty() && position != 1) {
        std::cout << "TDS - TUSCIAS! Pagal pozicija prideti negalima! \n";
        return;
    }

    if (position < 1 || position > size + 1) {
        std::cout << "Netinkama pozicija! \n";
        return;
    }

    if (position == 1) {
        
        if (isEmpty()) {
            head = tail = temp;
            temp->next = temp->prev = nullptr;
        } else {
            temp->next = head;
            head->prev = temp;
            temp->prev = nullptr;
            head = temp;
        }
    } 
    else if (position == size + 1) {
        temp->prev = tail;
        tail->next = temp;
        temp->next = nullptr;
        tail = temp;
    }
    else if (position <= size / 2) {
        node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
        temp->prev = current;
    }
    else {
        node* current = tail;
        for (int i = size; i > position; i--) {
            current = current->prev;
        }
        temp->prev = current->prev;
        current->prev->next = temp;
        temp->next = current;
        current->prev = temp;
    }

    size = size + 1;
}

    int deleteNodeStart()
    {
        if (head == nullptr) {
        throw std::out_of_range("List is empty");
        }
        int vl = head->data;
        if (head != tail)
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            size = size - 1;
        }
        else
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = size - 1;
        }
        return vl;
    }

    int deleteNodeEnd()
    {
        if (tail == nullptr) {
        throw std::out_of_range("List is empty");
        }
        int vl = tail->data;
        if (head != tail)
        {
            /*node* OldTail = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete OldTail;*/

            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            size = size - 1;

        }
        else
        {
            delete tail;
            tail = nullptr;
            head = nullptr;
            size = size - 1;
        }
        return vl;
    }

    int deleteNodePosition(int position)
{
    int value;
    if (position == 1) {
        value = deleteNodeStart();
    } 

    else if (position == size) {
        value = deleteNodeEnd();
    }

    else if (position <= size / 2) {
        node* current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        value = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size = size - 1;
    } 

    else if (position > size / 2){
        node* current = tail;
        for (int i = size; i > position; i--) {
            current = current->prev;
        }
        value = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size = size - 1;
    }
    return value;
}

    void display()
    {
        node* read;
        read = head;
        while (read != nullptr)
        {
            std::cout << read->data <<" ";
            read = read->next;
        }
        delete read;
        //std::cout << "Size: " << size;
    }

    bool isEmpty()
    {
        return (head == nullptr && tail == nullptr);
    }

    void clear()
    {
        node* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void reverse()
    {
        tail = head;
        node* cur = head;
        node* nxt = nullptr;

        while (cur != nullptr)
        {
            nxt = cur->prev;
            cur->prev = cur->next;
            cur->next = nxt;
            cur = cur->prev;
        }
        
        if (nxt != nullptr)
        {
            head = nxt->prev;
        }
    }

    void search(int value)
    {
        int isHere = 0;
        if (isEmpty()) {
            std::cout <<"Skaiciaus {" << value <<"} pozicijos sarase negalima surasti, nes sarasas - TUSCIAS! \n";
            return;
        }
        else {
            node* read;
            read = head;
            for (int i = 1; read != nullptr; i++)
            {
                if (read->data == value) 
                {
                    std::cout << "Skaiciaus {" << value << "} pozicija sarase - " << i << "\n";
                    isHere = isHere + 1;
                }
                read = read->next;
            }
            delete read;
        }
        if (isHere == 0) std::cout <<"Skaiciaus {" << value << "} poziciju sarase - NERA! \n";
    }

};
