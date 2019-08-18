#include "ord_alphlong.h"
#include <unistd.h>
#include <stdio.h> // delete

int			main(int argc, char **argv)
{
	char		**words;

	if (argc == 2)
	{
		words = ft_splitword(argv[1]);
		p(words);
		printf("\n");
		ft_sortalph(words);
		p(words);
		printf("\n");
		
		ft_sortlen(words);
		p(words);
		printf("\n");
	
		print_words(words);
		free(words);
	}
	write(1, "\n", 1);
	return (0);
}

// USE THIS ONE !!!

// https://github.com/Julow/exam-00/tree/master/ex03

/* TO SHOW THAT INCREMENTING WORDS VARIABLE BY 1 MOVES TO THE NEXT WORD

        while (*words)
        {
            printf("111a %s\n", *words);
            words++;
        }
*/