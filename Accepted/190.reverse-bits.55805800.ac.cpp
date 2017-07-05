/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits
 *
 * Easy (29.52%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * 
 * Related problem: Reverse Integer
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			uint32_t res = 0;
			int i = 31;
			while (i--) {
				res |= (n & 1);
				res <<= 1;
				n >>= 1;
			}
			return  res | (n & 1);;
		}
};
