/************************************************************
  FileName:     main.cpp
  Author:       Mr.who     
  Version :     1.3      
  Date:         2016/05/09
  Description:  the main function file
  History:
  	<author>	<time>		  <version>	  <description>
  	Mr.who		16/03/20	    1.0       完成函数基本功能 
  	Mr.who      16/03/21	    1.1       添加注释
	Mr.who      16/04/11		1.2		  添加参数"-a"的情况
	Mr.who      16/05/07        1.3       添加参数"-f"的情况 
***********************************************************/

#include <iostream>
#include "print.h"
#include "scan.h"
#include "calculation.h"
#include <sstream>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	scan sc;
	print pr;
	calculation ca;
	int flag = 0; //标记是哪种情况 
	
	string input,st,output;
	
	string infile,outfile;	 
	queue <string> result;
	queue<string> ans;
	
	for(int i = 0;i < argc;i++)
	{
		st = argv[i];
		
		if(st == "-a")
			flag = 1;
		else if(st == "-f")
			flag = 2;
	}//遍历所有参数，判断是第几种情况 

	if(flag == 2)
	{
		infile = argv[argc-2];
		outfile = argv[argc-1];
		freopen(infile.c_str(),"r",stdin);
		while(cin >> input)
		{
			result = sc.ToStringQueue(input);//将表达式存入队列 
			output = ca.ToCalculate(result);//将表达式运算出结果
			ans.push(output); //将结果存入输出队列 
		}
		
	}
	else
	{
		input = argv[argc-1];
		result = sc.ToStringQueue(input);//将表达式存入队列 
		output = ca.ToCalculate(result);//将表达式运算出结果
		ans.push(input);
		ans.push(output);//将结果存入输出队列 	
	}
	pr.ToPrint(ans,flag,outfile);
	return 0;
}
