#ifndef DISCRETE_RV
#define DISCRETE_RV
#include <vector>
#include <unordered_map>
#include <iostream>

#include "../rng/my_rng.hpp"

std::vector<int> disc_inv_trans(std::vector<std::pair<int, float>> events, int seq_len)
{
    float num;
    float curr;
    int pos;

    std::vector<int> res{};
    for (int i = 0; i < seq_len; i++)
    {   
        num = my_rng();
        pos = 0;
        curr = 0.0;
        std::cout << "rng: " << num << std::endl;
        while (pos < events.size() && curr < num)
        {
            curr += events[pos].second;
            std::cout << i << " " << curr << std::endl;
            pos++;
        }
        res.push_back(pos - 1);
    }
    return res;
}

#endif
