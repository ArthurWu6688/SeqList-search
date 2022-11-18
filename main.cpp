#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct {
    ElemType *elem;//整形指针，申请的堆空间的起始地址存入elem
    int TableLen;//存储动态数组里面元素的个数
}SSTable;

void ST_init(SSTable &ST,int len){
    //多申请一个位置，为了存哨兵，不使用哨兵也可以，为了和王道书保持一致
    int i;
    ST.TableLen=len+1;
    ST.elem=(ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));//随机数生成，考研不需要掌握
    for(i=1;i<ST.TableLen;++i){
        ST.elem[i]=rand()%100;//为了随机生成的数都在0到99之间
    }
}

void ST_print(SSTable ST){
    for(int i=1;i<ST.TableLen;++i){
        printf("%3d",ST.elem[i]);
    }
    printf("\n");
}

int search_seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//key存在零号元素作为哨兵
    int i;
    for(i=ST.TableLen-1;ST.elem[i]!=key;--i)//从后往前找
        ;
        return i;

}

//顺序查找
int main(){
    SSTable ST;
    ElemType key;
    ST_init(ST,10);
    ST_print(ST);
    printf("请输入要搜索的key值:");
    scanf("%d",&key);
    int pos= search_seq(ST,key);
    if(pos){
        printf("找到key,pos=%d\n",pos);
    }else{
        printf("没找到\n");
    }

    return 0;
}