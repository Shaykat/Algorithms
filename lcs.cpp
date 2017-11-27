#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int a = 100,b = 100;
int array[a][b];
int max(int p,int q);
int main()
{
    string str1,str2;

    cin >> str1;
    cin >> str2;
    int len1,len2;
    len1 = str1.length();
    len2 = str2.length();

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i] == str2[j])
            {
                array[i][j] = array[i-1][j-1] + 1;
                cout << array[i][j] << endl;
            }
            else
            {
                array[i][j] = max(array[i][j-1],array[i-1][j]);
            }
        }
    }
    cout << "LCS = " << array[len1][len2];
    int i=len1,j=len2;
    while(1)
    {
        if(i == 0 || j ==0)
        break;
        if(array[i-1][j-1]+1 == array[i][j])
        {
            cout << str2[j];
            i--;
            j--;
        }
        else
        {
            if(max(array[i][j-1],array[i-1][j]) == array[i][j-1])
            j--;
            else
            i--;
        }

    }
}

int max(int p,int q)
{
    if(p > q)
    return p;
    else if(p == q)
    return p;
    else
    return q;
}
/* abbcaac
 accbcca */
