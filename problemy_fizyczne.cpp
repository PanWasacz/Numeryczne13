#include <iostream>
#include <vector>
#include <functional>
#include "Rozniczkowe.h"
#include "Liniowe.h"

using namespace std;

void testChlodzenieKulki() {
    cout << "\nTest 1: Chłodzenie kulki według prawa Newtona\n";
    // dT/dt = -k(T - T_otoczenia), T(0) = 100, T_otoczenia = 20, k = 0.1
    double T0 = 100.0;
    double T_otoczenia = 20.0;
    double k = 0.1;
    double t0 = 0.0;
    double tn = 10.0;
    double h = 1.0;

    auto dTdt = [=](double t, double T) {
        return -k * (T - T_otoczenia);
    };

    vector<double> wynik = euler(t0, T0, tn, h, dTdt);
    for (size_t i = 0; i < wynik.size(); ++i) {
        cout << "T[" << i << "] = " << wynik[i] << " °C\n";
    }
}

void testObwodElektryczny() {
    cout << "\nTest 2: Obliczanie prądów w obwodzie (układ równań)\n";
    // Układ równań:
    // 10*I1 + 5*I2 = 20
    //  3*I1 + 7*I2 = 10

    vector<vector<double>> A = {
        {10, 5},
        {3, 7}
    };
    vector<double> b = {20, 10};

    vector<double> rozw = gaussElimination(A, b);
    cout << "Prąd I1 = " << rozw[0] << " A\n";
    cout << "Prąd I2 = " << rozw[1] << " A\n";
}

int main() {
    testChlodzenieKulki();
    testObwodElektryczny();
    return 0;
}
