/*
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words
 *
 * Hard (21.90%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '123'
 *
 * 
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 231 - 1.
 * 
 * 
 * For example,
 * 
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 */
class Solution {
	map<int, string> spec = {
		{1,"One"},
		{2,"Two"},
		{3,"Three"},
		{4,"Four"},
		{5,"Five"},
		{6,"Six"},
		{7, "Seven"},
		{8, "Eight"},
		{9, "Nine"},
		{10, "Ten"},
		{11, "Eleven"},
		{12, "Twelve"},
		{13, "Thirteen"},
		{14, "Fourteen"},
		{15, "Fifteen"},
		{16, "Sixteen"},
		{17, "Seventeen"},
		{18, "Eighteen"},
		{19, "Nineteen"},
	};
	map<int, string> ten = {
		{2, "Twenty"},
		{3, "Thirty"},
		{4, "Forty"},
		{5, "Fifty"},
		{6, "Sixty"},
		{7, "Seventy"},
		{8, "Eighty"},
		{9, "Ninety"},
	};
	map<int, string> thousand = {
		{1, "Thousand"},
		{2, "Million"},
		{3, "Billion"},
	};

	vector<string> getLessThanThousand(int ge, int shi, int bai)
	{
		vector<string> res;
		if (bai > 0)
		{
			res.push_back(spec[bai]);
			res.push_back("Hundred");
		}
		if (shi == 0 && ge == 0)
		{
			return res;
		}
		if (shi <= 1)
		{
			res.push_back(spec[shi * 10 + ge]);
		}
		else
		{
			res.push_back(ten[shi]);
			if (ge > 0) res.push_back(spec[ge]);
		}
		return res;
	}
	public:
	string numberToWords(int num) {
		vector<string> res;
		int i = 0;
		while(num)
		{
			int ge = num % 10; num /= 10;
			int shi = num % 10; num /= 10;
			int bai = num % 10; num /= 10;
			auto ret = getLessThanThousand(ge, shi, bai);
			if (i > 0 && !ret.empty())
			{
				res.insert(res.begin(), thousand[i]);
			}
			res.insert(res.begin(), ret.begin(), ret.end());
			i++;
		}
		if (res.empty())
		{
			return "Zero";
		}
		stringstream ss;
		ss << res[0];
		for (int j = 1; j < res.size(); j++)
		{
			ss << " " << res[j];
		}
		return ss.str();
	}
};
