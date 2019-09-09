#include <stdlib.h>

	struct s_node {
		void *content;
		struct s_node *next;
	};

int len(struct s_node *p)
{
	int i = 0;
	if (!p)
		return 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

void *intersection(struct s_node *l1, struct s_node *l2)
{
	int len1 = len(l1);
	int len2 = len(l2);
	int diff;
	int i = 0;

	if (len1 > len2)
	{
		diff = len1 - len2;
		while (i < diff)
		{
			l1 = l1->next;
			i++;
		}
	}

	i = 0;
	if (len1 < len2)
	{
		diff = len2 - len1;
		while (i < diff)
		{
			l2 = l2->next;
			i++;
		}	
	}
	while (l1 && l2)
	{
		if (l1 == l2)
		{
			return (l1);
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return NULL;
}
