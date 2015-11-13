//题很简单，凭感觉做就行，O(n)
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            auto it = words.begin();
            vector<string> line;
            vector<string> result;
            line.reserve(20);
            int remain = maxWidth;
            while(it != words.end())
            {
                line.push_back(*it);
                remain -= it->size();
                it++;
                while(it != words.end())
                {
                    if(it->size() + 1 <= remain)
                    {
                        line.push_back(*it);
                        remain -= it->size() + 1;
                        it++;
                    }
                    else
                    {
                        break;
                    }
                }

                if(line.size() != 1)
                {
                    int space = remain / (line.size() - 1);
                    int remainder = remain % (line.size() - 1);
                    string tmp;
                    for(int i = 0;i<line.size();i++)
                    {
                        auto pos = 0;
                        tmp.append(line[i]);
                        if(i!=line.size() - 1)
                        {
                            int s = (remain > space?space:remain) + 1;
                            if(remainder > 0)s++,remainder--;
                            if(it == words.end())s = 1;
                            tmp.append(s,' ');
                            //小于0之后不会运行到这里
                            remain -= s  - 1;
                        }
                    }
                    if(it == words.end())tmp.append(remain,' ');
                    result.push_back(tmp);
                }
                else
                {
                    string tmp;
                    tmp += line[0];
                    tmp.append(remain,' ');
                    result.push_back(tmp);
                }
                line.clear();
                remain = maxWidth;
            }
            return result;
        }
};
