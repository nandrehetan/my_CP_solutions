//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int k, int r, int c) {
        double dp[110][110]={0.0};
        dp[0][0]=k;
        // dp[101][101]=0.0;
        for(int i=0;i<=105;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>=1){
                    double rem = dp[i][j]-1.0;
                    dp[i][j]=1.0;
                    dp[i+1][j]+=rem/2.0;
                    dp[i+1][j+1]+=rem/2.0;
                }
            }
        }
        return dp[r-1][c-1];
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends