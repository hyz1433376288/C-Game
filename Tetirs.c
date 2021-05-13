#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define H 24+2+2
#define W 20+2+2
#define h 4 ///������ӦH�ı��
#define FR 350///ˢ��Ƶ��

int map[H][W];
int brick_flag;///��ľ
int brick_next;
int brick_cur;
int brick_num;
int *vanish_row;
int score;
int x[4],y[4];///��Ż�ľ���ĸ����������
void map_print();
void HideCursor(){//���ع��

    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
void gotoxy(int x,int y){//��궨λ����
	COORD p;//����ṹ�����p
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ�������
	p.X=x;p.Y=y;//������Ŀ���ƶ�λ�ô��ݸ��ṹ��
	SetConsoleCursorPosition(handle,p);//�ƶ����
}
void profile(){///���
int i,j;
system("color 04");
gotoxy(14,6);
     printf("Tetris");
     Sleep(2000);
      char announcement[]={"--Houyz Products"};
      for(i=0;i<17;i++)
      {
          gotoxy(16,8);
          for(j=0;j<=i;j++)
          {
              printf("%c",announcement[j]);
          }
          Sleep(200);
      }
      Sleep(2500);
    }
void space2(int n){//����ո�
while(n--) printf("  ");
}
void cube(int n){//�������
while(n--)printf("��");
}
int check_fill(){///�������
    int i,j,k=0;
    vanish_row=(int*)calloc(18,sizeof(int));
    for(i=H-2;i>=1;i--)
    {
        for(j=2;j<=W-4;j++,j++)
        if(map[i][j]!=2) break;///�����һ����������˿�ȱ����ôֱ�Ӳ鿴��һ��
        if(j==22) ///����û�г��ֿ�ȱ�����
        vanish_row[k]=i,k++;
    }
    score+=k;
    return k;
}
int check_top(){///��鶥�˳���
    int j;
    for(j=2;j<W;j++,j++) if(map[2][j]==2){ system("color 04"); map_print();gotoxy(13,29+h);printf("GAME OVER"); return 1;}
    return 0;
}
void brick_creat(){///���������ľ

    brick_flag=1;
    brick_num++;
    brick_cur=brick_next;
   switch(brick_cur){///��x[0]y[0]��,x[1]y[1]�ϣ�x[2]y[2]�£�x[3]y[3]��

   case 1:///һ
       x[0]=2,x[1]=2,x[2]=2,x[3]=2;
       y[0]=10,y[1]=8,y[2]=12,y[3]=14;
       break;
   case 2:///��
       x[0]=3,x[1]=2,x[2]=2,x[3]=3;
       y[0]=10,y[1]=12,y[2]=10,y[3]=12;
       break;
   case 3:///T
        x[0]=3,x[1]=2,x[2]=3,x[3]=3;
       y[0]=10,y[1]=10,y[2]=8,y[3]=12;
        break;
   case 4:///N
         x[0]=3,x[1]=3,x[2]=2,x[3]=4;
       y[0]=10,y[1]=12,y[2]=12,y[3]=10;
       break;
   case 5:///L
         x[0]=3,x[1]=4,x[2]=4,x[3]=2;
       y[0]=10,y[1]=10,y[2]=12,y[3]=10;
       break;
   case 6:///��N
        x[0]=3,x[1]=3,x[2]=2,x[3]=4;
       y[0]=10,y[1]=8,y[2]=8,y[3]=10;
        break;
   case 7:///��L
       x[0]=3,x[1]=4,x[2]=4,x[3]=2;
       y[0]=10,y[1]=10,y[2]=8,y[3]=10;
    break;
   }
   brick_next=1+rand()%7;
   system("cls");

       int i;
   for(i=0;i<4;i++) map[x[i]][y[i]]=1;
}
int rigid_body_TOUCH(){///����Ӵ�ģ��,������½����
    int distance;
    int landing_distance=20;///��½����
    int i,j;
    for(i=0;i<4;i++)
    {
        distance=1;
        while(map[x[i]+distance][y[i]]!=2)
        {
            distance++;
        }
        if(distance<landing_distance) landing_distance=distance;
    }
    return landing_distance;

}
void map_print(){///��ӡ
    int i,j;
gotoxy(0,1);
//system("cls");
        for(i=0;i<H-1;i++){
            space2(4);
            for(j=0;j<W;j++,j++)
         //printf("%2d",map[i][j]); printf("\n");}
            if(map[i][j]==-1) printf("--");
            else if(map[i][j]==-2) printf("||");
            else if(map[i][j]==0) printf("  ");
            else if(map[i][j]==2) printf("��");
            else if(map[i][j]==1) printf("��");
            printf("\n");}
            space2(4);
            for(j=0;j<W;j++,j++) printf("--");
            gotoxy(8,25+h); printf("SOCRE : %d | NUM : %d",score*10,brick_num);
            gotoxy(8,26+h); printf("THE  NEXT : ");
            gotoxy(20,26+h);
    if(brick_next==1) cube(4);
    else if(brick_next==2) {cube(2); gotoxy(20,27+h);cube(2);}
    else if(brick_next==3){space2(1);cube(1);gotoxy(20,27+h);cube(3);}
    else if(brick_next==4){space2(2);cube(1);gotoxy(22,27+h);cube(2);gotoxy(22,28+h);cube(1);}
    else if(brick_next==5){cube(1);gotoxy(20,27+h);cube(1);gotoxy(20,28+h);cube(2);}
    else if(brick_next==6){cube(1);gotoxy(20,27+h);cube(2);gotoxy(22,28+h);cube(1);}
    else if(brick_next==7){space2(1);cube(1);gotoxy(22,27+h);cube(1);gotoxy(20,28+h);cube(2);}

}
void brick_turn(){///��ľ��ת
    int i,j,k=1;
    int x1[8],y1[8];
    for(i=-1;i<=1;i++)
        for(j=-2;j<=2;j++,j++)
        if(map[x[0]+i][y[0]+j]==2||map[x[0]+i][y[0]+j]==-2)
            return;
        else if(i==0&&j==0) continue;
        else if(map[x[0]+i][y[0]+j]==1) {map[x[0]+i][y[0]+j]=0;x1[k]=i;y1[k]=j;k++;}
    for(i=1;i<k;i++)
       {
           if(x1[i]==-1)
           {
               if(y1[i]==-2)  x[i]=x[0]-1,y[i]=y[0]+2;
                else if(y1[i]==0) x[i]=x[0],y[i]=y[0]+2;
                else x[i]=x[0]+1,y[i]=y[0]+2;
           }
           else if(x1[i]==0)
           {
                if(y1[i]==-2) x[i]=x[0]-1,y[i]=y[0];
                else x[i]=x[0]+1,y[i]=y[0];
           }
           else
           {
                if(y1[i]==-2)x[i]=x[0]-1,y[i]=y[0]-2;
                else if(y1[i]==0) x[i]=x[0],y[i]=y[0]-2;
                else x[i]=x[0]+1,y[i]=y[0]-2;
           }
        map[x[i]][y[i]]=1;}
    return;



}
int case1_turn(){///������ת
    int i,j;
    for(i=x[0]-1;i<=x[0]+2;i++)
        for(j=y[0]-2;j<=y[0]+4;j++,j++)
        if(map[i][j]==-2||map[i][j]==2) return 0;///������ת

    map[x[3]][y[3]]=0;
     if(y[3]==y[0]+4) y[3]=y[0],x[3]=x[0]+2;
     else y[3]=y[0]+4,x[3]=x[0];


}
int main()
{
    system("mode con cols=42 lines=35");
    system("title Tetris");

    int i,j;
    profile();
    ///map��ʼ��
    for(i=0;i<H;i++){
            for(j=0;j<W;j++)
            if(i==0) map[i][j]=-1;
            else if(j==0||j>=W-2) map[i][j]=-2;
            else map[i][j]=0;
    }
    for(j=2;j<W-2;j++,j++) map[H-1][j]=2;///��ʼ���ػ�2

    brick_flag=0;
    brick_num=0;
    srand(time(NULL));
     HideCursor();
    score=0;
    brick_next=1+rand()%7;
     system("color 06");

    while(1)
    {

        ///����Ļ�ľ
      if(brick_flag==0) brick_creat();

       ///����
       if(kbhit())
       {
           int k;
           int dis=rigid_body_TOUCH();
           char input;
           input=getch();
           if(input=='a'/**���Ʒ���ġ�a'��d'����ҪԼ���߽��Լ����ģ**/
              &&y[0]>3&&y[1]>3&&y[2]>3&&y[3]>3
              &&map[x[0]][y[0]-2]!=2&&map[x[1]][y[1]-2]!=2
              &&map[x[2]][y[2]-2]!=2&&map[x[3]][y[3]-2]!=2) for(k=0;k<4;k++) {map[x[k]][y[k]]=0;y[k]-=2;map[x[k]][y[k]]=1;}
          else  if(input=='d'
                   &&y[0]<W-4&&y[1]<W-4&&y[2]<W-4&&y[3]<W-4
                   &&map[x[0]][y[0]+2]!=2&&map[x[1]][y[1]+2]!=2
                   &&map[x[2]][y[2]+2]!=2&&map[x[3]][y[3]+2]!=2)  for(k=0;k<4;k++){map[x[k]][y[k]]=0;y[k]+=2;map[x[k]][y[k]]=1;}
          else  if(input=='s'&&dis>1){for(i=0;i<4;i++) map[x[i]][y[i]]=0;for(i=0;i<4;i++){x[i]++;map[x[i]][y[i]]=1;}}
          else  if(input=='w'&&brick_cur!=2) ///��  ���Ե�
                    {
                        if(brick_cur==1)
                        {
                            if(case1_turn()!=0)///����ǡ�һ��
                            brick_turn();
                            }
                        else brick_turn();///����
                    }
         else if(input==' ') {for(i=0;i<4;i++) map[x[i]][y[i]]=0;
                                for(i=0;i<4;i++) x[i]+=(dis-1),map[x[i]][y[i]]=1; }
       }

        ///��ľ����
        int dis=rigid_body_TOUCH();
        if(dis>1){
        for(i=0;i<4;i++) map[x[i]][y[i]]=0;
        for(i=0;i<4;i++){x[i]++;map[x[i]][y[i]]=1;}
        }
        else {brick_flag=0;for(i=0;i<4;i++) map[x[i]][y[i]]=2;}//���ײ���

        ///�鿴�Ƿ�Խ��
        if(check_top()==1) break;
         ///��ӡmap��
         map_print();

        ///�鿴�Ƿ���������
       if(check_fill()>0) {//��
            int k=0;
            while(vanish_row[k]){
                for(j=2;j<W-2;j++,j++)
                    map[vanish_row[k]][j]=1;
                    k++;
            }
            ///��ʧʱ������˸Ч��
            map_print();
            for(k=0;vanish_row[k]>0;k++)
                    for(j=2;j<W-2;j++,j++)
                    map[vanish_row[k]][j]=0;
                ///�²���ʧ���ϲ����(�ѵ�)
            for(k=0;vanish_row[k]>0;k++){
                    if(vanish_row[k+1]==vanish_row[k]-1)
                        continue;//�����ʧ����������ô����߲�
               for(i=H-1;i>=1;i--)
               {
                   if(i<vanish_row[k])
                   for(j=2;j<W-2;j++,j++)
                    if(map[i][j]==2) map[i][j]=3;///��3���м�ֵ(����������)
               }
               for(i=H-1;i>=1;i--)//���������滻�����ӵײ���ʼ
               {
                   if(i<vanish_row[k])
                   for(j=2;j<W-2;j++,j++)
                    if(map[i][j]==3) map[i+k+1][j]=2;
               }
                for(i=1;i<H-1;i++)
               {
                   for(j=2;j<W-2;j++,j++)
                    if(map[i][j]==3) map[i][j]=0;///��ԭ
               }
            }
            Sleep(200);
            map_print();

            free(vanish_row);
       }
        Sleep(FR);
    }
}





