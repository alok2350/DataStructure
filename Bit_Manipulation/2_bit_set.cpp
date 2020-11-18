#include<iostream>

int main()
{
    int num{};
    std::cout << "Enter the number: ";
    std::cin >> num;
    int i{};
    std::cout << "Enter the bit number to check whether it is set or not: ";
    std::cin >> i;

    int f = 1;
    f = f << i;
    if(num & f)
    {
        std::cout << i << "th bit is set in " << num;
    }
    else
    {
         std::cout << i << "th bit is not set in " << num;
    }
    std::cout << "\n";
    return 0;
    
}