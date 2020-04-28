
//===================RANDOM=======================
#include<chrono>
#include<random>
// mt19937_64 se LL
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// Random_Shuffle
inline void shuff(vector<int> &v){
    shuffle(v.begin(), v.end(), rng);
}
// Random number in interval
inline int random_int(int i, int j){
    return uniform_int_distribution<int>(i, j)(rng);
}
// Random double in interval
inline double random_double(int i, int j){
    return uniform_real_distribution<double>(i, j)(rng);
}
// there is also :
// bernoulli_distribution, binomial_distribution, geometric_distribution
// normal_distribution, poisson_distribution, exponential_distribution


