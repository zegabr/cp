
#include <algorithm>
#include <iostream>
class FloydWarshall{
    static const int inf = 0x3f3f3f3f;
    static const int ms = 2222;
    int g[ms][ms];
    int p[ms][ms];

    void clear(int n = ms) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                g[i][j] = i == j ? 0 : inf;
                //p[i][j]=i;
            }
        }
    }

    void add(int u, int v, int w) {
        g[u][v] = std::min(w, g[u][v]);
    }

    void floydWarshall(int n = ms) {//O(V³)
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(g[i][k] + g[k][j] < g[i][j]){
                        g[i][j] = g[i][k] + g[k][j];
                        //p[i][j]=p[k][j];
                    }
                }
            }
        }
    }

    void printpath(int i,int j){
        if(i!=j)	printpath(i,p[i][j]);
        std::cout<<' '<<j;
    }
};
