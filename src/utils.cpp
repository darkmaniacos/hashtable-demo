#include "utils.h"

size_i StrSize(cstring str)
{
	assert(str != NULL);
	
	size_i size_count = 0;
	for (;str[size_count] != '\0';)
	{
		size_count++;
	}
	
	return size_count;
}

/* NOTE[theo]: Maybe use later, For hash checking. */
bool StrCompare(cstring str1, cstring str2)
{
	assert(str1 != NULL || str2 != NULL);
	
	size_i str1_size = StrSize(str1);
	size_i str2_size = StrSize(str2);
	if (str1_size != str2_size) return false;
	
	for (size_i i = 0; i < str1_size; i++)
	{
		if (str1[i] != str2[i]) return false;
	}
	
	return true;
}