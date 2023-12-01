/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100*/

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	int reversed;

	i = 0;
	reversed = 0;
	while (i < 8)
	{
		reversed = (reversed << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reversed);
}
#include <stdio.h>

int     main(void)
{
    unsigned char   octet = 0x41;
    unsigned char   reverse = reverse_bits(octet);

    printf("octet inverse : 0x%x\n", reverse);
    return(0);
}