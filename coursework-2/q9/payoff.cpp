#include "payoff.h"
#include "price_path.h"
#include <iostream>
#include <functional>

#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))

Payoff::Payoff(std::function<double(Path&, double)> func,double K,std::string option_desc_string) : K(K),payoff_func(func),option_desc(option_desc_string){}

double Payoff::get_K(){
    // Get the strike price of the Payoff object
    return K;
}

double Payoff::get_V(Path& path){
    // Get the final payoff of a path object using the payoff_func attribute of object
    return payoff_func(path,K);
}

std::string Payoff::get_option_desc(){
    // get the description of the asset
    return option_desc;
}

double european_call(Path& path,double K){
    // Payoff of the european call
    double ST = path.get_ST();
    return max(ST-K,0);
}

double european_put(Path& path,double K){
    // Payoff of the european put
    double ST = path.get_ST();
    return max(K-ST,0);
}

double asian_call(Path& path,double K){
    // Payoff of the asian call
    double avg_S = path.get_avg_S();
    return max(avg_S-K,0);
}

double asian_put(Path& path,double K){
    // Payoff of the asian put
    double avg_S = path.get_avg_S();
    return max(K-avg_S,0);
}