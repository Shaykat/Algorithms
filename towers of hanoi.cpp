#include<iostream>
#include<cstdio>
using namespace std;

void towers_of_hanoi(int n,char S,char I,char D)
{
    if(n>0)
    {
        towers_of_hanoi(n-1,S,D,I);
        printf("%d %c -> %c\n",n,S,D);
        towers_of_hanoi(n-1,I,S,D);
    }

}

int main()
{
    int n;
    char S,I,D;

    cin >> n;
    cin >> S >> I >> D;

    towers_of_hanoi(n,S,I,D);

    return 0;
}
