#include "AESKeyGenerator.h"
#include "substitution.h"
#include "constants.h"

Matrix AESKeyGenerator::generateKey(Matrix key, int rconIndex)
{
    Matrix key_slice_last = key.sliceColumns(key.getColumns() - 1, key.getColumns());
    key_slice_last.shiftColumn(0);

    for (int line = 0; line < key_slice_last.getLines(); line++)
    {
        key_slice_last.set(line, 0, sbox_substitute(key_slice_last.get(line, 0)));
    }

    Matrix result = key.sliceColumns(0, 1).add(key_slice_last);
    result.set(0, 0, result.get(0, 0) ^ R_CON[rconIndex]);

    for (int column = 1; column < key.getColumns(); column++)
    {
        result.extendRight(key.sliceColumns(column, column + 1).add(result.sliceColumns(column - 1, column)));
    }

    return result;
}

vector<Matrix> AESKeyGenerator::generateKeys(Matrix key)
{
    vector<Matrix> result;
    result.push_back(key);

    for (int iteration = 0; iteration < 10; iteration++)
    {
        result.push_back(generateKey(key, iteration));
        key = result.back();
    }

    return result;
}