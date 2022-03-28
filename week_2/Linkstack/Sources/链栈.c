#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

/*��ջ�ṹ*/
typedef  struct StackNode
{
	ElemType data;          /*������ָ��*/ 
	struct StackNode* next; /*ָ��ǰ������һ���*/ 
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top; /*����ջ��ָ��*/ 
	int	count;
}LinkStack;

/*��ʼ����ջ*/
Status initLStack(LinkStack* s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack)); /*�����½��*/ 
	if(s==NULL)
	{
		return ERROR;                          /*��ʼ��ʧ��*/ 
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;                            /*��ʼ���ɹ�*/ 
}

/*�ж���ջ�Ƿ�Ϊ��*/
Status isEmptyLStack(LinkStack* s)
{
	if (s->top) /*ջ�����ҷǿ�*/
		return ERROR;
	else
		return SUCCESS;
}

/*�õ�ջ��Ԫ��*/
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (!s->top)return ERROR;
	else
	{
		*e = s->top->data;
		printf("ջ��Ԫ����:%d", *e);
	}
	return SUCCESS;
}

/*���ջ*/
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

/*����ջ*/
Status destroyLStack(LinkStack* s)
{
	clearLStack(s);
	free(s);
	return SUCCESS;
}

/*���ջ����*/
Status LStackLength(LinkStack* s, int* length)
{
	length = & s->count;
	printf("��ջ����Ϊ:%d", *length);
	return SUCCESS;
}

/*��ջ*/
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top; /*�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/ 
	s->top = p;       /*���½��p��ֵ��ջ��ָ��*/ 
	s->count++;

	return SUCCESS;
}

/*��ջ*/
Status popLStack(LinkStack* s, ElemType* data)
{
	LinkStackPtr p;
	if (s->count == 0)
		return ERROR;
	data =& s->top->data;
	p = s->top;          /*��ջ����㸳ֵ��p*/ 
	s->top = p->next;    /*ʹ��ջ��ָ������һλ��ָ���һ���*/ 
	free(p);             /*�ͷŽ��p*/ 
	s->count--;
	return SUCCESS;
}

/*��ʾ�˵�ҳ��*/
void menuLStack()
{   
	printf("\t\t\t***************************************************\n");
	printf("\t\t\t\t*  1��ʼ��ջ       * 2��ջ        *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 3�ж�ջ�Ƿ�Ϊ��  * 4�õ�ջ��Ԫ��*\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 5���ջ����      * 6��ջ        *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t* 7���ջ          * 8����ջ      *\n");
	printf("\t\t\t\t***********************************\n");
	printf("\t\t\t\t*              0�˳�ϵͳ          *\n");
	printf("\t\t\t***************************************************\n\n");
	printf("���������ѡ��:");
}

/*������2ʱ��ʾ�Ĵν���*/
void menuLtwo(ElemType*e)
{
	ElemType data;
	printf("������ջ������:");
	scanf_s("%d\n", &data);
	e=&data;
}

ElemType main()
{
	ElemType n;
	LinkStack* S;
	ElemType* e, * length;
	menuLStack(); 
	do /*����ѭ�������˳�ϵͳǰ��һֱ����ϵͳ*/ 
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
	} while (n!=0); /*������0ʱ���˳�ϵͳ*/ 
}




