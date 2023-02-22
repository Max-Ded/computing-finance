#include "price_path.h"
#include <functional>
#include <string>

#ifndef Payoff_H
#define Payoff_H
class Payoff{
    private:
        double K;
        double V;
        double barrier;
        std::string option_desc;
        std::function<double(Path&)> payoff_func;
    public:
        Payoff(std::function<double(Path&, double,double)> func,double K,double barrier,std::string option_desc_string); // If payoff uses a strike price + a know barrier
        Payoff(std::function<double(Path&, double)> func,double K,std::string option_desc_string); // If payoff uses a strike price
        Payoff(std::function<double(Path&)> func,std::string option_desc_string); // If payoff doesn't use a strike price
        double get_V(Path& path);
        double get_K();
        double get_barrier();
        std::string get_option_desc();
};

double european_call(Path& path,double K);
double european_put(Path& path,double K);
double asian_call(Path& path,double K);
double asian_put(Path& path,double K);
double american_call(Path& path,double K);
double american_put(Path& path,double K);
double diff_payoff(Path& path);
double knock_out_european_call(Path& path,double K,double barrier);
double knock_out_european_put(Path& path,double K,double barrier);
double knock_in_european_call(Path& path,double K,double barrier);
double knock_in_european_put(Path& path,double K,double barrier);
#endif
