// k smallest elements

#include<iostream>
#include<vector>
#include<queue>
int main()
{
    int elem{};
    std::vector<int> vec; 
    std::cout<< " Enter the elements: ";

    while(std::cin >> elem && elem!=-1)
    {
        vec.push_back(elem);
    }
    std::priority_queue<int> max;
    int k = 3;
    for(int i=0;i<vec.size();i++)
    {
        max.push(vec[i]);
        while(max.size() > k)
        {
            max.pop();
        }
    }
    std::cout<<"\n Kth smallest element in the vector: "<< max.top()<<std::endl;
    return 0;
}