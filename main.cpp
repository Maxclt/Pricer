#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include "lognormal_path.hpp"
#include "various_payoffs.hpp"

using namespace std;


/*double
option_price_call_european_simulated(
    const double& S, //price of underlying
    const double& X, // exercice price
    const double& r, //risk free rate
    const double& sigma, //volatility of underlying
    const double& time, //time to maturity (in years)
    const int& nb_sims // number of simulations
){
    double R = (r - 0.5*pow(sigma,2))*time;
    double SD = sigma * sqrt(time);
    double sum_payoffs = 0.0;
    for (int n=1; n<=nb_sims; n++){
        double S_T = S*exp(R + SD * generate_normal());
        sum_payoffs += max(0.0, S_T - X);
    };
    return exp(-r*time) * (sum_payoffs/double(nb_sims));
}*/

int main() {
    double S = 100.0; 
    double K = 100.0;
    double r = 0.1;
    double sigma = 0.25;
    double time = 1.0;
    int no_steps = 10;
    int nb_sims = 5000;

    /*cout << option_price_call_european_simulated(S,K,r,sigma,time,nb_sims) << endl;*/
    cout << simulate_lognormal_rv(S,r,sigma,time) << endl;
    const vector<double> &prices = simulate_lognormal_path(S, r, sigma, time, no_steps);
    for (int i = 0; i != prices.size(); i++)
    {
        std::cout << prices[i] << std::endl;
    }
}

