int productofdigits(int n){
    int p=1;
    while(n!=0){
        int d=n%10;
        p*=d;
        n/=10;
    }
    return p;
}

int smallestNumber(int n, int t) {
    while(productofdigits(n)%t!=0) n++;
    return n;
}