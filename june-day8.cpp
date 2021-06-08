// Min Cost of Climbing Stairs

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution{
public:
	int minCostClimbingStairs(vector<int>& cost) {
        // using iterative dp
        int n=cost.size();
        vi dp(n);

        // initialize last steps
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];

        if(n<=2)return min(cost[0],cost[2]);
        // if n>=3
        for(int i=n-3;i>=0;i--){
        	dp[i]=min(dp[i+1],dp[i+2])+cost[i];
        }
        return min(dp[0],dp[1]);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.minCostClimbingStairs(a)<<endl;
	}
}