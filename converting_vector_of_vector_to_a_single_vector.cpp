#include<iostream>
#include<vector>
#include<chrono>
int main()
{
    std::vector<std::vector<int>> vals{
        {0,0,0,0,0,0,0,0,0}, {1,1,1,1,1,1}, {2,2,2,2,2,2},
        {3,3,3,3,3,3,3,3,3}, {4,4,4,4,4,4,4}
    };
    const auto tstart = std::chrono::steady_clock::now();
    std::vector<int> myvector{};
    
    for(auto && v : vals)
    {
        myvector.insert(myvector.begin(), v.begin(), v.end());
    }
    const auto tend = std::chrono::steady_clock::now();
    std::cout << " done in " << std::chrono::duration_cast<std::chrono::nanoseconds>(tend - tstart).count() << " ns."
<< std::endl;
    for(auto it: myvector)
        std::cout << it << std::endl;

    /* std::vector<int> myvector1{};
    myvector1.assign(10, 0);
    myvector1.at(7) = 9;
    std::cout<< "myvector1.at(7): " << ++myvector1.at(7); */

    return 0;
}