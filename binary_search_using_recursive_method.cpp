#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

std::vector<int> input{};

int find_element_using_binary_search(int low, int high, int key)
{
    if(low == high)
    {
        if(key == input[low])
        {
            return low;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        double mid = std::round((low + high)/2);
        if(key == input[mid])
        {
             return mid;
        }
        else
        {
            if(key > input[mid])
            {
                find_element_using_binary_search(mid+1, high, key);
            }
            else
            {
                find_element_using_binary_search(low, mid-1, key);
            }
        }
    }
}

int main()
{
    int number{};
    std::cout<<"Please enter the number of elements in array: \n";
    std::cin>> number;

    int data{};
    std::cout<<"Please enter the numbers in array: \n";
    for(int counter=0; counter<number; counter++)
    {
        std::cin>>data;
        input.push_back(data);
    }
    //Binary Search requires sorted array
    std::sort(input.begin(), input.end());

    std::cout<<"Please enter the number to find: ";
    std::cin >> data;
    int low = 0;
    int high = input.size();
    int position = find_element_using_binary_search(low, high, data);
    if(position == -1)
        std::cout<< "Element not found\n";
    else
    {
        std::cout<<"Element found at index: "<< position<<std::endl;
    }
    return 0;
}