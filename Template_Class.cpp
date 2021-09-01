#include<iostream>
using namespace std;

// *** Template Class ***
template<class T>
class Arithmetic{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add(){
    T c;
    c = a + b;
    return c;
}

template<class T>
T Arithmetic<T>::sub(){
    T c;
    c = a - b;
    return c;
}


/* Normal Class

class Arithmetic{
    private:
        int a;
        int b;
    public:
        Arithmetic(int a, int b);
        int add();
        int sub();
};

Arithmetic::Arithmetic(int a, int b){
    this->a = a;
    this->b = b;
}

int Arithmetic::add(){
    int c;
    c = a + b;
    return c;
}

int Arithmetic::sub(){
    int c;
    c = a - b;
    return c;
} */

int main(){
    Arithmetic<float> a(8.4, 5.1);
    cout<<"Add : "<<a.add()<<endl<<"Sub : "<<a.sub()<<endl; // But What If We want for float and double type data???? Therefore, we will convert this class to Template
    return 0;
}