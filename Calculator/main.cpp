#include <iostream>
#include "print.h"
#include "scan.h"
int main()
{
	scan sc;
	print pr;
	string input;
	cin >> input;
	queue <string> result = sc.ToStringQueue(input);
	pr.PrintStringQueue (result);
	return 0;
}
