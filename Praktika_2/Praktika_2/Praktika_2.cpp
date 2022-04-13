#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void prov(double eps) {
    if (eps < 0.0) {
        cout << "Error: eps must be posistive!!" << endl;
        exit(0);
    }
    else if (eps > 1.0) {
        cout << "Error: eps incorrect" << endl;
        exit(0);
    }
}

void schet(int x, double ex) {
    double y, c = 0;
    do {
        y = c;
        c = exp(x);
    } while (abs(y - c) >= ex);
    cout << c;
}

int main()
{
    int x = 0;
    double eps = 0.0;
    cout << "Enter X0 for the function y = exp(x): ";
    cin >> x;
    cout << endl;
    cout << "Specify the precision for the function y = exp(x): ";
    cin >> eps;
    cout << endl;

    prov(eps);
    schet(x, eps);
    return 0;
}
