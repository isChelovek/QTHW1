#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H
#include <QObject>

class quadratic_equation : public QObject

{
    Q_OBJECT
public:
   explicit  quadratic_equation(QObject *parent = nullptr);

signals:
    void sendAnswer(int numRoots, float root1, float root2);

public slots:
    void setKoef(int a, int b, int c);

private:
    float aK;
    float bK;
    float cK;
    float diskriminant;
    float calkDickriminant();
    void getRoots();
    float root1;
    float root2;
};

#endif // QUADRATIC_EQUATION_H
