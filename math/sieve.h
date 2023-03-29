
#include <algorithm>
#include <vector>
class Sieve{
    public:
        static const int P = 2e7+5;
        std::vector<bool> prime;
        std::vector<long long> primes;

        Sieve (){
            if(prime.size() == P+1) return;
            prime.assign(P+1, 1);

            prime[0]=prime[1]=0;
            for (long long p=2; p*p<=P;p++) if(prime[p]){
                for(long long i=p*p; i<=P; i+=p)
                    prime[i]=0;
            }
            primes.push_back(2);
            for(int i=3;i<=P;i+=2)
                if(prime[i])
                    primes.push_back(i);
        }

        bool isprime(long long n){
            if(n<prime.size()) return prime[n];
            for(long long &p:primes){
                if(p*p>n) break;
                if(n%p==0) return 0;
            }
            return 1;
        }
};
