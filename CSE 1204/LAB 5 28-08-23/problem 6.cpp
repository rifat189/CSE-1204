#include <bits/stdc++.h>
using namespace std;
void display(stack<int> bx){
    cout<<"Stack: "<<endl;
    while (!bx.empty()){
        cout<<bx.top()<<endl;
        bx.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int> st;
    cout << st.size() << endl;
    st.push(6);
    st.push(7);
    st.push(9);
    st.push(20);
    st.pop();
    display(st);
    cout << st.top() << endl;
    if(st.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }
}