#include <random>  

class Rand_int { 
public: 
Rand_int(int low,  int high)
      :dist{low,high} { 
	re.seed(std::random_device()());
} 
      
int operator()() { return dist(re); } 

private: 
default_random_engine re; 
uniform_int_distribution<> dist; 
};
