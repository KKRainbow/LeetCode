#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<climits>
#include<set>
#include<unordered_set>
#include<map>
#include<cassert>
using namespace std;
//不用最短路径，BFS即可
class Solution {
    vector<vector<int>> graph;
	list<vector<int>> result;
    map<int,set<int>> predecessor;
    vector<string> wordList;
	int allStart = 0;

    vector<int> tmpAnswer;
    void buildAnswer(int start, int end, int depth)
    {
        tmpAnswer[depth] = end;
        //depth等于0的时候，end必须等于start
        assert(depth != 0 ||  end == start);
        if(end == start)
        {
            result.push_back(this->tmpAnswer);
        }
        else
        {
            for (auto i : predecessor[end])
            {
                buildAnswer(start, i, depth - 1);
            }
        }
    }
    void fastBfsPrint(int start, int end)
    {
        int one = 1;
        vector<int> all(this->graph.size(),one);
		all[end] = -1;
        vector<int> toTraverse;
        toTraverse.push_back(start);
        bool flag = false;
        int depth = 0;

        while(!flag)
        {
            auto tmp = toTraverse;
			for(auto origin : toTraverse)
			{
				if (origin == this->allStart)
				{
					this->allStart += all[origin];
				}
				else
				{
					//找到前面的
					int i = origin - 1;
					for(;i >= this->allStart;i--)
					{
						if(all[i])break;
					}
					if(i >= 0)all[i] += all[origin];
				}
				all[origin] = 0;
			}
            toTraverse.clear();
            if(tmp.size() == 0)
                flag = true;
            else
                depth++;
            for(auto node : tmp)
            {
                buildNodeGraph(node,all);
                for(auto peer : this->graph[node])
                {
                    if (all[peer])
                    {
                        this->predecessor[peer].insert(node);
                        toTraverse.push_back(peer);
                    }
                    if (peer == end)
                        flag = true;
                }
            }
        }

        //开始构建答案
        tmpAnswer.resize(depth + 1);
        buildAnswer(start,end,depth);
    }
	bool isContiguous(const string& a, const string& b)
	{
		//ai和bi放寄存器，经过查看汇编，这样优化效果很明显，否则编译器会把他们放栈里，存取很慢
		register auto ai = a.c_str();
		register auto bi = b.c_str();
		//不会有完全相同的a和b
		while(*ai++ == *bi++);
		while(*ai && *ai == *bi)ai++,bi++;
		return *ai == 0;
	}

    void buildNodeGraph(int node, const vector<int>& alter)
    {
        if(this->graph[node].size() != 0)return;
		//这里都使用原生指针，防止额外的开销
		int size = alter.size();
		auto ptr = &(this->wordList[0]);
		auto alterptr = &alter[0];
		for(int idx = this->allStart; ;)
        {
			int tmp = alterptr[idx];
            if(isContiguous(ptr[idx],ptr[node]))
            {
                this->graph[node].push_back(idx);
            }
			idx += tmp;
			if(tmp == -1)break;
        }
    }

	public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		//思路：构成图，然后找最短路径
		vector<vector<string>> res;
		vector<string> vec;
		vec.push_back(beginWord);
		vec.insert(vec.end(), wordList.begin(), wordList.end());
		vec.push_back(endWord);

        this->wordList = vec;
        this->graph.resize(vec.size());
		//wordGraph(vec);

		this->fastBfsPrint(0,vec.size() - 1);
		
		//构造结果
		for(auto& mvec : this->result)
		{
			vector<string> tmp;
			for(auto i : mvec)
			{
				tmp.push_back(vec[i]);
			}
			res.push_back(tmp);
		}
        return res;
	}
};

int main()
{
    unordered_set<string> s = {"hot","dot","dog","lot","log"};
	string start = "hit";
	string end = "cog";
    Solution a;
    auto tmp = a.findLadders(end,start,s);

    for(auto& vec : tmp)
    {
        for(auto& str:vec)
            cout<<str<<'\t';
        cout<<endl;
    }
}
