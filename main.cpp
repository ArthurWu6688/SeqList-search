#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct {
    ElemType *elem;//����ָ�룬����Ķѿռ����ʼ��ַ����elem
    int TableLen;//�洢��̬��������Ԫ�صĸ���
}SSTable;

void ST_init(SSTable &ST,int len){
    //������һ��λ�ã�Ϊ�˴��ڱ�����ʹ���ڱ�Ҳ���ԣ�Ϊ�˺������鱣��һ��
    int i;
    ST.TableLen=len+1;
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));//��������ɣ����в���Ҫ����
    for(i=1;i<ST.TableLen;++i){
        ST.elem[i]=rand()%100;//Ϊ��������ɵ�������0��99֮��
    }
}

void ST_print(SSTable ST){
    for(int i=1;i<ST.TableLen;++i){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

int search_seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//key�������Ԫ����Ϊ�ڱ�
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;--i)//�Ӻ���ǰ��
        ;
        return i;

}

//˳�����
int main(){
    SSTable ST;
    ElemType key;
    ST_init(ST,10);
    ST_print(ST);
    printf("������Ҫ������keyֵ:");
    scanf("%d",&key);
    int pos= search_seq(ST,key);
    if(pos){
        printf("�ҵ�key,pos=%d\n",pos);
    }else{
        printf("û�ҵ�\n");
    }

    return 0;
}