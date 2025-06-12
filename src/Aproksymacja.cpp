#include "Aproksymacja.h"
#include <stdexcept>

/* Wchodzi: x, y (punkty); wychodzi: (a, b) - wspó³czynniki prostej */
 /* Metoda najmniejszych kwadratów - aproksymacja liniowa y = ax + b */
std::pair<double, double> leastSquares(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    if (n != y.size() || n == 0)
        throw std::runtime_error("Niepoprawne dane do aproksymacji.");

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double denominator = n * sumX2 - sumX * sumX;
    if (denominator == 0)
        throw std::runtime_error("Dzielenie przez zero przy liczeniu wspolczynnikow.");

    double a = (n * sumXY - sumX * sumY) / denominator;
    double b = (sumY * sumX2 - sumX * sumXY) / denominator;

    return { a, b };
}
