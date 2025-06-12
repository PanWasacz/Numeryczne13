#include "Liniowe.h"
#include <stdexcept>

/* Wchodzi: A (macierz), b (wektor wyrazów wolnych); wychodzi: rozwi¹zanie x */
 /* Eliminacja Gaussa - rozwi¹zywanie uk³adu równañ liniowych */
std::vector<double> gaussElimination(std::vector<std::vector<double>> A, std::vector<double> b) {
    int n = A.size();

    // eliminacja Gaussa
    for (int i = 0; i < n; i++) {
        if (A[i][i] == 0.0)
            throw std::runtime_error("Dzielenie przez zero.");

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
                A[j][k] -= factor * A[i][k];
            b[j] -= factor * b[i];
        }
    }

    // podstawianie wsteczne
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
    return x;
}
