
//2D array sum query, no updates
#include<algorithm>
class SUM_2D{
    private:
        static const int ms = 2000;
        int a[ms][ms];


    public:
        SUM_2D(){
            for(int i=0;i<ms;i++)
                for(int j=0;j<ms;j++){
                    if(i)a[i][j]+=a[i-1][j];
                    if(j)a[i][j]+=a[i][j-1];
                    if(i and j)a[i][j]-=a[i-1][j-1];
                }
        }

        int query2D(int x1, int y1, int x2, int y2){
            if(x1>x2) std::swap(x1,x2);
            if(y1>y2) std::swap(y1,y2);

            int ans = a[x2][y2];
            if(x1)ans-=a[x1-1][y2];
            if(y1)ans-=a[x2][y1-1];
            if(x1 and y1)ans+=a[x1-1][y1-1];
            return ans;
        }
};
