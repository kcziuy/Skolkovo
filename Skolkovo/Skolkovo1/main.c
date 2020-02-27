#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 0xdab0a001;
    printf("%p\n", a);
    unsigned char * ptr_a = &a;

    //Размеры типов данных
    printf("%d\n", sizeof(unsigned short));
    printf("%d\n\n", sizeof(unsigned char));

    //Массив создан для того, чтобы не было ошибки доступа у памяти после переменной A
    unsigned short mas[10];

    //овервью
    printf("%p\n\n", *((int *) ptr_a));

    //Первая строка задачи
    *(((unsigned short *) ptr_a) + 1) = 0xaa;
    printf("%p\n", *((unsigned short *)ptr_a+1));
    printf("%p\n\n", a);

    //Вторая строка задачи
    *((ptr_a) + 1) = 0xaa;
    printf("%p\n", *(ptr_a+1));
    printf("%p\n\n", a);

    //Овервью
    printf("%p\n", *((int *)ptr_a));

    return 0;
}
