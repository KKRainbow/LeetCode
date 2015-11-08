class Solution {
	static inline void exhaustNumber(string& s, int& start)
	{
		while(start < s.size() && (s[start] >= '0' && s[start] <= '9'))
		{
			start++;
		}
	}
	public:
	static inline bool stateMachine(string s)
	{
		int i = 0;
		enum state{
			INT,
			FLOAT,
			SCIENCE,
			SCIENCE_POSTFIX,
			INVALID,
		}curr = INT;
		int point,origin;
		for(;i<s.size();)
		{
			switch(curr)
			{
				case INT:
					if(s[i] == '+' || s[i] == '-')
					{
						i++;
						if(i == s.size())
						{
							curr = INVALID;
							break;
						}
					}
					exhaustNumber(s,i);
					if(i == s.size())break;
					else if(s[i] == '.')curr = FLOAT;
					//必须是小写e
					else if(s[i] == 'e')curr = SCIENCE;
					else curr = INVALID;
					break;
				case FLOAT:
					point = i;
					i++;
					exhaustNumber(s,i);
					//判断小数点的两边有没有数字,左边没，且右边没，则无效
					if((point == 0 || s[point - 1] == '+' || s[point-1] == '-') && point == i-1)
					{
						curr = INVALID;
						break;
					}
					if(i == s.size())break;
					//必须是小写e
					else if(s[i] == 'e')curr = SCIENCE;
					else curr = INVALID;
					break;
				case SCIENCE:
					//跳过e
					if(i == 0 || s[i - 1] == '+' || s[i - 1] == '-')
					{
						curr = INVALID;
						break;
					}
					i++;
					if(i == s.size())
					{
						curr = INVALID;
						break;
					}
					curr = SCIENCE_POSTFIX;
					if(s[i] == '+' || s[i] == '-')
					{
						i++;
						if(i == s.size())
						{
							curr = INVALID;
							break;
						}
					}
					break;
				case SCIENCE_POSTFIX:
					origin = i;
					exhaustNumber(s,i);
					if (i == origin)
					{
						curr = INVALID;
						break;
					}
					break;
				case INVALID:
					return false;
			}
		}
		return  curr != INVALID;
	}
	bool isNumber(string s) {
		auto begin = s.find_first_not_of(' ');
		auto last = s.find_last_not_of(' ') + 1;
		if(begin >= last)return false;
		return stateMachine(string(s,begin,last-begin));
	}
};
