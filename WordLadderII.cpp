#include<string>
#include<vector>
#include<list>
#include<climits>
#include<set>
#include<unordered_set>
using namespace std;
//不用最短路径，BFS即可
class Solution {
	int depth = INT_MAX;
	list<vector<int>> result;
	vector<int> tmp;
	void bfsPrint(char** graph, int start, int end, set<int> s, int depth = 0)
	{
		tmp.push_back(start);

		s.erase(start);
		set<int> toTraverse;
		for(auto it = s.begin(); it != s.end(); )
		{
			if(graph[start][*it] == 1)
			{
				toTraverse.insert(*it);
				if(*it == end)
				{
					this->depth = depth;
					result.push_front(tmp);
					result.begin()->push_back(end);
					tmp.pop_back();
					return;
				}
				it = s.erase(it);
			}
		}
		if(depth < this->depth)
		{
			for(auto node : toTraverse)
			{
				bfsPrint(graph, node, end, s,depth + 1);
			}
		}
		tmp.pop_back();
	}
	bool isContiguous(string a, string b)
	{
		int i = 0;
		while(i < a.size() && a[i] == b[i])i++;
		//此处i是否可能等于size  - 1呢，如果等于的话说明两个字符串完全相等。
		//先假设没有完全相等的字符串吧。
		i++;
		while(i < a.size() && a[i] == b[i])i++;
		return i == a.size();
	}
	char** wordGraph(const vector<string>& vec)
	{
		char** graph = new char*[vec.size()];
		for(int i = 0;i<vec.size();i++)
		{
			graph[i] = new char[vec.size()];
		}
		for(int i = 0; i < vec.size(); i++)
		{
			graph[i][i] = 0;
			for(int j = i; j< vec.size(); j++)
			{
				char i = 0;
				if (isContiguous(vec[i], vec[j]))
				{
					i = 1;
				}
				graph[i][j] = i;
				graph[j][i] = i;
			}
		}
		return graph;
	}

	public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		//思路：构成图，然后找最短路径
		vector<vector<string>> res;
		vector<string> vec;
		vec.push_back(beginWord);
		vec.insert(vec.end(), wordList.begin(), wordList.end());
		vec.push_back(endWord);

		char** graph = wordGraph(vec);

		//运行最短路径算法
		set<int> startSet;
		for(int i = 0;i<vec.size();i++)
		{
			startSet.insert(i);
		}
		this->bfsPrint(graph,0,vec.size() - 1,startSet);
		
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
	}
};

int main()
{
	vector<vector<string>> param = 
	{
		    {"hit","hot","dot","dog","cog"},
			{"hit","hot","lot","log","cog"}
	};
	string start = "hit";
	string end = "cog";
}
