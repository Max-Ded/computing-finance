#include "payoff.h"

class MonteCarloDerivatePricing{
    public:
    private:
        int N_sim;
        int num_steps;
        double S0;
        double sigma;
        double r;
        double T;
        Payoff& payoff;
    public:
        MonteCarloDerivatePricing(int N_sim,int num_steps,double S0,double sigma,double r, double T, Payoff& payoff);
        double price_one_path();
        double priceDerivative();
};
