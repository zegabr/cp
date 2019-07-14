//====================================================
//i grows from top->bottom
//j grows from left->right
int movi[] = {-1, 0, 1, 0,-1, 1, 1, -1};
int movj[] = {0, 1, 0, -1, 1, 1, -1, -1};
for(int i = 0; i < 8;++i){//u,r,d,l,ur,dr,dl,ul
	int nx = movi[i] + x;
	int ny = movj[i] + y;
	//if safe then dfs(nx,ny)
}
//====================================================