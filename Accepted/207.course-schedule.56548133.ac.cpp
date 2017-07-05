/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule
 *
 * Medium (31.71%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
class Solution {
	unordered_set<int> visited;
	vector<list<int>> table;

	bool dfs(int start, unordered_set<int>& v)
	{
		if (v.find(start) != v.end()) {
			return false;
		} else {
			v.insert(start);
			visited.insert(start);
			for (auto node : table[start]) {
				if(!dfs(node, v)) {
					return false;
				}
			}
			v.erase(start);
			return true;
		}
	}
	public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		table = vector<list<int>>(numCourses, list<int>());
		vector<int> empNode(numCourses);
		for (auto& p : prerequisites) {
			table[p.first].push_back(p.second);
			empNode[p.second] = 1;
		}
		for (int i = 0; i < numCourses; i++) {
			if (empNode[i] == 0) {
				unordered_set<int> tmp;
				if (!dfs(i, tmp)) {
					return false;
				}
			}
			if (visited.size() == numCourses) {
				return true;
			}
		}
		return false;
	}
};
