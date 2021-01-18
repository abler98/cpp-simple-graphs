#include <stdexcept>
#include "Matrix.h"

//region Matrix
Matrix::Matrix(int numberOfRows, int numberOfColumns) {
    this->numberOfRows = numberOfRows;
    this->numberOfColumns = numberOfColumns;
    this->values = new int[numberOfRows * numberOfColumns]();
}

Matrix::Matrix(
        int numberOfRows,
        int numberOfColumns,
        std::string (*rowLabel)(int),
        std::string (*columnLabel)(int)
) : Matrix::Matrix(numberOfRows, numberOfColumns) {
    this->rowLabel = rowLabel;
    this->columnLabel = columnLabel;
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

    return &this->values[rowNumber * this->numberOfRows + columnNumber];
}

MatrixRow Matrix::operator[](int rowNumber) {
    return MatrixRow(this, rowNumber);
}

std::string Matrix::getRowLabel(int rowNumber) {
    if (this->rowLabel == nullptr) {
        return std::to_string(rowNumber);
    } else {
        return (*this->rowLabel)(rowNumber);
    }
}

std::string Matrix::getColumnLabel(int columnNumber) {
    if (this->columnLabel == nullptr) {
        return std::to_string(columnNumber);
    } else {
        return (*this->columnLabel)(columnNumber);
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
