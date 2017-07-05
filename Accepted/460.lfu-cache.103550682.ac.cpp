/*
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache
 *
 * Hard (23.22%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LFUCache cache = new LFUCache( 2 /* capacity */ );
* 
* cache.put(1, 1);
* cache.put(2, 2);
* cache.get(1);       // returns 1
* cache.put(3, 3);    // evicts key 2
* cache.get(2);       // returns -1 (not found)
* cache.get(3);       // returns 3.
* cache.put(4, 4);    // evicts key 1.
* cache.get(1);       // returns -1 (not found)
* cache.get(3);       // returns 3
* cache.get(4);       // returns 4
* 
* 
*/
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

