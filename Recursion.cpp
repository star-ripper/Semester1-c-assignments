#include <iostream>
using namespace std;

void factorial();

int main(){
    int a;
    cin >> a;
    factorial(a);
}
void factorial(int x){
    cout << x*(--x) ;
}