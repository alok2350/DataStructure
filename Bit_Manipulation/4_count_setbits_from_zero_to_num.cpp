#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ans{};
    int num{};
    std::cout << "Enter the number: ";
    std::cin >> num;
    for(int i = 0 ; i <= num; i++)
    {
        int count{};
        int num = i;
        while(num > 0)
        {
            count++;
            num = num & (num-1);
        }
        ans.push_back(count);
    }
    for(auto elem : ans)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}