#include <stdio.h>
#include <stdlib.h>

// Structure for a term in a polynomial
struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

// Function to create a new term node
struct Term *createTerm(int coeff, int exp)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial (at the end)
void insertTerm(struct Term **polynomial, int coeff, int exp)
{
    struct Term *newTerm = createTerm(coeff, exp);
    if (*polynomial == NULL)
    {
        *polynomial = newTerm;
    }
    else
    {
        struct Term *temp = *polynomial;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term *polynomial)
{
    if (polynomial == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    while (polynomial != NULL)
    {
        printf("%dx^%d", polynomial->coefficient, polynomial->exponent);
        if (polynomial->next != NULL)
        {
            if (polynomial->next->coefficient >= 0)
            {
                printf(" + ");
            }
        }
        polynomial = polynomial->next;
    }
    printf("\n");
}

int main()
{
    // Create an empty polynomial
    struct Term *polynomial = NULL;

    // Insert terms into the polynomial
    insertTerm(&polynomial, 7, 6);
    insertTerm(&polynomial, 5, 3);
    insertTerm(&polynomial, -2, 1);
    insertTerm(&polynomial, 10, 0);

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
