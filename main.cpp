
#include <iostream>
#include "rng/my_rng.hpp"
#include "discrete_rv/discrete_rv.hpp"
#include <vector>


int main(){
    std::vector<std::pair<int,float>> probs {{1, 0.3}, {2, 0.15}, {3, 0.25}, {4, 0.3}};
    std::vector<int> res = sim_geometric(0.5, 100000000);
    float run = 0;
    for(int x: res){
        run += x;
    }
    std::cout << run/res.size() << std::endl;
    
    
    return 0;
}