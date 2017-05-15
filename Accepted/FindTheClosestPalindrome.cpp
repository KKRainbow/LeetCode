#include <string>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
private:
    string cur_palindrome_num, cur_min_palindrome;
    uint64_t min_diff = UINT64_MAX, origin_num, cur_min_num;
    
    uint64_t diff(uint64_t a, uint64_t b)
    {
        return a > b ? a - b : b - a;
    }
    
    bool is_all(const string& str, int idx, char c)
    {
        //判断str从idx位开始，到中心对称的另一位之间的数，是否都为c
        for (int i = idx; i < str.length() - idx; i++)
        {
            if (str[i] != c)
                return false;
        }
        return true;
    }
    
    void make_all(string& str, int idx, char c)
    {
        for (int i = idx; i < str.length() - idx; i++)
        {
            str[i] = c;
        } 
    }
    
	void try_update(const string& str)
	{
		uint64_t cur_num = strtoul(str.c_str(), nullptr, 10);
		uint64_t cur_diff = diff(cur_num, origin_num);
		//如果diff相同，选用更小的
		if (cur_diff && (cur_diff < min_diff || (cur_diff == min_diff && cur_min_num > cur_num)))
		{
			min_diff = cur_diff;
			cur_min_palindrome = str;
			cur_min_num = cur_num;
		}
	}
	
	bool is_palindrome(const string& n)
	{
	    for (int i = 0; i < (n.length() + 1) / 2; i++)
	    {
	        if (n[i] != n[n.length() - i - 1])
	            return false;
	    }
	    return true;
	}

public:
    string nearestPalindromic(string n) {
        origin_num = strtoul(n.c_str(), nullptr, 10);
        cur_palindrome_num = n;
        
        //如果小于一位，直接返回就行
        if (n.length() <= 1)
            return string(1, --n[0]);
        
		//如果是9999999那么结果一定是100000001
        if (is_all(n, 0, '9'))
            return "1" + string(n.length() - 1, '0') + "1";   
            
        //判断是否是x0000000000000x,有可能导致总位数减少
        if ((n[0] == n[n.length() - 1]) && is_all(n, 1, '0'))
        {
            //由于不可以是自身，第一位和最后一位相等且中间为0的都会导致位数减少
			if (n[0] == '1') {
				//100000000000001,总位数减小
				return string(n.length() - 1, '9');
			}
			else {
				//200000000000000002，总位数不变，首尾减1
				return char(n[0] - 1) + string(n.length() - 2, '9') + char(n[0] - 1);
			}
        }
        
		//1000000000000000000,位数减少
        if (n[0] == '1' && is_all(n, 1, '0') && n[n.length() - 1] == '0')
            return string(n.length() - 1, '9');
        

        
        //其他情况中，不可能导致总位数的变化，我们就从第一位到中间位循环并分情况讨论即可
        int i = 0;
        if (is_palindrome(n))
        {
			//如果已经是回文，从中间那一位开始讨论就行了
            i = (n.length() + 1) / 2 - 1;
        }
        for (; i < (n.length() + 1) / 2; i++)
        {
            //当前位会加1的情况
			//abcd9999dcba这种情况下d可能需要减小
            if (n[i] <= '8') //若果n[i]已经是9，那么上限有个abcd99999999dcba顶着，肯定不需要将d加1
            {
                string tmp = cur_palindrome_num;
                if (is_all(tmp, i + 1, '9'))
                {
					//变为abc(d+1)0000(d+1)cba
                    make_all(tmp, i + 1, '0');
                    tmp[n.length() - i - 1] = ++tmp[i];
					try_update(tmp);
                }  
            }
            
            //后讨论当前位会减1的情况，若当前位大于等于1，且中间位都位0，那么可能需要把该位减1
			//abcd0000dcba这种情况下d可能需要减小
            if (n[i] >= '1')//若n[i]为0，那么下限有abcd00000dcba顶着，肯定不需要将d减1
            {
                string tmp = cur_palindrome_num;
                if (is_all(tmp, i + 1, '0'))
                {
					//变为abc(d-1)9999(d-1)cba
                    make_all(tmp, i + 1, '9');
                    tmp[n.length() - i - 1] = --tmp[i];
					try_update(tmp);
                }
            }
            
            //当前位不变的情况。复制当前位到对称的地方， 直接开始讨论下一位
            cur_palindrome_num[n.length() - i - 1] = cur_palindrome_num[i]; 
        }
		//最后需要再update一下，不然最后一位生成的回文可能会没参加比较。
		try_update(cur_palindrome_num);

		return cur_min_palindrome.empty() ? cur_palindrome_num : cur_min_palindrome;
	}
};

int main()
{
	Solution s;
	cout << s.nearestPalindromic("1837722381") << endl;
}
