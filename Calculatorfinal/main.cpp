#include <iostream>
#include "print.h"
#include "scan.h"
#include "calculation.h"
#include <sstream>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	scan sc;
	//print pr;
	calculation ca;
	string input,st;
	int i = 0;
	
	input = argv[argc - 1];//�����һ��������������ʽ�����input 
	queue <string> result = sc.ToStringQueue(input);
	stack <double> output = ca.ToStack(result);
	for(i = 0;i < argc;i++)
	{
		st = argv[i];
		//cout<<st<<endl; 
		if(st == "-a")
			{
				cout << input << " = ";
				break;
			}
	}//�������в������ж��Ƿ��С�-a �� 

	cout << output.top() << endl;
	/*pr.PrintStringQueue (result);  */
	return 0;
}
