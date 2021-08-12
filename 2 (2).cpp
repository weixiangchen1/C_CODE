#include <stdio.h>
#include <stdlib.h>
typedef struct L* list;
struct L{
	int data;
	struct L* next;
};  
void insert(list p, int n){
	while(p->next!=NULL&&p->next->data<n){
		p=p->next;
	}
	list insert = (list)malloc(sizeof(struct L));
	insert->data = n;
	insert->next = p->next;
	p->next = insert;
}
void listprintf(list p){
	int flag=0;
	p=p->next;
	if(p==NULL){
		printf("\n");
		return;
	}
	while(p!=NULL){
		if(flag){
			printf("->");
		}
		flag=1;
		printf("%d", p->data);
		p=p->next;
		
	}
}
void freee(list p)
{
	list pp;
	while(p!=NULL)
	{
		pp=p;
		p=p->next;
		free(pp);
	
	}
}
list unionn(list head1, list head2){
	head1=head1->next;
	head2=head2->next;
	while(head1->next!=NULL){
		head1=head1->next;
	}
	head1->next=head2;
} 
int main()
{
	list head1 = (list)malloc(sizeof(L));
	list head2 = (list)malloc(sizeof(L));
	list head3 = (list)malloc(sizeof(L));
	head1->next = NULL;
	head2->next = NULL;
	head3->next = NULL;
	int n;
	while(scanf("%d", &n)!=EOF){
		if(n>0){
			insert(head1, n);
		}
		if(n<0){
			insert(head2, n);
		}
	}
	listprintf(head1);
	printf("\n");
	head3=unionn(head1, head2);
	
	listprintf(head3);
	printf("\n");
	
	
	listprintf(head1);
	freee(head1);
	freee(head2);
	freee(head3);
	return 0; 
	
}
