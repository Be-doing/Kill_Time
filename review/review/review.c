#include<assert.h>
//顺序表
typedef struct 
{
	int arr[100];
	int size;
}SeqList;
//头删
void SeqListPushFront(SeqList *a, int val)
{
	assert(a);
	assert(a->size > 0);
	for ( int i = a->size; i > 0; i--)
	{
		a->arr[i] = a->arr[i - 1];
	}
	a->arr[0] = val;
	++a->size;
}
//链表	单向+无头结点+无循环
typedef struct Node
{
	int val;
	struct Node* next;
}Node;
//链表的逆置
Node* Reverse_1(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	Node* p1 = NULL;
	Node* p2 = head;
	Node* p3 = head->next;
	while (p2!=NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
		
	}
	return p3;
}
Node* Reverse_2(Node* head)
{
	Node* temp = head;
	Node* next;
	Node* newhead = NULL;

	while (temp !=	NULL)
	{
		next = temp->next;

		temp->next = newhead;

		newhead = temp;
	}
	return newhead;
}
//链表的尾删
void ListPopBack(Node* head)
{
	assert(head != NULL);
	Node* p1 = NULL;
	Node* p2 = head;
	if (p2->next == NULL)
	{
		free(p2);
		return;
	}
	for (p2; p2->next!=NULL;p2=p2->next)
	{
		p1 = p2;
	}
	p1->next = NULL;
	free(p2);
}

//二叉树
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;
//递归前序遍历
void PreorderTraversal(TreeNode* root)
{
	assert(root);
	if (root ==  NULL)
	{
		return;
	}
	printf("%d->",root->val);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}
//树的高度
int GetHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	return GetHeight(root->left) > GetHeight(root->right)? GetHeight(root->left) : GetHeight(root->right) + 1;
}
//二叉树的查找
	//在二叉树中查找val，每个结点的val不重复
	//找到，返回结点地址，否则返回NULL

	//查找策略，如果根是，返回根的地址
	//否则从左子树开始查找
	//否则从右子树开始查找
	//否则返回空
TreeNode* Find(TreeNode* root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == val)
	{
		return root;
	}
	TreeNode* TempNode = Find(root->left, val);
	if (TempNode == NULL)
	{
		if (Find(root->right, val))
		{
			return Find(root->right);
		}
		else
		{
			return NULL;
		}
	}
	return TempNode;
}
TreeNode CreateTree(int preorder[], int inorder[], int size)
{

}
typedef int HeapData;
typedef struct Heap
{
	HeapData arr[100];
	int size;
}Heap;

void Adjustdown(HeapData arr[], int size, int root)
{
	assert(root);
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int min = left;
	if (left > size)
	{
		return;
	}
	if (right <size && arr[right] < arr[left])
	{
		right = min;
	}
	if (arr[root] < arr[min])
	{
		return;
	}
	HeapData temp = arr[root];
	arr[root] = arr[min];
	arr[min] = temp;
	//root =min
	Adjustdown(arr, size, min);
}