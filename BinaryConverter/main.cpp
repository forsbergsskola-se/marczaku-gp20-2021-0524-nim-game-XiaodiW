#include <iostream>
using std::cout; using std::endl;
void method1(int n){
    if(n > 1) method1(n / 2);
    cout << n % 2;
}

void method2(int n){
    if(n > 1) method2( n >> 1);
    int result = n & 1;
    cout << result;
}

int main() {
    cout << "Hello, World!" << endl;
    int number =1;
    while (number != 0) {
    restart:
    cout << "Type in a decimal integer number, which you want to convert to binary:"<< endl;
    std::cin >> number;
    if(number <= 0) {
        cout << "Please type in a valid number" << endl;
        goto restart;
    }
    method1(number);
    cout << endl;
    method2(number);
    cout << endl;
    }
    return 0;
}
