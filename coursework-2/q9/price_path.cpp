#include <math.h>
#include <cstdlib>
#include "price_path.h"
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159
#endif
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))

double randn() // generates a standard normal random variable
{
    double U = (double)rand() / RAND_MAX;
    double V = (double)rand() / RAND_MAX;
    double X = sqrt(-2 * log(U)) * cos(2 * M_PI * V);
    return X;
}


PricePath::PricePath(int num_steps,double S0,double r,double T,double sigma) : num_steps(num_steps),S0(S0), r(r), T(T), sigma(sigma){
    double dt = T / static_cast<double>(num_steps);
    double S = S0;

    for (int i = 1; i <= num_steps; i++) {
        double dW = sqrt(dt) * randn(); // generate a standard normal random variable
        double drift = r * S * dt;
        double diffusion = sigma * S * dW;
        S = S + drift + diffusion;
        min_S = min(S,min_S);
        max_S = max(S,max_S);
        avg_S += S/num_steps;
    }

    ST = S;
}
double PricePath::get_ST(){
        return ST;
}
double PricePath::get_max_S(){
        return max_S;
}   
double PricePath::get_min_S(){
        return min_S;
}
double PricePath::get_avg_S(){
        return avg_S;
}

