#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct song
{
	int sid;
	struct song *next;
	struct song *prev;
};
struct PL
{
	int pid;
	struct song *head;
	struct song *tail;
	struct song *active;
	int mode;
	int no_ofsongs;
};
struct song *S=NULL;
void create_playlist(struct PL P_list)
{
	P_list.pid=1;
	P_list.head=NULL;	
	P_list.tail=NULL;
	P_list.active=NULL;
	P_list.mode=1;
	P_list.no_ofsongs=0;
}
void Add_song(struct song *S,struct PL *P_list,int val)
{
	struct song *ptr,*trav;
	ptr=(struct song*)malloc(sizeof(struct song));
	ptr->sid=val;
	ptr->next=NULL;
	ptr->prev=NULL;
	if(P_list->no_ofsongs==0)
	{
		    P_list->head=ptr;
			P_list->tail=ptr;
			P_list->no_ofsongs=P_list->no_ofsongs+1;
				//S=P_list->head;
	}
	else
	{ 
    P_list->tail->next=ptr;
    ptr->next=NULL;
    ptr->prev=P_list->tail;
    P_list->tail=ptr;
    P_list->no_ofsongs+=1;
	}
	//*S=P.head->next;
	S=P_list->head;
}
void del_song(struct song *S,struct PL *P_list,int val)
{
	struct song *ptr=P_list->head;
	if(val==1)
	{
	P_list->head=P_list->head->next;	
	}
	else
	{
	while(ptr->sid!=val)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=ptr->next;
	P_list->no_ofsongs=P_list->no_ofsongs-1;
}
S=P_list->head;
}
void set_mode(struct PL *P_list,int m)
{
	P_list->mode=m;
}
void play_mode(struct song *S,struct PL *P_list,int val)
{
	struct song *ptr=P_list->head;
	if(P_list->mode==1)
	{
		while(ptr->sid!=val)
		{
			ptr=ptr->next;
		}
P_list->head=ptr;
P_list->tail=ptr;
ptr->next=NULL;
S=P_list->head;
	}
/*	else if(P_list->mode==2)
	{
		
	}
	/*else if(P_list->mode==2)
	{
		
	}*/
}
void play_playlist(struct song *S,struct PL P_list)
{
	S=P_list.head;
			while(S!=NULL)
		{
			printf("%d",S->sid);
			S=S->next;
	}
	
}
int main()
{
	struct PL P_list;
	create_playlist(P_list);
	Add_song(S,&P_list,1);
	Add_song(S,&P_list,2);
	Add_song(S,&P_list,3);
	Add_song(S,&P_list,4);
	Add_song(S,&P_list,5);
	Add_song(S,&P_list,6);
	//del_song(S,&P_list,4);
	//del_song(S,&P_list,3);
	//del_song(S,&P_list,1);
	set_mode(&P_list,1);
	play_mode(S,&P_list,4);
    //printf("%d ",P_list.no_ofsongs);
	//S=P_list.head;
	play_playlist(S,P_list);
	play_playlist(S,P_list);
}
