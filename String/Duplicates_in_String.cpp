#include <iostream>
#include <string.h>
using namespace std;

// Method 1 --> Comparing with rest of the elements : Time Complexity : O(n^2)
void Duplicate1(char A[])
{
    int n = strlen(A);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
            if (A[i] == A[j] && A[i] != '0')
            {
                A[j] = '0';
                count++;
            }
        if (count)
            cout << A[i] << " : " << count + 1 << endl;
    }
}

// Method 2 --> Using Hash Table : Time Complexity : O(n)
void Duplicate2(char A[])
{
    int H[26] = {0};
    int n = strlen(A);

    for (int i = 0; i < n; i++)
        H[(int)A[i] - 97]++;

    for (int i = 0; i < 26; i++)
        if (H[i] > 1)
            cout << (char)(i + 97) << " : " << H[i] << endl;
}

// Method 3 --> Using BitWise Operations
void Duplicate3(char a[])
{
    long int h = 0, x = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << (a[i] - 97); // brackets should be used
        if ((x & h) > 0) //x&h should be in brackets
            printf("duplicate character is %c \n", a[i]);
        else
            h = x | h;
    }
}

int main()
{
    char A[] = "ashishjha";
    Duplicate3(A);
    return 0;
}