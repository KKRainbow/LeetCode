/*
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification
 *
 * Hard (18.83%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[""]\n0'
 *
 * 
 * Given an array of words and a length L, format the text such that each line
 * has exactly L characters and is fully (left and right) justified.
 * ⁠
 * 
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly L characters.
 * 
 * 
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the
 * right.
 * 
 * 
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * 
 * 
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * 
 * 
 * 
 * Return the formatted lines as:
 * 
 * [
 * ⁠  "This    is    an",
 * ⁠  "example  of text",
 * ⁠  "justification.  "
 * ]
 * 
 * 
 * 
 * 
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * 
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * A line other than the last line might contain only one word. What should you
 * do in this case?
 * In this case, that line should be left-justified.
 * 
 * 
 */
class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			auto it = words.begin();
			vector<string> line;
			vector<string> result;
			line.reserve(20);
			int remain = maxWidth;
			while(it != words.end())
			{
				line.push_back(*it);
				remain -= it->size();
				it++;
				while(it != words.end())
				{
					if(it->size() + 1 <= remain)
					{
						line.push_back(*it);
						remain -= it->size() + 1;
						it++;
					}
					else
					{
						break;
					}
				}

				if(line.size() != 1)
				{
					int space = remain / (line.size() - 1);
					int remainder = remain % (line.size() - 1);
					string tmp;
					for(int i = 0;i<line.size();i++)
					{
						auto pos = 0;
						tmp.append(line[i]);
						if(i!=line.size() - 1)
						{
							int s = (remain > space?space:remain) + 1;
							if(remainder > 0)s++,remainder--;
							if(it == words.end())s = 1;
							tmp.append(s,' ');
							//小于0之后不会运行到这里
							remain -= s  - 1;
						}
					}
					if(it == words.end())tmp.append(remain,' ');
					result.push_back(tmp);
				}
				else
				{
					string tmp;
					tmp += line[0];
					tmp.append(remain,' ');
					result.push_back(tmp);
				}
				line.clear();
				remain = maxWidth;
			}
			return result;
		}
};


