// Minimum number of reuelling stops

// greedy priority queue approach
// here we greedily fill our car from the station that offer maximum fuel
// we do have to ensure that we are filling from the station
// which we can reach using previous fuel

// implementation
// go as far as possible 'curr'
// now add all the stations encountered till now to priority queue
// since we cannot go any furhter refill the car using station
// that has been accountered has max fuel

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int minRefuelStops(int target, int currFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int i=0,refillStops;
        for(refillStops=0;currFuel<target;refillStops++){
        	// push all the stations encountered so far in the pq
        	while(i<stations.size() && currFuel>=stations[i][0]){
        		pq.push(stations[i++][1]);
        	}

        	// now at this point our car is empty
        	// refill it using station with max fuel encountered till now
        	
        	// if no station in pq implies that even if we had
        	// made all the stops and refuelled yet not possible to go further
        	if(pq.empty())return -1;
        	currFuel+=pq.top();pq.pop();
        }
        return refillStops;
    }
};

int main(){
	int target,startFuel;
	int n;
	cin>>target>>startFuel;
	cin>>n;
	vector<vector<int>> stations;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		stations.push_back({a,b});
	}

	for(auto x:stations){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	Solution ob;
	cout<<ob.minRefuelStops(target,startFuel,stations)<<endl;
}