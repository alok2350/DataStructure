//binary search for desc numbers 
// 8 7 6 5 4 3 2 1   num:6


#include <iostream>
#include<vector>

int binary_search_desc(const std::vector<int>& vec,const int& num)
{
    int start = 0,end = vec.size()-1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(num == vec[mid])
            return mid;
        else if(num < vec[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::cout<< "Enter the numbers [DESC ONLY]: ";
    std::vector<int> vec;
    int elem{};
    while(std::cin >> elem && elem!=-1)
    {
        vec.push_back(elem);
    }
    int num{};
    std::cout<< "Enter the number to search: ";
    std::cin >> num;
    int index = binary_search_desc(vec,num);
    index == -1 ? std::cout<< "Number not found" : std::cout<<"Number found at index: " << index + 1;
    std::cout<<std::endl; 
    return 0;
}