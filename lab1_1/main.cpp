#include <iostream>
#include <cmath>

bool isPrime(int i){
    if(i>1){
        for (int k=2; k<i; ++i) {
            if (i % k == 0) {
                return false;
            }

            return true;
        }
    }
    else
        return false;
}

int main() {
    int n, counter =0, zn=1, chis=0;
    std::cout<<"n =";
    std::cin>>n;
    int *a=new int[n];
    for ( int i =2; counter<n ; i++){
        if (isPrime(i)){
            zn=zn*i;
            a[counter]=i;
            std::cout<<"a[n] ="<<a[counter]<<std::endl;
            counter++;
        }
    }
    for(int m=0; m<n; m++){
        chis+=(zn/a[m]);
    }
    std::cout<<"zn ="<<zn<<std::endl;
    std::cout<<"chis ="<<chis<<std::endl;
    std::cout<<chis<<"/"<<zn;

    return 0;
}

