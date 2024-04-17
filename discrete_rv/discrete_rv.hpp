// Chapter 4 mostly

#ifndef DISCRETE_RV
#define DISCRETE_RV
#include <vector>
#include <unordered_map>
#include <iostream>

#include "../rng/my_rng.hpp"

std::vector<int> disc_inv_trans_seq(std::vector<std::pair<int, float>> events, int seq_len)
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
        while (pos < events.size() && curr < num)
        {
            curr += events[pos].second;
            pos++;
        }
        res.push_back(pos - 1);
    }
    return res;
}

std::vector<int> gen_unif_perm(int low, int high, int seq_len)
{
    int len = high - low + 1;
    std::vector<int> start{};
    for (int i = low; i <= high; i++)
    {
        start.push_back(i);
    }
    std::vector<int> res{};
    for (int i = 0; i < std::min(len, seq_len); i++)
    {
        int curr = rand_int(0, len - i - 1);
        res.push_back(start[curr]);
        std::swap(start[curr], start[len - i - 1]);
    }

    return res;
}

std::vector<int> sim_geometric(float p, int seq_len)
{
    std::vector<int> res{};
    for (int i = 0; i < seq_len; i++)
    {
        float numerator = std::log(1 - my_rng());
        float denominator = std::log(1 - p);
        float frac = numerator / denominator;
        int int_res = (int)frac + 1;
        // std::cout << frac << " " << int_res << std::endl;
        res.push_back(int_res);
    }
    return res;
}

int first_success(float p)
{
    // geom but a sane return, not vec
    float num = std::log(1 - my_rng());
    float denom = std::log(1 - p);
    float frac = num / denom;
    int int_res = (int)frac + 1;
    return int_res;
}

std::vector<int> sim_bernoulli_seq(float p, int seq_len)
{
    std::vector<int> posits; // succesfull bernoulli
    int pos = 0;
    int cycle;
    while (pos < seq_len)
    {
        cycle = first_success(p);
        if (pos + cycle > seq_len)
        {
            break;
        }
        posits.push_back(pos + cycle);
        pos += cycle;
    }
    return posits;
}

int sim_poisson_indiv(float lambda)
{
    float U = my_rng();
    float p = std::exp(-lambda);
    int i = 0;
    float F = p; // F = F(i) is probability that r.v. is \leq i
    while (U >= F)
    {
        p = (lambda * p) / (i + 1);
        F += p;
        i++;
    }
    return i;
}

std::vector<int> sim_poisson_seq(float lambda, int seq_len)
{
    std::vector<int> res(seq_len, -1);
    for (int i = 0; i < seq_len; i++)
    {
        res[i] = sim_poisson_indiv(lambda);
    }
    return res;
}

int sim_binom_indiv(float p, int n){
    // Number of successes in n independent trials with each a success w/probability p
    float U = my_rng();
    float c = p/(1-p);
    float pr = std::pow(1-p, n);
    float F = pr; // F = F(i) is probability that r.v. is \leq i
    int i=0;
    while(U >= F){
        pr*=(c * (n-i)/(i+1));
        F += pr;
        i++;
    }
    return i;
}

std::vector<int> sim_binom_seq(float p, int n, int seq_len){
    std::vector<int> res(seq_len, -1);
    for(int i=0; i < seq_len; i++){
        res[i] = sim_binom_indiv(p, n);
    }
    return res;
}




#endif
