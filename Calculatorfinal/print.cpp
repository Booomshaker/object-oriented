#include"print.h"
void print::PrintStringQueue (queue<string> result)
	{
		while (result.size() > 0)
		{
			cout << result.front() << endl;//��ӡ���е���Ԫ�� 
			result.pop();//ɾ�����е���Ԫ�� 
		}	
	}
	
