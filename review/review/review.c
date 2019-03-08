#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//˳���
typedef struct 
{
	int arr[100];
	int size;
}SeqList;
//ͷɾ
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
//����	����+��ͷ���+��ѭ��
typedef struct Node
{
	int val;
	struct Node* next;
}Node;
//���������
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
//�����βɾ
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

//������
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;
//�ݹ�ǰ�����
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
//���ĸ߶�
int GetHeight(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return GetHeight(root->left) > GetHeight(root->right)? GetHeight(root->left) : GetHeight(root->right) + 1;
}
//�������Ĳ���
	//�ڶ������в���val��ÿ������val���ظ�
	//�ҵ������ؽ���ַ�����򷵻�NULL

	//���Ҳ��ԣ�������ǣ����ظ��ĵ�ַ
	//�������������ʼ����
	//�������������ʼ����
	//���򷵻ؿ�
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
			return Find(root->right,val);
		}
		else
		{
			return NULL;
		}
	}
	return TempNode;
}

typedef struct Heap
{
	int arr[100];
	int size;
}Heap;
