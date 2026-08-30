int digitSum(int x){
    int sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit){
    int box[100] = {0}, max=0;
    for(int i=lowLimit;i<=highLimit;i++){
        int s=digitSum(i);
        box[s]++;
        if(box[s]>max) max=box[s];
    }
    return max;
}
