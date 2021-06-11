// My Calendar I

#include<bits/stdc++.h>
using namespace std;

class Calendar {
public:
	vector<pair<int,int>> schedule;
	bool book(int start,int end){
		for(pair<int,int> x: schedule){
			if(max(x.first,start)<min(x.second,end))return false;
		}
		schedule.push_back({start,end});
		return true;
	}
}
