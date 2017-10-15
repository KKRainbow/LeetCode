/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int depthSumAux(vector<NestedInteger>& nestedList, int depth = 1) {
        int res = 0;
        for (auto& l : nestedList) {
            if (l.isInteger()) {
                res += depth * l.getInteger();
            } else {
                res += depthSumAux(l.getList(), depth + 1);
            }
        }
        return res;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSumAux(nestedList);
    }
};