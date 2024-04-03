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

std::vector<int> gen_unif_perm(int low, int high){
    int len = high - low + 1;
    std::vector<int> start{};
    for (int i = low; i <= high; i++){
        start.push_back(i);
    }
    std::vector<int> res{};
    for (int i = 0; i < len; i++){
        int curr = rand_int(0, len - i - 1);
        res.push_back(start[curr]);
        std::swap(start[curr], start[len - i - 1]);
    }

    return res;
}

#endif
