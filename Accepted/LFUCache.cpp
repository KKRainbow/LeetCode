#include <string>
#include <string>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
	unordered_map<int, pair<int, list<pair<int, int>>::iterator>> hash_map;

	//key, counter
	list<pair<int, int>> counter_list;
	int cap;
	
public:
    LFUCache(int capacity) {
        hash_map.reserve(capacity);
		cap = capacity;
    }

	void access_elem(list<pair<int, int>>::iterator& iter)
	{
		auto newiter = iter;
		iter->second += 1;
		int new_counter = iter->second;
		advance(newiter, 1);
		counter_list.erase(iter);
		for (;newiter != counter_list.end() && newiter->second <= new_counter; newiter++);
		iter = counter_list.insert(newiter, {iter->first, new_counter});
	}
    
    int get(int key) {
		try {
			auto& s = hash_map.at(key);
			access_elem(s.second);
			return s.first;
		}
		catch(...)
		{
			return -1;
		}
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
		try {
			auto& s = hash_map.at(key);
			access_elem(s.second);
			s.first = value;
		}
		catch(...)
		{
			if (hash_map.size() >= cap)
			{
				auto be = counter_list.begin();
				int del = be->first;
				hash_map.erase(del);
				counter_list.erase(be);
			}
			counter_list.push_front({key, 0});
			auto iter = counter_list.begin();
			access_elem(iter);
			hash_map[key] = {value, iter};
		}
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
	LFUCache c(1);
	c.put(1, 1);
	c.put(2, 2);
	cout << c.get(1) << endl;
	c.put(3, 3);
	cout << c.get(2) <<endl;
	return 0;
}
