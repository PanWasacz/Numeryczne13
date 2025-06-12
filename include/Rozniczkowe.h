#pragma once

#include <functional>
#include <vector>

// Rozwi�zywanie r�wna� r�niczkowych metod� Eulera
// y' = f(x, y), dane: x0, y0, x_end, krok h
// Zwraca: wektor kolejnych warto�ci y
std::vector<double> euler(double x0, double y0, double x_end, double h, std::function<double(double, double)> f);
