#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_dynamic(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    vector<int> test_values = {10, 25, 30, 40, 50};

    cout << "n\tRecursive Time (ms)\tDynamic Time (ms)" << endl;

    for (int n : test_values) {
        auto start = chrono::high_resolution_clock::now();
        fibonacci_recursive(n);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> recursive_time = end - start;

        start = chrono::high_resolution_clock::now();
        fibonacci_dynamic(n);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> dynamic_time = end - start;

        cout << n << "\t" << recursive_time.count() << "\t\t\t" << dynamic_time.count() << endl;
    }

    return 0;
}
