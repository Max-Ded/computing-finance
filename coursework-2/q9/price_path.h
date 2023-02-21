#define INF 9999999

#ifndef PricePath_H
#define PricePath_H

class PricePath{
    private:
        int num_steps;
        double S0;
        double r;
        double T;
        double sigma;
        double ST;
        double min_S = -INF;
        double max_S = INF;
        double avg_S = 0;
    public:
        PricePath(int num_steps,double S0,double r,double T,double sigma);
        double get_ST();
        double get_max_S();
        double get_min_S();
        double get_avg_S();
};
#endif
