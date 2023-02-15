#include <iostream>
#include <math.h>

using namespace std;

double compute_d1(double S,double K, double r,double sigma,double t){
    /// @brief Compute the d1 factor of the BSM model
    /// @param S Spot price
    /// @param K Strike price
    /// @param r interest rate
    /// @param sigma volatility
    /// @param t time to expiration
    /// @return d1
    return (log(S/K) + (r+sigma*sigma/2)*t)/(sigma*sqrt(t));
}

double N(double x){
    /// @brief Compute the CDF of a N(0,1) normal law
    /// @param x positive real to evalute N
    /// @return N(x)
    return 0.5 + 0.5 * erf(x / sqrt(2.0));
}
double compute_c(double S,double K, double r, double sigma,double t){
    /// @brief Compute the BSM price of a call
    /// @param S Spot price
    /// @param K Strike price
    /// @param r interest rate
    /// @param sigma volatility
    /// @param t time to expiration
    /// @return Call price
    double d1 = compute_d1(S,K,r,sigma,t);
    double d2 = d1 - sigma * sqrt(t);

    return N(d1)*S - N(d2) * K * exp(-r*t);
}

int main(){

    double t = 0.25;
    double K = 95;
    double S = 100;
    double r = 0.1;
    double sigma = 0.5;

    double C = compute_c(S,K,r,sigma,t);

    cout << "Parameters : " << endl  << "t = " << t << endl << "K = " << K
         << endl << "S = " << S << endl << "r = " << r << endl << "sigma = "
         << sigma << endl << endl << "C = " << C << endl; 

    return 0;
}