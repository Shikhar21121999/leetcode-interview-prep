// simple fraction
// link: https://practice.geeksforgeeks.org/problems/a-simple-fraction0921/1/?track=MD-Math&batchId=144

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	string recurrenceRemainder (int num, int denom) {
		cout<<num<<" "<<denom<<endl;
		string res = "%";
		unordered_map<int, int> recr_dict;

		int rem = num % denom;
		while (rem != 0 && recr_dict.find(rem) == recr_dict.end()){
			cout<<rem<<" "<<res<<" <"<res.length()<<endl;
			recr_dict[rem] = res.length();
			int rem = rem * 10;

			int res_part = rem / denom;
			res += to_string(res_part);

			rem = rem % denom;
		}
		cout<<res<<endl;

		return (rem == 0) ? "" : res.substr(recr_dict[rem]);
	}
	string fractionToDecimal(int num, int denom){
		cout<<recurrenceRemainder(num, denom);
		return "";
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
		int num,denom;
		cin>>num>>denom;
		Solution ob;
		cout<<ob.fractionToDecimal(num, denom)<<endl;
	}
}
