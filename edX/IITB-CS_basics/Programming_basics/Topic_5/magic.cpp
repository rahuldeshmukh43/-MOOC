#include<iostream>
using namespace std;
int main() {

    int square[20][20], N, i, j, sum;
    int rsum[20], jsum[20], csum[20], d1sum =0, d2sum =0;

    /* Read N*/
    cout << " Give value of N " << endl;
    cin >> N;
    cout << " Give elements of the matrix" << endl;
    for (i=0; i<N; i++) {
        for (j=0; j< N; j++) {
            cin >> square[i][j];
        }
    }
    for (i=0; i < N; i++) {
        rsum[i] = 0;
        jsum[i] = 0;
    }

    /* calculate the sum for this being N x N magic square */
    sum = N * (N*N +1) /2;

    /* find the row sums and check against required sum*/
    for (i=0; i< N; i++) {
        rsum[i] = 0;
        for (j=0; j < N; j++) {
            rsum[i] += square[i][j];
        }
        if (rsum[i] != sum) {
            cout << "Not a magic square" << endl;
            return 1;
        }
    }

    /* find the column sums and check against required sum*/
    for (j=0; j< N; j++) {
        csum[j] = 0;
        for (i=0; i < N; i++) {
            csum[j] += square[i][j];
        }
        if (csum[j] != sum) {
            cout << "Not a magic square" << endl;
            return 1;
        }
    }

    /* calculate the sums of two diagonals */
    for (i=0; i< N; i ++) 
        d1sum += square[i][i];
    for (j=0; j < N; j ++) 
        d2sum += square[j][N-j-1];

    /* Now check if these diagonal sums are correct or not */
    if (d1sum != sum) {
        cout << "D1: Not a magic square" << endl;
        return 1;
    }
    if (d2sum != sum) {
        cout << "D2: Not a magic square" << endl;
        return 1;
    }
    /* If we reach this point, then the square is a magic square */
    cout << "Given matrix is a magic square" << endl;
    return 0;
}
