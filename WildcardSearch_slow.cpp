#include<iostream>
#include<unordered_map>
#include<stack>
#include<tuple>
using namespace std;
class Solution {
	string t;
	string p;
	int tend;
	int pend;
	unordered_map<int,unordered_map<int,int>> cache;
    //所能选择的最小字符串序号,当前选择的字符串索引,pattern的序号
    stack<tuple<int,int,int>> mystack;
	bool test(int tidx, int pidx)
	{
        while(1)
        {
            if(tidx == tend && pidx == pend)return true;
            auto& c = cache[tidx][pidx];
            if(tidx == tend || pidx == pend || c != 0)
            {
                //回溯
                if(mystack.size() == 0)
                {
                    return false;
                }
                auto front = mystack.top();
                //记录当前状态不可达
                cache[get<1>(front)][get<2>(front)] = 1;
                mystack.pop();
                if(get<1>(front) > get<0>(front))
                {
                    get<1>(front)--;
                    tidx = get<1>(front);
                    pidx = get<2>(front);
                    mystack.push(front);
                }
                else
                {
                    cout<<"!!!!!"<<endl;
                    continue;
                }
            }

            auto state = make_tuple(tidx,tend,pidx + 1);
            switch(p[pidx])
            {
                case '*':
                    //判断之前一个是不是'*',如果也是，那么直接跳过这个pattern
                    tidx = tend;
                    //忽略后面的'*'
                    while(((++pidx) < pend) && p[pidx] == '*');
                    get<2>(state) = pidx;
                    mystack.push(state);
                    break;
                case '?':
                    get<1>(state) = tidx + 1;
                    tidx++;
                    pidx++;
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
		this->t = t;
		this->p = p;
		tend = t.size();
		pend = p.size();
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
