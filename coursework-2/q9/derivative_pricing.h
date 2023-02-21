#include "payoff.h"

class MonteCarloDerivatePricing{
    public:
    private:
        int N_sim;
        int num_steps;
        PathGenerator& path_generator;
        Payoff& payoff;
    public:
        MonteCarloDerivatePricing(int N_sim,PathGenerator& path_generator, Payoff& payoff);
        double price_one_path(Path& path);
        double priceDerivative();
};
