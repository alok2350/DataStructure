#include<iostream>


int main()
{
    int num{};
    std::cout << "Enter the number: ";
    std::cin >> num;
    int copy_num = num;
    int count{};
    while(num > 0)
    {
        count++;
        num = num & (num-1);
    }
    if(count == 1)
    {
        std::cout << copy_num << " is power of 2.";
    }
    else
    {
        std::cout << copy_num << " is not power of 2.";
    }
    std::cout << std::endl;
    return 0;
}