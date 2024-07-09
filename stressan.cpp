#include <iostream>
#include <vector>

using namespace std;

// Function declarations
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> matrixAdd(const vector<vector<int>>& A, const vector<vector<int>>& B);
void printMatrix(const vector<vector<int>>& matrix);

// Function to perform matrix multiplication of two matrices A and B
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size(); // assuming A and B are square matrices of the same size
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n <= 2) {
        // Base case: directly multiply A and B
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    } else {
        // Recursive case: divide matrices A and B into submatrices
        int half = n / 2;

        // Create submatrices
        vector<vector<int>> A11(half, vector<int>(half));
        vector<vector<int>> A12(half, vector<int>(half));
        vector<vector<int>> A21(half, vector<int>(half));
        vector<vector<int>> A22(half, vector<int>(half));

        vector<vector<int>> B11(half, vector<int>(half));
        vector<vector<int>> B12(half, vector<int>(half));
        vector<vector<int>> B21(half, vector<int>(half));
        vector<vector<int>> B22(half, vector<int>(half));

        // Populate submatrices
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + half];
                A21[i][j] = A[i + half][j];
                A22[i][j] = A[i + half][j + half];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + half];
                B21[i][j] = B[i + half][j];
                B22[i][j] = B[i + half][j + half];
            }
        }

        // Recursive calls
        vector<vector<int>> C11 = matrixAdd(matrixMultiply(A11, B11), matrixMultiply(A12, B21));
        vector<vector<int>> C12 = matrixAdd(matrixMultiply(A11, B12), matrixMultiply(A12, B22));
        vector<vector<int>> C21 = matrixAdd(matrixMultiply(A21, B11), matrixMultiply(A22, B21));
        vector<vector<int>> C22 = matrixAdd(matrixMultiply(A21, B12), matrixMultiply(A22, B22));

        // Combine results into C
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                C[i][j] = C11[i][j];
                C[i][j + half] = C12[i][j];
                C[i + half][j] = C21[i][j];
                C[i + half][j + half] = C22[i][j];
            }
        }
    }

    return C;
}

// Function to add two matrices (of the same size)
vector<vector<int>> matrixAdd(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of matrices (must be a power of 2): ";
    cin >> n;

    // Input matrices A and B (assuming square matrices of size n)
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Perform matrix multiplication using the Strassen's algorithm
    vector<vector<int>> C = matrixMultiply(A, B);

    // Output the result matrix C
    cout << "Resultant matrix C:\n";
    printMatrix(C);

    return 0;
}
