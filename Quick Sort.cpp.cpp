#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int x = 100;
int array[x];
int upper[100],lower[100];
void Quick_sort(int array[],int left,int right,int loc,int n)
{

    while(left != right)
    {
        while(array[loc] <= array[right])
        {
            right--;
        }
        if(loc == right)
        break;

        if(array[loc] > array[right])
        {
            swap(array[loc],array[right]);
            loc = right;
        }
        while(array[loc] >= array[left])
        {
            left++;
        }
        if(loc == left)
        break;

        if(array[loc] < array[left])
        {
            swap(array[loc],array[left]);
            loc = left;
        }
    }
}
int main()
{
    int top = 0;
    int loc,left,right,i,n;
    cout << "Enter how many elements you want to insert..... ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        array[i] = rand()%100;
        cout << array[i] << endl;
    }
    if(n>1)
    {
        top++;
        lower[top] = 1;
        upper[top] = n;
    }
    while(top)
    {
        left = lower[top];
        right = upper[top];
        loc = left;
        top--;
        Quick_sort(array,left,right,loc,n);
        /*if(left < loc-1)
        {
            top++;
            lower[top] = left;
            upper[top] = loc-1;
        }
        if(right > loc+1)
        {
            top++;
            lower[top] = left;
            upper[top] = loc-1;
        }*/
    }

    return 0;

}
