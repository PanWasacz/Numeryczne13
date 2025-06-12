#include "Interpolacja.h"

/* Wchodzi: x, y (punkty), xp (argument); wychodzi: interpolowana wartoœæ w xp */
 /* Interpolacja Lagrange’a - wyznaczenie wartoœci funkcji na podstawie punktów */
double lagrangeInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xp) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j)
                term *= (xp - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}

