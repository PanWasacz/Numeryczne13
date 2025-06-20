#pragma once

#include <functional>

// Rozwiązywanie równań nieliniowych metodą bisekcji
// Zwraca przybliżone rozwiązanie równania f(x) = 0
double bisection(double a, double b, double tol, std::function<double(double)> f);
