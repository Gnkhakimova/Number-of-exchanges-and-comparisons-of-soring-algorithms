#include<iostream>
using namespace std;

int main()
{

}
template <class Item_Type >
int linear_search(vector<Item_Type>& items, Item_Type& target, size_t pos_last)
{
	if (pos_last == items.size())
	{
		return -1;
	}
	if (target == items[pos_last])
	{
		return pos_last;
	}
	else
	{
		return linear_search(items, target, pos_last - 1);
	}
}

