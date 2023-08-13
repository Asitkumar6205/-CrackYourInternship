class Solution{
public:
    pair<int, int> longestSumZeroIndex(vector<int>&arr){
        unordered_map<long long, int>mp;
        mp[0]=-1;
        int l=0, r=0;
        long long sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(mp.count(sum)){
                if(i-mp[sum] > (r-l)){
                    l=mp[sum]+1;
                    r=i+1;
                }
            }
            else
                mp[sum]=i;
        }
        return {l,r};
    }
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> mat){
        int R=mat.size();
        int C=mat[0].size();
        vector<vector<int>>ans;
        int left=0, right=0, up=0, down=0;
        for(int startc=0; startc<C; startc++){
            vector<int> sum(R,0);
            for(int endc=startc; endc< C; endc++){
                for(int r=0; r<R; r++)
                    sum[r]+=mat[r][endc];                
                auto it=longestSumZeroIndex(sum);
                int l=it.first;
                int r=it.second;
                if((endc-startc+1)*(r-l) > (right-left)*(down-up)){
                    up=l;
                    down=r;
                    left=startc;
                    right=endc+1;
                }
            }
        }
        for(int i=up; i<down; i++){
            vector<int>temp;
            for(int j=left; j<right; j++)
                temp.push_back(mat[i][j]);
            ans.push_back(temp);
        }
        return ans;
    }
};