#include <iostream>

using namespace std;

void matr(int** a, int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
}

void print(int** a, int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void prov(int k, int n) {

    if (n < 1) {
        cout << "Error: negative number n!!" << endl;
        exit(0);
    }

    if (k > n) {
        cout << "Error: column k > n matrix!!" << endl;
        exit(0);
    }

    else if (k < 1) {
        cout << "Error: negative number k!!" << endl;
        exit(0);
    }
}

int SecondDeter(int** small, int n) {

    if (n == 1) {
        return small[0][0];
    }
    else if (n == 2) {
        return small[0][0] * small[1][1] - (small[0][1] * small[1][0]);
    }
    else {
        int opred = 0;
        int m = 1;
        int n_ = n - 1;
        int** p = new int* [n_];
        for (int i = 0; i < n_; ++i) {
            p[i] = new int[n_];
        }

        for (int i = 0; i < n; ++i) {
            int temp_t = 0;
            for (int t = 0; t < n_; ++t) {
                for (int j = 0; j < n_; ++j) {
                    if (t == i && temp_t == 0)
                        ++temp_t;

                    p[t][j] = small[t + temp_t][j + 1];
                }
            }

            cout << " Second " << endl;
            print(p, n_);
            cout << endl;

            opred += m * small[i][0] * SecondDeter(p, n_);
            m = -m;
        }

        return opred;
    }
}

int MainDeter(int** a, int n, int k) {

    if (n == 1) {
        return a[0][0];
    }

    else if (n == 2) {
        if (k % 2 == 0) {
            return a[0][0] * a[1][1] - (a[0][1] * a[1][0]);
        }

        else {
            return -1 * (a[0][1] * a[1][0]) + (a[0][0] * a[1][1]);
        }
    }

    else {
        int opred = 0;
        int m = 1;
        int n_ = n - 1;
        int** p = new int* [n_];
        for (int i = 0; i < n_; ++i) {
            p[i] = new int[n_];
        }

        for (int i = 0; i < n; ++i) {
            int temp_t = 0; // счётчик индекс строки 
            for (int t = 0; t < n_; ++t) {
                int temp_j = 0; // счётчик индекс столбца
                for (int j = 0; j < n_; ++j) {
                    if (t == i && temp_t == 0) { // проверка индекса строки
                        ++temp_t;
                    }
                    if (j == k && temp_j == 0) { // проверка индекса столбца
                        ++temp_j;
                    }
                    p[t][j] = a[t + temp_t][j + temp_j];
                }
            }

            cout << "Main " << endl;
            print(p, n_);
            cout << endl;

            if ((i + k) % 2 != 0) {
                m = -1;
            }

            opred += m * a[i][k] * SecondDeter(p, n_);
            m = -m;
        }

        return opred;
    }
}

int main()
{
    int opr = 0;
    int n, k;
    cout << "Enter the size of the quadratic matrix: ";
    cin >> n;
    cout << endl;
    cout << "Enter column number: ";
    cin >> k;

    cout << endl;
    prov(k, n);

    k = k - 1;
    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }

    cout << "Enter el. matrix: " << endl;
    cout << endl;
    matr(a, n);
    //print(a, n);

    cout << endl;
    opr = MainDeter(a, n, k);
    cout << "Opr = " << opr;
    cout << endl;

    delete[] a;
    return 0;
}
