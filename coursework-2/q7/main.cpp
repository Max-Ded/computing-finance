#include <iostream>
#include <math.h>

using namespace std;

double compute_d1(double St,double K, double r,double sigma,double t){
    return (log(St/K) + (r+sigma*sigma/2)*t)/(sigma*t);
}

double N(double x){
    return 0.5 + 0.5 * erf(x / sqrt(2.0));
}
double compute_c(double St,double K, double r, double sigma,double t){
    double d1 = compute_d1(St,K,r,sigma,t);
    double d2 = d1 - sigma * sqrt(t);

    return N(d1)*St - N(d2) * K * exp(-r*t);
}

int main(){

    double t = 1/4;
    double K = 95;
    double St = 100;
    double r = 10;
    double sigma = 50;

    double C = compute_c(St,K,r,sigma,t);

    cout << "Parameters : " << endl  << "t = " << t << endl << "K = " << K
         << endl << "St = " << St << endl << "r = " << r << endl << "sigma = "
         << sigma << endl << endl << "C = " << C << endl; 

    return 0;
}