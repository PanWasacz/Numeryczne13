#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include "Liniowe.h"
#include "Interpolacja.h"
#include "Aproksymacja.h"
#include "Calkowanie.h"
#include "Rozniczkowe.h"
#include "Nieliniowe.h"

using namespace std;

const double PI = 3.14159265358979323846;

/* Testy dla wszystkich funkcji numerycznych */
/* Ka¿da funkcja testowana dla przypadku ³atwego i trudniejszego */

// Uk³ady równañ liniowych
void testLiniowe() {
    cout << "Test: Uklady rownan liniowych" << endl;

    vector<vector<double>> A1 = { {2, 3}, {1, -1} };
    vector<double> b1 = { 5, 0 };
    auto x1 = gaussElimination(A1, b1);
    cout << "[Latwy] x=" << x1[0] << ", y=" << x1[1] << endl;

    vector<vector<double>> A2 = { {3, 2}, {4, -1} };
    vector<double> b2 = { 10, 5 };
    auto x2 = gaussElimination(A2, b2);
    cout << "[Trudniejszy] x=" << x2[0] << ", y=" << x2[1] << endl;
}

// Interpolacja
void testInterpolacja() {
    cout << "\nInterpolacja Lagrange'a" << endl;

    vector<double> x1 = { 1, 2, 3 };
    vector<double> y1 = { 1, 4, 9 };
    double xp1 = 2.5;
    double yp1 = lagrangeInterpolation(x1, y1, xp1);
    cout << "[Latwy] x=" << xp1 << ", y=" << yp1 << endl;

    vector<double> x2 = { 0, 1, 2, 3 };
    vector<double> y2 = { 1, 2, 5, 10 };
    double xp2 = 1.5;
    double yp2 = lagrangeInterpolation(x2, y2, xp2);
    cout << "[Trudniejszy] x=" << xp2 << ", y=" << yp2 << endl;
}

// Aproksymacja
void testAproksymacja() {
    cout << "\nTest: Aproksymacja najmniejszych kwadratow" << endl;

    vector<double> x1 = { 1, 2, 3, 4, 5 };
    vector<double> y1 = { 2.2, 2.8, 3.6, 4.5, 5.1 };
    auto res1 = leastSquares(x1, y1);
    cout << "[Latwy] a=" << res1.first << ", b=" << res1.second << endl;

    vector<double> x2 = { 1, 2, 3, 4 };
    vector<double> y2 = { 2, 3.9, 6.1, 8 };
    auto res2 = leastSquares(x2, y2);
    cout << "[Trudniejszy] a=" << res2.first << ", b=" << res2.second << endl;
}

// Ca³kowanie numeryczne
void testCalkowanie() {
    cout << "\nCalkowanie numeryczne (trapezy)" << endl;

    auto f1 = [](double x) { return x * x; };
    double result1 = trapezoidal(0, 1, 100, f1);
    cout << "[Latwy] calka = " << result1 << endl;

    auto f2 = [](double x) { return sin(x); };
    double result2 = trapezoidal(0, PI, 100, f2);
    cout << "[Trudniejszy] calka = " << result2 << endl;
}

// Równania ró¿niczkowe
void testRozniczkowe() {
    cout << "\nRozw. row. rozniczkowego (Euler)" << endl;

    auto f1 = [](double x, double y) { return -y; };
    auto res1 = euler(0, 1, 1, 0.1, f1);
    cout << "[Latwy]" << endl;
    for (size_t i = 0; i < res1.size(); i++)
        cout << "y[" << i << "] = " << res1[i] << endl;

    auto f2 = [](double x, double y) { return x + y; };
    auto res2 = euler(0, 1, 1, 0.1, f2);
    cout << "[Trudniejszy]" << endl;
    for (size_t i = 0; i < res2.size(); i++)
        cout << "y[" << i << "] = " << res2[i] << endl;
}

// Równania nieliniowe
void testNieliniowe() {
    cout << "\nRozw. row. nieliniowego (bisekcja)" << endl;

    auto f1 = [](double x) { return x * x - 2; };
    double root1 = bisection(0, 2, 1e-6, f1);
    cout << "[Latwy] pierwiastek z 2 = " << root1 << endl;

    auto f2 = [](double x) { return cos(x) - x; };
    double root2 = bisection(0, 1, 1e-6, f2);
    cout << "[Trudniejszy] cos(x) - x = 0: x = " << root2 << endl;
}

int main() {
    try {
        testLiniowe();
        testInterpolacja();
        testAproksymacja();
        testCalkowanie();
        testRozniczkowe();
        testNieliniowe();
    }
    catch (const exception& e) {
        cout << "Wystapil blad: " << e.what() << endl;
    }
    return 0;
}

