#ifndef UTILS_H
#define UTILS_H

/* NOTE[theo]: Assertion is used widely through this program */
#include <assert.h>
#include <stddef.h>

typedef const char* cstring;
typedef unsigned long long size_i;

size_i StrSize(cstring str);
bool StrCompare(cstring str1, cstring str2);

#endif
