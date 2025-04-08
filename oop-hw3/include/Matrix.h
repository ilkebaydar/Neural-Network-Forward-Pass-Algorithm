#ifndef OOP_HW3_MATRIX_H
#define OOP_HW3_MATRIX_H

class Matrix {
private:
    float** data;
    int rows;
    int cols;

public:
    // Constructor to create a matrix with specified dimensions
    Matrix(int rows, int cols);

    // Destructor to free allocated memory
    ~Matrix();

    // Copy constructor
    Matrix(const Matrix& other);

    // Assignment operator
    Matrix& operator=(const Matrix& other);

    // Matrix addition operator
    Matrix operator+(const Matrix& other) const;

    // Matrix multiplication operator
    Matrix operator*(const Matrix& other) const;

    // Row indexing operator, returns a pointer to the row
    float* operator[](int row);

    // Const version of row indexing operator
    const float* operator[](int row) const;

    // Print matrix contents
    void print() const;

    // Getter methods
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};


#endif //OOP_HW3_MATRIX_H
