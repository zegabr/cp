
#include <cmath>
#include "sieve.h"
class Divisors : public Sieve{
    long long sumdiv(long long n){
        long long pri = 0, prf = primes[pri], ans=1;
        while(prf*prf <= n){
            long long power=0;
            while(n%prf==0){n/=prf; power++;}
            ans*= ((long long)pow((double)prf, power+1.0) - 1)/(prf-1);
            prf = primes[++pri];
        }
        if(n!=1) ans*=((long long)pow((double)n, 2.0) - 1)/(n-1);
        return ans;
    }

    long long countDiv(long long n){//O(sqrt(n))
        long long c=0;
        for(long long i=1; i*i<=n; i++){
            if(n%i==0){
                if(n/i==i)c++; //count one divisor
                else c+=2; // count 2 divisors: i and n/i
            }
        }
        return c;
    }

    long long countDivUsingPrimes(long long n){ // n = P1^a1*P2^a2*...*Pk^ak => countDiv = (a1 + 1)(a2 + 1)..(ak + 1)
        long long c=0;
        long long power;
        for(long long p : primes){
            if(p*p > n) break;
            power = 0;
            while( n % p == 0){n /= p; power++;}
            if(power > 0){
                if(c == 0) c = 1;
                c *= (power + 1);
            }
        }
        if(n != 1) c *= 2;
        return c;
    }
};
