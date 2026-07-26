#include<bits/stdc++.h>
using namespace std;

void fun(int x) {
    cout << "Integer";
}

void fun(int* x) {
    cout << "Pointer";
}

int main(){
    fun(0); //interger
    fun(nullptr); //pointer
}