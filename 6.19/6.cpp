#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define MAX 20
typedef struct BTNode{       /*�ڵ�ṹ����*/
	char data ;               /*�ڵ�����*/
	struct BTNode *lchild;
	struct BTNode *rchild ;  /*ָ��*/
}*BiTree;

void createBiTree(BiTree *t){ /* �����������������*/
	char s;
	BiTree q;
	printf("\nplease input data:(exit for #)");
	s=getchar();
	if(s=='#'){*t=NULL; return;}
	q=(BiTree)malloc(sizeof(struct BTNode));
	if(q==NULL){printf("Memory alloc failure!"); exit(0);}
	q->data=s;
	*t=q;
	createBiTree(&q->lchild); /*�ݹ齨��������*/
	createBiTree(&q->rchild); /*�ݹ齨��������*/
}

void PreOrder(BiTree p){  /* �������������*/
    if ( p!= NULL ) {
       	printf("%c", p->data);
       	PreOrder( p->lchild ) ;
       	PreOrder( p->rchild) ;
    }
}
void InOrder(BiTree p){  /* �������������*/
    if( p!= NULL ) {
 	 InOrder( p->lchild ) ;
   	 printf("%c", p->data);
   	 InOrder( p->rchild) ;
    }
}
void PostOrder(BiTree p){  /* �������������*/
   if ( p!= NULL ) {
    	PostOrder( p->lchild ) ;
       	PostOrder( p->rchild) ;
       	printf("%c", p->data);
    }
}

void Preorder_n(BiTree p){ /*��������ķǵݹ��㷨*/
    BiTree stack[MAX],q;
    int top=0,i;
    for(i=0;i<MAX;i++) stack[i]=NULL;/*��ʼ��ջ*/
    q=p;
    while(q!=NULL){
        printf("%c",q->data);
        if(q->rchild!=NULL) stack[top++]=q->rchild;
        if(q->lchild!=NULL) q=q->lchild;
        else
            if(top>0) q=stack[--top];
            else q=NULL;
    }
}

void release(BiTree t){ /*�ͷŶ������ռ�*/
  	if(t!=NULL){
    	release(t->lchild);
    	release(t->rchild);
    	free(t);
  	}
}

int main(){
    BiTree t=NULL;
    createBiTree(&t);
    printf("\n\nPreOrder the tree is:");
    PreOrder(t);
    printf("\n\nInOrder the tree is:");
    InOrder(t);
    printf("\n\nPostOrder the tree is:");
    PostOrder(t);
    printf("\n\n����������У��ǵݹ飩:");
    Preorder_n(t);
    release(t);
    return 0;
}

