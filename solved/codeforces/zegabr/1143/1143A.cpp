#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int last1 = 0, last0 = 0;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if(a) last1 = i;
		else last0 = i;
	}
	cout << min(last1, last0) << endl;
}