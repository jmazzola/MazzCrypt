#include "Decrypt.h"



char* Decrypt(int count, ...) {
    va_list ap;

    char* buffer = new char[count + 1];

    va_start(ap, count);

    for (int i = 0; i < count; i++) {

        char read = va_arg(ap, char);

        buffer[i] = (read ^ ((XORKEY + i) % 0xFF));

    }
    va_end(ap);

    buffer[count] = '\0';

    return buffer;

}