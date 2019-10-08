// PASSED SECOND TIME AFTER CORRECTING
// NOT PASS, B/C OF DUMB MISTAKE BELOW

//#include <stdio.h> // del
#include <stdlib.h>
#include <string.h>

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node *s;
	struct s_node *f;

	if (!node)
		return 0; // REMEMBER!  RETURN 0; AND NOT RETURN;

	s = node;
	f = node->next; // remember!  only 1 next !

	while (f->next && f->next->next)
	{
		if (s == f)
		{
			return 1;
		}
		s = s->next;
		f = f->next->next; // remember next->next !!!
	}
	return 0;
}
/*
int main()
{


}
*/