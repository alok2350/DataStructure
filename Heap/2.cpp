// k largest elements using priority queue
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
int main()
{
    int elem{};
    std::vector<int> vec;
    std::cout<<"Enter the elements: ";
    while(std::cin >> elem && elem!=-1)
    {
        vec.push_back(elem);
    }
    std::priority_queue<int,std::vector<int>,std::greater<int>> min;
    int k = 3;
    for(int i=0;i<vec.size();i++)
    {
        min.push(vec[i]);
        if(min.size() > k)
        {
            min.pop();
        }
    }
    while(min.size()>0)
    {
        std::cout<<min.top()<<" ";
        min.pop();
    }
    return 0;
}


