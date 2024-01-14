#include "quadraticroots.h"
#include "math.h"

struct QuadraticRootsResult findroots(double a, double b, double c)
{
    double D = 0;
    struct QuadraticRootsResult var;
    
    var.norealroots = 0;
    var.x1 = 0;
    var.x2 = 0;

    D = (b*b) - (4*a*c);

    if(D>0)
    {
        var.x1 = (-b - sqrtl(D))/(a*2);
        var.x2 = (-b + sqrtl(D))/(a*2);
    }

    else if(D == 0)
    {
        var.x1 = -b/(2*a);
        var.x2 = var.x1;
    }
    else var.norealroots = 1;

    return var;
}