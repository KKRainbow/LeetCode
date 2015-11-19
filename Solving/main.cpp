#include<iostream>
#include<unordered_map>
#include<stack>
#include<tuple>
#include<cassert>
#include<map>
using namespace std;
class Solution {
	string t;
	string p;
	int tend;
	int pend;
	map<int,map<int,int>> cache;
	//用于星号
	map<int,int> max;
	//用于问号
	map<int,int> min;
    bool lastisstar;
    bool test(int tidx,int pidx)
    {
        while(
        
    }

public:
    bool isMatch(string t, string p) {
		//先对p进行处理，删去多余的*和?
		auto it = p.begin();
		string newp;
		int ni = 0;
		while(it != p.end())
		{
			if(*it != '*')
			{
				newp.push_back(*it);
				it++;
				continue;
			}
			while(it != p.end())
			{
				if(*it == '*')
				{
					it++;
				}
				else
				{
					break;
				}
			}
        if(it == p.end())
        {
            lastisstar = true;
        }
			if(it != p.end())
				newp.push_back('*');
		}
		this->t = t;
		this->p = newp;
		cout<<newp<<endl;
		tend = t.size();
		pend = newp.size();
		return test(0,0);
    }
};

int main()
{
	string t = "aaabbaabbbbbaabbbabbbaaabbbaaaabaaabaaaabbbbaabbbabaababababbaabbaabbbbaabaabbaabbaaaabbbbaaaabbaaabbaabbaaabababbabaaabbaabababbbaabaaaaaabababbaababaababaaabbbbaaaaaaaaaaaabbababaababaabababaabaabbaaba";
string p = 
		"*bb*bb*****b******a**ab*bba****ba*a*a*aa*abb*baa*a**ba**b*ba**b**ba*ab**bb***a*ba*ab****ab**aab*bb*b";
	t = "";
	p = "?";
    Solution s;
    cout<<endl<<s.isMatch(t,p)<<endl;

}
