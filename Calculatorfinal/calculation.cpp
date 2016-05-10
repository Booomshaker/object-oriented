#include"calculation.h"
#include<sstream>
using namespace std;
string calculation::ToCalculate(queue<string> some)
{
	queue<string> res;
	stack<string> sig;
	stack<double> num;
	double numt,t1,t2;
	string s = "0";
	stringstream str;
	
	string temp;
	if(some.front()[0] == '-')//首位负号情况 
		res.push(s);
	while(some.size()>0)
	{
		temp = some.front();
		bool isNumber = (temp[0] >= '0'&&temp[0] <= '9') || (temp.size()>1) ;
		if(isNumber)
			res.push(temp);			
		else
		{
			if(sig.empty()) sig.push(temp);        //空栈情况要先考虑！不然后面的s.top无效 ！ 
			else if(temp[0] == ')')
			{
				while(sig.top() != "(")//
				{
					temp = sig.top();
					res.push(temp);
					sig.pop();
				}
				sig.pop();
			}
			else if(temp[0] == '+'||temp[0] == '-')
			{
				while(sig.size() > 0)
				{
					if(sig.top()[0] == '(') break;
					temp = sig.top();
					res.push(temp);
					sig.pop();				
				}
				temp = some.front();
				sig.push(temp);
			}
			else if(temp[0] == '*'||temp[0] == '/')
			{
				while(sig.top()[0] == '*'||sig.top()[0] =='/') 
				{
					temp = sig.top();
					res.push(temp);
					sig.pop();
					if(sig.size() == 0) break;
				}
				temp = some.front();
				sig.push(temp);
			}
			else sig.push(temp);
		}
		some.pop();
	}
	while(sig.size() > 0)
	{
		temp = sig.top();
		res.push(temp);
		sig.pop();
	}
	/*中缀表达式转后缀表达式 原理：如果是数字就直接push进入后缀表达式队列，如果是符号就判断一下优先级关系。
	若栈顶的优先级小于当前符号的优先级，符号push进入符号栈；否则栈元素依次弹出，进入后缀表达式队列。最后得到的就是后缀队列。*/ 

	
	while(res.size() > 0)
	{
		temp = res.front();
		bool isNumber = (temp[0] >= '0' && temp[0] <= '9') || ( temp.size()>1);
		if(isNumber)
		{
			str << temp;
			str >> numt;
			num.push(numt);
			str.clear();
		}
		else
		{
			t2 = num.top();
			num.pop();
			t1 = num.top();
			num.pop();
			if(temp[0] == '+') t1 = t1 + t2;
			if(temp[0] == '-') t1 = t1 - t2;
			if(temp[0] == '*') t1 = t1 * t2;
			if(temp[0] == '/') t1 = t1 / t2;
			num.push(t1);
		}
		res.pop();
	}
	/*后缀表达式计算结果 原理：从左到右遍历表达式的每个数字和符号，遇到是数字就进栈；
	遇到是符号，就将处于栈顶两个数字出栈，进行运算，运算结果进栈，一直到最终获得结果。*/ 
	str << num.top();
	str >> temp;
	str.clear();
	num.pop();	
	return temp;
} 
