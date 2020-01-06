//i grows from top->bottom
//j grows from left->right
vector<int> ci = {-2, -2, -1, -1,  1,  1,  2,  2};// Knights Move
vector<int> cj = {-1,  1, -2,  2, -2,  2, -1,  1};// Knights Move

vector<int> ri = {-1, 0, 1, 0,-1, 1, 1, -1};//kings move
vector<int> rj = {0, 1, 0, -1, 1, 1, -1, -1};//kings move
/*
for(int k = 0; k < 8;k++){//u,r,d,l,ur,dr,dl,ul
	int ni = ri[k] + i;
	int ni = rj[k] + j;
	//if safe then dfs(nx,ny)
}
*/
