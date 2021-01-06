#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

int find_element_using_binary_search(std::vector<int> input, int key)
{
    int low = 0;
    int high = input.size();
    double mid {std::round(input.size()/2)};
    while(low <= high)
    {
        if(key == input[mid])
        {
            return mid;
        }
        else if(key > input[mid])
        {
            low = mid+1;
        }
        else if(key < input[mid])
        {
            high = mid-1;
        }
        mid = std::round((low + high)/2);
    }
    return -1;
}

int main()
{
    std::vector<int> input{};
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

    int position = find_element_using_binary_search(input, data);
    if(position == -1)
        std::cout<< "Element not found\n";
    else
    {
        std::cout<<"Element found at index: "<< position<<std::endl;
    }
    return 0;
}