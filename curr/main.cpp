#include<iostream>
#include<map>
using namespace std;
class Solution {
	string t;
	string p;
	int tend;
	int pend;
	map<int,map<int,int>> cache;
	bool test(int tidx, int pidx)
	{
		auto& c = cache[tidx][pidx];
		if(c != 0)return c == 1?true:false;
		if(tidx == tend && pidx == pend)return true;
		if(tidx == tend || pidx == pend)return false;

		switch(p[pidx])
		{
			case '*':
				break;
			case '*':
				break;
			default:
				break;
		}
	}
public:
    bool isMatch(string t, string p) {
		this->t = t;
		this->p = p;
		tend = t.size();
		pend = p.size();
		return test(0,0);
    }
};
