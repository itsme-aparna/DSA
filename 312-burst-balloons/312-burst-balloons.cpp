class Solution {
public:
    
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& memo){
        if(i>j)
            return 0;
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int maxi = INT_MIN;
        for(int k = i; k<=j; k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, memo) + solve(k+1, j, nums, memo);
            maxi = max(maxi, cost);
        }
        
        return memo[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        return solve(1, n, nums, memo);
    }
};