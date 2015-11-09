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
	int depth = INT_MAX;
	list<vector<int>> result;
	vector<int> tmp;
    map<int,set<int>> predecessor;

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
        set<int> all;
        for(int i = 0;i<this->graph.size();i++)
        {
            all.insert(i);
        }
        set<int> toTraverse;
        toTraverse.insert(start);
        bool flag = false;
        int depth = 0;

        while(!flag)
        {
            set<int> tmp = toTraverse;
            set<int> tmpAll;
            //set_difference(all.begin(),all.end(),toTraverse.begin(),toTraverse.end(),inserter(tmpAll,tmpAll.begin()));
            for(auto& origin:all)
            {
                if(toTraverse.find(origin) == toTraverse.end())
                {
                    tmpAll.insert(origin);
                }
            }
            all = tmpAll;
            toTraverse.clear();
            if(tmp.size() == 0)
                flag = true;
            else
                depth++;
            for(auto node : tmp)
            {
                for(auto peer : this->graph[node])
                {
                    if (all.find(peer) != all.end())
                    {
                        this->predecessor[peer].insert(node);
                        toTraverse.insert(peer);
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
	void wordGraph(const vector<string>& vec)
	{
        this->graph.resize(vec.size());
		for(int i = 0; i < vec.size(); i++)
		{
			for(int j = i; j< vec.size(); j++)
			{
				if (isContiguous(vec[i], vec[j]))
				{
                    this->graph[i].push_back(j);
                    this->graph[j].push_back(i);
				}
			}
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

        auto iter = vec.begin();
        for(auto i = 0;i<vec.size();i++)cout<<i<<' '<<*iter++<<endl;
		wordGraph(vec);

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
	vector<vector<string>> param = 
	{
		    {"hit","hot","dot","dog","cog"},
			{"hit","hot","lot","log","cog"}
	};
    unordered_set<string> s = 
    {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};

    string start = "cet";
    string end = "ism";
    /*
    {"hot","dot","dog","lot","log"};
	string start = "hit";
	string end = "cog";
    */
    Solution a;
    auto tmp = a.findLadders(start,end,s);

    for(auto& vec : tmp)
    {
        for(auto& str:vec)
            cout<<str<<'\t';
        cout<<endl;
    }
}
