#pragma once

#include <functional>

// Ca�kowanie numeryczne metod� trapez�w
double trapezoidal(double a, double b, int n, std::function<double(double)> f);
