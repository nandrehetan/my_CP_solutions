//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int n)
{
    // int n=s.size();
        bool dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=true;
                }else if(gap==1){
                    dp[i][j] = (s[i]==s[j]) ? true : false;
                }else{
                    dp[i][j] = ((s[i]==s[j]) && (dp[i+1][j-1]));
                }
            }
        }
        int cnt=0;
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(dp[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    //code here
    
    
}