#ifndef MINE_HASHTABLE_H
#define MINE_HASHTABLE_H

#include "utils.h"
#include <stdlib.h>

size_i Hash(cstring tag, size_i table_size);

/* NOTE[theo]: Is it a good idea to make the [] operator public? */
template<typename HASH_TYPE>
class Hashtable
{
	public:
	const size_i size;
	
	Hashtable(const size_i size);
	~Hashtable();
	
	size_i Add(cstring tag, HASH_TYPE data);
	HASH_TYPE* Get(cstring tag);
	HASH_TYPE* operator[](size_i index);
	
	private:
	HASH_TYPE **data;
};


template<typename HASH_TYPE>
HASH_TYPE* Hashtable<HASH_TYPE>::operator[](const size_i index)
{
	return this->data[index];
}

template<typename HASH_TYPE>
Hashtable<HASH_TYPE>::Hashtable(const size_i size) : size(size)
{
	assert(size != 0);
	this->data = (HASH_TYPE**) malloc(sizeof(HASH_TYPE**) * size);
	
	for (size_i i = 0; i < size; i++)
	{
		this->data[i] = nullptr;
	}
}

template<typename HASH_TYPE>
Hashtable<HASH_TYPE>::~Hashtable()
{
	for (size_i i = 0; i < this->size; i++)
	{
		if (this->data[i] != 0) free(this->data[i]);
	}
	
	free(this->data);
}

/* TODO[theo]: Create a linkedlist type collision helper. */
/* TODO[theo]: Make a way to Handle collisions. */
template<typename HASH_TYPE>
size_i Hashtable<HASH_TYPE>::Add(cstring tag, HASH_TYPE data)
{
	size_i tag_index = Hash(tag, this->size);
	
	if (this->data[tag_index] == 0)
	{
		this->data[tag_index] = (HASH_TYPE*) malloc(sizeof(HASH_TYPE*));
		*this->data[tag_index] = data;
		return tag_index;
	}
	
	for (size_i i = 0; i < this->size; i++)
	{
		if (this->data[i] == nullptr)
		{
			this->data[i] = (HASH_TYPE*) malloc(sizeof(HASH_TYPE*));
			*this->data[i] = data;
			return i;
		}
	}
	
	/* TODO[theo]: I REALLY need to thing in a better way to manage this. */
	//assert(false);
	return 0;
}

/* TODO[theo]: Think about a better way to do get a value from the table. */
template<typename HASH_TYPE>
HASH_TYPE* Hashtable<HASH_TYPE>::Get(cstring tag)
{
	size_i tag_index = Hash(tag, this->size);
	if (this->data[tag_index] != NULL) return this->data[tag_index];
	return nullptr;
}

#endif