#include "multiplication.h"

int multiplication(int operand1, int operand2)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((operand1 & (1 << i)) == 0) continue;
        for (int j = 0; j < 8; j++)
        {
            if (operand2 & (1 << j))
            {
                result ^= (1 << (i + j));
            }
        }
    }
    return result;
}

int modulo(int operand1)
{
    int operand2 = 0x11b;
    while (operand2 < operand1) operand2 <<= 1;
    while (operand1 > 0xff) 
    {
        if ((operand1 ^ operand2) < operand2 && (operand1 ^ operand2) < operand1)
        {
            operand1 ^= operand2;
        }
        operand2 >>= 1;
    }
    return operand1;
}