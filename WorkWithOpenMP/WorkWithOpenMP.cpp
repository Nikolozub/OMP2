#include <iostream>
#include "omp.h"

using namespace std;

double fun(double x);

int main() {

    double a = 0, b = 0;
    int n = 0;
    double sum = 0;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "n: ";
    cin >> n;
    
    double h = fabs((b - a) / n);

    #pragma omp parallel for num_threads(2) reduction (+: sum)
    for (int i = 1; i <= n; ++i)
        sum += fun(a + i * h) * h;

    printf("result: %f", sum);
    return 0;
}

double fun(double x) {
    return 10.0;
}