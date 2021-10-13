#include "utils.h"
#include "mine_hashtable.h"

size_i Hash(cstring tag, size_i table_size)
{
	assert(tag != NULL);
	
	size_i tag_size = StrSize(tag);
	size_i tag_id = 0;
	
	for (size_i i = 0; tag[i] != tag_size; i++)
	{
		tag_id += tag[i];
	}
	
	return (tag_id + tag_size) % table_size;
}
