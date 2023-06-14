#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}node;
int lenghOfList(node*temp);/*fait*/
node *creatNode(int val);/*fait*/
void displayLinkedList(node *temp);/*fait*/
node *addAtBegining(node *temp, int val);/*fait*/
node *addAtEnd(node *temp, int val);/*fait*/
node *addAtPosition(node *temp, int val,int pos);/*fait*/
node *deletFromBegining(node *temp);/*fait*/
node *deletFromAtEnd(node *temp);/*fait*/
node *deletFromAtPosition(node *temp,int pos);/*fait*/
/*:::::::::main::::::::::*/
int main(){
node *head;
head=creatNode(20);
head=addAtBegining(head,10);
head=addAtEnd(head,30);
head=addAtEnd(head,50);      //00;10;20;30;50;60;
head=addAtEnd(head,60);
head=addAtBegining(head,00);
displayLinkedList(head);
printf("the lenght of tis list is: %d\n",lenghOfList(head));
head=addAtPosition(head,40,5);
displayLinkedList(head);
printf("\n\n\n");
head=deletFromBegining(head);
head=deletFromAtEnd(head);
displayLinkedList(head);
printf("\n\n\n");
head=deletFromAtPosition(head,4);
displayLinkedList(head);
	return 0;
}
/*:::::::::::::creatNode function::::::::::::::::::*/
node *creatNode(int val){
	node *newNode=(node*)malloc(sizeof(node));
	if(newNode==NULL){
		printf("your node does not created\n");
	}
	else{
		newNode->data=val;
		newNode->next=NULL;
		newNode->prev=NULL;
	}
	return newNode;
}
/*:::::::::::::display function::::::::::::::::::*/
void displayLinkedList(node *temp){
	int i=1;
	if(temp==NULL){
		printf("your list is empty\n");
	}
	else if(temp->next==NULL){
		printf("your list have one data is: %d \n",temp->data);
	}
	else{
		while(temp!=NULL){
			printf("data %d= %d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
	}
}
node *addAtBegining(node *temp, int val){
	if(temp==NULL){
		temp=creatNode(val);
		return temp;
	}
	else{
		node *newNode=creatNode(val);
		newNode->data=val;
		newNode->next=temp;
		temp->prev=newNode;
		newNode->prev=NULL;
		return newNode;
	}
}
node *addAtEnd(node *temp, int val){
	node *tempr=temp;
	if(temp==NULL){
		temp=creatNode(val);
		return temp;
	}
	else{
		node *newNode=creatNode(val);
		while(temp->next!=NULL){
		temp=temp->next;
		}
		newNode->next=NULL;
		newNode->prev=temp;
		temp->next=newNode;
		return tempr;
	}
}
int lenghOfList(node *temp){
	int i=0;
	if(temp==NULL){
		printf("the list is empty\n");
		return 0;
	}
	else{
		while(temp!=NULL){
			i++;
			temp=temp->next;
		}
		return i;
	}
}
node *addAtPosition(node *temp, int val,int pos){
int lenght=lenghOfList(temp),i=1;
node *tempr=temp;
if(pos>lenght){
	printf("the position does not valide\n");
	return 0;
}
else{
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	node *newNode=creatNode(val);
	newNode->next=temp->next;
	temp->next=newNode;
	newNode->prev=temp;
	return tempr;
}
}
node *deletFromBegining(node *temp){
	if(temp==NULL){
       printf("your list is empty\n"); 
	   return 0;     
	}
	else if(temp->next==NULL){
		free(temp);
		printf("now your list is empty\n");
	    return 0;
	}
	else{
        temp=temp->next;
        free(temp->prev);
		return temp;
	}
}
node *deletFromAtEnd(node *temp){
		node *tempr=temp;
	if(temp==NULL){
		printf("your list is empty\n");
		return temp;
	}
	else{
		while(temp->next->next!=NULL){
		temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
		return tempr;
	}
}
node *deletFromAtPosition(node *temp,int pos){
	
int lenght=lenghOfList(temp),i=1;
node *tempr=temp;
node *ptr;
if(pos>lenght){
	printf("the position does not valide\n");
	return 0;
}
else if(pos==lenght){
	temp=deletFromAtEnd(temp);
}
else if(pos==1){
	temp=deletFromBegining(temp);
}
else{
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
    ptr=temp;
    temp=temp->next;
    ptr->next=temp->next;
    temp=temp->next;
    temp->prev=ptr;
    
	return tempr;
}
}	
