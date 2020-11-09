#include <iostream>
#include <cmath>
/*Дано функцію 𝑓(𝑥). Знайти лінійну функцію 𝑎𝑥+𝑏, яка найкращим чином апроксимує її.
 * Використати метод найменших квадратів.*/
int main() {
    int n,i;
    double sum_x1 =0;
    double sum_y1 =0;
    double sum_x2=0;
    double sum_y2=0;
    double x, y,a, b;
    std::cout<<"n =";
    std::cin>>n;

    for (i=0; i<n; ++i){
        std::cout<<"x =";
        std::cin>>x;
        std::cout<<"y ="<<x*x<<std::endl;
        sum_x1=sum_x1+x;
        sum_y1=sum_y1+y;
        sum_x2=sum_x2+pow(x,2);
        sum_y2=sum_y2+x*y;
    }

    a=((sum_y1*sum_y2)-(sum_x1*sum_y2))/((n*sum_x2)-(sum_x2*sum_x2));
    b=((n*sum_y2)-(sum_x1*sum_y1))/((n*sum_x2)-(sum_x1*sum_x1));

    std::cout<<"a ="<<a<<std::endl;
    std::cout<<"b -"<<b<<std::endl;
    if (b>0){
        std::cout<<"y ="<<a<<"x+"<<b;
    }
    else if (b<0){
        std::cout<<"y ="<<a<<"x"<<b;

    }

    return 0;
}
