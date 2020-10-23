#include <iostream>
#include <ctime>
#include <math.h>
#include "omp.h"

using namespace std;

double fun(double x);

int main() {

    setlocale(0, "");

    int k;
    double a = 0, b = 0;
    int n = 0;
    double sum = 0;

    cout << "Введите число потоков: ";
    cin >> k;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "n: ";
    cin >> n;

    double h = (b - a) / n;

    unsigned int start_time = clock(); // начальное время

    #pragma omp parallel for num_threads(k) reduction (+: sum)
    for (int i = 1; i <= n; ++i)
        sum += fun(a + i * h) * h;

    unsigned int end_time = clock(); // конечное время

    cout << "result: " << sum << endl;
    cout << "time: " << (end_time - start_time) << endl;

    return 0;
}

double fun(double x) {
    return (cos(2 * x * x) * sin(x) + log(x * x * x)) - (cos(2 * x * x) / sin(x) - log(x * x * x));
}
