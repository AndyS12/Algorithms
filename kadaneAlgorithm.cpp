//largest subarray sum problem
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,l;
	    cin>>n;
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        cin>>l;
	        v.push_back(l);
	    }
	    int s=0,max=v[0];
	    for(int i=0;i<n;i++){
	        s+=v[i];
	        if(max<s)
	            max=s;
	        if(s<0)
	            s=0;
	    }
	    cout<<max<<"\n";
	}
	return 0;
}