#pragma once

#include<string>
#include<vector>
#include<stack>


using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {

		if(tokens.size() == 0)
			return 0;
		stack<int> cal;
		int i = 0;
		int left = 0;
		int right = 0;
		char buffer[32];
		while( i < tokens.size())
		{
			if( tokens[i] == "+")
			{
				right = cal.top();
				cal.pop();
				left = cal.top();
				cal.pop();
				cal.push(left + right);
			}
			else if( tokens[i] == "-")
			{
				right = cal.top();
				cal.pop();
				left = cal.top();
				cal.pop();
				cal.push(left - right);
			}
			else if ( tokens[i] == "/")
			{
				right = cal.top();
				cal.pop();
				left = cal.top();
				cal.pop();
				cal.push(left/right);
			}
			else if (tokens[i] == "*")
			{
				right = cal.top();
				cal.pop();
				left = cal.top();
				cal.pop();
				cal.push(left*right);
			}
			else
			{
				cal.push(atoi(tokens[i].c_str()));
			}
			i++;
		}

		return cal.top();
    }
};