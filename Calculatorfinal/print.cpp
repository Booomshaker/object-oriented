#include"print.h"
void print::PrintStringQueue (queue<string> result)
	{
		while (result.size() > 0)
		{
			cout << result.front() << endl;//打印队列的首元素 
			result.pop();//删除队列的首元素 
		}	
	}
	
