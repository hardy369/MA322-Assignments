#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f1(double x,double y)
{return y*cos(x*y)+1;}
double f2(double x,double y)
{return sin(x*y)+x-y;}

double df1_dx(double x,double y)
{return -y*sin(x*y)*y;}
double df1_dy(double x,double y)
{return cos(x*y)-x*y*sin(x*y);}
double df2_dx(double x,double y)
{return y*cos(x*y)+1;}
double df2_dy(double x,double y)
{return x*cos(x*y)-1;}

void newtonMethod(double x0,double y0,double tolerance){
 double x=x0,y=y0;
  int iteration=0;
    double dx,dy;
    while(true){
        double f1_val=f1(x,y),f2_val=f2(x,y);
        double J11=df1_dx(x,y),J12=df1_dy(x,y),J21=df2_dx(x,y),J22=df2_dy(x,y);
        double det=J11*J22-J12*J21;
        double invJ11=J22/det,invJ12=-J12/det,invJ21=-J21/det,invJ22=J11/det;
        dx=-(invJ11*f1_val+invJ12*f2_val);
        dy=-(invJ21*f1_val+invJ22*f2_val);
        x+=dx;
        y+=dy;
        iteration++;
        if(fabs(dx)<tolerance&&fabs(dy)<tolerance)break;
    }
    cout<<"Solution: ("<<x<<", "<<y<<")"<<endl;
    cout<<"Iterations: "<<iteration<<endl;
}

int main(){
    double x0=1.0,y0=2.0,tolerance=1e-6;
    newtonMethod(x0,y0,tolerance);
    return 0;
}

