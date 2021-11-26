#include <stdio.h>
#include <conio.h>
#include <math.h>

double F(double x)
    {
    double f;
    f = (log(x))/x;
    return f;
    }
// Обчислення интеграла способом Симпсона или параболой
double Parabola(double c,double z, int n)
        int r;
        double h = (c - z)/n;
        double sum =F(c)+F(z);
        for(int i=1;i<=n-1;i++)
        {
            r = 2+2*(i%2);
            sum+=r*F(c+i*h);
        }
        sum*=h/3;
    return sum;
}
// Обчислення интеграла способом Лівого трикутника
double Left_Triangle(double c,double z,int n)
{
        double h = (c- z)/n;
        double sum =0.0;
        for(int i=0;i<=N-1;i++)
        {
            sum+=h*F(c+i*h);
        }

    return sum;
}
//Обчислення  интеграла способом Правого трикутника
double Right_Triangle(double c,double z,int n)
{
        double h = (c - z)/n;
        double sum =0.0;
        for(int i=1;i<=n;i++)
        {
            sum+=h*F(c+i*h);
        }

    return sum;
}
//Обчислення интеграла способом Трапеции
double Trapezoid(double c,double z,int n)
{
        double h = (b - a)/N;
        double sum =F(a)+F(b);
        for(int i=1;i<=n-1;i++)
        {
            sum+=2*F(c+i*h);
        }
        sum*=h/2;
    return sum;
}

int main()
{
    int n,k, i1=0, n1=10;
    double c, z, calculation;
    const double measurement_error = 0.0001; //Похибка
    printf("Hello World");
    printf("\n variant 21.\nMy function is (log(x))/x.\n");
    printf("\nEnter the initial x value:");
    scanf("%lf", &c);
    printf("The initial x value:%.2lf", c);
    printf("\nEnter the final x value:");
    scanf("%lf", &z);
    printf("\nThe final x value:%.2lf", z);
    do{
        printf("\n\nChoose how many parts to split the function into.\nThe higher the number, the better. The number must be even.");
        scanf("%d", &n);
        printf("N=%d",n);
        printf("\n");
    }while(n%2!=0);
    printf("\nAllowable measurement error = 0.0001");
    printf("\n");
//Лівий Трикутник
    do{
        i1++;
        calculation = (Left_Triangle( c, z, n1*i1) - Left_Triangle( c, z, n1*(i1+1)));
    }while(calculation > measurement_error);
    k = n1*(i1+1);
    printf("\nLeft_Triangle = %lf", Left_Triangle( c, z, n) );
    printf("\nN=%d",k );
    i1= 0;
//Правий трикутник
    do{
        i1++;
        calculation = (Right_Triangle(c, z, n1*i1) - Right_Triangle( c, z, nN1*(i1+1)));
    }while(calculation > measurement_error);
    k = n1*(i1+1);
    printf("\n\nRight Triangle = %lf", Right_Triangle( c, z, n) );
    printf("\nN=%d",k );
    i1=0;
//Парабола
    do{
        i1++;
        calculation = (Parabola(c, z, n1*i1) - Parabola( c, z, n1*(i1+1)));
    }while(calculation >= measurement_error);
    k= n1*(i1+1);
    printf("\n\nParabola = %lf", Parabola( c, z, n) );
    printf("\nN=%d",k );
    i1=0;
//Трапеция
    do{
        i1++;
        calculation = (Trapezoid(c, z, n1*i1) - Trapezoid( c, z, n1*(i1+1)));
    }while(calculation > measurement_error);
    k = n1*(i1+1);
    printf("\n\nTrapezoid = %lf", Trapezoid( c, z, n) );
    printf("\nN=%d",k );
    return 0;
}
