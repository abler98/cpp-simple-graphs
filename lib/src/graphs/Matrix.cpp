#include <string>
#include <stdexcept>
#include "graphs/Matrix.h"

//region Matrix
Matrix::Matrix(int numberOfRows, int numberOfColumns) {
    this->numberOfRows = numberOfRows;
    this->numberOfColumns = numberOfColumns;
    this->values = new int[numberOfRows * numberOfColumns]();
}

Matrix::Matrix(
        int numberOfRows,
        int numberOfColumns,
        std::string (*rowLabeler)(int),
        std::string (*columnLabeler)(int)
) : Matrix::Matrix(numberOfRows, numberOfColumns) {
    this->rowLabeler = rowLabeler;
    this->columnLabeler = columnLabeler;
}

Matrix::~Matrix() {
    delete[] this->values;
}

int Matrix::getNumberOfRows() const {
    return this->numberOfRows;
}

int Matrix::getNumberOfColumns() const {
    return this->numberOfColumns;
}

int *Matrix::getValue(int rowNumber, int columnNumber) const {
    if (rowNumber < 0 || rowNumber >= this->numberOfRows || columnNumber < 0 || columnNumber >= this->numberOfColumns) {
        throw std::out_of_range("Out of range error");
    }

    return &this->values[columnNumber * this->numberOfRows + rowNumber];
}

MatrixRow Matrix::operator[](int rowNumber) {
    return MatrixRow(this, rowNumber);
}

std::string Matrix::getRowLabel(int rowNumber) {
    if (this->rowLabeler == nullptr) {
        return std::to_string(rowNumber);
    } else {
        return (*this->rowLabeler)(rowNumber);
    }
}

std::string Matrix::getColumnLabel(int columnNumber) {
    if (this->columnLabeler == nullptr) {
        return std::to_string(columnNumber);
    } else {
        return (*this->columnLabeler)(columnNumber);
    }
}
//endregion


//region MatrixRow
MatrixRow::MatrixRow(Matrix *matrix, int rowNumber) {
    this->matrix = matrix;
    this->rowNumber = rowNumber;
}

int *MatrixRow::operator[](int columnNumber) {
    return this->matrix->getValue(this->rowNumber, columnNumber);
}
//endregion
