#pragma once

#include <vector>
#include <utility>

// Aproksymacja najmniejszych kwadratów liniowa (y = a*x + b)
// Zwraca parê (a, b)
std::pair<double, double> leastSquares(const std::vector<double>& x, const std::vector<double>& y);