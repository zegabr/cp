
int maxProfit(int k, vector<int>& prices) {
    k = min(k, (int)prices.size() / 2);

    vector<int> buy(k, -1e9), sell(k);
    int res = 0;

    for(int num : prices){
        for(int i = 0; i < k; i++){
            if(i == 0) 
                buy[i] = max(buy[i], -num);
            else 
                buy[i] = max(buy[i], sell[i-1] - num);

            sell[i] = max(sell[i], buy[i] + num);
            res = max(res, sell[i]);
        }
    }
    return res;
}
