#include "fdf.h"

int		fdf_pnt_color(t_pnt *pnt1, t_pnt *pnt2)
{
	int		color;
	int		main_color;

	main_color = (pnt1->color < pnt2->color) ? main_color = pnt2->color : main_color = pnt1->color;
	if (main_color <= 10)
		//some color
	else if (main_color >= 11 && main_color <= 20)
		//another color
	else if (main_color >= 21 && main_color <= 30)
		//another one
	//and so forth
}