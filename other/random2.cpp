
void reset_seed(){
    srand(unsigned(time(NULL)));
}

int randint(int l, int r){//random from l to r inclusive
    return rand() % (r+1) + l;   
}
