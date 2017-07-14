#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	int i;
	int div;

	i = atoi(str);
	div = 2;

	if(i == 1)
		printf("1");
	if(i <= 1)
		return ;
	while(div <= i)
	{
		if(i % div == 0)
		{
			printf("%d", div);
			if(i == div)
				return ;
			printf("*");
			i = i / div;
			div = 1;
		}
		div++;
	}

}

int	main(int argc, char **argv)
{
	if(argc == 2)
		fprime(argv[1]);
	printf("\n");
	return(0);
}