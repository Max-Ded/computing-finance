#include "payoff.h"

class MonteCarloDerivatePricing{
    public:
    private:
        PathGenerator& path_generator;
        Payoff& payoff;
    public:
        MonteCarloDerivatePricing(PathGenerator& path_generator, Payoff& payoff);
        double price_one_path(Path& path);
        double priceDerivative(int N_sim);
};
