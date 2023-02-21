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
        std::function<double(Path&, double)> payoff_func;
    public:
        Payoff(std::function<double(Path&, double)> func,double K,std::string option_desc_string); // If payoff uses a strike price
        double get_V(Path& path);
        double get_K();
        std::string get_option_desc();
};

double european_call(Path& path,double K);
double european_put(Path& path,double K);
double asian_call(Path& path,double K);
double asian_put(Path& path,double K);
#endif
