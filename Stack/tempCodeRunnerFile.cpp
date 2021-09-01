valuate(char *postfix){
//     stack<int> st;
//     int i, x1, x2, r;
//     for(i=0; postfix[i]!='\0'; i++){
//         if(isOperand(postfix[i]))
//             st.push(postfix[i] - '0');
//         else{
//             x2 = st.pop();
//             x1 = st.pop();
//             switch (postfix[i])
//             {
//             case '+' : r = x1 + x2; st.push(r); break;
//             case '-' : r = x1 - x2; st.push(r); break;
//             case '*' : r = x1 * x2; st.push(r); break;
//             case '/' : r = x1 / x2; st.push(r); break;
//             }
//         }
//     }
//     return st.pop();
// }