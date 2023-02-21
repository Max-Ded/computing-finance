#include "payoff.h"
#include "price_path.h"
#include <iostream>
#include <functional>

#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))


Payoff::Payoff(std::function<double(Path&, double,double)> func,double K,double barrier,std::string option_desc_string) : K(K),barrier(barrier),option_desc(option_desc_string){
    // If we want to implement a payoff with a barrier (example : knock out european call)
    payoff_func = [=](Path& p){return func(p,K,barrier);};
}
Payoff::Payoff(std::function<double(Path&, double)> func,double K,std::string option_desc_string) : K(K),option_desc(option_desc_string){
    // If we want to implement a payoff with a strike (example : european call)
    payoff_func = [=](Path& p){return func(p,K);};
}
Payoff::Payoff(std::function<double(Path&)> func,std::string option_desc_string) : payoff_func(func),option_desc(option_desc_string){
    // If we want to implement a payoff with no paremeters other than the path (example : a diff "option")
}

double Payoff::get_K(){
    // Get the strike price of the Payoff object
    return K;
}

double Payoff::get_barrier(){
    // Get the barrier of the Payoff object
    return barrier;
}

double Payoff::get_V(Path& path){
    // Get the final payoff of a path object using the payoff_func attribute of object
    return payoff_func(path);
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

double knock_out_european_call(Path& path,double K,double barrier){
    // Payoff of knock-out european call
    double ST = path.get_ST();
    double max_S = path.get_max_S();
    return max_S < barrier ? max(ST-K,0) : 0;
}

double knock_out_european_put(Path& path,double K,double barrier){
    // Payoff of knock-out european put
    double ST = path.get_ST();
    double max_S = path.get_max_S();
    return max_S < barrier ? max(K-ST,0) : 0;
}

double knock_in_european_call(Path& path,double K,double barrier){
    // Payoff of knock-out european call
    double ST = path.get_ST();
    double min_S = path.get_min_S();
    return min_S > barrier ? max(ST-K,0) : 0;
}

double knock_in_european_put(Path& path,double K,double barrier){
    // Payoff of knock-out european put
    double ST = path.get_ST();
    double min_S = path.get_min_S();
    return min_S > barrier ? max(K-ST,0) : 0;
}

double diff_payoff(Path& path){
    // Payoff of a dummy option that always return max(St) - min(St)
    return path.get_max_S() - path.get_min_S();
}