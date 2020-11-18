//first and last occurrence of a number (duplicates are allowed)
//1 2 2 2 2 2 3 4 5 6 7    2
#include<iostream>
#include<vector>

int first_index(const std::vector<int>& vec,const int& num)
{
    int start = 0,end = vec.size()-1;
    int res = -1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if( num == vec[mid])
        {
            res = mid;
            end = mid - 1;
        }
        else if(num < vec[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int last_index(const std::vector<int>& vec, int& num)
{
    int start = 0,end = vec.size()-1;
    int res = -1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if( num == vec[mid])
        {
            res = mid;
            start = mid + 1;
        }
        else if(num < vec[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
    return 0;
}
int main()
{
    std::cout<< "Enter the numbers: ";
    std::vector<int> vec;
    int elem{};
    int num{};
    while(std::cin >> elem && elem != -1)
    {
        vec.push_back(elem);
    }
    std::cout<< "Enter the number to search: ";
    std::cin >> num;
    int findex = first_index(vec,num);
    int lindex = last_index(vec,num);
    std::cout<< "First index of "<<num <<" is : "<< findex + 1;
    std::cout<< "\nlast index of "<<num <<" is : "<< lindex + 1 ;
    std::cout<<std::endl;
    return 0;
}