// Generate parenthesis

// Approach recursion+implementation

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	void recur(int openLeft,int closLeft,string curr,vector<string>& ans){
		// cout<<openLeft<<" "<<closLeft<<endl;
		// base case
		if(openLeft==0 and closLeft==0){
			ans.push_back(curr);
			return;
		}

		// add open bracket to the string
		if(openLeft>0){
			recur(openLeft-1,closLeft,curr+"(",ans);
		}

		// add close bracket if close bracket in string
		// is lesser than open bracket
		if(closLeft>openLeft){
			recur(openLeft,closLeft-1,curr+")",ans);
		}
		return ;
	}
	vector<string> generateParenthesis(int n) {
        // for a balanced parenthesis we have to constantly ensure
        // that for every string closed brackets are lesser than
        // opening brackets
        vector<string> ans;
        recur(n-1,n,"(",ans);
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
		vector<string> ans=ob.generateParenthesis(n);
		for(auto x:ans){
			cout<<x<<endl;
		}
	}
	return 0;
}