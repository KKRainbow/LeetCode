class Solution {
public:
    int reachNumber(int64_t target) {
        target = abs(target);
        // 1 + 2 + ... + n，找出最大的n使该和大于等于target
        int max_n = (sqrt(1 + 8 * target) - 1) / 2;
        while ((max_n * (max_n + 1)) / 2 < target) max_n++;
        
        // 得到1 + 2 + .... + max_n 与 target 的差值
        int diff = ((max_n * (max_n + 1)) / 2) - target;
        
        // 这个时候，要从[1-max_n]中选一个，把其符号变成负号，消去diff，每改一个符号，会减少两倍的该数，因此diff一定是偶数。
        // 又考虑到 diff / 2 一定比diff小，diff / 2 < diff < max_n, 因此一定能在1-max_n中找到diff / 2并将其消去。
        // 考虑到diff为奇数数时肯定消不掉，diff为偶数时只用一个数就能消掉，所以只要找到使diff为偶数的最大n就行。
        // 事实上考虑到使 diff(奇数) + x + (x + 1) + ... + (x + m) 为偶数的m满足条件 m <= 1，因此只要判断两次就行，下面这个循环是没有必要的。
        while (diff % 2 != 0) {
            max_n++;
            diff = ((max_n * (max_n + 1)) / 2) - target;
        }
        
        return max_n;
    }
};
