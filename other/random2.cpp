
void reset_seed(){
    srand(unsigned(time(NULL)));
}

int randint(int l, int r){//random from l to r inclusive
    return rand() % (r-l+1) + l;   
}
//l = 3, r = 10, r-l+1 = 8 == {3,4,5,6,7,8,9,10}
//                             0 1 2 3 4 5 6 7
//                       + l = 3 4 5 6 7 8 9 10
