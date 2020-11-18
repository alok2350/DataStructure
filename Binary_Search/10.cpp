// find the ciel of a number
// 1 2 3 4 5 6 7 8     5

#include<iostream>
#include<vector>

int ciel_num(std::vector<int>& vec,int num)
{
    int res{};
    int start = 0,end = vec.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) /2;
        if(num < vec[mid])
        {
            res = vec[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int main()
{
    std::vector<int> vec;
    int elem{};
    std::cout << "Enter the numbers: ";
    while(std::cin >> elem && elem != -1)
    {
        vec.push_back(elem);
    }
    int num{};
    std::cout<< "Enter the number to find floor: ";
    std::cin >> num;
    int result = ciel_num(vec,num);
    std::cout<<"Ceil of "<<num <<" is: "<<result;
    std::cout<<std::endl;
    return 0;
}