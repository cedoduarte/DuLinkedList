#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DuLinkedList.h"

typedef struct Persona Persona;

struct Persona
{
    char nombre[255];
    int edad;
    float salario;
};

Persona *personaNueva(char nombre[], int edad, float salario)
{
    Persona *persona = (Persona *) malloc(sizeof(Persona));
    strcpy(persona->nombre, nombre);
    persona->edad = edad;
    persona->salario = salario;
    return persona;
}

void personaImprime(Persona *persona)
{
    printf("%s, %d, %g\n", persona->nombre, persona->edad, persona->salario);
}

void imprime(DuNode *persona, void *ptr)
{
    personaImprime(DuData(persona));
    (void) ptr;
}

void libera(DuNode *persona, void *ptr)
{
    free(DuData(persona));
    (void) ptr;
}

int main(void)
{
    DuLinkedList *empleados = DuLinkedListNew();
    DuLinkedListAppend(empleados, personaNueva("Pedro", 18, 3000.0));
    DuLinkedListAppend(empleados, personaNueva("Juan", 19, 5000.0));
    DuLinkedListAppend(empleados, personaNueva("Luis", 20, 2300.0));
    DuForEach(DuBegin(empleados), NULL, imprime, NULL);
    DuForEach(DuBegin(empleados), NULL, libera, NULL);
    DuLinkedListFree(empleados);
    return 0;
}
