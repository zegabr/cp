#include <bits/stdc++.h>

using namespace std;

int n,k,seq[200000],sum;
vector<pair<int, pair<int, int>>> a;

int main() {

	
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> n;
        
        sum=0;
		for (int j = 0; j < n; ++j){
			cin >> seq[j];
            sum+=seq[j];
        }
		for (int j = 0; j < n; ++j)
			a.push_back( make_pair(sum - seq[j], make_pair(i, j) )   );
	}
	
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i].first == a[i + 1].first && (a[i].second.first != a[i + 1].second.first)) {
			printf("YES\n%d %d\n%d %d\n",a[i + 1].second.first + 1, a[i + 1].second.second + 1, a[i].second.first + 1, a[i].second.second + 1  );
			return 0;
		}
	}
	
    printf("NO\n");
	
	return 0;
}