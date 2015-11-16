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

    //所能选择的最小字符串序号,当前选择的字符串索引,pattern的序号
    stack<tuple<int,int,int>> mystack;
	//最末尾如果是×或者？，判断可以在末尾忽略的target的字符个数。
	int ignoreatlast = 0;
	bool test(int tidx, int pidx)
	{
		//做一点trick
		if(!ignoreatlast && p[pend - 1] != t[tend - 1])return false;
        while(1)
        {
            if(pidx == pend && ignoreatlast != 0)return true;
			auto& c = cache[tidx][pidx];
            if((tidx == tend && pidx != pend) || (pidx == pend) || c != 0)
            {
                //回溯
                if(mystack.size() == 0)
                {
                    return false;
                }
                auto& front = mystack.top();
				auto lowbound = get<0>(front);
                //记录当前状态不可达
                cache[get<1>(front)][get<2>(front)] = 1;
                if(get<1>(front) > lowbound)
                {
                    auto tmppidx = get<2>(front);
					if(tmppidx == pend)
					{
						mystack.pop();
					}
					auto& desttidx = get<1>(front);
					while(t[(--desttidx)] != p[tmppidx] && desttidx >= lowbound);
					if(desttidx < lowbound)
					{
						mystack.pop();
					}
					else
					{
						pidx = tmppidx;
						tidx = desttidx;
					}
					continue;
                }
                else
                {
					mystack.pop();
                    continue;
                }
            }

            auto state = make_tuple(tidx,tend,pidx + 1);
			int repeat = 0;
			int lowbound,highbound; //tidx 的下限
			int mi,ma;
            switch(p[pidx])
            {
                case '*':
					mi = min[pidx];
					ma = max[pidx];

					lowbound = tidx + mi; //low bound
					highbound = tidx + ma;

					if(lowbound > tend)
					{
						c = -1; //下限不能超出tend,如果超出说明target字符不够匹配
						continue;
					}

					if(highbound > tend)highbound = tend;

					pidx++;
					state = make_tuple(lowbound,highbound,pidx);
					tidx = highbound;

                    mystack.push(state);
                    break;
                default:
                    while(p[pidx] != '*' && p[pidx] != '?' && pidx < pend && tidx < tend)
                    {
						if (p[pidx] == t[tidx])
						{
							tidx++,pidx++;
						}
						else
						{
							tidx = tend;
							break;
						}
                    }
                    break;
            }
        }
    }
public:
    bool isMatch(string t, string p) {
		//先对p进行处理，删去多余的*和?
		auto it = p.begin();
		string newp;
		int ni = 0;
		while(it != p.end())
		{
			if(*it != '*' && *it != '?')
			{
				newp.push_back(*it);
				ni++;
				it++;
				continue;
			}
			int star = 0,question = 0;
			while(it != p.end())
			{
				if(*it == '*')
				{
					star++;
					it++;
				}
				else if(*it == '?')
				{
					question++;
					it++;
				}
				else
				{
					break;
				}
			}
			auto& mi = min[ni];
			auto& ma = max[ni];
			mi = question;
			if(star != 0)
			{
				ma = t.size();
				if(it == p.end() && question == 0)
					ignoreatlast = t.size();
			}
			else
			{
				ma = question;
				mi = question;
			}
			if(it != p.end())
				newp.push_back('*');
			ni++;
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
