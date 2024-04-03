#ifndef RNG_HPP
#define RNG_HPP

#include <random>

int rand_int(int a, int b){
    if(a==b) return a;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distrib(a, b);
    
    return distrib(rng);
}

float my_rng(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(0.0, 1.0);

    float randomFloat = distr(gen);
    return randomFloat;
}


#endif