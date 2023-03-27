//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int num,int N,int K,vector<vector<vector<int>>>& dp)
    {
        if(K==0)
        {
            if(N==0) return 1;
            return 0;
        }
        
        if(dp[num][N][K]!=-1) return dp[num][N][K];
        
        int ways=0;
        for(int i=num;i<=N;i++)
        {
            ways+=f(i,N-i,K-1,dp);
        }
        return dp[num][N][K]=ways;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        return f(1,N,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends