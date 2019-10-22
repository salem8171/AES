#ifndef AES_FILE
#define AES_FILE

#include "matrix.h"

class AES
{
    private:
        vector<Matrix> keys;
        Matrix subBytes(Matrix state);
        Matrix shiftRows(Matrix state);
    
    public:
        AES(Matrix key);
        Matrix encrypt(Matrix payload);
};

#endif