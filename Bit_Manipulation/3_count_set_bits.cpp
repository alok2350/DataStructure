#include<iostream>
void setbit(std::uint32_t num)
{
    std::uint32_t copy_num = num;
    std::uint32_t count{};
    while(num > 0)
    {
        if((num & 1) > 0)
        {
            count++;
        }
        num = num >> 1;
    }
    std::cout << "Total Set Bits in " << copy_num <<" is: " << count;
    std::cout << "\n";

}
void setbit_other(std::uint32_t num)
{
    std::uint32_t copy_num = num;
    std::uint32_t count{};
    while(num > 0)
    {
        count++;
        num = num & (num-1);
    }
    std::cout << "Total Set Bits in " << copy_num <<" is: " << count;
    std::cout << "\n";
}


int main()
{
    std::uint32_t num{};
    std::cout << "Enter the number to count the set bits: ";
    std::cin >> num;
    setbit(num);
    setbit_other(num);
    return 0;
}