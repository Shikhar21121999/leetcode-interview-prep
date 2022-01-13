#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// if a dry day is present
// we have to dry a lake such that =>
    // it is already full
    // it is the next lake which can be flooded

vector<int> avoidFlood(vector<int>& rains) {
    // result vector
    vector<int> res(rains.size(),-1);
    // hash map to store value with index
    unordered_map<int, int> m;
    // to store indexes at which we got zero
    set<int> zero;
    for(int i =0; i < rains.size(); ++i)
    {
        if(rains[i] == 0)
        {
            zero.insert(i);
            res[i] = 1;
        }
        else
        {
            // check if rain has already once fallen on this lake
            if(m.count(rains[i]))
            {
                int lastIndex = m[rains[i]];
                auto zeroIndex = zero.upper_bound(lastIndex);
                if(zeroIndex == zero.end())
                {
                    return {};
                }
                res[*zeroIndex] = rains[i];
                zero.erase(zeroIndex);
            }
            m[rains[i]] = i;
        }
    }
    return res;
}

int main() {
    vi arr{1,2,0,0,2,1};

    vi ans = avoidFlood(arr);

    for (auto x: ans) {
        cout << x << space;
    }
}