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
	int flag = 0; //������������ 
	
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
	}//�������в������ж��ǵڼ������ 

	if(flag == 2)
	{
		infile = argv[argc-2];
		outfile = argv[argc-1];
		freopen(infile.c_str(),"r",stdin);
		while(cin >> input)
		{
			result = sc.ToStringQueue(input);//�����ʽ������� 
			output = ca.ToCalculate(result);//�����ʽ��������
			ans.push(output); //���������������� 
		}
		
	}
	else
	{
		input = argv[argc-1];
		result = sc.ToStringQueue(input);//�����ʽ������� 
		output = ca.ToCalculate(result);//�����ʽ��������
		ans.push(input);
		ans.push(output);//���������������� 	
	}
	pr.ToPrint(ans,flag,outfile);
	return 0;
}
