#include <stdio.h>
#include <math.h>

float pila[8];

void showPila(void)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("%d: %f \n", 8 - i, pila[i]);
    }
}

void insertNumber(int number){
    int i = 8;
    for (i = 8; i>0; i--){
        if(pila[i-1] == 0){
            pila[i-1] = number;
            break;
        }
        else if(pila[0] != 0){
            printf("No hay espacio en la calculadora\n");
            break;
        }
    }
}

void deletePila(){
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        pila[i] = 0.0;
    }
}
void deleteLast(){
    int i = 0;
    for (i = 0; i<8; i++){
        if(pila[i] != 0){
            pila[i] = 0.0;
            break;
        }
        else if(pila[7] == 0){
            printf("Ya la pila esta vacía\n");
            break;
        }
    }
}

int main()
{
    int opc = 0;
    int num = 0;
    while (opc != 5)
    {
        showPila();
        printf("\nBienvenid@ a la calculadora RPN, Ingresa alguna de las opciones:\n");
        printf("Ingresar un número: 1, Realizar Operación: 2, Borrar Último: 3, Borrar todo: 4, Salir: 5\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
        printf("Ingresa el número:  ");
        scanf("%d",&num);
            insertNumber(num);
            break;

        case 2:
            /* code */
            break;

        case 3:
            deleteLast();
            break;

        case 4:
            deletePila();
            break;

        case 5:
            printf("Gracias por usar la calculadora :D\n");
            break;

        default:
            printf("Porfavor Ingresa una opción válida\n");
            break;
        }
    }
    return 0;
}