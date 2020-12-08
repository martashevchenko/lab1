#include <iostream>
#include <stdio.h>
#include <string.h>


bool isPalindrome(char *str)
{
    int len = sizeof (str)/sizeof(str[0])-1;

    // single character is always palindrome
    if (len == 1)
        return true;

    // pointing to first character
    char *ptr1 = str;

    // pointing to last character
    char *ptr2 = str+len-1;

    while (ptr2 > ptr1)
    {
        if (*ptr1 != *ptr2)
            return false;
        ptr1++;
        ptr2--;
    }

    return true;
}


int NumberOfAppends(char *str)
{
    int k=0;
    for (int i=0; i<sizeof (str)/sizeof(str[0])-1; i++)
    {
        k++;
        if (isPalindrome(str))
        {
            break;
        }
    }
    return k;
}

int main()
{
    char s[]="frala";
    int n;
    std::cout<<"Enter n =";
    std::cin>>n;
    char* m=new char [n];
    char* l=new char [n];
    strcpy(m,s);
    for (int i=0; i<NumberOfAppends(s); i++)
    {
        l[i]=s[NumberOfAppends(s)-i-1];
    }
    strcat(m,l);
    std::cout<<"m ="<<m;


}

