// k closest numbers to num

#include<iostream>
#include<vector>
#include<queue>

int main()
{
    std::vector<int> vec;
    std::priority_queue<std::pair<int,int>> max;
    int elem{};
    int k = 3;
    int num = 7;

    std::cout<<"Enter the elements: ";
    while(std::cin >> elem && elem != -1)
    {
        vec.push_back(elem);
    }
    for(int i=0;i<vec.size();i++)
    {
        max.push({abs(vec[i]-num),vec[i]});
        if(max.size() > k)
        {
            max.pop();
        }
    }
    while(max.size() > 0)
    {
        std::cout<<max.top().second<<" ";
        max.pop();
    }
    return 0;
}