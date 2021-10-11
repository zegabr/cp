
//=============stars and bars=======================
/*
   -n identical objects into k labeled boxes is comb(n+k-1,n)
   -equals combination with repetition of n+k-1, repeating n and k-1

*/


#include <vector>
#include <algorithm>
#include <iostream>
class Combinatorics{
    //================derrangements=======================
    /*
       the number of ways to make an arrangment where no index is at its proper position is
       derr(n) = (n-1)*(derr(n-1)+derr(n-2))
       derr(0)=derr(1)=0

*/

    static const int ms=10000;
    std::vector<std::vector<long long>> c;

    void initcomb(){
        c.resize(ms+1,std::vector<long long>(ms/2+1,0));
    }

    long long comb(int n,int k){//combinacao de n, escolhendo k
        if(k==0 or k==n) return 1;
        k = std::min(k,n-k);
        if(c[n][k]) return c[n][k];
        return c[n][k] = comb(n-1,k-1)+comb(n-1,k);
    }

    void pascaltriangle(int n){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                std::cout<<comb(i,j)<<' ';
            }
            std::cout<<std::endl;
        }
    }

    int binomialCoeff(int n, int k) { //O(k) time O(1) space 
        // C(n, k) = C(n, n-k) 
        if (k > n - k) k = n - k; 

        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
        int res = 1;
        for (int i = 0; i < k; ++i) { 
            res *= (n - i); 
            res /= (i + 1); 
        } 
        return res; 
    } 
};
