#include "Calkowanie.h"
#include <stdexcept>

/* Wchodzi: a, b, n, f(x); wychodzi: warto�� przybli�onej ca�ki */
 /* Metoda trapez�w - przybli�enie ca�ki oznaczonej */
double trapezoidal(double a, double b, int n, std::function<double(double)> f) {
    if (n <= 0)
        throw std::runtime_error("Liczba przedzialow musi by� dodatnia.");

    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}
