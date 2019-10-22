#include "matrix.h"
#include "multiplication.h"

Matrix::Matrix() {}

Matrix::Matrix(int lines, int columns)
{
    this -> lines = lines;
    this -> columns = columns;
    this -> data = vector<int>(lines * columns);
}

Matrix::Matrix(int lines, int columns, vector<int> data)
{
    this -> lines = lines;
    this -> columns = columns;
    this -> data = data;
}

int Matrix::getLines()
{
    return lines;
}

int Matrix::getColumns()
{
    return columns;
}

int Matrix::get(int line, int column)
{
    return data[columns * line + column];
}

void Matrix::set(int line, int column, int value)
{
    data[columns * line + column] = value;
}

Matrix Matrix::add(Matrix operand)
{
    Matrix result(lines, columns);
    for (int line = 0; line < lines; line++)
    {
        for (int column = 0; column < columns; column++)
        {
            result.set(line, column, get(line, column) ^ operand.get(line, column));
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix operand)
{
    Matrix result(lines, operand.getColumns());
    for (int result_line = 0; result_line < result.getLines(); result_line++)
    {
        for (int result_column = 0; result_column < result.getColumns(); result_column++)
        {
            int sum = 0;
            for (int index = 0; index < columns; index++)
            {
                sum ^= multiplication(get(result_line, index), operand.get(index, result_column));
            }
            result.set(result_line, result_column, modulo(sum));
        }
    }
    return result;
}

void Matrix::extendRight(Matrix extention)
{
    Matrix result(lines, columns + extention.getColumns());
    for (int line = 0; line < lines; line++)
    {
        for (int column = 0; column < columns; column++)
        {
            result.set(line, column, get(line, column));
        }
    }

    for (int line = 0; line < extention.getLines(); line++)
    {
        for (int column = 0; column < extention.getColumns(); column++)
        {
            result.set(line, column + columns, extention.get(line, column));
        }
    }

    this -> columns = result.getColumns();
    this -> data = result.data;
}


Matrix Matrix::sliceLines(int from, int to)
{
    Matrix result(to - from, columns);
    for (int line = from; line < to; line++)
    {
        for (int column = 0; column < columns; column++)
        {
            int val = get(line, column);
            result.set(line - from, column, val);
        }
    }
    return result;
}

Matrix Matrix::sliceColumns(int from, int to)
{
    Matrix result(lines, to - from);
    for (int line = 0; line < lines; line++)
    {
        for (int column = from; column < to; column++)
        {
            result.set(line, column - from, get(line, column));
        }
    }
    return result;
}

Matrix Matrix::slice(int fromLine, int toLine, int fromColumn, int toColumn)
{
    return sliceLines(fromLine, toLine).sliceColumns(fromColumn, toColumn);
}

void Matrix::shiftRow(int line)
{
    for (int column = 1; column < columns; column++)
    {
        int aux = get(line, column - 1);
        set(line, column - 1, get(line, column));
        set(line, column, aux);
    }
}

void Matrix::shiftColumn(int column)
{
    for (int line = 1; line < lines; line++)
    {
        int aux = get(line - 1, column);
        set(line - 1, column, get(line, column));
        set(line, column, aux);
    }
}

Matrix Matrix::copy()
{
    Matrix result(lines, columns);
    for (int line = 0; line < lines; line++)
    {
        for (int column = 0; column < columns; column++)
        {
            result.set(line, column, get(line, column));
        }
    }
    return result;
}

string Matrix::toString()
{
    stringstream result;
    result << hex << setfill('0');
    for (int line = 0; line < lines; line++)
    {
        result << "[ " << setw(2) << get(line, 0);
        for (int column = 1; column < columns; column++)
        {
            result << ", " << setw(2) << get(line, column);
        }
        result << " ]" << endl;
    }
    return result.str();
}