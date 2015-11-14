#include<iostream>
#include<unordered_map>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;
class Solution {
	string t;
	string p;
	int tend;
	int pend;
	unordered_map<int,unordered_map<int,int>> cache;
	map<int,int> repeat;
    //所能选择的最小字符串序号,当前选择的字符串索引,pattern的序号
    stack<tuple<int,int,int>> mystack;
	//最末尾如果是×或者？，判断可以在末尾忽略的target的字符个数。
	int ignoreatlast = 0;
	bool test(int tidx, int pidx)
	{
        while(1)
        {
            if(tidx == tend && pidx >= pend - ignoreatlast)return true;
            auto& c = cache[tidx][pidx];
            if((tidx == tend && pidx != pend) || c != 0)
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
                    pidx = get<2>(front);
					auto desttidx = get<1>(front);
					while(t[(--desttidx)] != p[pidx] && desttidx > lowbound);
					if(desttidx <= lowbound)
					{
						continue;
					}
					else
					{
					}
                    tidx = get<1>(front);
                }
                else
                {
					mystack.pop();
                    cout<<"!!!!!"<<endl;
                    continue;
                }
            }

            auto state = make_tuple(tidx,tend,pidx + 1);
			int repeat = 0;
            switch(p[pidx])
            {
                case '*':
					repeat = this->repeat[pidx];
					dest = repeat == -1?tend-1:tidx + repeat;
					assert(repeat!=0);

					pidx++;
					state = make_tuple(tidx,dest,pidx);

                    mystack.push(state);
                    break;
                default:
                    while((p[pidx] == t[tidx]) && p[pidx] != '*' && p[pidx] != '?')
                    {
                        tidx++,pidx++;
                        cout<<"hey"<<' '<< tidx<<' '<<pidx<<endl;
                    }
                    c = 1;
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
			if(start != 0)
			{
				this->repeat[ni] = -1;
				if(it == p.end())
					ignoreatlast = newp.size();
			}
			else
			{
				this->repeat[ni] = question;
				if(it == p.end())
					ignoreatlast = question;
			}
			if(it != p.end())
				newp.push_back('*');
			ni++;
		}
		this->t = t;
		this->p = newp;
		tend = t.size();
		pend = newp.size();
		return test(0,0);
    }
};

int main()
{
    string t =  "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
    string p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
    Solution s;
    s.isMatch(t,p);
}
