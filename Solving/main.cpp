#include<iostream>
#include<unordered_map>
#include<cmath>
#include<vector>
#include<map>
#include<set>
//一个O(n^2*m)的算法 
using namespace std;
struct TrieNode
{
	string str;
	//已经访问过的点，当前字符的坐标
	//pair没法hash，当然可以用数字来定位，但是比较麻烦
	vector<pair<set<pair<int,int>>,pair<int,int>>> media;
	map<char,TrieNode*> child;
};
//边上记录字符的Trie树
class Trie
{
	public:
		TrieNode root;
		Trie(const vector<string>& strs, int n)
		{
			n *=n;
			auto* step = &root;
			for(auto& str : strs)
			{
				if(str.size() > n)continue;

				for(int i = 0;i<str.size();i++)
				{
					auto c = str[i];
					try 
					{
						step = step->child.at(c);
					}
					catch(...)
					{
						auto tmp =  new TrieNode();
						step->child[c] = tmp;
						step = tmp;
					}
				}
				step->str = str;
			}
		}
};
class Solution {
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
	void searchAnswer(TrieNode* node, TrieNode* parent, char curr)
	{
		auto& pointsVec = hash[curr];
		for(auto& point : pointsVec)
		{
			if(parent->media.size() == 0)
			{
				//跟节点。还没有已经访问过的点
				set<pair<int,int>> tmp;
				tmp.insert(point);
				node->media.push_back(make_pair(tmp,point));
			}
			else
			{
				bool flag = false;
				if(node->str.size() != 0 && node->child.size() == 0)//叶子节点
				{
					flag = true;
				}
				for(auto& med : parent->media)
				{
					auto& visited = med.first;
					auto& currp = med.second;

					if(isAdjacent(currp.first,currp.second,point.first,point.second) && visited.find(point) == visited.end())
					{
						if(flag)
						{
							result.push_back(node->str);
							return;
						}
						node->media.push_back(make_pair(visited,point));
						node->media.back().first.insert(point);
					}
				}
			}
		}
		if(node->str.size() != 0 && node->media.size() != 0)
		{
			result.push_back(node->str);
		}
		for(auto& cp : node->child)
		{
			searchAnswer(cp.second, node, cp.first);
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{
		Trie trie(words,board.size());
		auto& root = trie.root;
		for(int i = 0;i<board.size();i++)
		{
			auto& vec = board[i];
			for(int j = 0;j<vec.size();j++)
				hash[vec[j]].push_back(make_pair(i,j));
		}
		
		for(auto& cp : root.child)
		{
			searchAnswer(cp.second, &root, cp.first);
		}
		return result;
    }
};
int main()
{
}
