#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
     //functions
     void displaymenu();
     void booking();
     void ticket();
     void looping();
     void Search();
     void seatsavailable();
     void display();
//structures
struct node{
	int p,q;
	char customer[15],theatr[15];
	struct node *next;
};
struct node *start=NULL,*newnode,*ptr;
struct node *read(struct node*);
void records(struct node *);
struct node1{
		int d;
	    char s[15];
	    struct node1 *next;
};
struct node1 *start2=NULL,*new1,*ptr2;
struct node1 *read1(struct node1 *);
struct theatre {
		int a[4][5];
	}t[11];
	//variables
    int k,b,c,x,i,j,selection;
    char thr[15],cust[15],mve[15],mv[15],w[15],m[15];
main()
{
		for(k=0;k<=10;k++) 
	    for(b=0;b<=3;b++) 
	    for(c=0;c<=4;c++)
	    t[k].a[b][c]=0;
		start2=read1(start2);
		display();
        displaymenu();
        while(selection!=5)
        {
                looping();
        }
        return 0;
}
        void displaymenu()
        {
        printf("\n");
        printf("\t Theater reservation\n"
                  "\t=======================\n"
                  "\t  MENU\n"
                  "\t=======================\n"
                  "\t1.BOOKING\n"
                  "\t2.RECORDS\n"
                  "\t3.SEAT\n"
                  "\t4.Search\n"
                  "\t5.EXIT\n\n");

        printf("\tEnter your selection : ");
        scanf("%d",&selection);
        looping();
        return;
        }

        //looping()
        void looping()
        {       
        switch(selection)
                {
                case 1:
                        booking();
                        break;
                case 2:
                      records(start);
                      break;
                case 3:
					  seatsavailable();
					  break;
				case 4:
					  Search();
					  break;	  
				case 5:
					  printf("Exit\n");
					  break;	       
                default:
                      printf("\tInvalid selection\n");
                      displaymenu();
                      break;
        }
        return;
        }
        //booking
        void booking()
        {
			x=100;
			ptr2=start2;
			printf("Enter theatre name to book seat\n");
			scanf("%s",thr);
			while(ptr2!=NULL)
			{
				if(!strcmpi(thr,ptr2->s)){
				x=ptr2->d;
				break;
			      }
			      ptr2=ptr2->next;
				}
				if(x==100)
				{
					printf("Theatre name is invalid\n");
					displaymenu();
					}
			printf("Enter seat no\n");
			scanf("%d %d",&i,&j);
			if(i<=3&&j<=4) {
			if(t[x].a[i][j]==0) {
				printf("Enter your name\n");
				scanf("%s",cust);
			    t[x].a[i][j]=1;
			    printf("Your seat has been booked successfully\n");
			    ticket();
			}
			else
			    printf("This seat was filled already\nchoose another seat\n");
			}
			else
			    printf("Invalid seat selection \n");
			    displaymenu();
			}
			//ticket
			void ticket()
			{
				FILE *fp;
				fp=fopen("customers.txt","a");
				fprintf(fp,"%s\t%s\t%d%d\n",cust,thr,i,j);
				printf("%s\t%s\t%d%d\n",cust,thr,i,j);
				start=read(start);
				fclose(fp);
				return;
				}
				struct node *read(struct node *start)
				{
					newnode=(struct node *)malloc(sizeof(struct node));
					if(start==NULL)
					{
						start=newnode;
						newnode->next=NULL;
						strcpy(newnode->customer,cust);
						strcpy(newnode->theatr,thr);
						newnode->p=i;
						newnode->q=j;
						}
						else
						{
							ptr=start;
							while(ptr->next!=NULL)
							ptr=ptr->next;
							ptr->next=newnode;
							newnode->next=NULL;
							strcpy(newnode->customer,cust);
						    strcpy(newnode->theatr,thr);
						    newnode->p=i;
						    newnode->q=j;
							}
							return start;
					}
					void records(struct node *start)
					{
						ptr=start;
						if(start==NULL)
						{
							printf("NO RECORDS\n");
							displaymenu();
							}
                        while(ptr!=NULL)
                         {
		                  	printf("%s\t%s\t%d%d",ptr->customer,ptr->theatr,ptr->p,ptr->q);
			                ptr=ptr->next;
			             }
			             displaymenu();
						}
			 //seatsavailability
	         void seatsavailable()
		      {
	           printf("Enter theatre name\n");
	           scanf("%s",mve);
	           ptr2=start2;
	           while(ptr2!=NULL)
	             {
			      if(!strcmpi(mve,ptr2->s))
			      {
				    for(b=0;b<=3;b++) 
				    {
						printf("\n");
	                for(c=0;c<=4;c++)
	                printf("%d\t",t[ptr2->d].a[b][c]);
				}
	                break;
			      	}
				    ptr2=ptr2->next;
			   }
			   displaymenu();
		   }				
			struct node1 *read1(struct node1 *start2) {
        	FILE *fp;
        	fp=fopen("indice.txt","r");
	        if(fp==NULL)															
	     	printf("cannot open file\n");
	     	new1=(struct node1*)malloc(sizeof(struct node1));
		    while(fscanf(fp,"%d\t%s \n",&new1->d,new1->s)!=EOF )
		    {
		      if(start2==NULL) 
	        	{
			     new1->next=NULL;
			     start2=new1;
		         ptr2=start2;
	        	}
	        	else
	         	{
		     	ptr2->next=new1;
		    	new1->next=NULL;
		     	ptr2=new1;		
		       }
		    new1=(struct node1*)malloc(sizeof(struct node1));			
	       }
	       fclose(fp);
	       return start2;	
		}
		//Search
		void Search()
        {
		  FILE *n,*f;
		  n=fopen("theatre1.txt","r");
		  f=fopen("require.txt","w");
		  printf("Enter movie name to get theatres\n");
		  scanf("%s",mv);
	      while(fscanf(n,"%s\t%s",w,m)!=EOF)
	      {
            if(!strcmpi(m,mv))
            {
             fputs(w,f);
             fputs("\n",f);
             puts(w);
             puts("\n");
            }
            else if(strstr(m,mv))
            {
              fputs(w,f);
              fputs("\n",f);
            }   
          } 
        fflush(stdin);
        fclose(n);
        fclose(f);
        displaymenu();
       }	
	   void display() 
	   {
		  FILE *n,*f;
		  n=fopen("theatre1.txt","r");
		  f=fopen("require.txt","w");
		  printf("\tTheatre          Movie\n");
		  while(fscanf(n,"%s\t%s",w,m)!=EOF)
		  {
				printf("\t%s\t%s",w,m);
				printf("\n");
				}
			}		
