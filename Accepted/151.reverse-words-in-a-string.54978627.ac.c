/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string
 *
 * Medium (15.71%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * 
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * 
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * 
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 * 
 * 
 */
void reverse(char* l, char* r)
{
	while (r > l) {
		char tmp = *r;
		*r = *l;
		*l = tmp;
		l++;
		r--;
	}
}

void reverseWords(char *s) {
	//先把字符串整个翻转，然后分别翻转每一个词
	size_t len = strlen(s);
	if (!len) {
		return;
	}

	char* l = s, *r = s + len - 1;
	reverse(l, r);

	l = s;
	while (*l == ' ') l++;
	r = l;
	char* rightPlace = s;

	if (!*l) {
		*s = '\0';
		return;
	}

	while (*l) {
		while (*r != ' ' && *r) {
			r++;
		}

		reverse(l, r - 1);
		memmove(rightPlace, l, r - l);
		rightPlace += r - l;

		while(*r == ' ') {
			r++;
		};
		if (*r) {
			*rightPlace = ' ';
			rightPlace++;
		} else {
			*rightPlace = '\0';
		}

		l = r;
	}
}
