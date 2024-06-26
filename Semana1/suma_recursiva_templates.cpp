#include <iostream>
#include <vector>
#include <functional>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <int N>
using Matrix = vector<vector<int>>;

template <int N>
int SumaRecursivaMatrices(const Matrix<N>& mat1, const Matrix<N>& mat2, int fil, int col) {
    return [&](int fil, int col) -> int {
        if (fil == 0 && col == 0)
            return mat1[fil][col] + mat2[fil][col];
        else if (col > -1) {
            col--;
            return mat1[fil][col + 1] + mat2[fil][col + 1] + SumaRecursivaMatrices<N>(mat1, mat2, fil, col);
        }
        else {
            fil--;
            return SumaRecursivaMatrices<N>(mat1, mat2, fil, N - 1);
        }
    }(fil, col);
};

int main() {
    const int N = 3;
    Matrix<N> mat11, mat22;

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        vector<int> fil1(N), fil2(N);
        for (int j = 0; j < N; j++) {
            fil1[j] = rand() % 10;
            fil2[j] = rand() % 10;
        }
        mat11.push_back(fil1);
        mat22.push_back(fil2);
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat11[i][j] << "\t";
        cout << endl;
    };
    cout << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat22[i][j] << "\t";
        cout << endl;
    };
    cout << "Suma de Matrices es: " << SumaRecursivaMatrices<N> (mat11, mat22, N - 1, N - 1);
    cout << endl;
    
    return 0;
}
