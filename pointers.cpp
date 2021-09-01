#include<iostream>
using namespace std;

struct Rectangle{
    int length; 
    int breadth;
};

int main(){
    // int a = 10;
    // int *p;
    // p = &a;
    // cout<<a<<endl;
    // cout<<"Using Pointer : "<< *p <<endl; // * -> Derefrencing Operator

    // Pointer to an Array
    // int A[] = {1,2,3,4,5};
    // int *p =A;
    // for (int i = 0; i < 5; i++)
    //     cout<<p[i]<<" ";
    // cout<<endl;

    // int *p = (int *)malloc(5 * sizeof(int)); // malloc or new provide memory under heap, which we can access directly // ********* Malloc function returns a VOID POINTER and hence we have to typecast it always *****
    // int *p = new int[5]; // In C++
    // for(int i=0; i<5; i++)
    //     p[i] = i+1;
    // for (int i = 0; i < 5; i++)
    //     cout<<p[i]<<" "; 
    // delete [ ] p; // In C++ //Always release the memory which is dynamically allocated
    // free(p); // In C



    // ********* Very Interesting thing to NOTE *********
    // ** Size of a pointer is independent of its Data Types
    int *p1;
    float *p2;
    double *p3;
    struct Rectangle *p4;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    return 0;
}