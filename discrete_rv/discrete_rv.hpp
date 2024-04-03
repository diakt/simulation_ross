// Chapter 4 mostly

#ifndef DISCRETE_RV
#define DISCRETE_RV
#include <vector>
#include <unordered_map>
#include <iostream>

#include "../rng/my_rng.hpp"

std::vector<int> disc_inv_trans_seq(std::vector<std::pair<int, float>> events, int seq_len){
    float num;
    float curr;
    int pos;

    std::vector<int> res{};
    for (int i = 0; i < seq_len; i++){
        num = my_rng();
        pos = 0;
        curr = 0.0;
        while (pos < events.size() && curr < num){
            curr += events[pos].second;
            pos++;
        }
        res.push_back(pos - 1);
    }
    return res;
}

std::vector<int> gen_unif_perm(int low, int high, int seq_len){
    int len = high - low + 1;
    std::vector<int> start{};
    for (int i = low; i <= high; i++){
        start.push_back(i);
    }
    std::vector<int> res{};
    for (int i = 0; i < std::min(len, seq_len); i++){
        int curr = rand_int(0, len - i - 1);
        res.push_back(start[curr]);
        std::swap(start[curr], start[len - i - 1]);
    }

    return res;
}


std::vector<int> sim_geometric(float p, int seq_len){
    std::vector<int> res {};
    for(int i=0; i < seq_len; i++){
        float numerator = std::log(1-my_rng());
        float denominator = std::log(1-p);
        float frac = numerator/denominator;
        int int_res = (int)frac+1;
        // std::cout << frac << " " << int_res << std::endl; 
        res.push_back(int_res);
    }
    return res;
}


int first_success(float p){
    //geom but a sane return, not vec
    float num = std::log(1-my_rng());
    float denom = std::log(1-p);
    float frac = num/denom;
    int int_res = (int)frac + 1;
    return int_res;
}

std::vector<int> sim_bernoulli_seq(float p, int seq_len){
    std::vector<int> posits; //succesfull bernoulli
    int pos = 0;
    int cycle;
    while(pos < seq_len){
        cycle = first_success(p);
        if(pos+cycle > seq_len){ break;}
        posits.push_back(pos+cycle);
        pos+=cycle;
    }
    return posits;
}

std::vector<int> sim_poisson(float lambda){
    return std::vector<int>{};
}

#endif
