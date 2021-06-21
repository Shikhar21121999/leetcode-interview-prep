// Pascal's Triangle

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vvi ans;
        ans.push_back({1});
        if(n==1)return ans;
        if(n==2){
        	ans.push_back({1,1});
        	return ans;
        }
        else{
        	ans.push_back({1,1});
        	for(int i=2;i<n;i++){
        		vi curr_lis={1};
        		for(int j=1;j<ans[i-1].size();j++){
        			curr_lis.push_back(ans[i-1][j]+ans[i-1][j-1]);
        		}
        		curr_lis.push_back(1);
        		ans.push_back(curr_lis);
        	}
        }
        return ans;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Solution ob;
		vvi ans;
		ans=ob.generate(n);
		for(auto row:ans){
			for(auto el:row){
				cout<<el<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}