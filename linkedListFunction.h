#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *next;
}Node;
//--------------------------------------------------------------------------------------------------
Node* createLList(int n){

	int d;
	printf("enter the data number 1  : ");
	scanf("%d",&d);
	Node *head=(Node*) malloc(sizeof(Node));
	if(head==NULL)
		printf("element not created try again! ");
	else{
		head->next=NULL;
		head->data=d;
		Node *temp=head;
		int i;
		for(i=2;i<=n;i++){ 
			Node *newNode= (Node*)malloc(sizeof(Node));
			printf("enter the data number %d  : ",i);
	 		scanf("%d",&d);
	 		newNode->next=NULL;
			newNode->data=d;
			temp->next=newNode;
			temp= temp->next;
		}
		
	}
	return head;
	
	
}

//--------------------------------------------------------------------------------------------------

void displayList(Node *head){
	if(head==NULL)//empty linked list
	printf("your list is empty!!");
	else if(head->next==NULL)//contains only one node
	{
		printf("data number 1 :  %d\n",head->data);	
	}
	else//contains more than one node
	{
		Node *temp=head;
		int i=1;
		while(temp!=NULL){
			printf("data number %d :   %d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
	}
}

//--------------------------------------------------------------------------------------------------

void displayLListReverse( Node *head){
	if(head!=NULL)
	{
		displayLListReverse(head->next);
		printf("%d \n",head->data);
	}
}

//--------------------------------------------------------------------------------------------------

Node* addBegin(Node *head , int d){
	Node *newNode= (Node*)malloc(sizeof(Node));
	newNode->data=d;
	if(head==NULL){//empty  linked list
		newNode->next=NULL;
		head=newNode;
		}
	else{// full linked list
		newNode->next=head;
		head=newNode;
	}		
	return head;
	
}

//--------------------------------------------------------------------------------------------------

Node* addEnd( Node *head, int d){
	Node *newNode= (Node*)malloc(sizeof(Node));
	newNode->data=d;
	newNode->next=NULL;
	if(head==NULL){// empty linked list
		head=newNode;// head=addBegin(head,d); // we call the previous function to add the new node at the beggening of an empty linked list
		}
	else{// full linked list
		Node *temp=head;
		while(temp->next!=NULL)
		{temp=temp->next;} //move te the last node
		temp->next=newNode;
		}
	return head;

}

//--------------------------------------------------------------------------------------------------

int LListLength(Node *head){
	int i;
	if(head==NULL)//empty linked list
	{	printf("your list is empty!!");
	 	i=0;
	}
	
	else if(head->next==NULL)//contains only one node
	{
		i=1;	
	}
	else//contains more than one node
	{
		Node *temp=head;
		int i=0;
		while(temp!=NULL){
			
			temp=temp->next;
			i++;
		}
	}
	return i;
}

//--------------------------------------------------------------------------------------------------

Node* addMiddle( Node *head, int d){
	Node *newNode= (Node*)malloc(sizeof(Node));
	newNode->data=d;
	if(head==NULL)//empty list
		head=addBegin(head,d);// or head=addEnd(head,d);

	if(LListLength(head)==1)
		head=addEnd(head,d);
	else
	{
		int mid=(LListLength(head)+1)/2;
		int i;
		Node *temp=head;
		for(i=1;i<=mid;i++){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}	
	 return head;
	
}

//--------------------------------------------------------------------------------------------------

Node* addPosition( Node *head, int d, int pos)
{
	
	if(pos<1||pos>LListLength(head)+1)
	printf("INVALID POSITION !!");
	if(head==NULL)//empty list
		head=addBegin(head,d);// or head=addEnd(head,d);
	if(pos==1)//insert at the first position
	    head=addBegin(head,d);
	if(pos==LListLength(head)+1)
		head=addEnd(head,d);
	else
	{	Node *newNode= (Node*)malloc(sizeof(Node));
		newNode->data=d;
		Node *temp=head;
		int i;
		for(i=1;i<=pos;i++){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
		
	}
	return head;
	
}

//--------------------------------------------------------------------------------------------------

Node* deleteBegin(Node *head){
	if(head==NULL)
	{	printf("YOUR LIST IS ALREADY EMPTY");
		return head;
	}
	else{
		Node *temp=head->next;
		free(head);
		return temp;
	}
	
}

//--------------------------------------------------------------------------------------------------

Node* deleteEnd(Node* head){
	if(head==NULL)
	{	printf("YOUR LIST IS ALREADY EMPTY");
		return head;
	}
	if(head->next==NULL)
	{	free(head);
		return NULL;
	}
	else{
		Node *avantTemp, *temp=head;
		while(temp->next!=NULL)
		{
			avantTemp->next=temp;
			temp=temp->next;
		}
		avantTemp->next=NULL;
		free(temp);
		return head;
	}
}

//--------------------------------------------------------------------------------------------------

Node* deleteMiddle(Node *head)
{
	if(head==NULL)
	{	printf("YOUR LIST IS ALREADY EMPTY");
		
	}
	else
	{	int i, mid=(LListLength(head)+1)/2;
		Node *temp=head, *avantTemp;
		for(i=1;i<=mid;i++)
		{
			avantTemp->next=temp;
			temp=temp->next;
		}
		avantTemp->next=temp->next;
		free(temp);
		
		
	}
	return head;
}

//--------------------------------------------------------------------------------------------------

Node* deletePosition(Node *head, int pos)
{
	if(pos<1||pos>LListLength(head)+1)
	printf("INVALID POSITION !!");
	if(head==NULL)//empty list
		head=deleteBegin(head);// or head=addEnd(head,d);
	if(pos==1)//insert at the first position
	    head=deleteBegin(head);
	if(pos==LListLength(head)+1)
		head=deleteEnd(head);
	else
	{	int i;
		Node *temp=head, *avantTemp;
		for(i=1;i<=pos;i++)
		{
			avantTemp->next=temp;
			temp=temp->next;
		}
		avantTemp->next=temp->next;
		free(temp);
		
		
	}
	return head;
}

//--------------------------------------------------------------------------------------------------

Node* searchNode(Node *head, int val){
	if(head==NULL)
	return NULL;
	else
	{
		bool found=false;
		Node *temp=head;
		while(temp!=NULL&&!found)
		{
			if(temp->data==val)
				found=true;
		}
		return temp;
	}
	
}


//--------------------------------------------------------------------------------------------------


int getNodePosition(Node *head, int val){
	if(head==NULL)
	return 0;
	else
	{
		bool found=false;
		Node *temp=head;
		int i=1;
		while(temp!=NULL&&!found)
		{
			if(temp->data==val)
				found=true;
			else
			i++;
		}
		return i;
	}
	
}

//--------------------------------------------------------------------------------------------------

int getNthNode(Node *head, int index){
	
	if(index>1||index>LListLength(head))
	{
		printf("INVALID INDEX!!!");
		return -1;
	}
	if(index==1)
		return head->data;
	else
	{
		int i=1; Node *temp=head;
		while(temp!=NULL&&i<=index)
		{
			temp=temp->next;
			i++;
		}
		return temp->data;
	}
	
}

//--------------------------------------------------------------------------------------------------

int* convertIntoArray(Node *head){
	int t[LListLength(head)];
	if(head==NULL)
	printf("YOUR LIST IS EMPTY!!!");
	else
	{
		int i=0;Node *temp=head;
		for(i=0;i<LListLength(head);i++)
		{
			t[i]=temp->data;
			temp=temp->next;
		}
	}
	return t;
}

//--------------------------------------------------------------------------------------------------

char* convertIntoString(Node *head){
	char t[LListLength(head)];
	if(head==NULL)
	printf("YOUR LIST IS EMPTY!!!");
	else
	{
		int i=0;Node *temp=head;
		for(i=0;i<LListLength(head);i++)
		{
			t[i]=temp->data;
			temp=temp->next;
		}
	}
	return t;
}

//--------------------------------------------------------------------------------------------------

int nbOccururs(Node *head , int val){
	int i=0; Node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==val)
			i++;
		temp=temp->next;
	}
	return i;
}

//--------------------------------------------------------------------------------------------------

Node* freeList(Node *head){
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		free(head);
		return NULL;
	}
	else
	{	Node *temp=head, *tempNext;
		while(temp->next!=NULL)
		{
			tempNext=temp->next;
			free(temp);
			temp=temp->next;
		}
		return head;
	}
}

//--------------------------------------------------------------------------------------------------

Node* merge2List(Node *head1, Node*head2){
	if(head1==NULL)//empty
		head1=head2;
	if(head1->next==NULL)//contains one node
		head1->next=head2;
	else
	{
		Node *temp=head1;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=head2;
		
	}
	return head1;
}

//--------------------------------------------------------------------------------------------------

Node* reverseLinkedList(Node *head)
{
	Node *prev=NULL, *curr=head, *next;
	if(head==NULL)
		return NULL;
	else
	{
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
		return head;
	}
}

//--------------------------------------------------------------------------------------------------

bool isPalindrome(Node *head)
{
	Node *rev=reverseLinkedList(head);
	Node *temp1=rev, *temp2=head;
	bool palindrome=true;
	while(temp1!=NULL && temp2!=NULL && palindrome)
	{
		if(temp1->data!=temp2->data)
			palindrome=false;
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return palindrome;
}

//--------------------------------------------------------------------------------------------------

Node* removeDuplicates(Node* head)
{
    /* Pointer to traverse the linked list */
    Node* current = head;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    Node* next_next;
     
    /* do nothing if the list is empty */
    if (current == NULL)
    printf("YOUR LIST IS EMPTY !!!!");
 
    /* Traverse the list till last node */
    while (current->next != NULL)
    {
    /* Compare current node with next node */
    if (current->data == current->next->data)
    {
        /* The sequence of steps is important*/       
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
    }
    else /* This is tricky: only advance if no deletion */
    {
        current = current->next;
    }
    }
    return head;
}

//--------------------------------------------------------------------------------------------------

Node* intersection2list(Node *head1, Node *head2)
{	Node *head3=NULL;
	if(head1==NULL || head2==NULL)
		printf("CHECK IF YOUR LISTS ARE NOT EMPTY !!!!");
	else{
		Node *temp1=head1, *temp2=head2;
		while(temp1!=NULL && temp2!=NULL)
		{
			if(temp1->data==temp2->data)
				head3=addEnd(head3,temp1->data);
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	return head3;
}

//--------------------------------------------------------------------------------------------------

void splitlist(Node *head, Node *firstHalf, Node *secondHalf){
	if(head==NULL)
	printf("YOUR LIST IS EMPTY !!!");
	Node *temp1=head, *temp2;
	int nb=LListLength(head);
	if(LListLength(head)%2!=0)
		nb=LListLength(head)+1;
	int mid=nb/2;
	int i;
	for(i=1;i<=mid;i++)
	{
		firstHalf=addBegin(firstHalf,temp1->data);
		temp1=temp1->next;
	}
	temp2=temp1->next;
	for(i=mid+1;i<=nb;i++)
	{
		secondHalf=addBegin(secondHalf,temp1->data);
		temp2=temp2->next;
	}
	
}
















