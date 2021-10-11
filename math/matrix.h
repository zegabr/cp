
#include <vector>
#include <cmath>
namespace Matrix{
    const double EPS = 1e-9;
    const int INF = 1e9;
    int determinant(std::vector<std::vector<double>> &a, int n){
        double det = 1;
        for (int i=0; i<n; ++i) {
            int k = i;
            for(int j=i+1; j<n; ++j)
                if (abs(a[j][i]) > abs(a[k][i]))
                    k = j;
            if(abs(a[k][i]) < EPS) {
                det = 0;
                break;
            }
            std::swap(a[i], a[k]);
            if (i != k)
                det = -det;
            det *= a[i][i];
            for(int j=i+1; j<n; ++j)
                a[i][j] /= a[i][i];
            for(int j=0; j<n; ++j)
                if (j != i && abs (a[j][i]) > EPS)
                    for (int k=i+1; k<n; ++k)
                        a[j][k] -= a[i][k] * a[j][i];
        }
        return det;
    }

    int gauss (std::vector<std::vector<double>> a, std::vector<double> & ans) {//Ax=b, b is at last collumn of vector a
        int n = (int) a.size();
        int m = (int) a[0].size() - 1;

        std::vector<int> where (m, -1);
        for (int col=0, row=0; col<m && row<n; ++col) {
            int sel = row;
            for (int i=row; i<n; ++i)
                if (abs (a[i][col]) > abs (a[sel][col]))
                    sel = i;
            if (abs (a[sel][col]) < EPS)
                continue;
            for (int i=col; i<=m; ++i)
                std::swap (a[sel][i], a[row][i]);
            where[col] = row;

            for (int i=0; i<n; ++i)
                if (i != row) {
                    double c = a[i][col] / a[row][col];
                    for (int j=col; j<=m; ++j)
                        a[i][j] -= a[row][j] * c;
                }
            ++row;
        }

        ans.assign (m, 0);
        for (int i=0; i<m; ++i)
            if (where[i] != -1)
                ans[i] = a[where[i]][m] / a[where[i]][i];
        for (int i=0; i<n; ++i) {
            double sum = 0;
            for (int j=0; j<m; ++j)
                sum += ans[j] * a[i][j];
            if (abs (sum - a[i][m]) > EPS)
                return 0;//zero solutions
        }

        for (int i=0; i<m; ++i)
            if (where[i] == -1)
                return INF;//infinite solutions
        return 1;//one solution at ans
    }
} // namespace Matrix
