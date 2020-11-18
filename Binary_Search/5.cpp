//count the number of times a number is appeared (num are sorted and dup are allowed)
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
int count_occur(std::vector<int>& vec,int num)
{
    int findex = first_index(vec,num);
    int lindex = last_index(vec,num);
    return lindex - findex + 1;
}
int main()
{
    std::cout<<"Enter the numbers: ";
    std::vector<int> vec;
    int elem{};
    int num{};
    while(std::cin >> elem && elem != -1)
    {
        vec.push_back(elem);
    }
    std::cout<<"Enter the number to count: ";
    std::cin >> num;
    int count = count_occur(vec,num);
    std::cout<<"Number appered "<< count << " times";
    std::cout<<std::endl;
    return 0;
}