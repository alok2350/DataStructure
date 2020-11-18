// Author: Alok Gupta
// Date created: 22.10.20
// Date Modified: 22.10.20
// Description: This programs displys the functionality of priority queue

#include <iostream>
#define size 10
class element
{
    int data{};
    int priority{};

public:
    element(int = 0, int = 0);
    int getdata();
    void setdata(int);
    int getpriority();
    void setpriority(int);
    void print();
};

element::element(int d, int p)
{
    data = d;
    priority = p;
}

int element::getdata()
{
    return data;
}
void element::setdata(int d)
{
    data = d;
}

int element::getpriority()
{
    return priority;
}
void element::setpriority(int p)
{
    priority = p;
}
void element::print()
{
    std::cout << "DATA: " << data << " "
              << "Priority: " << priority << std::endl;
}

class pqueue
{
    element arr[size];
    int rear{}, front{};

public:
    pqueue();
    void insert(element e);
    element remove();
    bool isFull();
    bool isEmpty();
};

pqueue::pqueue()
{
    front = rear = -1;
}
void pqueue::insert(element e)
{
    int i{};
    if (!isFull())
    {
        if (rear == -1)
        {
            arr[++rear] = e;
        }
        else
        {
            for (i = rear; i > front; i--)
            {
                if (e.getpriority() < arr[i].getpriority())
                {
                    arr[i + 1] = arr[i];
                }
                else
                {
                    break;
                }
            }
            arr[i + 1] = e;
            rear++;
        }
    }
    else
    {
        throw "overflow";
    }
}
element pqueue::remove()
{
    if (!isEmpty())
    {
        return arr[++front];
    }
    else
    {
        throw "underflow";
    }
}
bool pqueue::isFull()
{
    return rear == size - 1;
}
bool pqueue::isEmpty()
{
    return front == rear;
}

int main()
{
    pqueue pq;
    element e;
    try
    {
        for (int i = 0, j = 5; i < 5, j < 10; i++, j--)
        {
            e.setdata(i);
            e.setpriority(j);
            pq.insert(e);
        }
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }

    try
    {
        for (int i = 0; i < size; i++)
        {
            pq.remove().print();
        }
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    return 0;
}