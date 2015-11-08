#include<string>
#include<vector>
#include<set>
using namespace std;
class ShortestPath
{
	char** graph;
	vector<int> completeNode;
	set<int,int> processingNode;
	//第一项是
	unordered_set<int,pair<int,int>> knownNode;
	map<int,vector<int>> predecessorNode;

	//i -> j
	void relax(int i, int j)
	{
		int weight = graph[i][j];
		if(weight == 1)
		{
			if(processingNode[i] != -1)
			{
				processingNode[i] = 
			}
		}
	}
	public:
	ShortestPath(char** _graph):graph(_graph){}

	vector<vector<int>> getPath()
	{

	}	
};
class Solution {
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
		char** graph = new char[vec.size()][vec.size()];
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
		vector<string> vec;
		vec.push_back(beginWord);
		vec.insert(vec.end(), wordList.begin(), wordList.end());
		vec.push_back(endWord);

		char** graph = wordGraph(vec);

		//运行最短路径算法
	}
};
