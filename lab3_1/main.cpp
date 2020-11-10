#include <iostream>
#include <cmath>
//Знайти чисельний розв’язок системи лінійних рівнянь 𝐴𝑥=𝑏

int main() {
    int n;
    int NumberOfTrue=0;
    int k;
    double delta;
    std::cout << "n =";
    std::cin >> n;
    std::cout << "k =";
    std::cin >> k;
    int** a = new int* [n];
    double** x = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        x[i] = new double[k+1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int* b = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        x[i][0] = 0;
    }

    for (int i =0; i<n; ++i){
        int sum=0;
        for (int j=0; j<n; ++j){
            sum+=abs(a[i][j]);
        }
        sum=sum-abs(a[i][i]);
        if (abs(a[i][i])>sum){
            ++NumberOfTrue;
        }
    }
    if (NumberOfTrue==n){
        std::cout<<"Convergence condition is True"<<std::endl;
    }
    else {
        std::cout<<"Convergence condition is not True"<<std::endl;
    }

    for (int w = 0; w < k; w++)
    {

        for (int i = 0; i < n; i++)
        {
            double sum2 = b[i];
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                sum2 -= (x[j][w] * a[i][j]);
            }
            x[i][w+1] = sum2 / a[i][i];
        }
        for (int i = n-1; i < n; i++)
        {
            std::cout <<"x["<<i<<"]["<<w+1<<"]="<< x[i][w+1]<<std::endl;
        }

        std::cout << std::endl;
    }

    double MaxDelta=x[0][2]-x[0][1];
    for (int i=0; i<n; i++){
        for (int j=k-1; j<k; j++ ){
            delta=x[i][j+1]-x[i][j];
            std::cout<<"delta"<<i+1<<" "<<delta<<std::endl;
            if(delta>MaxDelta) {
                MaxDelta = delta;
            }
        }

    }
    std::cout<<"MaxDelta ="<<MaxDelta<<std::endl;
    double e;
    std::cout<<"Enter e > MaxDelta"<<std::endl;
    std::cin>>e;
    std::cout<<"solution of a system of linear equations with accuracy e ="<<e;



    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] b;
    delete[] x;

    return 0;

}

