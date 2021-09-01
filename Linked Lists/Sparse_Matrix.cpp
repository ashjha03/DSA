#include <iostream>
using namespace std;
class node
{
public:
    int col;
    int val;
    node *next;
};
class sparse
{
private:
    int trow;
    int tcol;
    node **a; //take this as a double pointer
public:
    sparse(int r, int c)
    {
        trow = r;
        tcol = c;
        node *t, *last;
        a = new node *[r]; // create a array in heap
        int i, x;
        for (i = 0; i < r; i++)
        {
            a[i] = NULL;
        }
        for (i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << "enter the element at row:" << i << " and column:" << j << "\n";
                cin >> x;
                if (x != 0)
                {
                    if (a[i] == NULL)
                    {
                        t = new node;
                        t->col = j;
                        t->val = x;
                        t->next = NULL;
                        a[i] = t;
                        last = t;
                    }
                    else
                    {
                        t = new node;
                        t->col = j;
                        t->val = x;
                        t->next = NULL;
                        last->next = t;
                        last = t;
                    }
                }
            }
            cout << endl;
        }
    }
    void display()
    {
        int i, j;
        node *p;
        for (i = 0; i < trow; i++)
        {
            p = a[i];
            for (j = 0; j < tcol; j++)
            {

                if (p != NULL && j == p->col)
                {
                    cout << p->val << " ";
                    p = p->next;
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main()

{
    sparse a(3, 3);
    a.display();
}