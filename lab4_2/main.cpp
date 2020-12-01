#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cout<<"Enter n -";
    std::cin>>n;
    int* data = new int[n];
    for (int i=0; i<n; i++)
    {
        std::cout<<"data["<<i<<"]=";
        std::cin>>data[i];
    }
    for (int a=0; a<n; a++)
    {
        if (data[a]==0)
        {
            continue;
        }
        for (int b=0; b<n; b++)
        {
            if (data[b]==0 || b==a)
            {
                continue;
            }
            for (int c=0; c<n; c++)
            {
                if (data[c]==0 || c==b || c==a)
                {
                    continue;

                }
                else if ((pow(data[a],2)+pow(data[b],2)>pow(data[c],2)) && (pow(data[a],2)+pow(data[c],2)>pow(data[b],2)) &&(pow(data[b],2)+pow(data[c],2)>pow(data[a],2)))
                {
                    std::cout<<"a ="<<data[a]<<" "<<"b ="<<data[b]<<" "<<"c ="<<data[c]<<" "<<std::endl;


                }

            }
        }
    }


    return 0;
}
