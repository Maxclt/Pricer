#ifndef PRICING_C___LOGNORMAL_PATH_HPP
#define PRICING_C___LOGNORMAL_PATH_HPP

/* Simulate a normal variable */

double generate_normal(double mean, double stddev) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<double> normal_dist(mean, stddev);
    return normal_dist(gen);
};
/* Simulate S_T  for non-path dependent payoffs where S_T is log-normally distributed */

double simulate_lognormal_rv(const double& S, // initial stock value
                             const double& r, // interest rate
                             const double& sigma, // volatility
                             const double& time) { // time to maturity
    double R = (r - 0.5 * pow(sigma, 2)) * time;
    double SD = sigma * sqrt(time);
    return S * exp(R + SD * generate_normal(0, 1));
};

/* Simulate the random path (S_1, ..., S_T) for dependent payoffs where S_i is log-normally distributed */

std::vector<double>;
std::vector<double> simulate_lognormal_path(const double& S, // initial stock value
                               const double& r, // interest rate
                               const double& sigma, // volatility
                               const double& time, // time to maturity
                               const int& no_steps){ // number of steps before maturity
    std::vector<double> prices(no_steps);
    double delta_t = time/no_steps;
    double R = (r-0.5*pow(sigma,2))*delta_t;
    double SD = sigma*sqrt(delta_t);
    double S_t = S; // initialize at initial stock value
    for (int i=0; i<no_steps; ++i){
        S_t = S_t*exp(R+SD*generate_normal(0,1));
        prices[i] = S_t;
    };
    return prices;
};




#endif //PRICING_C___LOGNORMAL_PATH_HPP
