#include <iostream>

using namespace std;

const int s = 20;
const int k = 10;

void print(int a[])
{
    for ( int i = 0; i < s; i++ )
        cout << a[i] << " ";
    cout << endl;
}

void countingsort(int a[])
{
    int CountArr[k] = { 0 };

    for (int i=0;i<s;i++)
    {
        CountArr[a[i]]++;
    }

    int outputindex=0;
    for (int j=0;j<k;j++)
    {
        while (CountArr[j]--)
            a[outputindex++] = j;
    }

}

int main()
{
    int n,a[100];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    countingsort(a);
    cout << "Output: ";
    print(a);
    return 0;
}
