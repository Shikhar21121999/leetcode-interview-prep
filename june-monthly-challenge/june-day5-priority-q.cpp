// priority queue implementation code

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

class Solution{
public:
	int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {

		// make a container to club speed and efficiency
		vpii engineer(n);
		for(int i=0;i<n;i++){
			engineer[i]=make_pair(efficiency[i],speed[i]);
		}

		// sort in descending order according to efficincy
		sort(engineer.rbegin(),engineer.rend());

		// priority queue to store k engineers with highest speed
		priority_queue<int, vector<int>, greater<int>> minHeap;

		long speedSum=0,ans=0;
		// iterate over engineer
		for(auto eng:engineer){
			speedSum+=eng.first;
			minHeap.push(eng.second);
			if(minHeap.size()>k){
				speedSum-=minHeap.top();
				minHeap.pop();
			}
			ans=max(ans,speedSum*eng.second);
		}
		return ans%(int)(1e9+7);
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi speed(n);
		vi eff(n);
		for(int i=0;i<n;i++){
			cin>>speed[i];
		}
		for(int i=0;i<n;i++){
			cin>>eff[i];
		}
		int k;
		cin>>k;
		Solution ob;
		cout<<ob.maxPerformance(n,speed,eff,k)<<endl;
	}
}