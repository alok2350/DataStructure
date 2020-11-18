// Author: Alok Gupta
// Date Created: 7-11-20
// Date Modified:7-11-20
// Description: will print half (left and right) pyramids in both orientation

#include <iostream>

void left_half_pyramid(const int &levels, const char &sym)
{
    for (int i = 1; i <= levels; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << sym;
        }
        std::cout << std::endl;
    }
}

void left_half_flipped_pyramid(const int &levels, const char &sym)
{
    for (int i = levels; i >= 1; i--)
    {
        for (int j = i; j > 0; j--)
        {
            std::cout << sym;
        }
        std::cout << std::endl;
    }
}

void right_half_pyramid(const int &levels, const char &sym)
{
    for (int i = 1; i <= levels; i++)
    {
        for (int k = levels - i; k > 0; k--)
        {
            std::cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            std::cout << sym;
        }
        std::cout << std::endl;
    }
}

void right_half_flipped_pyramid(const int &levels, const char &sym)
{
    for (int i = levels; i > 0; i--)
    {
        for (int k = levels - i; k > 0; k--)
        {
            std::cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            std::cout << sym;
        }
        std::cout << std::endl;
    }
}

int main()
{
    int num_level{};
    std::cout << "Enter the number of levels: ";
    std::cin >> num_level;
    char symbol{};
    std::cout << "Enter the character to print: ";
    std::cin >> symbol;

    left_half_pyramid(num_level, symbol);
    std::cout << std::endl;
    left_half_flipped_pyramid(num_level, symbol);
    std::cout << std::endl;

    right_half_pyramid(num_level, symbol);
    std::cout << std::endl;
    right_half_flipped_pyramid(num_level, symbol);
    std::cout << std::endl;

    return 0;
}