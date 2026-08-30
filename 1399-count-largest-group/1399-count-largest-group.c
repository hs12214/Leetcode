int digitSum(int x){
    int sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int countLargestGroup(int n){
    int freq[40]={0}, max=0, cnt=0;
    for(int i=1;i<=n;i++){
        int s=digitSum(i);
        freq[s]++;
        if(freq[s]>max) max=freq[s];
    }
    for(int i=0;i<40;i++){
        if(freq[i]==max) cnt++;
    }
    return cnt;
}
