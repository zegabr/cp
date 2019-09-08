//==========================
const double EPS = 1e-9;
int determinant(vector < vector<double> > &a, int n){
	double det = 1;
	for (int i=0; i<n; ++i) {
		int k = i;
		for(int j=i+1; j<n; ++j)
			if (abs (a[j][i]) > abs (a[k][i]))
				k = j;
		if(abs (a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap(a[i], a[k]);
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
//=============================
