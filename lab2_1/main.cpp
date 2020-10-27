#include <iostream>
#include <cmath>

int main() {
    int n, i;
    std::cout<<"n =";
    std::cin>>n;
    double *y= new double[n];
    double *x= new double[n];
    for (i=0; i<n; ++i){
        std::cout<<"y[n] =";
        std::cin>>y[i];
        std::cout<<"x[n] =";
        std::cin>>x[i];
    }
    double s=0;
    double p=0;
    for(i=0; i<n; ++i){
        s+=(y[i+1]+y[i])*(x[i+1]-x[i])/2;
        p += sqrt((x[i] - x[i+1])*(x[i] - x[i+1]) + (y[i]-y[i+1]) * (y[i]-y[i+1]));
    }
    std::cout<<"s ="<<abs(s)<<std::endl;
    std::cout<<"p ="<<p;




    return 0;
}
