class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount(26);
        int result = 0, taskSize = 0;
        for (auto c : tasks) {
            if (0 == taskCount[c - 'A']++) {
                taskSize++;
            }
        }
        sort(taskCount.begin(), taskCount.end(), greater<int>());
        while (1) {
            int slots = n + 1;
            if (slots >= taskSize) {
                result += (taskCount[0] - 1) * slots;
                int c = 0;
                for (; c < taskSize; c++) {
                    if (taskCount[c] != taskCount[0]) {
                        break;
                    }
                }
                result += c;
                break;
            }
            int diff = taskCount[slots - 1] - taskCount[slots] + 1;
            for (int i = 0; i < slots; i++) {
                taskCount[i] -= diff;
                result += diff;
            }
            sort(taskCount.begin(), taskCount.begin() + taskSize, greater<int>());
            while (taskSize > 0 && taskCount[taskSize - 1] == 0) {
                taskSize--;
            }
        }
        return result;
    }
};