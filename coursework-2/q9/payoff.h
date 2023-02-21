#include "price_path.h"
#include <functional>
#include <string>

#ifndef Payoff_H
#define Payoff_H
class Payoff{
    private:
        double K;
        double V;
        std::string option_desc;
        std::function<double(PricePath&, double)> payoff_func;
    public:
        Payoff(std::function<double(PricePath&, double)> func,double K,std::string option_desc_string); // If payoff uses a strike price
        double get_V(PricePath& ppath);
        double get_K();
        std::string get_option_desc();
};

double european_call(PricePath& ppath,double K);
double european_put(PricePath& ppath,double K);
double asian_call(PricePath& ppath,double K);
double asian_put(PricePath& ppath,double K);
#endif
