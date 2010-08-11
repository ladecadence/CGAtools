/*
 * Creates a ROM image for a IBM CGA compatible card
 * from a text file containing a representation of the data.
 *
 * (CC) David Pello 2010
 * http://ladecadence.net
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BINARY_HIGH	'#'
#define _BINARY_LOW		'.'

FILE* 	input;
FILE*	output;
int 	c;

/* converts binary text representation to a byte */
char txt2byte(char data[8])
{
	int i;
	char n;
	char byte = 0;
	char tmp[8];

	/* invert input string */
	for(i=0; i<8; i++)
		tmp[7-i] = data[i];
	data = tmp;

	/* conversion */
	for(i=0; i<8; i++)
	{
		n = data[i];
		
		if (n == _BINARY_HIGH)
			n = 1;
		else
			n = 0;

		byte = byte | (n<<i);
	}

	return byte;
}

int main(int argc, char* argv[])
{
	char line[8];
	char buffer[255];
	int count = 0;

	/* check parameters */
	if (argc<3) {
		printf("Usage:\n");
		printf("\t%s <input txt> <output rom>\n", argv[0]);
		exit(1);
	}

	/* Open files */
	input = fopen(argv[1], "r");
	if (input == NULL)
		printf("Can't open input file\n");

	output = fopen(argv[2], "w");
    if (output == NULL)
        printf("Can't open output file\n");

	/* main loop */
	/* read a line from the input, convert it to a byte */
	/* and write it to the output */
	while (!feof(input))
	{
		if (fgets(buffer, 255, input) != NULL)
		{
			strncpy(line, buffer, 8);
			fputc(txt2byte(line), output);
			count++;
		}
	}
	
	printf("%d bytes written.\n", count);

	/* cleaning */
	fclose(input);
	fclose(output);

	return 0;
}

