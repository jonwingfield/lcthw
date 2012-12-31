#include <stdio.h>

int main(int argc, char** argv)
{
// 	int age = 10
// ;	int height = 20;
// 	char name[] = "Jon";
// 	char initial = 'P';
//     char full_name[] = {
//         'Z', 'e', 'd',
//          ' ', 'A', '.', ' ',
//          'S', 'h', 'a', 'w'
//     };

// 	printf("%d\n", sizeof(int));
// 	printf("I am %d years old\n", height);
// 	printf("%s\n", full_name);

	char item = argv[1][0];

	switch (item)
	{
		case 'a':
			printf("Its an a!\n");
			break;

		case 'c':
			printf("Its a c!\n");
			break;

		case 'g':
			printf("It's an f!!\n");
			break;

		case 'm':
			printf("Tis a d!\n");
			break;

		case 'p':
			printf("Tis a d!\n");
			break;

		case 'z':
			printf("Tis a d!\n");
			break;

		default:
			printf("huh?\n");
			break;
	}

	return 0;
}
