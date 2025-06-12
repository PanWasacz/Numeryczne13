#pragma once

#include <functional>

// Ca³kowanie numeryczne metod¹ trapezów
double trapezoidal(double a, double b, int n, std::function<double(double)> f);
