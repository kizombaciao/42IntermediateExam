#include <unistd.h>
#include <stdlib.h>

struct	s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	const char		*word_start;
	int				word_len;
};

int				ft_isspace(const char c);
int				word_len(const char *word_start);
int				ft_tolower(const char c);
int				ft_strcmp(const char *s1, const char *s2);


int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\v' || c == '\f' ||
			c == ' ' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	word_len(const char *word_start)
{
	int	i;

	i = 0;
	while (word_start[i])
	{
		if (ft_isspace(word_start[i]))
			return (i);
		++i;
	}
	return (i);
}

int	ft_tolower(const char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
	{
		if (ft_tolower(*s1) == ft_tolower(*s2))
		{
			++s1;
			++s2;
		}
		else
		{
			return (ft_tolower(*s1) - ft_tolower(*s2));
		}
	}
	return (0);
}

struct s_tree	*make_node(const char *word_start, int word_len)
{
	struct s_tree	*new_node;

	new_node = (struct s_tree *)malloc(sizeof(struct s_tree));
	new_node->left = 0;
	new_node->right = 0;
	new_node->word_start = word_start;
	new_node->word_len = word_len;
	return (new_node);
}

void			insert_word(struct s_tree **tree, struct s_tree *word)
{
	if (!*tree)
	{
		*tree = word;
		return;
	}
	if (word->word_len < (*tree)->word_len)
		insert_word(&(*tree)->left, word);
	else if (word->word_len == (*tree)->word_len)
	{
		if (ft_strcmp(word->word_start, (*tree)->word_start) < 0)
			insert_word(&(*tree)->left, word);
		else
			insert_word(&(*tree)->right, word);
	}
	else
		insert_word(&(*tree)->right, word);
}

struct s_tree	*convert_string_to_tree(const char *string)
{
	struct s_tree	*tree;
	int	i;
	int	len;

	tree = 0;
	i = 0;
	while (string[i])
	{
		if (ft_isspace(string[i]))
		{
			++i;
			continue;
		}
		len = word_len(&string[i]);
		insert_word(&tree, make_node(&string[i], len));
		i += len;
	}
	return (tree);
}

void			print_tree(struct s_tree *tree, int *previous_wordlen)
{
	if (tree->left)
		print_tree(tree->left, previous_wordlen);
	if (*previous_wordlen != 0)
	{
		if (*previous_wordlen == tree->word_len)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
	}
	write(1, tree->word_start, tree->word_len);
	*previous_wordlen = tree->word_len;
	if (tree->right)
		print_tree(tree->right, previous_wordlen);
}

int				main(int argc, char **argv)
{
	struct s_tree	*tree;
	int				previous_wordlen;

	if (argc == 2)
	{
		tree = convert_string_to_tree((const char *)argv[1]);
		previous_wordlen = 0;
		print_tree(tree, &previous_wordlen);
	}
	write(1, "\n", 1);
	return (0);
}
