#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char* name;
	int age;
	int weight;
	int height;
};


void Person_init(struct Person* who, char* name, int age, int height, int weight)
{
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
}

struct Person* Person_create(char* name, int age, int height, int weight)
{
	struct Person* who = malloc(sizeof(struct Person));
	assert(who != NULL);

	Person_init(who, name, age, height, weight);

	return who;
}

void Person_destroy(struct Person* who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d feet, %d inches\n", who.height / 12, who.height % 12);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char const *argv[])
{
	struct Person* joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person* frank = Person_create("Frank Blank", 20, 72, 180);

	printf("Joe is at memory location %p:\n", joe);
	Person_print(*joe);

	printf("Frank is at memory location %p\n", frank);
	Person_print(*frank);

	joe->age += 20;
	joe->height -=2;
	joe->weight += 40;
	Person_print(*joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(*frank);

	Person_destroy(joe);
	Person_destroy(frank);

	printf("Allocating a Person on the stack.\n");

	struct Person jon;
	Person_init(&jon, "Jon Wingfield", 29, 76, 171);
	Person_print(jon);

	jon.age += 9;
	jon.weight -= 5;

	Person_print(jon);

	return 0;
}