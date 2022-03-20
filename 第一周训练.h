#include<stdio.h>   /*头文件*/ 
#include<stdlib.h>  /*头文件*/ 
typedef int ElemType;/*使用 typedef 为int起了一个别名*/
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;  /*使用 typedef 为这个新的结构起了一个别名*/
typedef enum Status {
	ERROR,
	SUCCESS
} Status;               /*使用 typedef 为这个枚举结构起了一个别名*/
ElemType n;             /*定义整形变量n*/ 
LinkedList L;           /*定义指向结构体 变量的指针L*/ 
ElemType* e = NULL;
/*定义一个函数，用于创建新的链表*/ 
Status InitList(LinkedList L) {
	LinkedList p;
	ElemType i;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
    ElemType j;
    scanf("%d", j);
	for ( i = 0; i < j; i++)
	{   printf("请输入第%d个数据:", i + 1);
		scanf("%d", p->data);
		p = (LNode*)malloc(sizeof(LNode));		
		p->next = L->next;
		L->next = p;
	}
	return(SUCCESS);
}


/*定义一个函数，用于删除结点p后的第一个结点,并数值传给e*/ 
Status DeleteList(LNode* p, ElemType* e) {
	LNode* p1 = p->next,*t;
	while (p1->next!=NULL)
	{
		if (&p->data == e) {        /*要删除的是结点p的下一个结点，但需要通过结点p的数据来判断要删除的是哪一个结点*/ 
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

/*定义一个函数，用于销毁链表*/ 
void DestroyList(LinkedList L)
{
	LinkedList q, p = L; //让p指向头结点
	while (p != 0) {    //当头结点的指针域不为0，即不是链尾时
		q = p->next;   //让q指向头结点的后续结点
		free(p);     //删除p
		p = q;       //让p和q都指向后续结点

	}
	L = NULL;      //让指向头结点的指针的指针的值为0
}
/*输出e的值*/ 
void visit(ElemType e) {

	ElemType k;
	k=e;
	printf("e的值是:%d\n",k);
}

/*输出链表*/ 
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

/*显示系统界面*/ 
void list() {
	printf("\t\t\t********************系统功能菜单****************************\n");
	printf("\t\t\t**********--------------------------------******************\n");
	printf("\t\t\t\t*********  0.退出系统      *****************\n");
	printf("\t\t\t\t*********  1.建立新链表    *****************\n");
	printf("\t\t\t\t*********  2.删除节点并取值*****************\n");
	printf("\t\t\t\t*********  3.输出链表      *****************\n");
	printf("\t\t\t\t*********  4.销毁链表      *****************\n");
	printf("\t\t\t----------------------------------------------------\n");
	printf("\t\t\t请输入您的选择：");
}
/*主函数*/ 
ElemType main() {
	list();
	ElemType* e;
	do                   /*利用循环使在退出系统前可以连续使用其他功能*/ 
	{
	scanf("%d", n);
	switch (n)
	{
	case 0:printf("退出系统"); break;
	case 1:printf("请问您想创建多少个节点：");
	      
		   InitList(L); break;
	case 2:printf("你想删除的节点的上一个节点的data是：");
		   scanf("%d", e);
		   DeleteList(L, e); break;
	case 3:TraverseList(L,visit);
	case 4:DestroyList(L);
	default:printf("error\a");
	}
} while (n != 0);     /*输入0，退出系统，不再循环*/ 
}

