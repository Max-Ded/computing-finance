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

class BlackScholesCallFunctor{
    private : 
        double T;
        double K;
        double S;
        double r;
    public :
        BlackScholesCallFunctor(double T,double K,double S,double r);
        double operator()(double sigma) const;
};

BlackScholesCallFunctor :: BlackScholesCallFunctor(double T,double K,double S,double r) : T(T), K(K), S(S) ,r(r){}

double BlackScholesCallFunctor :: operator()(double sigma) const{
    /// @brief Compute the call price with the class attribute and parameter sigma
    /// @param sigma volatility
    /// @return call price
    double d1 = compute_d1(S,K,r,sigma,T);
    double d2 = d1 - sigma * sqrt(T);
    double C = N(d1)*S - N(d2) * K * exp(-r*T);
    return C;
}

template <typename T>
double interval_bisection(double y_target ,double left,double right,double epsilon,T functor){
    /// @brief Find the pre-image of y_target w.r.t f (with epsilon precision) in a search interval
    /// @tparam T return type of the functor
    /// @param y_target point which we want ot find the pre-image of w.r.t f
    /// @param left left bound of the search interval
    /// @param right right bound of the search interval
    /// @param epsilon precision (functions stops when |f(x_target)-y_target| < epsilon)
    /// @param functor function f to evaluate, returns a type T
    /// @return pre-image of y_target

    double midpoint = (right+left) / 2; // compute center of the search imperial

    while (abs(functor(midpoint)-y_target)>epsilon){
        /// Iterate until convergence is reached (|f(x_target)-y_target| < epsilon)
        if (functor(midpoint) < y_target){
            // if midpoint is below y_target, move the left bound
            left=midpoint;
        }
        else{
            // if midpoint is above y_target, move the right bound
            right = midpoint;
        }
        midpoint = (right+left) / 2; // re-compute midpoint
        }
    return midpoint;
}


int main(){
    double T = 0.25;
    double K = 95;
    double S = 100;
    double r = 0.1;
    double C_target = 13.6953;

    double left = 0;
    double right = 0.9;
    double epsilon = 0.0001;

    cout << "Parameters : " << endl  << "T = " << T << endl << "K = " << K
         << endl << "S = " << S << endl << "r = " << r << endl << "C_target = "
         << C_target << endl << "Looking in the interval : [" << left << "," 
         << right << "] (precision : " << epsilon << ")" << endl << endl;

    BlackScholesCallFunctor functor = BlackScholesCallFunctor(T,K,S,r);

    double sigma = interval_bisection(C_target,left,right,epsilon,functor);
    cout << "Result : "<< endl << "Sigma = " << sigma <<endl;

    return 0;
}