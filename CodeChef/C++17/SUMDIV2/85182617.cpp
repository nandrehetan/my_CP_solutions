#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        // if(x==1 && y==1){
        //     cout<<1<<endl;
        //     return 0;
        // }
         if(x==y){
            cout<<x*100<<endl;
        }
        // if(x!=y){
        //     if(y!=1){
        //         cout<<x*y-x-y<<endl;
        //     }
        //     else{
        //         cout<<x-1<<endl;
        //     }
        // }
        // else{
        //     cout<<y<<endl;
        // }
        
        else{
            if(x!=1 && y!=1){
                cout<<x*y-x-y<<endl;
            }
            else{
                cout<<max(x,y)-1<<endl;
            }
        }

    }
    return 0;
}
