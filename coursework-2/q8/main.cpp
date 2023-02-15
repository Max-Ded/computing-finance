#include <iostream>
#include <math.h>
using namespace std;

double compute_d1(double St,double K, double r,double sigma,double t){
    return (log(St/K) + (r+sigma*sigma/2)*t)/(sigma*t);
}

double N(double x){
    return 0.5 + 0.5 * erf(x / sqrt(2.0));
}

class BlackScholesCallClass{
    public : 
        double s;
    public :
        double BlackScholesCallFunctor(double T,double K,double S,double r);
        double operator()(double sigma) const;
}

double BlackScholesCallClass :: operator()double sigma) const{
    this.s = sigma;
}
double BlackScholesCallClass :: BlackScholesCallFunctor(double T,double K,double S,double r){
    double d1 = compute_d1(S,K,r,s,T);
    double d2 = d1 - s * sqrt(T);

    return N(d1)*S - N(d2) * K * exp(-r*t);
}

template <typename T>
double interval_bisection(double y_target ,double left,double right,double epsilon,T functor){
    double midpoint = (right+left) / 2;
    double T_midpoint = functor(midpoint);
    while (abs(T_midpoint-y_target)>epsilon){
        if (T_midpoint < y_target){
            left=midpoint;
        }
        else{
            right = midpoint;
        }
        midpoint = (right+left) / 2;
        T_midpoint = functor(midpoint);
        }
    return midpoint;
}

double functor(double x){
    return x-5;
}

int main(){
    double y_target = 0;
    double left = -10;
    double right = 10;
    double epsilon = 1;

    double res = interval_bisection(y_target,left,right,epsilon,functor);
    cout << "Res is : " << res <<endl;
    return 0;
}