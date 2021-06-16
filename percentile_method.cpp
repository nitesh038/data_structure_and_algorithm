// C++ program to calculate Percentile of Students 
  
#include<iostream> 
#include<vector>
#include<algorithm>
#include <cmath>
  
  
// Function to calculate the percentile 
void percentile(std::vector<double>marks, double percentile) 
{ 
    constexpr double tolerance_epsilon {0.00001f};

    std::sort(marks.begin(),marks.end());
    for(auto it : marks)
        std::cout<< it << std::endl;
 
    //1)Arrange n number of data points in ascending order: x1, x2, x3, ... xn
    //2)Calculate the rank r for the percentile p you want to find: r = (p/100) * (n - 1) + 1
    //3)If r is an integer then the data value at location r, xr, is the percentile p: p = xr
    //3)If r is not an integer, p is interpolated using ri, the integer part of r, and rf, the fractional part of r:
    //p = xri + rf * (xri+1 - xri)

    auto rank =  (percentile/100)*(marks.size() -1) + 1 ;
    std::cout<< "Rank: " << rank << std::endl;


    if (fabsf(roundf(rank) - rank) <= tolerance_epsilon) 
    {
        if(rank <= 0)
            rank = 0;
        std::cout<< "Result: " << marks.at(rank-1) << std::endl;
    } 
    else
    {
        double ri{};
        auto rf = modf(rank, &ri);//fractional part
         if(rank <= 0)
            rank = 0;
        if(rank >= marks.size())
            rank = marks.size()-1;

        auto result = marks.at(ri-1) + (rf * (marks.at(ri) - marks.at(ri-1)));
        std::cout<< " Result : " << result << std::endl;
    }

} 
  
// Driver Code 
int main() 
{ 
    std::vector<double> StudentMarks{ 12, 60, 80, 71, 30 }; 
    percentile(StudentMarks, 0); 
    percentile(StudentMarks, 10); 
    percentile(StudentMarks, 14); 
    percentile(StudentMarks, 25); 
    percentile(StudentMarks, 50); 
    percentile(StudentMarks, 75); 
    percentile(StudentMarks, 98); 
    percentile(StudentMarks, 99); 
    percentile(StudentMarks, 100); 

    return 0; 
} 