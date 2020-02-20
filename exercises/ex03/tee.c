/* Nikhil Anand */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN_END 1
#define READ_ERROR 2

int readNextChar(char *bufferChar) {
	int bytesRead = read(STDIN_FILENO, bufferChar, 1);
	switch(bytesRead) {
		case -1:
			return READ_ERROR;
		case 0:
			return STDIN_END;
		default:
			return 0;
	}
}

int writeNextChar(char *bufferChar, FILE *fp) {
	int res = fputc(*bufferChar, fp);
	return res;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		puts("Need to include a file name");
		return 1;
	}
	FILE *fp = fopen(argv[1], "ab+");
	if(!fp) {
		puts("Error creating file");
		return 1;
	}
	char *buffer = malloc(sizeof(int));
	int readResult = readNextChar(buffer);
	int writeResult = 0;
	while(readResult != STDIN_END && readResult != READ_ERROR) {
		writeResult = writeNextChar(buffer, fp);
		if(writeResult == EOF) {
			puts("Error writing file");
			break;
		}
		readResult = readNextChar(buffer);
	}
	int res = fclose(fp);
	return res;
}

/*
Question 3: The code is working fine, but there are some warnings that I'm not 100% sure about.
trying to fully understand what UNIX command tee does tripped me up a little bit.

Question 4:
The first solution uses an entire string, which after looking it, seems to be more efficient
than how I did it of reading STDIN one character at a time. The professial solution also takes a lot more into acount
like the buffer for example. 

*/
