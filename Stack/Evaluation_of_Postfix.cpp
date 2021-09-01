#include <iostream>
#include<cstring>
#include <stack>

using namespace std;
 
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')')
        return 0;

    return 1;
}

int Evaluate(char *postfix){
    stack<int> st;
    int i, x1, x2, r;
    for(i=0; postfix[i]!='\0'; i++){
        if(isOperand(postfix[i]))
            st.push(postfix[i] - '0');
        else{
            x2 = st.top();
            st.pop();
            x1 = st.top();
            st.pop();
            switch (postfix[i])
            {
            case '+' : r = x1 + x2; st.push(r); break;
            case '-' : r = x1 - x2; st.push(r); break;
            case '*' : r = x1 * x2; st.push(r); break;
            case '/' : r = x1 / x2; st.push(r); break;
            }
        }
    }
    return st.top();
}

int main(){
    char infix[] = "532*+1-";
    cout<<Evaluate(infix)<<endl;
    return 0;
}