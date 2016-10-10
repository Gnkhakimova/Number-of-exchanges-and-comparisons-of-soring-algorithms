#include<string>
#include<iostream>
#include<cctype>
using namespace std;

int to_number(string value, int start_pos, int sum);

int main()
{
	string value;
	int sum = 0;
	cin >> value;
	int start_pos = 0;
	int result = to_number(value,start_pos, sum);
	cout<< result;
	return 0;
}

int to_number(string value, int start_pos, int sum)
{
	if (value.empty())
		return -1;

	if (isdigit(value[start_pos])&& value[start_pos]!=NULL)
	{
		int temp= (int)value[start_pos]-48;
		sum += temp;
		return to_number(value, start_pos + 1, sum);
	}
	else if(!isdigit(value[start_pos])&& value[start_pos] != NULL)
	{
	return to_number(value, start_pos + 1, sum);
	}

	return sum;

	
}