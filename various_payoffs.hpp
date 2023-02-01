#ifndef PRICING_C___VARIOUS_PAYOFFS_HPP
#define PRICING_C___VARIOUS_PAYOFFS_HPP

/* Non-dependent path payoffs */

    /* Payoffs of vanilla options */

double vanilla_payoff_call(const double& price, const double& K){
    return std::max(0.0,price-K);
}  // payoff for a call option

double vanilla_payoff_put(const double& price, const double& K){
    return std::max(0.0,K-price);
}  // payoff for a put option

    /* Payoffs for digital options */

        /* asset or nothing */

double digital_a_or_n_payoff_call(const double& price, const double& K){
    if (price >= K) return price;
    return 0;
}

/* we do not compute the payoff of an asset or nothing put option because payoff depends on another constant that is not
for all the other type of option */

        /* cash or nothing */

double digital_c_or_n_payoff_call(const double& price, const double& K){
    if (price >= K) return 1;
    return 0;
}

double digital_c_or_n_payoff_put(const double& price, const double& K) {
    if (price <= K) return 1;
    return 0;
}

/* Dependent path payoffs */

    /* Payoffs for asian options */

        /* arithmetic asian options */

double asian_arithmetic_payoff_call(const std::vector<double>& prices, const double& K){
    double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
    double avg = sum/prices.size();
    return std::max(0.0,avg-K);
}

double asian_arithmetic_payoff_put(const std::vector<double>& prices, const double& K){
    double sum = std::accumulate(prices.begin(), prices.end(), 0.0);
    double avg = sum/prices.size();
    return std::max(0.0,K-avg);
}

        /* geometric asian options */

double asian_geometric_payoff_call(const std::vector<double>& prices, const double& K){
    double logsum = log(prices[0]);
    for (unsigned i=1; i<prices.size(); ++i){logsum+=log(prices[i]);};
    double avg = exp(logsum/prices.size());
    return std::max(0.0,avg-K);
}

double asian_geometric_payoff_put(const std::vector<double>& prices, const double& K){
    double logsum = log(prices[0]);
    for (unsigned i=1; i<prices.size(); ++i){logsum+=log(prices[i]);};
    double avg = exp(logsum/prices.size());
    return std::max(0.0,K-avg);
}

    /* Payoffs for lookback options */

double lookback_payoff_call(const std::vector<double>& prices, const double& unused_variable){
    double m = *std::min_element(prices.begin(),prices.end());
    return prices.back() - m;
}

double lookback_payoff_put(const std::vector<double>& prices, const double& unused_variable) {
    double m = *std::max_element(prices.begin(), prices.end());
    return m - prices.back();
}
#endif //PRICING_C___VARIOUS_PAYOFFS_HPP
