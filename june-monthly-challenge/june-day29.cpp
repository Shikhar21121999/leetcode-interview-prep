// Remove all adjacent duplicates

// approach
// stack based implementation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stor;
        if(s.length()<2)return s;
        stor.push(s[0]);
        for(int i=1;i<s.length();i++){
        	if(!stor.empty() && s[i]==stor.top()){
        		// pop out the char from stack
        		stor.pop();
        	}
        	else{
        		stor.push(s[i]);
        	}
        }
        string ans="";
        while(!stor.empty()){
        	ans+=stor.top();
        	stor.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
	string inp;
	cin>>inp;
	Solution ob;
	cout<<ob.removeDuplicates(inp);
}