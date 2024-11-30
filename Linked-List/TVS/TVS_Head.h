#include <iostream>
struct node {
	int data;
	node* next;
};
class NODE {
private:
    node* head;
    node* tail;
public:
    NODE() : head(nullptr), tail(nullptr) {}
    ~NODE() { clear(); }
    void addNodeEnd(int value)
    {
        node* temp = new node();
        temp->data = value;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void addNodeStart(int value)
    {
        node* temp = new node();
        temp->data = value;
        temp->next = head;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head = temp;
        }
    }
    void addNodePosition(int value, int position)
    {
        int currentPosition = 1;
        node* ride = head;
        for (int i = 0; ride != nullptr; i++)
        {
            currentPosition++;
            ride = ride->next;
        }
        delete ride;

        if (head == nullptr && position > 2)
        {
            std::cout << "Negalima prideti elemento pozicijoje {" << position << "}, nes sarasas yra tuscias! \n";
        }
        
        else if (head == nullptr && position == 1)
        {
            node* temp = new node();
            temp->data = value;
            temp->next = nullptr;
            head = temp;
            tail = temp;
        }
 
        else if (position >= currentPosition || position == 0)
        {
            std::cout << "Netinkama pozicija! \n";
        }

        else if (head != nullptr && position == currentPosition)
        {
            node* temp = new node();
            temp->data = value;
            temp->next = nullptr;
            tail->next = temp;
        }

        else if (position == 1)
        {
            node* temp = new node();
            temp->data = value;
            temp->next = head;
            head = temp;

            if (tail == nullptr) {
                tail = temp;
            }
            return;
        }

        else
        {
            node* temp = new node();
            node* pre = head;
            temp->data = value;

            for (int i = 1; i < position - 1; i++)
            {
                pre = pre->next;
            }

            temp->next = pre->next;
            pre->next = temp;
        }
    }

    int deleteNodeStart()
    {
        if (head != nullptr)
        {
            int vl;
            node* temp = head;
            head = head->next;
            vl = temp->data;
            delete temp;
            return vl;
        }
    }

    int deleteNodeEnd()
    {
        if (head != nullptr)
        {
            if (head == tail)
            {
                int vl = head->data;
                delete head;
                head = nullptr;
                tail = nullptr;
                return vl;
            }

            int vl;
            node* temp;
            temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }

            vl = tail->data;
            delete tail;
            tail = temp;
            tail->next = nullptr;
            return vl;
        }
    }

    void deleteNodePosition(int position, int &vl, bool &can)
    {
        int currentPosition = 1;
        node* ride = head;
        for (int i = 0; ride != nullptr; i++)
        {
            currentPosition++;
            ride = ride->next;
        }
        delete ride;
        currentPosition--;

        if (head == nullptr && position >= 1)
        {
            std::cout << "Negalima pasalinti elemento pozicijoje {" << position << "}, nes sarasas yra tuscias! \n";
            can = false;
            return;
        }

        else if (position > currentPosition || position == 0)
        {
            std::cout << "Netinkama pozicija! \n";
            can = false;
            return;
        }

        else if (head != nullptr && position == currentPosition)
        {
            if (head == tail)
            {
                vl = head->data;
                delete head;
                head = nullptr;
                tail = nullptr;
                can = true;
            }
            else
            {
                node* cur;
                cur = head;
                while (cur->next != tail)
                {
                    cur = cur->next;
                }

                vl = tail->data;
                delete tail;
                tail = cur;
                tail->next = nullptr;
                can = true;
            }
        }

        else if (position == 1)
        {
            node* temp = head;
            head = head->next;
            vl = temp->data;
            delete temp;
            can = true;
        }

        else
        {
            node* pre = head;
            node* cur = head;

            for (int i = 1; i < position - 1; i++)
            {
                pre = pre->next;
            }

            for (int i = 1; i < position; i++)
            {
                cur = cur->next;
            }
            vl = cur->data;
            pre->next = cur->next;
            delete cur;
            can = true;
        }
    }

	void display()
	{
		node* rd;
		rd = head;
		while (rd != nullptr)
		{
			std::cout << rd->data << " ";
			rd = rd->next;
		}
        delete rd;
	}

    void search(int value)
    {
        if (head != nullptr)
        {
            node* temp = head;
            for (int i = 1; temp != nullptr; i++)
            {
                if (temp->data == value) std::cout << "Skaiciaus {" << value << "} pozicija sarase: " << i << "\n";
                temp = temp->next;
            }
            delete temp;
        }
        else
        {
            std::cout << "Skaiciaus {" << value << "} poziciju ieskoti negalima, nes sarasas yra tuscias! \n";
        }
    }

    void clear()
    {
        node* temp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }

        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void reverse()
    {
        if (!isEmpty())
        {
            node* pre = nullptr;
            node* nxt = nullptr;
            node* cur = head;
            tail = head;

            while (cur != nullptr)
            {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            head = pre;
        }
    }
};
