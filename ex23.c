#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dbg.h"

int normal_copy(char* from, char* to, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		*to++ = *from++;
	}

	return i;
}

int _32_bit_copy(char* from, char* to, int count) {
	int i;

	for (i = 0; i < count / sizeof(long); ++i)
	{
		((long*)to)[i] = ((long*)from)[i];
	}

	for (i = (count - count % sizeof(long)); i < count; i++) {
		to[i] = from[i];
	}

	return i;
}

#define COUNT (100002+15) / 16
#define MOD  100002 % 16

int unrolled_copy(char* from, char* to, int count) {
	{
		int cnt = COUNT, i = 0;

		switch (MOD) {
			case 0: do {
					*to++ = *from++;
					case 15: *to++ = *from++;
					case 14: *to++ = *from++;
					case 13: *to++ = *from++;
					case 12: *to++ = *from++;
					case 11: *to++ = *from++;
					case 10: *to++ = *from++;
					case 9: *to++ = *from++;
					case 8: *to++ = *from++; 
					case 7: *to++ = *from++;
					case 6: *to++ = *from++;
					case 5: *to++ = *from++;
					case 4: *to++ = *from++;
					case 3: *to++ = *from++;
					case 2: *to++ = *from++;
					case 1: *to++ = *from++; 
				} while (++i < COUNT);
			}
		
	}

	return 0;
}

int valid_copy(char* data, int count, char expects)
{
	for (int i = 0; i < count; ++i)
	{
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}

	return 1;
}

#define clock_it(MSG, CMD)  \
	begin = clock(); \
	for (int i = 0; i < 10000; ++i) { CMD } \
	end = clock(); \
	printf(MSG " took %d ticks\n", end - begin );

#define SIZE 100002

int main(int argc, char const *argv[])
{
	time_t begin, end;

	char from[SIZE] = {'a'};
	char to[SIZE] = {'c'};
	int rc = 0;

	memset(from, 'x', SIZE);
	memset(to, 'y', SIZE);
	check(valid_copy(to, SIZE, 'y'), "Not initialized right");

	clock_it("Normal copy", rc = normal_copy(from, to, SIZE););

	check(rc == SIZE, "Normal copy failed: %d", rc);
	check(valid_copy(to, SIZE, 'x'), "Normal copy failed");

	memset(to, 'y', SIZE);

	clock_it("32 bit copy", rc = _32_bit_copy(from, to, SIZE););
	check(valid_copy(to, SIZE, 'x'), "32 bit copy failed");

	memset(to, 'y', SIZE);

	clock_it("unrolled_copy", unrolled_copy(from, to, SIZE););
	check(valid_copy(to, SIZE, 'x'), "unrolled copy failed");

	return 0;
error:
	return 1;
}