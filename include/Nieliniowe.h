#pragma once

#include <functional>

// Rozwi¹zywanie równañ nieliniowych metod¹ bisekcji
// Zwraca przybli¿one rozwi¹zanie równania f(x) = 0
double bisection(double a, double b, double tol, std::function<double(double)> f);
