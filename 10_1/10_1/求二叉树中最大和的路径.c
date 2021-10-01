//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//typedef struct Node
//{
//	struct Node* left;
//	struct Node* right;
//	int val;
//}Node;
//
//int max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int NodeMax(struct Node* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int left = NodeMax(root->left);
//		int right = NodeMax(root->right);
//		return max(left, right) + root->val;
//	}
//}
//
//int main()
//{
//	Node a = { NULL,NULL,5 };
//	Node b = { NULL,NULL,2 };
//	Node c = { NULL,NULL,4 };
//	Node d = { NULL,NULL,3 };
//	Node e = { NULL,NULL,1 };
//	Node f = { NULL,NULL,7 };
//	a.left = &b;
//	a.right = &c;
//	b.right = &d;
//	c.left = &e;
//	c.right = &f;
//	int ret = NodeMax(&a);
//	printf("%d\n", ret);
//
//	return 0;
//}