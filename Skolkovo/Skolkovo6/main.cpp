#define MAX_RAW_DATA 48

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct message_s {
    unsigned char raw_data[MAX_RAW_DATA];
    unsigned int raw_data_length;
};

vector<message_s> real_messages;
//«јѕќЋЌ≈Ќ»≈ массива случайными сообщени€ми
void pushRand(int c){
    printf("CREATING RANDOM VECTOR:\n");
    printf("\n------------------------------------------------------------------------------\n\n");
    for(int j = 0; j<c; j++){
        printf("%d.\t",j+1);
        struct message_s buf;

        buf.raw_data_length = 1 + rand()%MAX_RAW_DATA;
        printf("%d\t", buf.raw_data_length);

        for(unsigned int i = 0; i < buf.raw_data_length; i++){
            buf.raw_data[i] = rand()&0xff;
            printf("%d'", buf.raw_data[i]);
        }
        printf("\n");

        real_messages.push_back(buf);
    }
    printf("\n\nDONE!\n");
    printf("\n------------------------------------------------------------------------------\n\n");
}

//»Ќ»÷»јЋ»«ј÷»я вектора указателей из вектора сообщений
void getMes(vector<message_s*>* m){
    vector<message_s>::iterator it = real_messages.begin();
    while(it != real_messages.end()){
        m->push_back(&(*it));
        it++;
    }
}
//‘”Ќ ÷»я удалени€ всех сообщений, длина которых меньше заданной
void deleteTooSmall(vector<message_s*>* m, int min_data){

    vector<message_s*>::iterator it = m->begin();
    while(it != m->end()){
        if((*it)->raw_data_length < min_data){
            it = m->erase(it);
            it--;
        }
        it++;
    }
}

//‘”Ќ ÷»я, удал€юща€ ссылки на сообщени€ из вектора, и добавл€ющее новое сообщение, где:
//первый аргумент vector<message_s> m - ссылка на вектор ссылок на сообщени€
//второй аргумент int min_length - минимальна€ длина сообщени€
//третий аргумент message_s* mes - указатель на новое сообщение

void func(vector<message_s*>* m, int min_length, message_s* mes){
    deleteTooSmall(m, min_length);
    m->push_back(mes);
}

int main()
{
    //»Ќ»÷»јЋ»«ј÷»я
    vector<message_s*> mes;

    pushRand(1000);

    getMes(&mes);

    unsigned char* inp =(unsigned char*) malloc(sizeof(unsigned char)*MAX_RAW_DATA);
    int mindata;

    scanf("%d", &mindata);

    printf("CREATING RANDOM MESSAGE:\n");
    printf("\n------------------------------------------------------------------------------\n\n");

        struct message_s buf;

        buf.raw_data_length = rand()%MAX_RAW_DATA;
        printf("%d\t", buf.raw_data_length);

        for(unsigned int i = 0; i < buf.raw_data_length; i++){
            buf.raw_data[i] = rand()&0xff;
            printf("%d'", buf.raw_data[i]);
        }
        printf("\n");

    printf("\n------------------------------------------------------------------------------\n\n");
    // ќЌ≈÷ »Ќ»÷»јЋ»«ј÷»»

    //¬џ«ќ¬ ‘”Ќ ÷»», удал€ющей ссылки на сообщени€ из вектора, и добавл€ющей новое сообщение, где:
    //первый аргумент vector<message_s> m - ссылка на вектор указателей на сообщени€
    //второй аргумент int min_length - минимальна€ длина сообщени€
    //третий аргумент message_s* mes - адрес нового сообщени€
    func(&mes, mindata, &buf);


    //¬џ¬ќƒ
    printf("NEW DATA:\n");
    printf("\n------------------------------------------------------------------------------\n\n");

    vector<message_s*>::iterator it = mes.begin();
    int c = 0;
    while(it != mes.end()){
        printf("%d\t%d\t", c, (*it)->raw_data_length);
        for(int i = 0; i<(*it)->raw_data_length; i++){
            printf("%d'", (*it)->raw_data[i]);
        }
        printf("\n");
        it++;
        c++;
    }
    // ќЌ≈÷ ¬џ¬ќƒј

    return 0;
}
