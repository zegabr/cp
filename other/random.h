
#include<chrono>
#include<random>
#include<vector>
#include<algorithm>
namespace Random{
    // mt19937_64 se LL
    const std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    // Random_Shuffle
    inline void shuff(std::vector<int> &v){
        std::shuffle(v.begin(), v.end(), rng);
    }
    // Random number in interval
    inline int random_int(int i, int j){
        return std::uniform_int_distribution<int>(i, j)(rng);
    }
    // Random double in interval
    inline double random_double(int i, int j){
        return std::uniform_real_distribution<double>(i, j)(rng);
    }
    // there is also :
    // bernoulli_distribution, binomial_distribution, geometric_distribution
    // normal_distribution, poisson_distribution, exponential_distribution

    inline void reset_seed(){
        srand(unsigned(time(NULL)));
    }

    inline int randint(int l, int r){//random from l to r inclusive
        //l = 3, r = 10, r-l+1 = 8 == {3,4,5,6,7,8,9,10}
        //                             0 1 2 3 4 5 6 7
        //                       + l = 3 4 5 6 7 8 9 10
        return rand() % (r-l+1) + l;
    }
}
