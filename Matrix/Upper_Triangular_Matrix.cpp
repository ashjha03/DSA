#include<iostream>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};

// Row Major Mapping
void Set(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[((i-1) * m->n) - ((i-1) * (i-2) /2) + (j-i)] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i <= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.A[((i-1) * m.n) - ((i-1) * (i-2) /2) + (j-i)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    Matrix m;
    m.n = 4;
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    Set(&m, 1, 1, 1);
    Set(&m, 1, 2, 2);
    Set(&m, 1, 3, 3);
    Set(&m, 1, 4, 4);
    Set(&m, 2, 2, 1);
    Set(&m, 2, 3, 2);
    Set(&m, 2, 4, 3);
    Set(&m, 3, 3, 1);
    Set(&m, 3, 4, 2);
    Set(&m, 4, 4, 1);

    Display(m);
    return 0;
}

// Column major mapping formula
// Index(i, j) = ( j * ( j - 1) / 2 ) + ( i - 1 )