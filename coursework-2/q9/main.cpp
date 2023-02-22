#include <iostream>
#include "derivative_pricing.h"
#include "payoff.h"
#include "price_path.h"
#include "price_path.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


/*
PathGenerator obj with market param (S0,r,T,sigma,pricing_engines)=> generates (with the pricing_engine logic) => Path obj with final price/avg_price/min_price_max_price
Payoff Obj used to compute payoff of a path obj (with a payoff function and a strike price)

MonteCarloDerivatePricing with the PathGenerator obj generates a bunch of path, computes the payoff with the payoff obj, and averages the prices

*/
using namespace std;

int main(){

    srand(time(0));

    int N_sim = 10000;
    double S0 = 100;
    double sigma = 0.5;
    double r=0.1;
    double T = 0.25;
    double K = 105.;
    int num_steps = 100;
    double barrier = 130;

    
    std::function<double(Path&, double)> payoff_func = &american_call;
    Payoff payoff = Payoff(payoff_func,95,"American call");

    // std::function<double(Path&, double,double)> payoff_func = &knock_out_european_call;
    // Payoff payoff = Payoff(payoff_func,K,barrier,"Knock-out European call");

    std::function<double(double, double, double, double)> pricing_engine = &BSM_pricing;
    PathGenerator path_generator = PathGenerator(pricing_engine,num_steps,S0,r,T,sigma);
    
    MonteCarloDerivatePricing mc_pricing = MonteCarloDerivatePricing(path_generator,payoff);
    std :: cout << "Option type : "<< payoff.get_option_desc() << std::endl << "K (if set) : " << payoff.get_K() <<endl << "Barrier (if set) : " << payoff.get_barrier() << std::endl;

    double price = mc_pricing.priceDerivative(N_sim);
        
    cout << "Monte Carlo price : " << price << endl;

    return 0;
}