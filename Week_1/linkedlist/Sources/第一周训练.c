#include<stdio.h>   /*ͷ�ļ�*/ 
#include<stdlib.h>  /*ͷ�ļ�*/ 
typedef int ElemType;/*ʹ�� typedef Ϊint����һ������*/
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;  /*ʹ�� typedef Ϊ����µĽṹ����һ������*/
typedef enum Status {
	ERROR,
	SUCCESS
} Status;               /*ʹ�� typedef Ϊ���ö�ٽṹ����һ������*/
ElemType n;             /*�������α���n*/ 
LinkedList L;           /*����ָ��ṹ�� ������ָ��L*/ 
ElemType* e = NULL;
/*����һ�����������ڴ����µ�����*/ 
Status InitList(LinkedList L) {
	LinkedList p;
	ElemType i;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
    ElemType j;
    scanf("%d", j);
	for ( i = 0; i < j; i++)
	{   printf("�������%d������:", i + 1);
		scanf("%d", p->data);
		p = (LNode*)malloc(sizeof(LNode));		
		p->next = L->next;
		L->next = p;
	}
	return(SUCCESS);
}


/*����һ������������ɾ�����p��ĵ�һ�����,����ֵ����e*/ 
Status DeleteList(LNode* p, ElemType* e) {
	LNode* p1 = p->next,*t;
	while (p1->next!=NULL)
	{
		if (&p->data == e) {        /*Ҫɾ�����ǽ��p����һ����㣬����Ҫͨ�����p���������ж�Ҫɾ��������һ�����*/ 
			t->next = p1->next;
			*e =(p->next)->data;
			break;
	}
		t = p1;
		p1 = p1->next;
	}
	free(p1);
	return(SUCCESS);
}

/*����һ��������������������*/ 
void DestroyList(LinkedList L)
{
	LinkedList q, p = L; //��pָ��ͷ���
	while (p != 0) {    //��ͷ����ָ����Ϊ0����������βʱ
		q = p->next;   //��qָ��ͷ���ĺ������
		free(p);     //ɾ��p
		p = q;       //��p��q��ָ��������

	}
	L = NULL;      //��ָ��ͷ����ָ���ָ���ֵΪ0
}
/*���e��ֵ*/ 
void visit(ElemType e) {

	ElemType k;
	k=e;
	printf("e��ֵ��:%d\n",k);
}

/*�������*/ 
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* p = L->next;
	ElemType i = 0;
	while (p) {
		i++;
		printf("---->|Node%d->data:%d|\n", i, p->data);
		p = p->next;
	}
	visit(*e);
}

/*��ʾϵͳ����*/ 
void list() {
	printf("\t\t\t********************ϵͳ���ܲ˵�****************************\n");
	printf("\t\t\t**********--------------------------------******************\n");
	printf("\t\t\t\t*********  0.�˳�ϵͳ      *****************\n");
	printf("\t\t\t\t*********  1.����������    *****************\n");
	printf("\t\t\t\t*********  2.ɾ���ڵ㲢ȡֵ*****************\n");
	printf("\t\t\t\t*********  3.�������      *****************\n");
	printf("\t\t\t\t*********  4.��������      *****************\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t����������ѡ��");
}
/*������*/ 
ElemType main() {
	list();
	ElemType* e;
	do                   /*����ѭ��ʹ���˳�ϵͳǰ��������ʹ����������*/ 
	{
	scanf("%d", n);
	switch (n)
	{
	case 0:printf("�˳�ϵͳ"); break;
	case 1:printf("�������봴�����ٸ��ڵ㣺");
	      
		   InitList(L); break;
	case 2:printf("����ɾ���Ľڵ����һ���ڵ��data�ǣ�");
		   scanf("%d", e);
		   DeleteList(L, e); break;
	case 3:TraverseList(L,visit);
	case 4:DestroyList(L);
	default:printf("error\a");
	}
} while (n != 0);     /*����0���˳�ϵͳ������ѭ��*/ 
}

