// Author: Alok Gupta
// Date Created: 7-11-20
// Date Modified: 7-11-20
// Description: will print the incremental half pyramid in both oreintation

#include <iostream>

void left_half_incremental_pyramid(const int &level)
{
    for (int i = 1; i <= level; i++)
    {
        for (int j = i; j > 0; j--)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

void left_half_incremental_flipped_pyramid_(const int &level)
{
    for (int i = level; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << level - i + 1;
        }
        std::cout << std::endl;
    }
}

void right_half_incremental_pyramid(const int &level)
{
    for (int i = 1; i <= level; i++)
    {
        for (int k = level - i; k > 0; k--)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

void right_half_incremental_flipped_pyramid(const int &level)
{
    for (int i = level; i > 0; i--)
    {
        for (int k = level - i; k > 0; k--)
        {
            std::cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            std::cout << level - i + 1;
        }
        std::cout << std::endl;
    }
}

int main()
{
    int num_level{};
    std::cout << "Enter the number of levels: ";
    std::cin >> num_level;

    left_half_incremental_pyramid(num_level);
    std::cout << std::endl;
    left_half_incremental_flipped_pyramid_(num_level);
    std::cout << std::endl;

    right_half_incremental_pyramid(num_level);
    std::cout << std::endl;
    right_half_incremental_flipped_pyramid(num_level);
    std::cout << std::endl;

    return 0;
}