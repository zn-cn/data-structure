#include<stdio.h>
#include<stlib.h>

struct polynomial
{
	int degree;
	int coeff;
	polynomial *next;
} List;

// 指数不排序
Polynomial* PolyMult (List *p1, List *p2)
{
	List *result = (List *)malloc(sizeof(List));
	List *head = result;
	while (p1->next != NULL)
	{
		while (p2->next != NULL)
		{
			result->degree = p1->degree + p2->degree;
			result->coeff = p1->coeff * p2->coeff;
			result->next = (List*) malloc(sizeof(List));
			result = result->next;
		}
	}
	return head;

}

// 指数排序, 链表排序，幂数相同的项，系数合并
int sort_list(List* list)
{
	//标记元素是否排序
	int sorted = 0;
	List* node;
	List* tmp;
	List* const head = list;
	if ( NULL == list )
	{
		printf("链表没有初始化，无法排序！/n");
		return 0;
	}
	node = head->next;
	head->next = NULL;
	while ( NULL != node )
	{
		sorted = 0;
		list = head;
		while ( NULL != list->next )
		{
			//如果是幂数相同，则合并系数
			if ( node->degree == list->next->degree )
			{
				list->next->coeff += node->coeff;
				node = node->next;
				sorted = 1;
				break;
			}
			else if (node->degree > list->next->degree)
			{
				tmp = node;
				node = node->next;
				tmp->next = list->next;
				list->next = tmp;
				sorted = 1;
				break;
			}
			list = list->next;
		}
		//如果node的幂数最小，插入链表最后
		if ( 0 == sorted )
		{
			tmp = node;
			node = node->next;
			list->next = tmp;
			tmp->next = NULL;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{

	return 0;
}

