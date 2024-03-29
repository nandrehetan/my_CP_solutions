//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
     long long f(string &str, char p, char q) 
    {
        stack<char> st; 
        long long cnt = 0; 
        
        // find pq 
        for(int i = str.size()-1; i >= 0; i--) 
        {
            if(!st.empty() and str[i] == p and st.top() == q) 
            {
                cnt++; 
                st.pop(); 
                continue; 
            }
            st.push(str[i]); 
        }
        
        // clear string
        str.clear();
        
        // after removing pq string become, not required to reverse string
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop(); 
        } 
        return cnt; 
    }
    long long solve(int x,int y,string str){
        
        // if x is greater than calculate pr first then rp 
        if(x >= y) 
        {
            long long cntPR = f(str, 'p', 'r');  
            long long cntRP = f(str, 'r', 'p'); 
            return cntPR*x + cntRP*y; 
        }
        // if x is smaller than calculate rp first then pr 
        else 
        {
            long long cntRP = f(str, 'r', 'p');  
            long long cntPR = f(str, 'p', 'r'); 
            return cntPR*x + cntRP*y; 
        }
        return 0; 
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends