#ifndef AES_KEY_GENERATOR
#define AES_KEY_GENERATOR

#include "matrix.h"

class AESKeyGenerator
{
    private:
        Matrix generateKey(Matrix key, int rconIndex);
        
    public:
        vector<Matrix> generateKeys(Matrix key);
        
};

#endif