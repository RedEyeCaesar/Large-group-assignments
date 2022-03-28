#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

/*链栈结构*/
typedef  struct StackNode
{
	ElemType data;          /*数据域指针*/ 
	struct StackNode* next; /*指向当前结点的下一结点*/ 
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top; /*用于栈项指针*/ 
	int	count;
}LinkStack;

/*初始化链栈*/
Status initLStack(LinkStack* s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack)); /*创建新结点*/ 
	if(s==NULL)
	{
		return ERROR;                          /*初始化失败*/ 
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;                            /*初始化成功*/ 
}

/*判断链栈是否为空*/
Status isEmptyLStack(LinkStack* s)
{
	if (s->top) /*栈存在且非空*/
		return ERROR;
	else
		return SUCCESS;
}

/*得到栈顶元素*/
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (!s->top)return ERROR;
	else
	{
		*e = s->top->data;
		printf("栈顶元素是:%d", *e);
	}
	return SUCCESS;
}

/*清空栈*/
Status clearLStack(LinkStack* s)
{
	LinkStackPtr p;
	while (s->top) {
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
}

/*销毁栈*/
Status destroyLStack(LinkStack* s)
{
	clearLStack(s);
	free(s);
	return SUCCESS;
}

/*检测栈长度*/
Status LStackLength(LinkStack* s, int* length)
{
	length = & s->count;
	printf("链栈长度为:%d", *length);
	return SUCCESS;
}

/*入栈*/
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top; /*把当前的栈顶元素赋值给新结点的直接后继*/ 
	s->top = p;       /*将新结点p赋值给栈顶指针*/ 
	s->count++;

	return SUCCESS;
}

/*出栈*/
Status popLStack(LinkStack* s, ElemType* data)
{
	LinkStackPtr p;
	if (s->count == 0)
		return ERROR;
	data =& s->top->data;
	p = s->top;          /*将栈顶结点赋值给p*/ 
	s->top = p->next;    /*使得栈顶指针下移一位，指向后一结点*/ 
	free(p);             /*释放结点p*/ 
	s->count--;
	return SUCCESS;
}

/*显示菜单页面*/
void menuLStack()
{   
	printf("\t\t\t***************************************************\n");
	printf("\t\t\t\t*  1初始化栈       * 2入栈        *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 3判断栈是否为空  * 4得到栈顶元素*\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 5检测栈长度      * 6出栈        *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 7清空栈          * 8销毁栈      *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t*              0退出系统          *\n");
	printf("\t\t\t***************************************************\n\n");
	printf("请输入你的选择:");
}

/*当输入2时显示的次界面*/
void menuLtwo(ElemType*e)
{
	ElemType data;
	printf("请输入栈的数据:");
	scanf_s("%d\n", &data);
	e=&data;
}

ElemType main()
{
	ElemType n;
	LinkStack* S;
	ElemType* e, * length;
	menuLStack(); 
	do /*利用循环，在退出系统前可一直操作系统*/ 
	{
		scanf_s("%d", &n);
		switch (n)
		{
		case 0:printf("Goodbuy!"); break;
		case 1:
			initLStack(S);
			break;
		case 2:
			menuLtwo(e);
			pushLStack(S, *e);
			break;
		case 3:isEmptyLStack(S); break;
		case 4:getTopLStack( S, e); break;
		case 5:LStackLength( S, length); break;
		case 6:
			popLStack(S, e);    break;
		case 7:clearLStack(S); break;
		case 8:destroyLStack(S); break;
		default:
			printf("input error!");
		}
	} while (n!=0); /*当输入0时，退出系统*/ 
}




