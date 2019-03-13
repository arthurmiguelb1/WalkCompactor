#include <stdio.h>
#include <stdlib.h>
#include "../hufman_tree.h"

int is_bit_i_set(Byte b, int i){
	Byte mask = i << i;
	return mask & b;
}

Byte set_bit_i(Byte b, int i){
	Byte mask = 1 << i;
	return mask | b;
}

Byte clear_byte(){
	return 0 << 8;
}

// pensar em nome melhor pra essa função
int do_and_write_compression(FILE *compressedFile, int *nextBitToSet,
								Byte *compressionBuffer, charInfo){
	int byteFullyCompressed = 0;
	int currentCharBit = 0;
	while (!byteFullyCompressed){
		if (*nextBitToSet == 8){
			*nextBitToSet = 0;
			fputc(*compressionBuffer, compressedFile);
			*compressionBuffer = clear_byte();
		}
		if (is_bit_i_set(charInfo->symbol, currentCharBit)){
			set_bit_i(*compressionBuffer, *nextBitToSet);
			*nextBitToSet += 1;
			currentCharBit += 1;
		}
		if (currentCharBit == charInfo->size){
				byteFullyCompressed = 1;
		}
	}
}
// symbol = 01100000
// size = 3
/*struct
	Byte symbol;
	Byte size;
*/

int compress(FILE *file, FILE *compressedFile, HASH charMaping){
	Byte compressionBuffer = clear_byte();
	Byte readingBuffer;
	int nextBitToSet = 0;
	charInfo;
	while (1){
		readingBuffer = fgetc(file);
		if (feof(file)) break;
		charInfo = get(charMaping, readingBuffer);
		do_and_write_compression(compressedFile, &nextBitToSet,
									&compressionBuffer, charInfo);
	}
	if (nextBitToSet != 0){
		fputc(compressionBuffer, compressedFile);
	}
		return 8 - nextBitToSet;
}


int main(){
	return 0;
}
