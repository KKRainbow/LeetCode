//这真的是简单的不能再简单的一道题了= =

//解法1：不经思考的递归解法，也就是让计算机完整的玩一遍游戏
//为了防止重复计算，才用了带备忘的自顶向下方法。
class Solution {
    unordered_map<int,bool> cache;
    public:
        bool canWinNim(int n) {
            try
            {
                return cache.at(n);
            }
            catch(...)
            {
                bool res;
                if (n<= 3)res = true;
                else
                {
                    res = !canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3); 
                }
                cache[n] = res;
                return res;
            }
        }
};


//解法2：思考的结果。如果只有1,2,3个那肯定可以赢，如果有4个，那么无论怎么取对方都会赢，如果有5,6,7个那么我们可以取得只剩4个，那对方肯定输，以此类推，只要不是4的倍数，我们就能赢，所以，解只需要一行

class Solution {
public:
    bool canWinNim(int n) {
        return n & 0b11;
        //或者
        return n % 4 != 0;
    }
};
