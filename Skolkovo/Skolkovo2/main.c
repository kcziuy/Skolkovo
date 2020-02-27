#include <stdio.h>
#include <stdlib.h>


char * getErrorStr(int err_code) {
		char * result = "unknown";
		switch(err_code) {
			case 1:
				result="bad data";
				break;
			// …
		}
		return result;
	}


int main()
{
    //Нет ошибок, т.к. автоматически выделяется память под "unknown"
    printf(getErrorStr(-1));
    printf("\n");
    printf(getErrorStr(0));
    printf("\n");

    //Может быть ошибка доступа к памяти, т.к. sizeof("unknown") < sizeof("bad data")
    printf(getErrorStr(1));
    printf("\n");
    return 0;
}
