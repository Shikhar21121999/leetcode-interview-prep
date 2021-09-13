// Minimum number of reuelling stops

// dp approach
// dp[k] denote max distance that is reachable
// if k stops are made for refilling

// Process
// we check using each station and see farthest we can go
// if last station used for refuelling is current one or ith one


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     	int n=stations.size();
     	long dp[n+1];
     	memset(dp,0,sizeof(dp));
     	// max distance with 0 stops is equal to starting fuel
     	dp[0]=startFuel;   

     	for(int i=0;i<n;i++){
     		for(int refill=i;refill>=0 && stations[i][0]<=dp[refill];refill--){
     			dp[refill+1]=max(dp[refill+1],dp[refill]+stations[i][1]);
     		}
     	}

     	// get the dp[i] such that i is minimum and dp[i]>=target
     	for(int i=0;i<=n;i++){
     		// cout<<dp[i]<<endl;
     		if(dp[i]>=target)return i;
     	}

     	// couldn't get to target even after making n stops

     	return -1;
    }
};

int main(){
	int target,startFuel;
	int n;
	cin>>target>>startFuel;
	cin>>n;
	vector<vector<int>> stations;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		stations.push_back({a,b});
	}

	for(auto x:stations){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	Solution ob;
	cout<<ob.minRefuelStops(target,startFuel,stations)<<endl;
}