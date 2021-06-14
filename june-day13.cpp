// Pallindrome pairs
// map based approach

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool isPallindrome(string a){
		int i=0;
		int j=a.size()-1;
		while(i<j){
			if(a[i++]!=a[j--])return false;
		}
		return true;
	}
	vector<vector<int>> palindromePairs(vector<string>& words) {
		// map to store strings;
		int n=words.size();
		unordered_map<string,int> dict;

		vector<vector<int>> ans;

		for(int i=0;i<n;i++){
			dict[words[i]]=i;
		}

		// pallindrome empty case
		// if "" is present then all the pallindrome can make a pair with it
		if(dict.find("")!=dict.end()){
			for(int i=0;i<n;i++){
				if(words[i]!="" && isPallindrome(words[i])){
					ans.push_back({dict[""],i});
				}
			}
		}

		// pallindrome by combination
		for(int i=0;i<n;i++){
			for(int j=0;j<words[i].size();j++){
				string lef=words[i].substr(0,j);
				string rigth=words[i].substr(j,words[i].size()-j);

				string lefrev=lef;
				reverse(lefrev.begin(),lefrev.end());
				string revright=rigth;
				reverse(revright.begin(),revright.end());

				if(dict.find(lefrev)!=dict.end() && isPallindrome(rigth) && dict[lefrev]!=i){
					ans.push_back({i,dict[lefrev]});
				}
				if(dict.find(revright)!=dict.end() && isPallindrome(lefrev) && dict[revright]!=i){
					ans.push_back({dict[revright],i});
				}

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
		vector<string> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		Solution ob;
		vector<vector<int>> ans;
		ans=ob.palindromePairs(a);
		for(auto x:ans){
			cout<<x[0]<<" "<<x[1]<<endl;
		}
	}
	return 0;
}