#include<iostream>
using namespace std;
int main() {

    int i, m, j, p, k, n;
    int A[20][20], B[20][20], C[20][20];

    cout << "Enter the size of matrix A (m x n), where m <= 20 and n <= 20: " << endl;
    cin >> m >> n;

    cout << "Enter the size of matrix B (" << n << " x p), where p <= 20: " << endl;
    cin >> p;

    if ( m > 20 || n > 20 || p > 20) {
        cout << "Invalid size";
        return -1;
    }

    // Read matrices A and B
    cout << "Enter elements of Matrix A of size " << m << " x " << n << endl;
    for (i=0; i<m; i=i+1) {
        for (j=0; j<n; j=j+1) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B of size " << n << " x " << p << endl;
    for (i=0; i<n; i=i+1) {
        for (j=0; j<p; j=j+1) {
            cin >> B[i][j];
        }
    }

    //Compute Multiplication of matrices A and B
    for (i=0; i<m; i=i+1) {
        for (j=0; j<p; j=j+1) {
            C[i][j]=0;
            for (k=0; k<n; k=k+1) {
                C[i][j]=C[i][j] + A[i][k]*B[k][j];
            }
        }
    }

    // Output result matrix C
    cout << "Multiplication of Matrices A and B is " << endl;
    for (i=0; i<m; i=i+1) {
        for (j=0; j<p; j=j+1) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}


