// Number of Matching Subsequences

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isSubseq(string a,string b){
		// check wether b is a subseq of a
		if(a.length()<b.length())return false;
		if(b=="")return true;

		int i=0,j=0;
		while(i<a.length() && j<b.length()){
			// if characters match
			if(a[i]==b[j]){
				i++;
				j++;
			}
			else i++;
		}
		return (j==b.length());
	}
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        // traverse through word array
        // and check if word is a subseq of s
        for(auto curr:words){
        	if(isSubseq(s,curr))ans++;
        }
        return ans;
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