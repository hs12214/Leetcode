int cmp(const void *a,const void *b){
    return (*(int*)a)-(*(int*)b);
}
int findRadius(int* houses,int housesSize,int* heaters,int heatersSize){
    qsort(heaters,heatersSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<housesSize;i++){
        int h=houses[i];
        int l=0,r=heatersSize;
        while(l<r){
            int mid=l+(r-l)/2;
            if(heaters[mid]<h)
                l=mid+1;
            else
                r=mid;
        }
        int dist1=INT_MAX;
        int dist2=INT_MAX;
        if(l<heatersSize)
            dist1=abs(heaters[l]-h);
        if(l>0)
            dist2=abs(h-heaters[l-1]);

        int need=dist1<dist2?dist1:dist2;
        if(need>ans)
            ans=need;
    }
    return ans;
}