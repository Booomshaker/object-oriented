#include"print.h"

void print::ToPrint (queue<string>ans,int flag,string outfile)
{
	if(flag == 1)
	{
		cout << ans.front() << "=";
		ans.pop();
		cout << ans.front() << endl;
	}
	else if(flag == 2)
	{
		cout << "Congratulations!" << endl;
		freopen(outfile.c_str(),"w",stdout);
		while(!ans.empty())
		{
			cout << ans.front() << endl;
			ans.pop();
		}
	}
	else
	{
		ans.pop();
		cout << ans.front() << endl; 
	}
	
}
	
