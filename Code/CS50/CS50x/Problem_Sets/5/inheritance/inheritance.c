// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *newPerson = malloc(sizeof(person));
    if(newPerson == NULL)
    {
        return NULL;
    }

    char _alleles[2];

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        newPerson->parents[0] = parent0;
        newPerson->parents[1] = parent1;

        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        //parent0->alleles[2];
        //parent1->alleles[2];
        int randomIndex;

        for(int i = 0; i < 2; i++)
        {
            randomIndex = rand() % 2;
            _alleles[i] = newPerson->parents[i]->alleles[randomIndex];
            newPerson->alleles[i] = _alleles[i];
        }

    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        newPerson->parents[0] = NULL;
        newPerson->parents[1] = NULL;


        // TODO: Randomly assign alleles
        for(int i = 0; i < 2; i++)
        {
            _alleles[i] = random_allele();
            newPerson->alleles[i] = _alleles[i];
        }
    }

    // TODO: Return newly created person
    return newPerson;
}

// Free `p` and all ancestors of `p`.
//
//            GrandChild
//        Mom             Dad
// grandmom grandad  grandma grandpa

void free_family(person *p)
{
    // TODO: Handle base case
    if(p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);
    // grandchild calls mom
    // mom calls grandma
    // granda calls mom - return null
    // grandma calls dad - return null
    // mom calls grandpa
    // grandpa calls mom/dad - return null

    // granchild calls dad
    // dad calls mom
    // dad's mom (grandmama) calls parents - returns null
    // dad calls's his dad
    // dad's dad (granpapa) calls parents - returns null
    // grandpapa is freed
    // grandmama is freed
    // dad is freed
    // grandpa is freed
    // grandma is freed
    // mom is freed
    // grandchild is freed

    free_family(p->parents[1]);

    // TODO:
    // Free grand child is initial call - grandchild is root - bottom of stack
    // Second call - 2nd bottom of stack is to free the parents of the grandchild (2 calls)
    // third call - 3rd bottom of stack is to call the parent's parents - grandparents (4 calls - 2 for each parent)
    // fourth call - returns null because grandparents don't have any parents

    // Top of stack - return null
    // Finish each grandparent call by using free below the recursion - grandparents are freed (4 calls - 2 per parent)
    // Finish each parent call - recursive call has already been processed - to then use free below it to free both parents
    // Finish initial call - bottom of stack - freeing the grandhild.

    free(p);

    return;
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
