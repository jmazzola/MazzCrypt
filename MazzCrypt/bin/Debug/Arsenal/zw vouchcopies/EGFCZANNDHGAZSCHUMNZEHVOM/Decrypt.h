#ifndef DECRYPT_H
#define DECRYPT_H

#include <stdlib.h>
#include <stdarg.h>

const char XORKEY = 'W';
char* Decrypt(int count, ...);

#endif