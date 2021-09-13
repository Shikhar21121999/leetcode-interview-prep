// Matchsticks to  square

// Approach
// bruteforce-recursive with optimization
// 132/133 test case got passed doubt on 133 test case

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution {
public:
	bool solve(int index,vector<int>& sticks,vector<bool>& visited,int target){
		cout<<index<<" "<<target<<endl;
		if(target==0)return true;

		// check for a stick in sticks in size
		for(int i=index;i<sticks.size();i++){
			if(!visited[i] && target-sticks[i]>=0){
				visited[i]=1;
				if(solve(i,sticks,visited,target-sticks[i]))return true;
				visited[i]=0;
			}
		}
		return false;
	}
	
    bool makesquare(vector<int>& sticks) {
        int reqdSum=0;
        for(int i=0;i<sticks.size();i++){
        	reqdSum+=sticks[i];
        }
        if(reqdSum%4)return false;
        reqdSum=reqdSum/4;

        vector<bool> visited(sticks.size(),0);

        sort(sticks.begin(),sticks.end(),greater<int>());

        // now instead of recursively checking for each and every stick
        // we iteratively select a side of square and check if its possible
        // to get its length equal to required sum
        for(auto x:sticks){
        	cout<<x<<" ";
        }
        cout<<endl;
        for(int i=0;i<3;i++){
        	for(auto x:visited){
        		cout<<x<<" ";
        	}
        	cout<<endl;
        	if(!solve(0,sticks,visited,reqdSum)){
        		return false;
        	}
        }

        return true;
    }
};

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Solution ob;
	cout<<ob.makesquare(a);
}