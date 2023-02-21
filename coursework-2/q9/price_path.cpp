#include <math.h>
#include <cstdlib>
#include "price_path.h"
#include <iostream>
#include <functional>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159
#endif
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define max(a,b)            (((a) > (b)) ? (a) : (b))

using namespace std;

// PATHGENERATOR Class

PathGenerator::PathGenerator(std::function<double(double, double, double, double)> pricing_engine,int num_steps,double S0,double r,double T,double sigma) : pricing_engine(pricing_engine),num_steps(num_steps),S0(S0), r(r), T(T), sigma(sigma){}

Path PathGenerator :: generate_path(){
    // Generate a Path object from the market parameters attributes of the object
    // Use the pricing_engine attribute to compute the increments of the stock price S
    // logs the average value of the Stock, the Max and the Max, for specific payoff function
    // Returns a Path object with these values
    double dt = T / static_cast<double>(num_steps);
    double S = S0;

    double min_S = INF;
    double max_S = -INF;
    double avg_S = 0; 
    vector<double> price_hist(num_steps+1);
    price_hist[0] = S;

    for (int i = 1; i <= num_steps; i++) {

        S = pricing_engine(S,r,sigma,dt);        
        min_S = min(S,min_S);
        max_S = max(S,max_S);
        avg_S += S/num_steps;
        price_hist[i] = S;
    }

    Path result = Path(min_S,max_S,avg_S,S,price_hist);
    return result;
}

double PathGenerator::get_r(){
    return r;
}
double PathGenerator::get_T(){
    return T;
}
double PathGenerator::get_sigma(){
    return sigma;
}
double PathGenerator::get_S0(){
    return S0;
}
// PATH class impl

Path :: Path(double min_S,double max_S,double avg_S,double ST,vector<double>) : min_S(min_S),max_S(max_S),avg_S(avg_S),ST(ST),price_hist(price_hist){}
Path :: Path(){}

double Path::get_ST(){
        return ST;
}
double Path::get_max_S(){
        return max_S;
}   
double Path::get_min_S(){
        return min_S;
}
double Path::get_avg_S(){
        return avg_S;
}
vector<double> Path::get_price_hist(){
    return price_hist;
}

// PRICING ENGINES

double randn() // generates a standard normal random variable
{
    double U = (double)rand() / RAND_MAX;
    double V = (double)rand() / RAND_MAX;
    double X = sqrt(-2 * log(U)) * cos(2 * M_PI * V);
    return X;
}


double BSM_pricing(double St_1,double r, double sigma, double dt){
    // Compute St from S(t-1) using the BlackScholesMerton model and market data
    // dSt = St ( r dt + σ dWt )
    double dW = sqrt(dt) * randn(); // generate a standard normal random variable
    double drift = r * St_1 * dt;
    double diffusion = St_1 * sigma  * dW; //
    double St = St_1 + drift + diffusion;
    return St;
}

double Bachelier_pricing(double St_1,double r, double sigma, double dt){
    // Compute St from S(t-1) using the Bachelier model and market data
    // dSt =r St dt + σ dWt,
    double dW = sqrt(dt) * randn(); // generate a standard normal random variable
    double St = St_1 + r * St_1 * dt + sigma * dW;
    return St;
}