

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

struct s_node* b(void* v) {
	struct s_node* new;
	new = malloc(sizeof(struct s_node));
	new->content = v;
	new->next = 0;
	return new;
}
int main() {
	struct s_node* a;
	struct s_node* c;
	struct s_node* ret;

	a = b("a");
	a->next = b("b");
	a->next->next = b("c");
	a->next->next->next = b("d");
	a->next->next->next->next = b("e");
	a->next->next->next->next->next = b("f");

	c = b("g");
	c->next = b("h");
	c->next->next = b("i");
	c->next->next->next = b("j");
	c->next->next->next->next = b("k");
	c->next->next->next->next->next = b("l");

	ret = iii(a, c);
	printf("%s\n", ret ? ret->content : 0);

	c->next->next = a->next->next->next; // intersection created
	ret = iii(a, c);
	printf("%s\n", ret ? ret->content : 0);
	return 0;
}

