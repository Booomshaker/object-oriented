#include "stdafx.h"
#include "Scanner.h"


queue<string> Scanner::ToStringQueue(string input)
{
	queue<string> result;
	for (int i = 0, digit = 0, z = 0; i < input.size(); i++) //逐个字符扫描表达式 
	{
		bool isNumber = ((input[i] >= '0') && (input[i] <= '9')) || (input[i] == '.');//判断字符是否为数字 
		int y = digit;
		bool isMinus = (z == 1 && input[i] == '-');


		if (isNumber || isMinus)
		{
			digit++;
			if (digit > 10) cout << "出错啦！" << endl;
		}
		else digit = 0;
		//digit变量计算数字出现个数，并在出现大于10位数的情况报错 

		if (y >= digit)
		{
			if (y > digit) result.push(input.substr(i - y, y));
			result.push(input.substr(i, 1));
		}
		//如果是符号则单独传入队列，如果是数字则整串传入队列 

		if (i == input.size() - 1)
		{
			if (digit != 0) result.push(input.substr(i - y, digit));
		}
		else;
		//对表达式的最后一个字符单独处理 

		if (input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			z = 1;
		else z = 0;
		//判断负数 
	}
	return result;
}