//binary search when order is not known

#include<iostream>
#include<vector>

int binary_search_asc(const std::vector<int>& vec,const int& num)
{
    int start = 0, end = vec.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (num == vec[mid])
            return mid;
        else if (num < vec[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
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
    std::cout << "Enter the numbers [Either ASC/DESC]: ";
    std::vector<int> vec;
    int elem{};
    int num{};
    while(std::cin >> elem && elem != -1)
    {
        vec.push_back(elem);
    }
    std::cout<<"Enter the number to search: ";
    std::cin >> num;
    int index = vec[0] < vec[1] ? binary_search_asc(vec,num) : binary_search_desc(vec,num);
    index == -1 ? std::cout << "Element not found" : std::cout << "Element found at index " << index;
    std::cout << std::endl;
    return 0;
}