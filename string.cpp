/////////TRIE////////////////
int trie[ms][sigma], terminal[ms], z;
//sigma eh o tamanho do alfabeto
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


////////////KMP/////////
string p, t;
int b[ms], n, m; 

void kmpPre() {
  int i = 0, j = -1;
  b[0] = -1;
  while(i < m) {
    while(j >= 0 && p[i] != p[j]) j = b[j];
    b[++i] = ++j;
  }
}

void kmpSearch() {
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

