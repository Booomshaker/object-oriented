#include"scan.h"
queue<string> scan::ToStringQueue(string input)
	{
		queue<string> result;
		for(int i = 0,digit = 0; i < input.size() ; i++) //����ַ�ɨ����ʽ 
		{
			bool isNumber = ((input[i] >= '0') && (input[i] <= '9'))||(input[i] == '.');//�ж��ַ��Ƿ�Ϊ���� 
			int y = digit;
			if (isNumber)
			{
				digit++;
				if (digit > 10) cout << "��������" << endl;
			}
			else digit = 0;
			//digit�����������ֳ��ָ��������ڳ��ִ���10λ����������� 
			
			if (y >= digit)
			{
				if(y > digit) result.push(input.substr(i-y,y));
				result.push(input.substr(i,1));				
			}
			//����Ƿ����򵥶�������У����������������������� 
			
			if(i == input.size()-1) 
			{ 
				if (digit!=0) result.push(input.substr(i-y,digit));
			} 
			else;
			//�Ա��ʽ�����һ���ַ��������� 
		}
		return result;
	}
