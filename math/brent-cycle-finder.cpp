
int f(int x){

    return x;
}

pair<int,int> brent(int x0){
    int p,l,t,h;
    p = l = 1;
    t = x0;
    h = f(x0);
    while(t != h){
        if(p == l){
            t = h;
            p *= 2;
            l = 0;
        }
        h = f(h);
        l++;
    }

    t = h = x0;
    for(int i=0;i<l;i++)
        h = f(h);

    int mu = 0;
    while(t != h){
        t = f(t);
        h = f(h);
        mu++;
    }

    return make_pair(l,mu);//{period, index where it begins}
}
