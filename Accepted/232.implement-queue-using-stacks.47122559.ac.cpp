/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks
 *
 * Easy (36.37%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * 
 * peek() -- Get the front element.
 * 
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
class Queue {
	stack<int> a;
	stack<int> b;
	public:
	// Push element x to the back of queue.
	void push(int x) {
		a.push(x);
	}

	void transfer()
	{
		int i = a.size();
		while(i--)
		{
			b.push(a.top());
			a.pop();
		}
	}
	// Removes the element from in front of queue.
	void pop(void) {
		if(b.size())b.pop();
		else
		{
			transfer();
			b.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if(b.size())return b.top();
		else
		{
			transfer();
			return b.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return b.size() + a.size() == 0;
	}
};
