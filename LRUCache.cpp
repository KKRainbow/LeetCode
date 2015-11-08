#include<map>
#include<algorithm>
#include<climits>
#include<cassert>
using namespace std;
class LRUCache{
	struct LRULine;
	struct CacheLine
	{
		LRULine* lru_line_ptr;
		int val;
	};
	struct LRULine
	{
		CacheLine* cache_line_ptr;
		int counter;
		int key;
	};
	int counter = INT_MIN;
	map<int,CacheLine> cache;
	map<int,LRULine> lru;
	int capacity = 0;
	public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	inline void update_lru(LRULine* lru_line)
	{
		auto iter = lru.find(lru_line->counter);
		assert(iter != lru.end());
		auto newline = *lru_line;
		newline.counter = ++counter;
		auto new_iter = lru.insert(make_pair(newline.counter, newline));
		lru.erase(iter);
		newline.cache_line_ptr->lru_line_ptr = &new_iter.first->second;
	}
	inline void swap_out()
	{
		if (cache.size() < capacity)
		{
			return;
		}
		auto iter = lru.begin();
		auto num = cache.erase(iter->second.key);
		assert(num > 0);
		lru.erase(iter);
	}
	int get(int key) {
		int res = -1;
		try 
		{
			auto line = cache.at(key);
			int val = line.val;
			update_lru(line.lru_line_ptr);
			res = val;
		}
		catch(out_of_range& e)
		{
		}
		catch(...)
		{
		}
		return res;
	}
	void set(int key, int value) {
		try 
		{
			auto& line = cache.at(key);
			line.val = value;
			update_lru(line.lru_line_ptr);
		}
		catch(out_of_range& e)
		{
			swap_out();
			LRULine lru_line = {
				nullptr,
				++counter,
				key,
			};
			auto lru_iter = lru.insert(make_pair(lru_line.counter, lru_line));
			CacheLine cache_line = {
				&(lru_iter.first->second),
				value,
			};
			auto cache_iter = cache.insert(make_pair(key,cache_line));
			lru_iter.first->second.cache_line_ptr = &cache_iter.first->second;
			return;
		}
		catch(...)
		{
			return;
		}
		return;
	}
};
