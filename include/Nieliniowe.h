#pragma once

#include <functional>

// Rozwi�zywanie r�wna� nieliniowych metod� bisekcji
// Zwraca przybli�one rozwi�zanie r�wnania f(x) = 0
double bisection(double a, double b, double tol, std::function<double(double)> f);
