#ifndef MATRIX
#define MATRIX

#include <bits/stdc++.h>
using namespace std;

class Matrix
{
    private:
        int lines;
        int columns;
        vector<int> data;

    public:
        Matrix();
        Matrix(int lines, int columns);
        Matrix(int lines, int columns, vector<int> data);

        int getLines();
        int getColumns();
        int get(int line, int column);
        void set(int line, int column, int value);
        Matrix add(Matrix operand);
        Matrix multiply(Matrix operand);
        void extendRight(Matrix extention);
        Matrix sliceLines(int from, int to);
        Matrix sliceColumns(int from, int to);
        Matrix slice(int fromLine, int toLine, int fromColumn, int toColumn);
        void shiftRow(int line);
        void shiftColumn(int column);
        Matrix copy();
        string toString();

};

#endif