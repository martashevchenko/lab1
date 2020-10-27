#include <iostream>
#include <cmath>
const double PI=3.14159265;

int main() {
    double t,x,y,R,r, a,b;
    std::cout<<"Enter a radius of our round R =";
    std::cin>>R;
    std::cout<<"Enter an angle t =";
    std::cin>>t;
    std::cout<<"Enter a =";// a is the coordinate x of the centre of our round
    std::cin>>a;
    std::cout<<"Enter b =";// b is the coordinate y of the centre of our round
    std::cin>>b;
    std::cout<<"Enter x =";// x is the coordinate x of our point in/on the round
    std::cin>>x;
    std::cout<<"y =";//x is the coordinate x of our point in/on the round
    std::cin>>y;
    r=sqrt((a-x)*(a-x)+(b-y)*(b-y));
    std::cout<<"r ="<<r<<std::endl;
    if (r==R){
        for (int i=0; i<t; ++i){
            x=r*i*PI/180-r*sin(i*PI/180);
            std::cout<<"x["<<i<<"] ="<<x<<" ";
            y=r-r*cos(i*PI/180);
            std::cout<<"y["<<i<<"] ="<<y<<std::endl;
        }
    }
    else if (r<R){
        for (int i=0; i<t; ++i){
            x=r*i*PI/180-r*sin(i*PI/180);
            std::cout<<"x["<<i<<"] ="<<x<<" ";
            y=r-r*cos(i*PI/180);
            std::cout<<"y["<<i<<"] ="<<y<<std::endl;
        }
    }
    else if (r>R){
        std::cout<<"A point is outside the round";
    }
    return 0;
}


