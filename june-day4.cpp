#include<bits/stdc++.h>
using namespace std;

void wheelTurner(string a){
	cout<<a<<endl;
	// function to simulate turing of all possible wheel
	// and generate next possible codes for the lock
	for(int i=0;i<4;i++){
		string upwheel,downWheel;
		upwheel=downWheel=a;
		upwheel[i]=(a[i]=='9')?'0':a[i]+1;
		downWheel[i]=(a[i]=='0')?'9':a[i]-1;
		cout<<upwheel<<" "<<downWheel<<endl;
	}
}

// implementation 2
void wheelTurner1(string a){
	for(int i=0;i<4;i++){
		for(int diff=-1;diff<2;diff+=2){
			string nextCode=a;
			nextCode[i]=(a[i]-'0'+diff+10)%10+'0';
			cout<<nextCode<<endl;
		}
	}
}
int main(){
	string inp;
	cin>>inp;
	wheelTurner1(inp);
}