#include "AES.h"
#include "constants.h"
#include "AESKeyGenerator.h"

AES::AES(Matrix key)
{
    keys = AESKeyGenerator().generateKeys(key);
}

Matrix AES::subBytes(Matrix state)
{
    Matrix result(state.getLines(), state.getColumns());
    for (int line = 0; line < state.getLines(); line++)
    {
        for (int column = 0; column < state.getColumns(); column++)
        {
            int current_state_value = state.get(line, column);
            int s_box_line = current_state_value / 0x10;
            int s_box_column = current_state_value % 0x10;
            int substitution_value = S_BOX.get(s_box_line, s_box_column);
            result.set(line, column, substitution_value);
        }
    }
    return result;
}

Matrix AES::shiftRows(Matrix state)
{
    Matrix result = state.copy();
    for (int line = 0; line < result.getLines(); line++)
    {
        for (int times = 0; times < SHIFT_ROW_COUNTS[line]; times++)
        {
            result.shiftRow(line);
        }
    }
    return result;
}

Matrix AES::encrypt(Matrix state)
{
    Matrix result(state.getLines(), state.getColumns());

    result = state.add(keys[0]);

    for (int iteration = 1; iteration <= 9; iteration++)
    {
        result = subBytes(result);
        result = shiftRows(result);
        result = MIX_COLUMNS.multiply(result);
        result = result.add(keys[iteration]);
    }

    result = subBytes(result);
    result = shiftRows(result);
    result = result.add(keys[10]);

    return result;
}