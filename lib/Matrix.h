#ifndef SIMPLE_GRAPHS_MATRIX_H
#define SIMPLE_GRAPHS_MATRIX_H


class MatrixRow;


class Matrix {
private:
    int numberOfRows;
    int numberOfColumns;
    int *values;
    std::string (*rowLabel)(int) = nullptr;
    std::string (*columnLabel)(int) = nullptr;

public:
    explicit Matrix(int numberOfRows, int numberOfColumns);
    explicit Matrix(int numberOfRows, int numberOfColumns, std::string (*rowLabel)(int), std::string (*columnLabel)(int));
    ~Matrix();

    [[nodiscard]] int getNumberOfRows() const;
    [[nodiscard]] int getNumberOfColumns() const;
    [[nodiscard]] int *getValue(int rowNumber, int columnNumber) const;
    MatrixRow operator[](int rowNumber);
    std::string getRowLabel(int rowNumber);
    std::string getColumnLabel(int columnNumber);
};


class MatrixRow {
private:
    Matrix *matrix;
    int rowNumber;

public:
    explicit MatrixRow(Matrix *matrix, int rowNumber);

    int *operator[](int columnNumber);
};


#endif //SIMPLE_GRAPHS_MATRIX_H
