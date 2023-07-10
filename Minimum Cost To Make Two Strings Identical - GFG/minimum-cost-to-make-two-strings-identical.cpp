//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findMinCost(string x, string y, int costX, int costY)
	{
	    int m=x.size();
	    int n=y.size();
	    int dp[m+1][n+1];
	    for(int i=m;i>=0;i--){
	        for(int j=n;j>=0;j--){
	            if(i==m || j==n){
	                dp[i][j]=0;
	            }
	            else if(x[i]==y[j]){
	                dp[i][j]=1+dp[i+1][j+1];
	            }else{
	                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
	            }
	        }
	    }
	    int c1=(m-dp[0][0])*costX;
	    int c2=(n-dp[0][0])*costY;
	    return c1+c2;
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends