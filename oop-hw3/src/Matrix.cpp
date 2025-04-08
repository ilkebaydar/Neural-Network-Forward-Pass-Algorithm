#include "../include/Matrix.h"

#include <iostream>
#include <iomanip>


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    // Allocate memory for the matrix
    data = new float*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new float[cols];
        // Initialize all values to zero
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0.0f;
        }
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Copy constructor
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    // Allocate memory
    data = new float*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new float[cols];
        // Copy values
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        // Copy new dimensions
        rows = other.rows;
        cols = other.cols;

        // Allocate new memory
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[cols];
            // Copy values
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// Matrix addition
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match for addition");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0.0f;
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

// Row indexing
float* Matrix::operator[](int row) {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    return data[row];
}

// Const version of row indexing
const float* Matrix::operator[](int row) const {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Row index out of range");
    }
    return data[row];
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(4) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

