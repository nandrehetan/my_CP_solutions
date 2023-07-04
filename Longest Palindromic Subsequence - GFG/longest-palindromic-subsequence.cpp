//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());

        int m=s.size();
        int n=t.size();

        int dp[m+1][n+1];

        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m || j==n){
                    dp[i][j]=0;
                }else if(s[i]==t[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        //code here
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends