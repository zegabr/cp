//==========GRID MOVING=======
int movx[] = {-1, 0, 1, 0,-1, 1, 1, -1};
int movy[] = {0, 1, 0, -1, 1, 1, -1, -1};
for(int i = 0; i < 8;++i){//u,r,d,l,ur,dr,dl,ul
	int nx = movx[i] + x;
	int ny = movy[i] + y;
	//if safe then dfs(nx,ny)
}