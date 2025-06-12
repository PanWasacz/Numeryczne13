#pragma once

#include <functional>
#include <vector>

// Rozwi¹zywanie równañ ró¿niczkowych metod¹ Eulera
// y' = f(x, y), dane: x0, y0, x_end, krok h
// Zwraca: wektor kolejnych wartoœci y
std::vector<double> euler(double x0, double y0, double x_end, double h, std::function<double(double, double)> f);
