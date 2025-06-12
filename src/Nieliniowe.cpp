#include "Nieliniowe.h"
#include <stdexcept>
#include <cmath>

/* Wchodzi: a, b (przedzia�), tol (dok�adno��), f(x); wychodzi: pierwiastek r�wnania */
 /* Metoda bisekcji - znajdowanie miejsca zerowego funkcji */
double bisection(double a, double b, double tol, std::function<double(double)> f) {
    if (f(a) * f(b) >= 0)
        throw std::runtime_error("Brak zmiany znaku funkcji w przedziale.");

    double c;
    while ((b - a) / 2.0 > tol) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0)
            return c;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}
