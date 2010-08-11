/*
 * Creates a text file containing a representation of the data
 * in a ROM image from a IBM CGA compatible card.
 *
 * (CC) David Pello 2010
 * http://ladecadence.net
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include "cgatools.h"

FILE* 	input;
FILE*	output;
int 	c;

/* converts one byte to it's text representation */
void byte2txt(char data, char ret[8])
{
	int i, n;

	for (i=0; i<=7; i++)
	{
		n = data & (1<<i);
		n = n >> i;

		if (n==1)
			ret[7-i] = _BINARY_HIGH;
		else
			ret[7-i] = _BINARY_LOW;
	}

}


int main(int argc, char* argv[])
{
	char line[8];
	int count = 0;

	/* check parameters */
	if (argc<3) {
		printf("Usage:\n");
		printf("\t%s <input rom> <output txt>\n", argv[0]);
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
	/* read a byte from the input, convert it to text */
	/* and write it to a line on the output */
	while (!feof(input))
	{
		c = fgetc(input);
		
		if (c != EOF)	
		{
			byte2txt(c, line);
			fprintf(output, "%s%s", line, __EOL);
			count++;
		}

	}
	
	printf("%d bytes extracted.\n", count);

	/* cleaning */
	fclose(input);
	fclose(output);

	return 0;
}

