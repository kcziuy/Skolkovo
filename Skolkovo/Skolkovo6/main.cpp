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
//���������� ������� ���������� �����������
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

//������������� ������� ���������� �� ������� ���������
void getMes(vector<message_s*>* m){
    vector<message_s>::iterator it = real_messages.begin();
    while(it != real_messages.end()){
        m->push_back(&(*it));
        it++;
    }
}
//������� �������� ���� ���������, ����� ������� ������ ��������
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

//�������, ��������� ������ �� ��������� �� �������, � ����������� ����� ���������, ���:
//������ �������� vector<message_s> m - ������ �� ������ ������ �� ���������
//������ �������� int min_length - ����������� ����� ���������
//������ �������� message_s* mes - ��������� �� ����� ���������

void func(vector<message_s*>* m, int min_length, message_s* mes){
    deleteTooSmall(m, min_length);
    m->push_back(mes);
}

int main()
{
    //�������������
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
    //����� �������������

    //����� �������, ��������� ������ �� ��������� �� �������, � ����������� ����� ���������, ���:
    //������ �������� vector<message_s> m - ������ �� ������ ���������� �� ���������
    //������ �������� int min_length - ����������� ����� ���������
    //������ �������� message_s* mes - ����� ������ ���������
    func(&mes, mindata, &buf);


    //�����
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
    //����� ������

    return 0;
}
