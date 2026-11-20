class Solution {
public:
    long long querySegmentTree(int qs,int qe,int i,int l,int r,vector<long long>&segTree){
        if(r<qs || qe<l){
            return 0;
        }
        if(l>=qs && r<=qe){
            return segTree[i];
        }
        int mid=l+(r-l)/2;
        long long left=querySegmentTree(qs,qe,2*i+1,l,mid,segTree);
        long long right=querySegmentTree(qs,qe,2*i+2,mid+1,r,segTree);
        return left+right;
    }
    void updateSegmentTree(int i,int l,int r,int idx,vector<long long>&segTree){
        if(l==r){
            segTree[i]=1;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            updateSegmentTree(2*i+1,l,mid,idx,segTree);
        }else{
            updateSegmentTree(2*i+2,mid+1,r,idx,segTree);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums1.size();
        for(int i=0 ; i< n ; i++){
            mp[nums2[i]]=i;
        }
        vector<long long>segTree(4*n);
        long long result=0;
        updateSegmentTree(0,0,n-1,mp[nums1[0]],segTree);
        for(int i=1 ; i<n ; i++){
            int idx=mp[nums1[i]];
            long long leftCommonCount=querySegmentTree(0,idx,0,0,n-1,segTree);
            long long leftUncommonCount=i-leftCommonCount;
            long long elementAfterIdxNums2=(n-1)-idx;
            long long rightCommonCount=elementAfterIdxNums2-leftUncommonCount;
            result+=leftCommonCount * rightCommonCount;
            updateSegmentTree(0,0,n-1,idx,segTree);
        }
        return result;
    }
};