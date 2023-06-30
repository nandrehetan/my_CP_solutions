//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix){
         int row = n;
        int col = m;
        int dp[row+1][col+1];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==row-1 || j==col-1){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }
            }
        }
        

        for(int i=row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                if(matrix[i][j]==1){
            dp[i][j]=min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})+1;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends