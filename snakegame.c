#include<stdio.h>
struct snake
{
	int x;
	int y;
	char val;
};
struct food
{
	int x;
	int y;
};
void gen_food(struct food f,char board[][20])
{
board[f.x][f.y]='x';
}
void display(char board[][20])
{
	int i,j;
	printf("**********************\n");
	for(i=0;i<20;i++)
	{printf("*");
		for(j=0;j<20;j++)
		{
			printf("%c",board[i][j]);
		}
		printf("*");
				printf("\n");
	}
	printf("**********************\n");
}
void gen_snake(struct snake s[],char board[][20],int i)
{
	//board[s[i].x][s[i].y]=' ';
		board[s[i].x][s[i].y]=s[i].val;
}
void move_snake(struct snake s[],int *x1,int *y1,int *tail)
{
	int x2,y2,asc;
	int i=0;
	while(i<=*tail)
	{
		x2=s[i].x;
		y2=s[i].y;
		s[i].x=*x1;
		s[i].y=*y1;
		*x1=x2;
		*y1=y2;
		i++;
	}
		
}
void new_snake(struct snake s[],char board[][20],int *tail)
{
	int i=0;
	while(i<=*tail)
	{
	board[s[i].x][s[i].y]=s[i].val;
	i++;
}
}
void eat_food(struct food f,struct snake s[],int *tail,char board[][20])
{
	int x1,y1;
board[f.x][f.y]=' ';
	x1=s[*tail].x;
	y1=s[*tail].y+1;
	//board[s[*tail].x][s[*tail].y]=' ';
	*tail=*tail+1;
	s[*tail].x=x1;
	s[*tail].y=y1;
	s[*tail].val='#';
	//board[x1][y1]='#';
}
food(struct food f,int *v1,int *v2)
{
	f.x=*v1;
	f.y=*v2;
}
int main()
{
	int i,c=5,v1=4,v2=3,s1=6,s2=6,a=0,b=0,t1=4;
	int *tail=&t1;
	int flag=0;
	int *x1,*y1;
    int *V1=&v1,*V2=&v2;
	x1=&a;
	y1=&b;
   int d=0,e1=1;
	char ch='A',c1='#',key,k1='a';
	char board[20][20]={' '};
	struct snake s[50]={0};
	struct food f;
	//while(c--)
	//{
	food(f,V1,V2);
	gen_food(f,board);
	//v1++;1
//}
   	s[0].x=s1;
 	s[0].y=s2;
	s[0].val=ch;
	board[s[0].x][s[0].y]=s[0].val;
	i=1;
c=5;
while(i<5)
{
s[i].x=s1;
s[i].y=s2+1;
s[i].val='#';
gen_snake(s,board,i);
i++;
s2++;
}
c=5;
i=0;
	display(board);
	while(k1!='E')
	{
		scanf("%c",&key);
		k1=key;
		//printf("t==%d",*tail);
		if(key=='l')
		{
		*x1=s[0].x;
		*y1=s[0].y;
		*y1=*y1-1;
		if(*y1<0)
		{
			*y1=19;
		}
			move_snake(s,x1,y1,tail);
			//printf("%d %d",*x1,*y1);	
			board[*x1][*y1]=' ';
			new_snake(s,board,tail);
		    display(board);
	}
	else if(key=='u')
		{
		*x1=s[0].x;
		*y1=s[0].y;
		*x1=*x1-1;
		if(*x1<0)
		{
			*x1=19;
		}
			move_snake(s,x1,y1,tail);
				board[*x1][*y1]=' ';
			new_snake(s,board,tail);
		   display(board);
	}
	else if(key=='d')
		{
			*x1=s[0].x;
		*y1=s[0].y;
		*x1=*x1+1;
			if(*x1>19)
		{
			*x1=0;
		}
			move_snake(s,x1,y1,tail);
				board[*x1][*y1]=' ';
			new_snake(s,board,tail);
		   display(board);
	}
	
	else if(key=='r')
		{
			*x1=s[0].x;
		*y1=s[0].y;
		*y1=*y1+1;
		if(*y1>19)
		{
			*y1=0;
		}
			move_snake(s,x1,y1,tail);
				board[*x1][*y1]=' ';
			new_snake(s,board,tail);
		   display(board);
	}
	else if(f.x==s[0].x&&f.y==s[0].y)
	{
		eat_food(f,s,tail,board);
		flag=1;
		board[f.x][f.y]=' ';
		}
		if(flag==1)
		{
			*V1=*V1+2;
			 *V2=*V2+2;
			 gen_food(f,board);
		}
	//printf("%d",*tail);
}
}
