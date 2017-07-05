/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii
 *
 * Hard (23.11%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["oaan","etae","ihkr","iflv"]\n["oath","pea","eat","rain"]'
 *
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * For example,
 * Given words = ["oath","pea","eat","rain"] and board = 
 * 
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 
 * Return ["eat","oath"].
 * 
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 * 
 * 
 * click to show hint.
 * 
 * You would need to optimize your backtracking to pass the larger test. Could
 * you stop backtracking earlier?
 * 
 * If the current candidate does not exist in all words' prefix, you could stop
 * backtracking immediately. What kind of data structure could answer such
 * query efficiently? Does a hash table work? Why or why not? How about a Trie?
 * If you would like to learn how to implement a basic trie, please work on
 * this problem: Implement Trie (Prefix Tree) first.
 * 
 */
#pragma GCC optimize ("O3")
#include<iostream>
#include<algorithm>
#include<memory>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#define I(x,y) (x*dim + y)
//一个O(n^2*m)的算法
using namespace std;
struct TrieNode
{
	//已经访问过的点，当前字符的坐标
	//pair没法hash，当然可以用数字来定位，但是比较麻烦
	list<pair<vector<int>,pair<int,int>>> media;
	map<char,shared_ptr<TrieNode>> child;
};
//边上记录字符的Trie树
class Solution {
	shared_ptr<TrieNode> root;
	void buildTrie(const vector<string>& strs)
	{
		//不一定是方阵
		auto n = dim * dimy;
		root = make_shared<TrieNode>();
		auto size = strs.size();
		auto firstc = strs[0][0];

		for(int idx = 0;idx<size;idx++)
		{
			auto& str = strs[idx];
			auto step = root;
			auto parent = root;
			if(str[0] != firstc)
			{
				step->child[firstc].reset();
				firstc = str[0];
			}
			if(str.size() > n)
			{
				continue;
			}
			int i = 0;
			for(;i<str.size();i++)
			{
				auto c = str[i];
				try
				{
					step = step->child.at(c);
				}
				catch(...)
				{
					step = step->child[c] =  make_shared<TrieNode>();
					searchAnswer(step, parent, c);
				}
				if(step->media.size() == 0)
				{
					break;
				}
				parent = step;
			}
			//防止有重复。

			if(i == str.size() && step->child[0] != root)
			{
				step->child[0] = root;
				result.push_back(str);
			}
		}
	}

	int dim;
	int dimy;
	vector<string> result;
	unordered_map<char,vector<pair<int,int>>> hash;
	bool isAdjacent(int x0,int y0,int x1,int y1)
	{
		if(x0 == x1)
			return abs(y0-y1) == 1;
		if(y0 == y1)
			return abs(x0-x1) == 1;
		return false;
	}
	void searchAnswer(shared_ptr<TrieNode>& node, shared_ptr<TrieNode>& parent, char curr)
	{
		auto& pointsVec = hash[curr];
		if(pointsVec.size() == 0)return;
		if(parent != this->root && parent->media.size() == 0)
		{
			return;
		}
		for(auto& point : pointsVec)
		{
			if(parent->media.size() == 0)
			{
				//跟节点。还没有已经访问过的点
				//vector<int> tmp;
				//tmp.push_back(I(point.first,point.second));
				//node->media.push_back(make_pair(tmp,point));
				node->media.emplace_back(make_pair(vector<int>(),point));
				node->media.back().first.push_back(I(point.first,point.second));
			}
			else
			{
				for(auto& med : parent->media)
				{
					auto& visited = med.first;
					auto& currp = med.second;
					if(isAdjacent(currp.first,currp.second,point.first,point.second) && find(visited.begin(),visited.end(),I(point.first,point.second)) == visited.end())
					{
						node->media.push_back(make_pair(visited,point));
						node->media.back().first.push_back(I(point.first,point.second));
					}
				}
			}
		}

	}
	public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		//卧曹这里千万别把行列搞混啊= =
		dimy = board.size();
		if(board.size() == 0)return result;
		dim = board[0].size();
		for(int i = 0;i<board.size();i++)
		{
			auto& vec = board[i];
			for(int j = 0;j<vec.size();j++)
			{
				hash[vec[j]].push_back(make_pair(i,j));
			}
		}

		sort(words.begin(),words.end());
		if(words.size() != 0)buildTrie(words);
		return result;
	}
};
