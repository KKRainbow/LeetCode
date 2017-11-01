class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int want = nums[0];
        int count[3] = {0, 0, 0};
        auto iter = nums.begin();
        while (iter != nums.end()) {
            if (*iter != want) {
                if (count[0] != 0 || count[1] != 0) {
                    return false;
                } else {
                    count[0] = count[1] = 0;
                    want = *iter;
                    continue;
                }
            }
            auto range = equal_range(iter, nums.end(), *iter);
            int n = range.second - range.first;
            if (n < count[0] + count[1]) {
                cout << "?" << endl;
                return false;
            }
            int tmpn = n;
            // 三个及三个以上，由两个的升上去的，已经挂到原来的上面的
            tmpn -= count[1] + min(count[2], n - count[0] - count[1]);
            count[2] = count[1] + min(count[2], n - count[0] - count[1]);
            // 两个
            tmpn -= count[0];
            count[1] = count[0];
            //
            count[0] = tmpn;
            iter = range.second;
            want++;
        }
        return count[0] == 0 && count[1] == 0;
    }
};