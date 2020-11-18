#include<iostream>
#define size 5
class queue
{
    int arr[size]{};
    int front{},rear{};
    public:
        queue();
        void insert(int);
        int remove();
        bool isEmpty();
        bool isFull();
        void print();
};
void queue::print()
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

queue::queue()
{
    front = rear = -1;
}
void queue::insert(int data)
{
    if(!isFull())
    {
        arr[++rear] = data;
    }
    else
    {
        throw "Overflow";
    }
}
int queue::remove()
{
    if(!isEmpty())
    {
        return arr[++front];
    }
    else
    {
        throw "underflow";
    }
}
bool queue::isEmpty()
{
    return rear == front;
}
bool queue::isFull()
{
    return rear == size-1;

}
int main()
{
    queue q;
    try
    {
        for(int i=0;i<5;i++)
        {
        q.insert(i*10);
        }   
    }
    catch(const char* msg)
    {
        std::cout<<msg<<std::endl;
    }
    for(int i=0;i<5;i++)
    {
        int e = q.remove();
        std::cout<<e<<" ";
    }
    return 0;
}



