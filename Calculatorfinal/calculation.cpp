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
	if(some.front()[0] == '-')//��λ������� 
		res.push(s);
	while(some.size()>0)
	{
		temp = some.front();
		bool isNumber = (temp[0] >= '0'&&temp[0] <= '9') || (temp.size()>1) ;
		if(isNumber)
			res.push(temp);			
		else
		{
			if(sig.empty()) sig.push(temp);        //��ջ���Ҫ�ȿ��ǣ���Ȼ�����s.top��Ч �� 
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
	/*��׺���ʽת��׺���ʽ ԭ����������־�ֱ��push�����׺���ʽ���У�����Ƿ��ž��ж�һ�����ȼ���ϵ��
	��ջ�������ȼ�С�ڵ�ǰ���ŵ����ȼ�������push�������ջ������ջԪ�����ε����������׺���ʽ���С����õ��ľ��Ǻ�׺���С�*/ 

	
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
	/*��׺���ʽ������ ԭ�������ұ������ʽ��ÿ�����ֺͷ��ţ����������־ͽ�ջ��
	�����Ƿ��ţ��ͽ�����ջ���������ֳ�ջ���������㣬��������ջ��һֱ�����ջ�ý����*/ 
	str << num.top();
	str >> temp;
	str.clear();
	num.pop();	
	return temp;
} 
