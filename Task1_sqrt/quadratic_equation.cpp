#include "quadratic_equation.h"

quadratic_equation::quadratic_equation(QObject *parent)
    : QObject{parent}
{

}

void quadratic_equation::setKoef(int a, int b, int c)
{
    aK = a;
    bK = b;
    cK = c;
    calkDickriminant();
    getRoots();
}

float quadratic_equation::calkDickriminant()
{
    diskriminant = bK*bK - 4 * aK * cK;
    return diskriminant;
}

void quadratic_equation::getRoots()
{
    if (diskriminant > 0)
    {
        root1 =  (-bK + qSqrt(calkDickriminant())) / (2 * aK);
        root2 =  (-bK - qSqrt(calkDickriminant())) / (2 * aK);
        emit sendAnswer(2 , root1, root2);
    }
    else if (diskriminant == 0)
    {
        root1 =  (-bK + qSqrt(calkDickriminant())) / (2 * aK);
        emit sendAnswer(1 , root1, root1);
    }
    else
    {
        emit sendAnswer(0, 0, 0);
    }
}
