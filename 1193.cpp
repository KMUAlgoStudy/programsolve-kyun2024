#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n,a,b;
    cin >> n;
    n--;
    a = (-1+sqrt(1+8*n))/2;
    b = n-a*(a+1)/2;
    //짝수 : 역방향(5/1)
    //홀수 : 정방향(1/5)
    cout << (a%2)*(1+b) + (1-a%2)*(a+1-b) << '/' << (a%2)*(a+1-b) + (1-a%2)*(1+b) << endl;
    return 0;
}