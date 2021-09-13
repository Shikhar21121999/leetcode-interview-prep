// leetcode may challenge prefix and suffix probelm

#include <bits/stdc++.h>
using namespace std;

#define vs vector<string>

class WordFilter {
public:
	vs collection;

	// parameterized constructor
	WordFilter(vs& words){
		int n=words.size();	

		for(int i=0;i<n;i++){
			collection.push_back(words[i]);
		}		
	}

	int f(string prefix,string suffix){
		
		// iterate through all the words in the dectionary
		// and check if current prefix and suffix belong to any word
		int ps=prefix.size();
		int ss=suffix.size();
		for(int i=this->collection.size();i>=0;i--){
			string x=this->collection[i];
			if(prefix==x.substr(0,ps) && suffix==x.substr(x.size()-ss,x.size())){
				return i;
			}
		}
		return -1;
	}
};

int main(){
	int n;
	cin>>n;
	vs coll(n);
	for(int i=0;i<n;i++){
		cin>>coll[i];
	}
	WordFilter* obj=new WordFilter(coll);
	int t;
	cin>>t;
	while(t--){
		string pr,ss;
		cin>>pr>>ss;
		cout<<obj->f(pr,ss)<<" ";
	}

}