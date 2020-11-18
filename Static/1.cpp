#include<iostream>

void caller();
static int x = 10;     //limiting the scope to this file only
static void print_num()
{
    static int y = 0 ;
    std::cout << y << std::endl;
    y = y+1;
}
int main()
{
    caller();
    return 0;
}