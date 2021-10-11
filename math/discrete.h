
#include <cmath>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
namespace Discrete
{
    const int P = 2e7 + 5;

    template <typename T>
        T divceil(T a, T b){
            return (a + b - 1) / b;
            /**
             * ceil(a/b) =(a + b - 1) / b
             * proof: if a = bk + 0, then 
             * bk == (a+b-1), then ceil = k.
             * Otherwise, a = bk + r, 0 < r < b,
             * then (a+b-1) = (bk + r + b - 1) == b(k+1) + r.
             * Since 0 < r < b, we have b(k+1) < b(k+1) + r, then ceil((b(k+1)+r)/b) == k+1 as expected (for integer divisions)
             * */
        }

    long long gcd(long long a, long long b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(const long long &a, const long long &b){
        return (a / std::__gcd(a, b)) * b;
    }

    /**
     * a ^ 6 = a ^ 110 == a ^ (0*2⁰+1*2¹+1*2²)
     * == a⁰ * a² * a⁴ == a⁰ * a² * (a²)²
     * So, we keep squaring the base a, 
     * and multiply it by the answer every time we encounter a 1 bit in the power binary's representation
     * 
     * */
    long long fexp(long long a, long long b){ //O(logb)
        long long ans = 1;
        while (b){
            if (b & 1)
                ans = ans * a;
            a = a * a;
            b >>= 1;
        }
        return ans;
    }

    long long fexp(long long a, long long b, long long mod){ //O(logb)
        long long ans = 1;
        while (b){
            if (b & 1)
                ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }

    long long invmod(long long a, long long mod){ //mod has to be prime
        return fexp(a, mod - 2, mod);
    }

    int dlog(int a, int b, int m){ //find x where a^x = b mod m, with a and m co-prime (discrete log)
        int n = (int)sqrt(m + .0) + 1;
        int an = 1;
        for (int i = 0; i < n; i++)
            an = an * a % m;

        std::map<int, int> vals;
        for (int p = 1, cur = an; p <= n; p++){
            if (!vals.count(cur))
                vals[cur] = p;
            cur = cur * an % m;
        }

        for (int q = 0, cur = b; q <= n; q++){
            if (vals.count(cur)){
                int ans = vals[cur] * n - q;
                return ans;
            }
            cur = cur * a % m;
        }
        return -1;
    }

    std::vector<long long> phi(P + 1);
    void PHI(){ //get prime factors and calculate phi
        for (long long i = 1; i < P; i++)
            phi[i] = i;
        for (long long i = 2; i < P; i++){ //O(N)
            if (phi[i] == i){ //n is prime
                for (long long j = i; j < P; j += i)
                { //O(logi)
                    //i is a prime factor of j
                    phi[j] = phi[j] / i * (i - 1);
                }
            }
        }
    }

    long long PHI(long long n){ //calculates one phi
        long long ans = n;
        for (long long i = 2; i * i <= n; i++){
            if (n % i == 0){
                ans -= ans / i;
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1){ //n is prime
            ans -= ans / n;
        }
        return ans;
    }

    int generator(int p){ //find a primitive root modulo p
        //talvez seja interessante fazer uma condicional aqui pra saber se o p tem raíz primitiva
        std::vector<int> fact;
        int tot = PHI(p), n = tot;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0){
                fact.push_back(i); //fatores de phi
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            fact.push_back(n);

        for (int res = 2; res <= p; ++res){
            bool ok = true;
            for (int i = 0; i < fact.size() && ok; ++i)
                ok &= fexp(res, tot / fact[i], p) != 1;
            if (ok)
                return res; //primitive root
        }
        return -1; //there is none
    }

    //=================raízes primitivas=======================
    // 	ord(a,m) = menor inteiro positivo tal que a^k==1modm
    //  ord(a,m)|phi(m) //ordem de a mod m divide phi(m)
    // 	se ord(a,m)==phi(m) , a é raíz primitiva
    // 	gcd(a,m) tem q ser 1 para a possuir ordem modulo m
    // 	se k=ord(a,m), ord(a^t,m)=k/gcd(k,t);//logo se a for raíz primitiva, vc consegue ordem de qualquer potencia dele, logo de qualquer nmero q possui ordem
    // 	um número tem raíz primitiva se for da forma 2,4,p^k ou 2p^k com k inteiro positivo e p PRIMO ÍMPAR
    //====================================================
    std::vector<int> droot(int k, int a, int n){ //find x where x^k==a mod n (discrete root)
        if (a == 0){
            //0 is the only solution
            std::vector<int> ans = {0};
            return ans;
        }

        int g = generator(n);

        //baby-step giant-step discrete log algorithm
        int sq = (int)sqrt(n + .0) + 1;
        std::vector<std::pair<int, int>> dec(sq);
        for (int i = 1; i <= sq; i++)
            dec[i - 1] = {fexp(g, i * sq * k % (n - 1), n), i};
        sort(dec.begin(), dec.end());
        int any_ans = -1;
        for (int i = 0; i < sq; i++){
            int my = fexp(g, i * k % (n - 1), n) * a % n;
            auto it = lower_bound(dec.begin(), dec.end(), std::make_pair(my, 0));
            if (it != dec.end() and it->first == my){
                any_ans = it->second * sq - i;
                break;
            }
        }
        if (any_ans == -1){
            std::vector<int> ans; //no solutions
            return ans;
        }

        int delta = (n - 1) / std::__gcd(k, n - 1);
        std::vector<int> ans;
        for (int cur = any_ans % delta; cur < n - 1; cur += delta)
            ans.push_back(fexp(g, cur, n));
        sort(ans.begin(), ans.end());
        return ans;
    }

    // extended euclids
    // acha x e y da equacao:
    // a * x + b * y = gcd(a, b) = d;
    // x eh inverso modular de a no modulo y (se d == 1)
    // y eh inverso modular de b no modulo x (se d == 1)
    //long long x,y,d;
    void euclides(long long a, long long b, long long &x, long long &y, long long &d){
        if (b == 0){
            x = 1;
            y = 0;
            d = a;
            return;
        }
        euclides(b, a % b, x, y, d);
        int x1 = y;
        int y1 = x - (a / b) * y;
        x = x1;
        y = y1;
    }

    /////positive solution
    bool makePositive(long long &x, long long &y, long long d, long long a, long long b){
        if (x < 0){
            //x+ t*b/d >= 0 ==> t >= -x*d/b = -x/(b/d)
            long long t = (-x + (b / d) - 1) / (b / d); //ceil de -x/(b/d)
            x += b / d * t;
            y -= a / d * t;
        }

        if (y < 0){
            //y+ t*a/d >= 0 ==> t >= -y*d/a = -y/(a/d)
            long long t = (-y + (a / d) - 1) / (a / d); //ceil de -y/(a/d)
            x -= b / d * t;
            y += a / d * t;
        }

        return x >= 0 and y >= 0;
    }

    //ax+by=k
    int solve(long long a, long long b, long long k, long long &x, long long &y, long long &d){
        euclides(a, b, x, y, d);
        if (k % d != 0)
            return 0; // no solution at all
        x = k / d * x;
        y = k / d * y;
        if (makePositive(x, y, d, a, b))
            return 2; //positive solution exists (comment this if any solution is good)
        return 1;	  //integer solution exists
    }

    void minimizeX(long long a, long long b, long long &x, long long &y, long long &d){ //for positive solution
        long long t = x / (b / d);
        x -= b / d * t;
        y += a / d * t;
    }

    void minimizeY(long long a, long long b, long long &x, long long &y, long long &d){ //for positive solution
        std::swap(a, b);
        std::swap(x, y);
        minimizeX(a, b, x, y, d);
        std::swap(a, b);
        std::swap(x, y);
    }

    // miller rabin
    bool overflow(long long a, long long b){
        return b && (a >= (1LL << 62) / b);
    }

    long long add(long long a, long long b, long long mod){
        return (a + b) % mod;
    }

    long long mul(long long a, long long b, long long mod){
        if (!overflow(a, b))
            return (a * b) % mod;
        long long ans = 0;
        while (b){
            if (b & 1)
                ans = add(ans, a, mod);
            a = add(a, a, mod);
            b >>= 1;
        }
        return ans;
    }

    long long my_rand(){
        long long ans = rand();
        ans = (ans << 31) | rand();
        return ans;
    }

    bool miller(long long p, int precision){ //check primality
        if (p < 2)
            return 0;
        if (p % 2 == 0)
            return (p == 2);
        long long s = p - 1;
        while (s % 2 == 0)
            s >>= 1;
        for (int i = 0; i < precision; i++){
            long long a = rand() % (p - 1) + 1, temp = s;
            long long mod = fexp(a, temp, p);
            while (temp != p - 1 && mod != 1 && mod != p - 1){
                mod = mul(mod, mod, p);
                temp <<= 1;
            }
            if (mod != p - 1 && temp % 2 == 0)
                return 0;
        }
        return 1;
    }

    long long rho(long long n){ //find a prime factor
        if (n == 1 || miller(n, 10))
            return n;
        if (n % 2 == 0)
            return 2;
        while (1){
            long long x = my_rand() % (n - 2) + 2, y = x;
            long long c = 0, cur = 1;
            while (c == 0){
                c = my_rand() % (n - 2) + 1;
            }
            while (cur == 1){
                x = add(mul(x, x, n), c, n);
                y = add(mul(y, y, n), c, n);
                y = add(mul(y, y, n), c, n);
                cur = std::__gcd((x >= y ? x - y : y - x), n);
            }
            if (cur != n)
                return cur;
        }
    }
}; // namespace Discrete
