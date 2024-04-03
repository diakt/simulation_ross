
#include <iostream>
#include "rng/my_rng.hpp"
#include "discrete_rv/discrete_rv.hpp"
#include <vector>


int main(){
    std::vector<std::pair<int,float>> probs {{1, 0.3}, {2, 0.15}, {3, 0.25}, {4, 0.3}};
    std::vector<int> res = sim_bernoulli_seq(0.01, 1000);

    for(int x: res){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    
    
    return 0;
}