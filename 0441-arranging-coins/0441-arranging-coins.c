int arrangeCoins(int n){
    long long l=1,r=n,ans=0;
    while(l<=r){
        long long m=l+(r-l)/2;
        long long coins=m*(m+1)/2;
        if(coins<=n){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return ans;
}