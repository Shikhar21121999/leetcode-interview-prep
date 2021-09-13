// open the lock
// shortest path implementation using bfs queue

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<string> getNeighbour(string a){
		vector<string> ans;
		for(int i=0;i<4;i++){
			string upwheel,downwheel;
			upwheel=downwheel=a;
			upwheel[i]=(a[i]=='9')?'0':a[i]+1;
			downwheel[i]=(a[i]=='0')?'9':a[i]-1;
			ans.push_back(upwheel);
			ans.push_back(downwheel);
		}
		return ans;
	}
	int openLock(vector<string>& deadends, string target){

		// an unordered set to store deadends
		unordered_set <string> deadlock(deadends.begin(),deadends.end());

		// queue to perform  bfs
		queue<string> q;
		q.push("0000");

		if(deadlock.count("0000"))return -1;

		for(int steps=1;!q.empty();steps++){
			for(int i=0;i<q.size();i++){
				string curr=q.front();q.pop();
				// cout<<curr<<endl;
				if(curr==target)return steps;
				for(auto neighbour:getNeighbour(curr)){
					// cout<<neighbour<<" ";
					if(deadlock.count(neighbour))continue;
					q.push(neighbour);
					deadlock.insert(neighbour);
				}
				// cout<<endl;
			}
		}
		return -1;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> deadend(n);
		for(int i=0;i<n;i++){
			cin>>deadend[i];
		}
		string target;
		cin>>target;
		Solution ob;
		cout<<ob.openLock(deadend,target)<<endl;
	}
}