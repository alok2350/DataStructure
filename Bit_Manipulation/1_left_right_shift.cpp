#include<iostream>

void left_shift(int num,const int& times)
{
    std::cout << "Left Shifted " << times << " times: " << (num << times);
}

void right_shift(int num,const int& times)
{
    std::cout << "Right Shifted " << times << " times: " << (num >> times);
}

int main()
{
    int n{},i{};

    std::cout << "Enter the number: ";
    std::cin >> n;

    std::cout << "Enter the number to shift: ";
    std::cin >> i;

    left_shift(n,i);
    std::cout << std::endl;

    right_shift(n,i);
    std::cout << std::endl;
    
    return 0;

}