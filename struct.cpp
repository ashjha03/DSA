#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x; // ***** Here Compiler is assigning 4 bytes to char for the ease of simplicity but char in actual is using only 1 byte ***** This concept is known as PADDING ******
} r1 ;

int main(){
    cout<<sizeof(r1)<<endl<<sizeof(r1.x)<<endl;
    return 0;
}