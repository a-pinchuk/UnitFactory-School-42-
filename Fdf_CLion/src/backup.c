#include "fdf.h"

void	bresenheim_algorithm_floats(t_pnt *pnt1, t_pnt *pnt2, t_env *e)
{
	int 	x1 = (int)pnt1->x;
	int 	x2 = (int)pnt2->x;
	int 	y1 = (int)pnt1->y;
	int 	y2 = (int)pnt2->y;
	const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    fdf_drawing_pxl(e, x2, y2);
    while(x1 != x2 || y1 != y2) 
   {
        fdf_drawing_pxl(e, x1, y1);
        const int error2 = error * 2;
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}