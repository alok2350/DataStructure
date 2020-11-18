#include<iostream>
#define size 15
class cqueue
{
    int arr[size]{};
    int front{},rear{};
    public:
        cqueue();
        void insert(int);
        int remove();
        bool isEmpty();
        bool isFull();
};

cqueue::cqueue()
{
    front = rear = size-1;
}
void cqueue::insert(int data)
{
    if(!isFull())
    {
        rear = (rear+1)%size;
        arr[rear] = data;
    }
    else
    {
        throw "overflow";
    }
}
int cqueue::remove()
{
    if(!isEmpty())
    {
        front = (front+1) % size;
        return arr[front];
    }
    else
    {
        throw "underflow";
    }
}
bool cqueue::isEmpty()
{
    return rear == front;

}
bool cqueue::isFull()
{
    return front == (rear+1) % size;
}

int main()
{
    cqueue cq;
    try
    {
        for(int i=0;i<size-1;i++)
        {
            cq.insert(i*10);
        }
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    for(int i=0;i<size-1;i++)
    {
        int elem = cq.remove();
        std::cout<<elem<<" ";
    }
    return 0;
}