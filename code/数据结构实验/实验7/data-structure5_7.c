#include<stdio.h>

typedef struct Mul_Poly
{
	int exp;
	int para;
	struct Mul_Poly* next;
} Mul_Poly;

Mul_Poly* get_tail_point(Mul_Poly* root)
{
	while (root->next != NULL)
		root = root->next;
	return root;
}

Mul_Poly* insert(Mul_Poly* root)
{
	int exp;
	int para;
	scanf("请输入指数： %d", &exp);
	scanf("请输入参数： %d", &para);
	Mul_Poly* new_node = (Mul_Poly*)malloc(sizeof(Mul_Poly));
	new_node->exp = exp;
	new_node->para = para;
	new_node->next = NULL;
	Mul_Poly* tail = get_tail_point(root);
	tail->next = new_node;
}

// 从大到小排序
Mul_Poly* sort(Mul_Poly* head, Mul_Poly* new_poly)
{
	if (head->exp < new_poly->exp)
	{
		new_poly->next = head;
		head = new_poly;
	}
	else
	{
		Mul_Poly* temp = head;
		Mul_Poly* temp_pre = head;
		while (temp != NULL)
		{
			if (temp->exp < new_poly->exp)
			{
				temp_pre->next = new_poly;
				new_poly->next = temp;
				break;
			}
			else
			{
				if (temp->exp == new_poly->exp)
				{
					temp->para += new_poly->para;
					free(new_poly);
					break;
				}
				else
				{
					temp_pre = temp;
					temp = temp->next;
				}

			}

		}
		if (temp == NULL)
		{
			temp_pre->next = new_poly;
		}
	}
	return head;
}

Mul_Poly* multiply(Mul_Poly* first, Mul_Poly* second)
{
	if (first == NULL || second == NULL)
		return NULL;

	Mul_Poly* head = (Mul_Poly*)malloc(sizeof(Mul_Poly));
	int count = 0;

	Mul_Poly* first_head = first;
	Mul_Poly* second_head = second;
	while (first)
	{
		second = second_head;
		while (second)
		{
			Mul_Poly* new_poly = (Mul_Poly*)malloc(sizeof(Mul_Poly));

			new_poly->exp = first->exp + second->exp;
			new_poly->para = first->para * second->para;
			if (new_poly->para == 0)
				free(new_poly);
			else
			{
				if (count)
				{
					head = sort(head, new_poly);
				}
				else
				{
					head->exp = new_poly->exp;
					head->para = new_poly->para;
					free(new_poly);
					count++;
				}
			}
		}
	}
	return head;
}

int main()
{

}
