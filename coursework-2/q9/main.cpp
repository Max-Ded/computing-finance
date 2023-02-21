#include <iostream>
#include "derivative_pricing.h"
#include "payoff.h"
#include "price_path.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main(){

    srand(time(0));

    int N_sim = 1000;
    double S0 = 100;
    double sigma = 0.5;
    double r=0.1;
    double T = 0.25;
    double K = 95.;
    int num_steps = 100;

    std::function<double(PricePath&, double)> payoff_func = &european_call;

    Payoff payoff = Payoff(payoff_func,95,"European call");
    
    MonteCarloDerivatePricing mc_pricing = MonteCarloDerivatePricing(N_sim,num_steps,S0,sigma,r,T,payoff);
    std :: cout << "Option type : "<< payoff.get_option_desc() << std::endl << "K = " << payoff.get_K() << std::endl;

    double price = mc_pricing.priceDerivative();
        
    cout << "Monte Carlo price : " << price << endl;

    return 0;
}

// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// double monte_carlo_price(double S0, double r, double sigma, double T, double K, int N)
// {
//     double dt = T / static_cast<double>(N);
//     double total_payoff = 0.0;
//     srand(time(0)); // seed the random number generator with the current time
//     for (int i = 0; i < N; i++) {
//         double eps = rand() / static_cast<double>(RAND_MAX);
//         double z = sqrt(-2.0 * log(eps)) * cos(2.0 * M_PI * eps);
//         double S = S0 * exp((r - sigma*sigma/2) * dt + sigma * sqrt(dt) * z);
//         double payoff = max(S - K, 0.0);
//         total_payoff += payoff;
//     }
//     double expected_payoff = total_payoff / static_cast<double>(N);
//     double call_price = expected_payoff * exp(-r * T);
//     return call_price;
// }

// int main()
// {
//     double S0 = 100;  // initial stock price
//     double r = 0.1;  // risk-free interest rate
//     double sigma = 0.5;  // volatility
//     double T = .25;  // time to maturity
//     double K = 95;  // strike price
//     int N = 1000000; // number of simulations

//     double price = monte_carlo_price(S0, r, sigma, T, K, N);
//     cout << "The Monte Carlo price of the call option is " << price << endl;

//     return 0;
// }