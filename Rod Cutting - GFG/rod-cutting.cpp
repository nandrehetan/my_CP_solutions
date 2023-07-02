//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int newPrices[n+1];
        for(int i=0;i<n;i++){
            newPrices[i+1]=price[i];
        }
        int dp[n+1];
        dp[0]=0;
        dp[1]=newPrices[1];
        
        for(int i=2;i<=n;i++){
            dp[i]=newPrices[i];
            int left=1;
            int right=i-1;
            
            while(left <= right){
                if(dp[left]+dp[right] > dp[i]){
                    dp[i] = dp[left]+dp[right];
                }
                left++;
                right--;
            }
        }
        return dp[n];
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends