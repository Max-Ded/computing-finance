#include <iostream>
#include "derivative_pricing.h"
#include "price_path.h"
#include "payoff.h"
#include "math.h"

using namespace std;

MonteCarloDerivatePricing :: MonteCarloDerivatePricing(PathGenerator& path_generator, Payoff& payoff) : path_generator(path_generator),payoff(payoff){
    // PathGenerator Object to generate prices using a pricing engine (more in price_path.cpp)
    // Payoff object to compute the payoff of a specific path using the payoff_func attribute
    cout << "Parameters :" << endl << "S0 : " << path_generator.get_S0() << endl << "T : " << path_generator.get_T() << endl << "r : " << path_generator.get_r() << endl << "sigma : " << path_generator.get_sigma() <<endl;
}

double MonteCarloDerivatePricing :: price_one_path(Path& path){
    // Compute the discounted payoff of a Path object using the payoff attribute of the MonteCarloDerivatePricing object
    return payoff.get_V(path)* exp(-path_generator.get_r() * path_generator.get_T());
}

double MonteCarloDerivatePricing :: priceDerivative(int N_sim){
    // Generates N_sim Path object using the PathGenerator attribute
    // Computes the payoff for each Path object
    // Compute and return the average payoff over N_sim
    double avg_derivative_price = 0.;
    Path p;
    double discounted_derivative_price;
    for (int i=0;i<N_sim;i++){
        p = path_generator.generate_path();
        discounted_derivative_price = price_one_path(p);
        avg_derivative_price += discounted_derivative_price;
    }
    avg_derivative_price = avg_derivative_price/N_sim;
    return avg_derivative_price;
}
