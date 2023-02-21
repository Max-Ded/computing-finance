#include "payoff.h"
#include "price_path.h"
#include <iostream>
#include <functional>

#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))

Payoff::Payoff(std::function<double(PricePath&, double)> func,double K,std::string option_desc_string) : K(K),payoff_func(func),option_desc(option_desc_string){}

double Payoff::get_K(){
    return K;
}

double Payoff::get_V(PricePath& ppath){
    return payoff_func(ppath,K);
}

std::string Payoff::get_option_desc(){
    return option_desc;
}

double european_call(PricePath& ppath,double K){
    double ST = ppath.get_ST();
    return max(ST-K,0);
}

double european_put(PricePath& ppath,double K){
    double ST = ppath.get_ST();
    return max(K-ST,0);
}

double asian_call(PricePath& ppath,double K){
    double avg_S = ppath.get_avg_S();
    return max(avg_S-K,0);
}

double asian_put(PricePath& ppath,double K){
    double avg_S = ppath.get_avg_S();
    return max(K-avg_S,0);
}