typedef struct Node{
    int val,pri;
    struct Node *l,*r;
}Node;

Node* newNode(int val){
    Node *n=malloc(sizeof(Node));
    n->val=val;
    n->pri=rand();
    n->l=n->r=NULL;
    return n;
}

void leftRotate(Node **root){
    Node *x=*root;
    Node *y=x->r;

    x->r=y->l;
    y->l=x;
    *root=y;
}

void rightRotate(Node **root){
    Node *x=*root;
    Node *y=x->l;

    x->l=y->r;
    y->r=x;
    *root=y;
}

void insert(Node **root,int val){
    if(!*root){
        *root=newNode(val);
        return;
    }

    if(val<(*root)->val){
        insert(&(*root)->l,val);

        if((*root)->l->pri>(*root)->pri)
            rightRotate(root);
    }else{
        insert(&(*root)->r,val);

        if((*root)->r->pri>(*root)->pri)
            leftRotate(root);
    }
}

int lowerBound(Node *root,int target,int *found){
    int ans=0;

    while(root){
        if(root->val>=target){
            ans=root->val;
            *found=1;
            root=root->l;
        }else{
            root=root->r;
        }
    }

    return ans;
}

int predecessor(Node *root,int target,int *found){
    int ans=0;

    while(root){
        if(root->val<target){
            ans=root->val;
            *found=1;
            root=root->r;
        }else{
            root=root->l;
        }
    }

    return ans;
}

int minAbsoluteDifference(int* nums,int numsSize,int x){
    if(x==0) return 0;

    Node *root=NULL;
    int ans=INT_MAX;

    for(int i=x;i<numsSize;i++){
        insert(&root,nums[i-x]);

        int ok=0;
        int v=lowerBound(root,nums[i],&ok);

        if(ok)
            ans=fmin(ans,abs(nums[i]-v));

        ok=0;
        v=predecessor(root,nums[i],&ok);

        if(ok)
            ans=fmin(ans,abs(nums[i]-v));

        if(ans==0)
            return 0;
    }

    return ans;
}
