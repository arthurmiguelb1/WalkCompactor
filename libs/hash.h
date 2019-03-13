#ifndef _HASH_H_
#define _HASH_H_

#define hash_size 256

typedef unsigned short USHORT;

typedef struct hash{
	USHORT table[hash_size];
} HASH;

HASH *creating_hash();

#endif