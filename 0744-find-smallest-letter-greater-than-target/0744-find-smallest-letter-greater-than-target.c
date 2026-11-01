char nextGreatestLetter(char* letters,int lettersSize,char target){
    int l=0,r=lettersSize-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(letters[mid]<=target)
            l=mid+1;
        else
            r=mid-1;
    }
    return l==lettersSize ? letters[0] : letters[l];
}