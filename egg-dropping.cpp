#include<bits/stdc++.h>
using namespace std;
int egg_drop(int floors, int eggs){
    int dp[eggs+1][floors+1];
    for(int i=1; i<=floors; i++){
        dp[1][i] = i;
    }
    for(int i=0;i<=eggs; i++){
        dp[i][0]=0;
    }
    for(int i=2; i<=eggs; i++){
        for(int j=1; j<=floors; j++)
            dp[i][j] = INT_MAX;
    }
    cout<<endl;
    for(int i=1; i<=eggs; i++){
        for(int j=1; j<=floors; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nhere\n";
    for(int i=2; i<=eggs; i++){
        for(int j=1; j<=floors; j++){
            if(i>j)
                dp[i][j] = dp[i-1][j];
            else{
                for(int k=1; k<=j; k++){
                    int t1 = 1+max(dp[i-1][k-1], dp[i][j-k]);
                    if(dp[i][j]>t1)
                        dp[i][j]=t1;
                }
            }
        }
    }
    cout<<endl;
    for(int i=1; i<=eggs; i++){
        for(int j=1; j<=floors; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[eggs][floors];
}
int main(){
    int floors, eggs;
    cout<<"\nEnter the number of floors and eggs: ";
    cin>>floors>>eggs;
    cout<<"Hello";
    int min_trial_needed = egg_drop(floors, eggs);
    cout<<"\nThe minimum number of eggs needed to find the breaking point: "<<min_trial_needed<<endl;
    return 0;
}
