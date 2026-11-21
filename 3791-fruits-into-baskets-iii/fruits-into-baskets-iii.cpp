class Solution {
public:
    void build(int i , int l ,int r,vector<int>&baskets,vector<int>&segTree){
        if(l==r){
            segTree[i]=baskets[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,baskets,segTree);
        build(2*i+2,mid+1,r,baskets,segTree);
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }
    bool querySegTree(int i,int l,int r,vector<int>&segTree,int fruit){
        if(segTree[i]<fruit){
            return false;
        }
        if(l==r){
            segTree[i]=-1;
            return true;
        }
        int mid=l+(r-l)/2;
        bool placed=false;
        if(segTree[2*i+1]>=fruit){
            placed=querySegTree(2*i+1,l,mid,segTree,fruit);
        }else{
            placed=querySegTree(2*i+2,mid+1,r,segTree,fruit);
        }
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
        return placed;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>segTree(4*n,-1);
        build(0,0,n-1,baskets,segTree);
        int unplaced=0;
        for(int &fruit:fruits){
            if(querySegTree(0,0,n-1,segTree,fruit)==false){
                unplaced++;
            }
        }
        return unplaced;
    }
};