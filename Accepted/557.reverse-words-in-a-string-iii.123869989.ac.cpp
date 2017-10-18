class Solution {
public:
    string reverseWords(string str) {
        string res;
	    int len = 0;
        for (int idx = 0; idx <= str.length(); idx++)
        {
            if (idx < str.length() && !isspace(str[idx]))
            {
                len++;
            }
            else 
            {
                //isspace
                string tmp = str.substr(idx - len, len); 
                res += string(tmp.rbegin(), tmp.rend());
                len = 0;
                if (idx != str.length())
                {
                    res += " ";
                }
            }
        }
        return res;
    }
};