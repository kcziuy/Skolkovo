#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 0xdab0a001;
    printf("%p\n", a);
    unsigned char * ptr_a = &a;

    //������� ����� ������
    printf("%d\n", sizeof(unsigned short));
    printf("%d\n\n", sizeof(unsigned char));

    //������ ������ ��� ����, ����� �� ���� ������ ������� � ������ ����� ���������� A
    unsigned short mas[10];

    //�������
    printf("%p\n\n", *((int *) ptr_a));

    //������ ������ ������
    *(((unsigned short *) ptr_a) + 1) = 0xaa;
    printf("%p\n", *((unsigned short *)ptr_a+1));
    printf("%p\n\n", a);

    //������ ������ ������
    *((ptr_a) + 1) = 0xaa;
    printf("%p\n", *(ptr_a+1));
    printf("%p\n\n", a);

    //�������
    printf("%p\n", *((int *)ptr_a));

    return 0;
}
