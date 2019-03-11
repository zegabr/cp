//===========TRIE=================
//int trie[N][sigma], terminal[N], z;
//sigma eh o tamanho do alfabeto
//N é o tamanho da maior string vezes a quantidade de strings
void init() {
	memset(trie[0], -1, sizeof trie[0]);
	z = 0;
}

int getid(char c) {
	return c - 'a';
}

void insert(string &p) {
	int cur = 0;
	for(int i = 0; i < p.size(); i++) {
		int id = getid(p[i]);
		if(trie[cur][id] == -1) {
			memset(trie[z], -1, sizeof trie[z]);//reseta por demanda
			trie[cur][id] = ++z;
		}
		cur = trie[cur][id];
	}
	terminal[cur]++;
}

int count(string &p) {
	int cur = 0;
	for(int i = 0; i < p.size(); i++) {
		int id = getid(p[i]);
		if(trie[cur][id] == -1) return 0;
		cur = trie[cur][id];
	}
	return terminal[cur];
}

//=============Z-ALGORITHM================
//z[i] is the length of the biggest prefix of s, beggining from position i
//z[0] is by definition s.size(), however never used, so leaving zero there is the best option
//to search for a pattern p in a text t, run zfunc(p+'¨'+t), so p will be prefix
vector<int> zfunc(const string &s){//O(n)
	int n = s.size();
	vector<int> z(n);
	for(int i=1, l=0, r=0; i<n; i++){
		if(i<=r) z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < n and s[z[i]] == s[i+z[i]]) z[i]++;
		if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;//z-array
}

//============KMP=================
//string p, t;
//int b[N], n, m; 
void kmpPre() {
	int i = 0, j = -1;
	b[0] = -1;
	while(i < m) {
		while(j >= 0 && p[i] != p[j]) j = b[j];
		b[++i] = ++j;
	}
}

int kmpSearch() {
	int i = 0, j = 0, ans = 0;
	while(i < n) {
		while(j >= 0 && t[i] != p[j]) j = b[j];
		i++; j++;
		if(j == m) {
			//ocorrencia aqui comecando em i - j
			ans++;
			j = b[j];
		}
	}
	return ans;
}
