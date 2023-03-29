
#include<vector>
class Stonks{
    int maxProfit(int k, std::vector<int>& prices) {
        k = std::min(k, (int)prices.size() / 2);

        std::vector<int> buy(k, -1e9), sell(k);
        int res = 0;

        for(int num : prices){
            for(int i = 0; i < k; i++){
                if(i == 0)
                    buy[i] = std::max(buy[i], -num);
                else
                    buy[i] = std::max(buy[i], sell[i-1] - num);

                sell[i] = std::max(sell[i], buy[i] + num);
                res = std::max(res, sell[i]);
            }
        }
        return res;
    }
};
