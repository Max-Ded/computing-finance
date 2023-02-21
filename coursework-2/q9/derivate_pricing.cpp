#include <iostream>
#include "derivative_pricing.h"
#include "price_path.h"
#include "payoff.h"
#include "math.h"

MonteCarloDerivatePricing :: MonteCarloDerivatePricing(int N_sim,int num_steps,double S0,double sigma,double r, double T, Payoff& payoff) : N_sim(N_sim),num_steps(num_steps),S0(S0),sigma(sigma),r(r),T(T),payoff(payoff){
    std :: cout << "Parameters : " << std ::endl  << "N sim : " << N_sim << std ::endl 
                << "T = " << T << std ::endl << "S = " << S0 << std ::endl
                << "r = " << r << std ::endl << "sigma : " << sigma << std::endl;
}

double MonteCarloDerivatePricing :: price_one_path(){
    PricePath ppath = PricePath(num_steps,S0, r, T, sigma);
    return payoff.get_V(ppath)* exp(-r * T);
}

double MonteCarloDerivatePricing :: priceDerivative(){
    double avg_derivative_price = 0.;
    for (int i=0;i<N_sim;i++){
        double one_path_price = price_one_path();
        avg_derivative_price += one_path_price;
    }
    avg_derivative_price = avg_derivative_price/N_sim;
    return avg_derivative_price;
}


// double MonteCarloDerivatePricing :: priceDerivative(){
//     double avg_derivative_price = 0.;
//     for (int i=0;i<N_sim;i++){
//         PricePath ppath = PricePath(num_steps,S0, r, T, sigma);
//         double res = payoff.get_V(ppath);
//         std :: cout << "Price : " << ppath.get_ST() << " PF : " << res << " K = " << payoff.get_K() << std::endl;
//         avg_derivative_price += res;
//     }
//     avg_derivative_price = avg_derivative_price/N_sim;
//     return avg_derivative_price;
// }