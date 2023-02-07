#include <stdio.h>
#include <math.h>

#define PI 3.1415926;

float pila[8];

void showPila(void)
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        printf("%d: %f \n", 8 - i, pila[i]);
    }
}

void moveUp()
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        pila[i] = pila[i + 1];
    }
}

void insertNumber(int number)
{
    if (pila[0] == 0)
    {
        moveUp();
        pila[7] = number;
    }
    else
    {
        printf("La calculadora esta llena!\n");
    }
}

void deletePila()
{
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        pila[i] = 0.0;
    }
}

void moveDown()
{
    int i = 7;
    for (i = 7; i >= 0; i--)
    {
        pila[i] = pila[i - 1];
    }
}

void deleteLast()
{
    pila[7] = 0.0;
    moveDown();
}

void menuOp()
{
    char temp;
    printf("Ingresa que operación deseas realizar: \n +,-,/,*,r(raiz cuadrada),s(seno),c(coseno),t(tangente),p(potencia)\n");
    scanf(" %c", &temp);
    float aux = pila[7] * PI;
    switch (temp)
    {
    case '+':
        pila[6] = pila[7] + pila[6];
        deleteLast();
        break;

    case '-':
        pila[6] = pila[6] - pila[7];
        deleteLast();
        break;

    case '/':
        pila[6] = pila[6] / pila[7];
        deleteLast();
        break;

    case '*':
        pila[6] = pila[6] * pila[7];
        deleteLast();
        break;

    case 'r':
        pila[7] = sqrt(pila[7]);
        break;

    case 's':
        pila[7] = sin((aux/180));
        break;

    case 'c':
        pila[7] = cos((aux/180));
        break;

    case 't':
        if(remainder(pila[7],90) != 0 || remainder(pila[7],180) == 0){
        pila[7] = tan((aux/180));
        break;
        }
        else{
            printf("MATH.ERROR\n");
        }
        break;

    case 'p':
        pila[6] = pow(pila[6],pila[7]);
        deleteLast();
        break;

    default:
        break;
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
            scanf("%d", &num);
            insertNumber(num);
            break;

        case 2:
            menuOp();
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