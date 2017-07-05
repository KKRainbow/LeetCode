/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii
 *
 * Hard (13.99%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * 
 * For example,
 * 
 * 
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 
 * Return
 * 
 * ⁠ [
 * ⁠   ["hit","hot","dot","dog","cog"],
 * ⁠   ["hit","hot","lot","log","cog"]
 * ⁠ ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/20):
 * The wordList parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
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
	int depth = INT_MAX;
	list<vector<int>> result;
	vector<int> tmp;
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

