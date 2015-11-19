#include<iostream>
//一个O(n^2*m)的算法 
using namespace std;
struct TrieNode
{
	map<char,set<TrieNode*>> child;
}
class Trie
{
	vector<TrieNode*> root;
	public:
		Trie(vector<string>& strs)
		{
			root.resize(26);
			for(auto& str:strs)
			{
				auto c0 = str[0];
				TrieNode* step = root[c0 - 'a']; 
				if(!step)
				{
					step = new TrieNode();
					root[c0 - 'a'] = step; 
				}
				for(int i = 1;i<str.size();i++)
				{
					auto c = str[i];
					auto tmp =  new TrieNode();
					step->child[c].insert = tmp;
					step = tmp;
				}
			}
		}
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{

    }
};
int main()
{
}
