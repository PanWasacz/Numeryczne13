#include "Calkowanie.h"
#include <stdexcept>

/* Wchodzi: a, b, n, f(x); wychodzi: wartoœæ przybli¿onej ca³ki */
 /* Metoda trapezów - przybli¿enie ca³ki oznaczonej */
double trapezoidal(double a, double b, int n, std::function<double(double)> f) {
    if (n <= 0)
        throw std::runtime_error("Liczba przedzialow musi byæ dodatnia.");

    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}
