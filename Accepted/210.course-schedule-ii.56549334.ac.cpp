/*
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii
 *
 * Medium (27.40%)
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
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So the correct course order is [0,1]
 * 
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have
 * finished both courses 1 and 2. Both courses 1 and 2 should be taken after
 * you finished course 0. So one correct course order is [0,1,2,3]. Another
 * correct ordering is[0,2,1,3].
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
 * This problem is equivalent to finding the topological order in a directed
 * graph. If a cycle exists, no topological ordering exists and therefore it
 * will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
#include <vector>
#include <unordered_set>
#include <list>
using namespace std;
class Solution {
	unordered_set<int> visited;
	vector<list<int>> table;
	vector<int> result;
	unordered_set<int> added;
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
			if (added.find(start) == added.end()) {
				added.insert(start);
				result.push_back(start);
			}
			v.erase(start);
			return true;
		}
	}
	public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
					return {};
				}
			}
			if (visited.size() == numCourses) {
				return result;
			}
		}
		return {};
	}
};

