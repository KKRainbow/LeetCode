/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence
 *
 * Medium (28.16%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
	uint64_t fac[11];
	private:
	void getFac()
	{
		fac[0] = fac[1] = 1;
		for (int i = 2; i < 10; i++) {
			fac[i] = fac[i - 1] * i;
		}
	}
	public:
	string getPermutation(int n, int k) {
		set<int> s;
		string res;
		k--;

		getFac();

		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}

		for (int i = n - 1; i > 0; i--) {
			int mod = k % fac[i];
			int div = k / fac[i];
			auto iter = s.begin();
			advance(iter, div);
			res.push_back(*iter + '0');
			s.erase(iter);
			k = mod;
		}
		res.push_back(*s.begin() + '0');
		return res;
	}
};
