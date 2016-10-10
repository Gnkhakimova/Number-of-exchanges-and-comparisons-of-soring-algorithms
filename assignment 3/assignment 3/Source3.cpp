#include<iostream>
using namespace std;


struct Node {
	int tmp;
	Node *next;
	Node(int x) : tmp(x), next(NULL) {}
};

Node * add_node(Node *head, int d)
{
	Node *temp = new Node(d);
	temp->next = head;
	return temp;
}

void output(Node *head)
{
	while (head)
	{
		cout << head->tmp << " ";
		head = head->next;
	}
	cout << endl;
}
Node * Insert(Node * head,Node *newNode)
{
	
	if (head == NULL || head->tmp >= newNode->tmp)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node *ptr = head;
	Node *prev = NULL;
	while (ptr != NULL && ptr->tmp < newNode->tmp)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	newNode->next = ptr;
	prev->next = newNode;
	return head;
}

Node* Insertion_Sort(Node *head)
{
	if (!head || !head->next)
		return head;

	Node * ptr = head->next;
	Node * result = head;
	result->next = NULL;

	while (ptr)
	{
		Node *temp = ptr;
		ptr = ptr->next;
		result = Insert(result, temp);
	}

	return result;
}

int main()
{
	Node *head = new Node(11);
	head = add_node(head, 6);
	head = add_node(head, 10);
	head = add_node(head, 1);
	head = add_node(head, 9);
	head = add_node(head, 4);
	head = add_node(head, 8);
	head = Insertion_Sort(head);
	output(head);
	system("pause");
	return 0;
}
