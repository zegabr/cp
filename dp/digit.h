
#include<vector>
#include<cstring>
#include<algorithm>

class DIGIT_DP {
    private:
        std::vector<int> num;
        static const int dig = 11;//input size + 1
        static const int maxsum = dig*9+1;
        long dp[dig][maxsum][2];//#digits, digit max sum, limited or not

    public:
        DIGIT_DP(){
            std::memset(dp,-1,sizeof dp);
        }

        void getnum(long n){
            num.clear();
            while(n){
                num.push_back(n%10);
                n/=10;
            }
            std::reverse(num.begin(), num.end());
        }

        //return sum of digits for all number from 0 to num
        long solve(int pos, int sum, int e){
            if(pos == num.size()){//check property here
                return sum;
            }

            long &res = dp[pos][sum][e];
            if(res != -1)	return res;

            res = 0;
            int lim = (e == 0) ? num[pos] : 9;

            for(int d = 0; d <= lim; d++){
                res += solve(pos+1, sum+d, (!e and d<lim)?1:e);
            }

            return res;
        }

        //solve from 0 to n
        long solve(long n){
            getnum(n);
            return solve(0,0,0);
        }

        //solve from a to b inclusively
        long solve(long a, long b){
            if(a==0)return solve(b);
            return solve(b) - solve(a-1);
        }
};





