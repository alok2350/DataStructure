//next alphabet
// a b c d e f g     b

#include<iostream>
#include<vector>

char next_alpha(std::vector<char> vec,char ch)
{
    char res{};
    int start = 0, end = vec.size()-1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(ch == vec[mid])
        {
            start = mid +1;
        }
        else if(ch  > vec[mid])
        {
            start = mid + 1;
        }
        else
        {
            res = vec[mid];
            end = mid - 1; 
        }
    }
    return res;
}

int main()
{
    std::vector<char> vec;
    char ch{},nch{};
    std::cout << "Enter the characters: ";
    while(std::cin >> ch && ch != 'z')
    {
        vec.push_back(ch);
    }
    std::cout<< "Enter the char to find the next alphabet: ";
    std::cin >> nch;
    char res = next_alpha(vec,nch);
    std::cout<<"Next alphabet of "<<ch<<" is: "<<res;
    std::cout<<std::endl;
    return 0;
}