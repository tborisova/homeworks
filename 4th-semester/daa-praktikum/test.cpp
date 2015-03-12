#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main (void)
{
    string str, temp;
    int n, i, j;

    printf("\nEnter string: ");
    // gets(string);
    cin >> str;
    n = str.size();

    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            int  s = tolower(string[i]) - tolower(string[j]);
            if ( s == 0 )
            {   // letters are the same... now watch out for case
                s = string[i] - string[j];
            }

            if (s > 0)
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    printf("\n%s", string);
    printf("\n");
    return 0;
}