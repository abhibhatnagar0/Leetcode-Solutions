class Solution {
public:
            const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector < long long > dp(arr.size(), 1);
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;//store the index of various elements of the array
            for (int j = 0; j <= i-1; j++)
            {
                if (arr[i] % arr[j] == 0)//to check whether arr[j] is a factor of arr[i] or not
                {
                    int temp = arr[i] / arr[j];
                    if (mp.find(temp)!=mp.end()) dp[i] += (dp[j] *dp[mp[temp]]) % mod;//check the presence of the required no in map, If it is in the map then increase dp[i] by the product of the dp[j] and dp[mp[temp]] taking the modulus
                }
            }
        }
        
        long long ans = 0;
        ans = accumulate(dp.begin(), dp.end(), 0LL);
        return ans%mod;//return toatl sum after taking modulus
    }
};