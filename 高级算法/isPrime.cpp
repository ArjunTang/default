// 素数判定

#include <iostream>
using namespace std;

// 试除法
bool isPrime1(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// wilson素数判定
bool isPrime2(int n) {
    
}

// 费马小定理
bool isPrime3(int n) {
    
}

// 孙子定理
bool isPrime4(int n) {
    
}

// 测试
int main() {
    int n;
    while (cin >> n) {
        if (isPrime1(n)) cout << "Prime" << endl;
        else cout << "Not Prime" << endl;
    }
    return 0;
}