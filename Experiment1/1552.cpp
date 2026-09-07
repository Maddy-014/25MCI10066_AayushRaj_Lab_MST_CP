class Solution {
public:
    bool isPossible(vector<int>&arr, int n, int m, int minAllowed){
        int currentPosi=arr[0];
        int balls=1;

        for(int i=1;i<n;i++){
            if(arr[i]-currentPosi>=minAllowed){
                balls++;
                currentPosi=arr[i];
            }

            if(balls==m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int n=position.size();
        int ans=-1;
        int st=-1;
        int end=position[n-1]-position[0];

        while(st<=end){
            int mid=st+(end-st)/2;

            if(isPossible(position,n,m,mid)){
                ans=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};
