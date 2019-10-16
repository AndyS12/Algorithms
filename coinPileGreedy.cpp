#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i];
	    sort(v.begin(),v.end());
	    int c=0;
	    int MinR=INT_MAX;
	    for(int i=0;i<n-1;i++){
	        int m=v[i];
	        int x=0;
	        if(i){
	            c+=v[i-1];
	            x+=c;
	        }
	        for(int j=i+1;j<n;j++)
	            if((v[j]-m)>k)
	                x+=(v[j]-m-k);
	        MinR=min(MinR,x);
	    }
	    cout<<MinR<<"\n";
	}
	return 0;
}