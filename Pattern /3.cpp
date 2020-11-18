// Author: Alok Gupta
// Date Created: 7-11-20
// Date Modified: 7-11-20
// Description: will print the incremental(at each level) half pyramid in both oreintation


#include<iostream>

void left_half_incremental_at_each_levele_pyramid(const int& num_level)
{
    for(int i=1;i<=num_level;i++)
    {
        for(int j=1;j<=i;j++)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void left_half_incremental_overall_pyramid(const int& num_level)
{
    int x = 1;
    for(int i=1;i<=num_level;i++)
    {
        for(int j=1;j<=i;j++)
        {
            std::cout << x++ << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    int num_level{};
    std::cout << "Enter the number of levels: ";
    std::cin >> num_level;

    left_half_incremental_at_each_levele_pyramid(num_level);
    std::cout << std::endl;

    left_half_incremental_overall_pyramid(num_level);
    std::cout << std::endl;

    return 0;
}