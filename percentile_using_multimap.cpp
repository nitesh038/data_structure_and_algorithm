#include<iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<set>
#include<cmath>

template<typename T>
class Percentile {
public:

  void insert(std::multimap<int, double> distribution)
  {
    typename std::multimap<int, double>::iterator it;
	for (it=distribution.begin(); it!=distribution.end(); it++) 
	{
		element_.insert(it->second);
	}

  }
  void calculate_percentile()
  {
    constexpr double tolerance_epsilon {0.00001f};
    for(auto it : element_)
        std::cout<< it << std::endl;

    double rank =  (percentile_/100)*(element_.size() -1) + 1 ;
    std::cout<< "Rank: " << rank << std::endl;

    if (fabsf(roundf(rank) - rank) <= tolerance_epsilon) 
    {
        if(rank <= 0)
            rank = 0;
        typename std::multiset<T>::iterator it = std::next(element_.begin(), rank-1);
        result_ = *it; 
    } 
    else
    {
        double ri{};
        auto rf = modf(rank, &ri);
         if(rank <= 0)
            rank = 0;
        if(rank >= element_.size())
            rank = element_.size()-1;

        typename std::multiset<T>::iterator it1 = std::next(element_.begin(), ri-1);
        typename std::multiset<T>::iterator it2 = std::next(element_.begin(), ri);

        result_ = (*it1) + (rf * ( (*it2) - (*it1) ));
    }
  }

  void set_percentile(const double& percentile)
  {
      percentile_ = percentile;
  }

  const double& get() const
  {
    return result_;
  }

  void clear()
  {
    element_.clear();
  }

private:
  double percentile_{};
  std::multiset<T> element_{};
  double result_{};
};

void calculate_percentile_0(std::multimap<int, double> distribution)
{
    Percentile<int> p;
    p.set_percentile(0);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_0: " << p.get() << std::endl;
}
/*void calculate_percentile_10(std::vector<int> distribution)
{
    Percentile<int> p;
    p.set_percentile(10);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_10: " << p.get() << std::endl;
}
void calculate_percentile_14(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(14);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_14: " << p.get() << std::endl;
}
void calculate_percentile_25(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(25);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_25: " << p.get() << std::endl;
}
void calculate_percentile_50(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(50);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_50: " << p.get() << std::endl;
}
void calculate_percentile_75(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(75);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_75: " << p.get() << std::endl;
}
void calculate_percentile_98(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(98);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_98: " << p.get() << std::endl;
}
void calculate_percentile_99(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(99);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_99: " << p.get() << std::endl;
}
void calculate_percentile_100(std::vector<int>distribution)
{
    Percentile<int> p;
    p.set_percentile(100);
    p.insert(distribution);
    p.calculate_percentile();
    std::cout<< "Result from calculate_percentile_100: " << p.get() << std::endl;
} */
int main()
{
     std::multimap<int, double> distribution;
    distribution.insert({5, 30.0});
    distribution.insert({1, 12.0});
    distribution.insert({5, 35.0});
    distribution.insert({1, 3.0});
    distribution.insert({5, 30.0});
    distribution.insert({1, 12.0});
    distribution.insert({2, 6.0});
    distribution.insert({1, 3.0});
    distribution.insert({1, 15.0});
    distribution.insert({2, 60.0});
    distribution.insert({1, 3.0});
    distribution.insert({4, 71.0});
    distribution.insert({2, 65.0});
    distribution.insert({3, 80.0});
        

    calculate_percentile_0(distribution);
    //std::vector<int> distribution{12, 60, 80, 71, 30};
   /*calculate_percentile_0(distribution);
     calculate_percentile_10(distribution);
    calculate_percentile_14(distribution);
    calculate_percentile_25(distribution);
    calculate_percentile_50(distribution);
    calculate_percentile_75(distribution);
    calculate_percentile_98(distribution);
    calculate_percentile_99(distribution);
    calculate_percentile_100(distribution); */
    
    return 0;
}
 