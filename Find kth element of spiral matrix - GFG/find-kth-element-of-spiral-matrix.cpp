//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int p=m,q=n,r=-1,s=0;
        if(k-p>0){
            k= k-p;
            p--;
        }else{
            return a[s][r+k];
        }
 		for(int x=0;x<n*m && k;x++){
 		    if(k-q+1+s>0){
 		        k= k-q+1+s;
 		        q--;
 		    }else{
 		        return a[s+k][p];
 		    }
 		    if(k-p+1+r>0){
 		        k = k-p+1+r;
 		        r++;
 		    }else return a[q][p-k];
 		    if(k-q+1+s>0){
 		        k= k-q+1+s;
 		        s++;
 		    }else return a[q-k][r];
 		    if(k-p+1+r>0){
 		        k= k-p+1+r;
 		        p--;
 		    }else return a[s][r+k];
 		}
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends