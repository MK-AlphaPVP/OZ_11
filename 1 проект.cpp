#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[15][15];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int s = 0;
    for (int j = 0; j < n; ++j) s += a[0][j];

    bool ok = true;

    for (int i = 0; i < n && ok; ++i) {
        int row = 0;
        for (int j = 0; j < n; ++j) row += a[i][j];
        if (row != s) ok = false;
    }

    for (int j = 0; j < n && ok; ++j) {
        int col = 0;
        for (int i = 0; i < n; ++i) col += a[i][j];
        if (col != s) ok = false;
    }

    int d1 = 0;
    for (int i = 0; i < n; ++i) d1 += a[i][i];
    if (d1 != s) ok = false;

    int d2 = 0;
    for (int i = 0; i < n; ++i) d2 += a[i][n - 1 - i];
    if (d2 != s) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}