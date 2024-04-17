
#include <iostream>
#include "rng/my_rng.hpp"
#include "discrete_rv/discrete_rv.hpp"
#include <vector>


int main(){
    float lambda = 0.5f;
    std::vector<int> res = sim_binom_seq(.5, 6, 10);

    for(int x: res){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    
    
    return 0;
}