// Number of Matching Subsequences

// Approach: Binary Search optimized Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alind(26);

        for(int i=0;i<s.size();i++){
        	alind[s[i]-'a'].push_back(i);
        }

        int res=0;
        for(auto word:words){
        	int x=-1;
        	bool found=true;
        	for(auto c:word){
        		// search for index which is greater than last on
        		// and corrosponds to the same character
        		auto it=upper_bound(alind[c-'a'].begin(),alind[c-'a'].end(),x);
        		if(it==alind[c-'a'].end())found=false;
        		else x=*it;
        	}
        	if(found)res++;
        }
        return res;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n;
		cin>>n;
		vector<string> words(n);
		for(int i=0;i<n;i++){
			cin>>words[i];
		}
		Solution ob;
		cout<<ob.numMatchingSubseq(s,words)<<endl;
	}
}