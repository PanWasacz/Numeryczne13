#include "Rozniczkowe.h"
#include <stdexcept>

std::vector<double> euler(double x0, double y0, double x_end, double h, std::function<double(double, double)> f) {
    if (h <= 0)
        throw std::runtime_error("Krok musi byc dodatni.");

    std::vector<double> y_values;
    double x = x0;
    double y = y0;

    y_values.push_back(y);

    while (x < x_end) {
        y += h * f(x, y);
        x += h;
        y_values.push_back(y);
    }

    return y_values;
}