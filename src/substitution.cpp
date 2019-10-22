#include "substitution.h"
#include "constants.h"

int sbox_substitute(int value)
{
    int s_box_line = value / 0x10;
    int s_box_column = value % 0x10;
    return S_BOX.get(s_box_line, s_box_column);
}