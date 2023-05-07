#include<stdio.h>
 #include<stdlib.h>
 #include <unistd.h>
 #include<cstdlib>
 #include<string.h>
 #define MAX 50       //  停车场最大容量为3辆，便于观察
 #define price 0.05
 
#include "abc.h"
 void InitStack(SeqStackCar *s){   // 栈的初始化
int i;
s->top=0;
for(i=0;i<=MAX;i++)
s->stack[s->top]=NULL; }
int InitQueue(LinkQueueCar *Q){     // 队列的初始化
Q->head=(QueueNode *)malloc(sizeof(QueueNode));
    if(Q->head!=NULL)
    {
        Q->head->next=NULL;
        Q->rear=Q->head;
        return(1);
    }
    else return(-1);
    }
    void PRINT(CarNode *p,int room){     // 车辆收费
 
 int A1,A2,B1,B2;
 printf("\n车辆离开的时间:");
scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
 printf("\n离开车辆的车牌号为:");
 puts(p->num);
 printf("\n其到达时间为: %d:%d",p->reach.hour,p->reach.min);
 printf("\n离开时间为: %d:%d",p->leave.hour,p->leave.min);
 A1=p->reach.hour;
 A2=p->reach.min;
 B1=p->leave.hour;
 B2=p->leave.min;
 printf("\n应交费用为: %2.1f元",((B1-A1)*60+(B2-A2))*price);
      free(p); }       // 车辆的到达登记
 int Arrival(SeqStackCar *Enter,LinkQueueCar *W){
        CarNode *p;
        QueueNode *t;
        p=(CarNode *)malloc(sizeof(CarNode));
       // flushall();
        printf("\n请输入车牌号(例:豫B1234):\n");
         scanf("%s",p->num);
 
          if(Enter->top<MAX)
            {
            Enter->top++;
          printf("\n车辆在车场第%d位置.",Enter->top);
          printf("\n车辆到达时间:");
          scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
          Enter->stack[Enter->top]=p;
            return(1);
             }
              else
        {
             printf("\n该车须在便道等待!有车位时进入车场");
                 t=(QueueNode *)malloc(sizeof(QueueNode));
                   t->data=p;
                     t->next=NULL;
                       W->rear->next=t;
                         W->rear=t;
                         return(1);
                         }
                          }
void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)
{
    //车辆的离开
int room;
 CarNode *p,*t;
  QueueNode *q;
   if(Enter->top>0)         //  判断车场是否为空
   {
        while(1)
        {
        prin
