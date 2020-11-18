// Author: Alok Gupta
// Date Created: 7-11-20
// Date Modified: 7-11-20
// Description: will find the maximum subarray sum



#include<iostream>
int main()
{
    int arr[] = {1, -2, -1, 5, -1, 0, -1, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int max_till_here = arr[0];
    int current_max = arr[0];

    for(int i=1;i<size;i++)
    {
        current_max = std::max(arr[i],current_max + arr[i]);
        max_till_here = std::max(max_till_here,max_till_here + current_max);
    }

    std::cout << "The maximum subarray sum: ";
    std::cout << max_till_here;
    
    return 0;
}