//i grows from top->bottom
//j grows from left->right
//const int di[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int dj[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
const int di[] = {-1, 0, 1, 0,-1, 1, 1, -1};//kings move
const int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};//kings move
/*
for(int k = 0; k < 8;k++){//u,r,d,l,ur,dr,dl,ul
	int ni = di[k] + i;
	int ni = dj[k] + j;
	//if safe then dfs(nx,ny)
}
*/
