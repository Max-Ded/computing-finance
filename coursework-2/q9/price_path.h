#define INF 9999999
#include <functional>
#include <vector>
#ifndef PathGenerator_H
#define PathGenerator_H

class Path{
    private:
        double min_S = -INF;
        double max_S = INF;
        double avg_S = 0; 
        double ST;
        double r;
        double dt;
        double sigma;
        double T;
        std::vector<double> price_hist;
    public:
        Path(double min_S,double max_S,double avg_S,double ST,std::vector<double> price_hist);
        Path(double min_S,double max_S,double avg_S,double ST,std::vector<double> price_hist,double r,double dt,double sigma,double T);
        Path();
        double get_ST();
        double get_max_S();
        double get_min_S();
        double get_avg_S();
        double get_r();
        double get_dt();
        double get_sigma();
        double get_T();
        std::vector<double> get_price_hist();
};

class PathGenerator{
    private:
        int num_steps;
        double S0;
        double r;
        double T;
        double sigma;
        std::function<double(double, double, double, double)> pricing_engine;
    public:
        PathGenerator(std::function<double(double, double, double, double)> pricing_engine,int num_steps,double S0,double r,double T,double sigma);
        Path generate_path();
        double get_r();
        double get_T();
        double get_sigma();
        double get_S0();
};
#endif

double BSM_pricing(double St_1,double r, double sigma, double dt);
double Bachelier_pricing(double St_1,double r, double sigma, double dt);
