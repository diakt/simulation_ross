#ifndef RNG_HPP
#define RNG_HPP

#include <random>


float my_rng(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distr(0.0, 1.0);
    float randomFloat = distr(gen);
    return randomFloat;
}


#endif