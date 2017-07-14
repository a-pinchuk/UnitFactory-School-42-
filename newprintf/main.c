#include "ft_printf.h"


int		main(int argc, char **argv)
{
	// printf("\n%d ", ft_printf("Lola %l010.2s HAH %c DORT %d", "Roman", 'c', 18));	
	ft_printf("My: %5%");
    printf("Unix\n: %5%");
// 	ft_printf("SECOND:%010d\n", 10);
//	ft_printf("THIRD:%0d\n", 5);
//	ft_printf("FORTH:%10d\n", 5);
//	ft_printf("FIFTH:%10+0d\n", 5);
//	ft_printf("SIXTH:%-+   10d\n", 2);
// 	ft_printf("SEVENTH:[%014-ld[]]\n", 10);
// 	ft_printf("EIGHTS:[%-10#12Od[]]\n", 10);
//    ft_printf("NINTH:[%-10%[]]\n", 10);
//    ft_printf("TENTH:%-10hhzXq\n", 10);
//    ft_printf("ELEVENTH:%     .2-10d", 12);
//    ft_printf("TWELWTH:%lhhc    ", 'a');
//    ft_printf("THIRTEENTH:%   10hhh   # d", 5);
//    ft_printf("FOURTEENTH:% 0-4lld[]]", 10);
//    ft_printf("FIFTTEENTH:[%.0.#2x[]]\n", 67);
//    ft_printf("[%010.2    s[]\n", "Kiev!");
//    ft_printf(":%s:\n", "Hello, world!");
//    ft_printf(":%15s:\n", "Hello, world!");
//    ft_printf(":%.10s:\n", "Hello, world!");
//    ft_printf(":%-10s:\n", "Hello, world!");
//    ft_printf(":%-15s:\n", "Hello, world!");
//    ft_printf(":%.15s:\n", "Hello, world!");
//    ft_printf(":%15.10s:\n", "Hello, world!");
//    ft_printf(":%-15.10s:\n", "Hello, world!");
	//ft_printf("[%   +10[]]\n");
	//printf("%20+05d\n", 10);
	//printf("%d ", ft_printf("[%   +10[]]\n"));
	//printf("%d ", ft_printf("[%010%-10[]]\n"));
	//printf("\n%010%lola\n");
	// printf("%w010d\n", 10);
	// printf("[%-10[]]\n", a);
	// printf("% +6d}\n", 10);
	/*
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("Loloa\n%s %i", "Roman", "97");
	printf("%5.f\n", 1.49999);
	printf("%x %X %#X\n", 31, 31, 31);
	printf("*%d*\n", PAGES);
	printf("*%4d*\n", PAGES);
	printf("*Curer: %10.d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	printf("%05d\n", zipCode);
	printf("%#.4O\n", a);
	printf("*%5.d*\n", 1);

	printf("\nSecond part\n\n");

	printf("%x %X %#-12.6X\n", 31, 31, 31);
	printf("%o %o %#O\n", -1, 31, 31);
	printf("**%llS**% d% d **\n", "EL", 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("\n");

	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.20s]\n", BLURB);
	*/
	//printf("%bd\n");
	//printf("%d ", ft_printf("%        010             d"));
	//printf("\n");
	//printf("{%l              d}\n", 10);
	//printf("%  -16.6o}\n", 12);
	return (0);
}

//# -> is only used with (o,O), (x,X) -> without bonuses, it is telling special type of variable
// if num is o -> it will print 0num, which means that var is octal, if X -> 0x
