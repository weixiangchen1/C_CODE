//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//
//using namespace std;
//
//int arrTree[100007];
//int n, p = 0;
//
//struct BiTree {
//    int value;
//    int maxSum;
//    BiTree* left;
//    BiTree* right;
//    BiTree* root;
//};
//
//BiTree* BuildTree()
//{
//    int tmp = arrTree[p++];
//    if (tmp == -1 || p == n) return NULL;
//
//    BiTree* head;
//    head = new BiTree;
//    head->maxSum = head->value = tmp;
//    head->root = NULL;
//
//    head->left = BuildTree();
//    head->right = BuildTree();
//
//    return head;
//}
//
//int FindMaxRoot(BiTree* Tree)
//{
//    if (Tree == NULL) return 0;
//    else {
//        int l = FindMaxRoot(Tree->left);
//        int r = FindMaxRoot(Tree->right);
//        Tree->maxSum += max(l, r);
//        Tree->root = l > r ? Tree->left : Tree->right;
//        return Tree->maxSum;
//    }
//}
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &arrTree[i]);
//    }
//    BiTree* Tree = BuildTree();
//    BiTree* p = Tree;
//    printf("%d\n", FindMaxRoot(p));
//    while (p) {
//        printf("%d ", p->value);
//        p = p->root;
//    }
//
//    return 0;
//}