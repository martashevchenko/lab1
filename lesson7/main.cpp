#include <iostream>
#include <algorithm>
void minmax5(){
    int n,i, maxnum;
    float m,v,p, pmax;
    std::cout<<"n =";
    std::cin>>n;
    for(i=1; i<=n; ++i){
        std::cout<<"m ="<<std::endl;
        std::cin>>m;
        std::cout<<"v ="<<std::endl;
        std::cin>>v;
        p=m/v;
        if ((i==1)||(p>pmax)){
            pmax=p;
            maxnum=i;
        }

    }
    std::cout<<"pmax ="<<pmax<<std::endl;
    std::cout<<"maxnum ="<<pmax<<std::endl;
}

void array14(){
    int n, i;
    int a[10];
    std::cout<<"n =";
    std::cin>>n;
    for (i=0; i<n; i++){
        std::cout<<"a[n] = ";
        std::cin>>a[i];
    }
    for (i=1; i<n; i+=2){
        std::cout<<a[i]<<" ";
    }
    for (i=0; i<n; i+=2){
        std::cout<<a[i]<<" ";
    }


}

void array23(){
    int n, i, k, l;
    int a[10];
    int sum=0;
    std::cout<<"n =";
    std::cin>>n;
    std::cout<<"k =";
    std::cin>>k;
    std::cout<<"l =";
    std::cin>>l;
    for (i=0; i<n; ++i){
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    for (i=0; i<k-1; ++i ) {
        sum += a[i];
    }
    for (i=l; i<n; ++i){
        sum +=a[i];
    }
    std::cout<<(float)sum/(float)(k-1+(n-l));

}

void array33() {
    int n, i;
    std::cout << "n =";
    std::cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; ++i) {
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    for(i=n-2; i>=1; --i){
        if ((a[i]>a[i-1])&&(a[i]>a[i+1])){
            std::cout<<a[i];
            break;
        }
    }

}

void array43(){
    int n,i;
    std::cout<<"n =";
    std::cin>>n;
    int *a= new int[n];
    for (i=0; i<n; ++i){
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    int k=1;
    for(i=1; i<n; ++i){
        if (a[i-1]!=a[i]){
            k+=1;
        }
    }
    std::cout<<"k ="<<k;
}

void array53(){
    int n,i;
    std::cout<<"n =";
    std::cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    int *c=new int[n];
    for(i=0; i<n; ++i){
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    for (i=0; i<n; ++i){
        std::cout<<"b[n] =";
        std::cin>>b[i];
    }
    for(i=0; i<n; ++i){
        if(a[i]>b[i]){
            c[i]=a[i];
        }
        else c[i]=b[i];
    }
    for (i=0; i<n; ++i) {
        std::cout << "c[n] ="<<c[i]<<std::endl;
    }
}

void array63(){
    int  n, i;
    int kb=0;
    int kc=0;
    std::cout<<"n =";
    std::cin>>n;
    int *a= new int[n];
    int *b= new int[kb];
    int *c= new int[kc];
    for (i=0; i<n; ++i){
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    for (i=0; i<n; ++i){
        if (a[i]>0){
            b[i]=a[i];
            ++kb;
        }
        if (a[i]<0){
            c[i]=a[i];
            ++kc;
        }

    }
    for(i=0; i<kb; ++i){
        std::cout<<"b[i] ="<<b[i]<<std::endl;
    }
    for (i=0; i<kc; ++i){
        std::cout<<"c[i] ="<<c[i]<<std::endl;
    }
    std::cout<<"kb ="<<kb<<std::endl;
    std::cout<<"kc ="<<kc;


}

void array75(){
    int n,i;
    std::cout<<"n =";
    std::cin>>n;
    int *a= new int[n];
    for(i=0; i<n; ++i){
        std::cout<<"a[n] =";
        std::cin>>a[i];
    }
    int max =a[0];
    int min =a[0];
    for(i=0; i<n; ++i){
        if (a[i]>max){
            max=a[i];
        }
        if (a[i]<min){
            min=a[i];
        }
    }
    for (i=0; i<n; ++i){
        std::reverse(min[a],max[a]);
    }
    for (i=min; i<=max; ++i){

    }



}

void array85(){
    int n,i;
    std::cout<<"n =";
    std::cin>>n;
}



int main() {
    array75();
    return 0;
}
