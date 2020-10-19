#include <iostream>

int main() {
    int N, max=0, k=0;
    std::cout<<"N =";
    std::cin>>N;
    while(N!=1){
        if (N%2==0){
            N=N/2;
        }
        else {
            N=N*3+1;
        }
        std::cout<<"N ="<<N<<std::endl;
        for (int i=0; i<=N; i++){
            if (N>max){
                max=N;
            }
        }
        k=k+1;
    }
    std::cout<<"max ="<<max<<std::endl;
    std::cout<<"k ="<<k;

    return 0;
}
