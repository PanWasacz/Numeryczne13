#pragma once

#include <vector>
#include <utility>

// Aproksymacja najmniejszych kwadrat�w liniowa (y = a*x + b)
// Zwraca par� (a, b)
std::pair<double, double> leastSquares(const std::vector<double>& x, const std::vector<double>& y);