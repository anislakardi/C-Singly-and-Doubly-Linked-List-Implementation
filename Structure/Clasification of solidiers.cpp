#include<stdio.h>
typedef struct emploe{
	char nom[20];
	char prenom[20];
	int  grade;
	float salaire;	
} emp ;
int main(){
	emp t[3];
	int i=0;
	for(i=0;i<3;i++){
for(i=0;i<3;i++){
		printf("Enter nom de l'employe number %d: ",i+1);
		scanf("%s",&t[i].nom);
		printf("Enter prenom de l'employe number %d: ",i+1);
		scanf("%s",&t[i].prenom);
		printf("Enter grade de l'employe number %d: ",i+1);
		scanf("%d",&t[i].grade);
		printf("Enter salaire de l'employe number %d: ",i+1);
		scanf("%f",&t[i].salaire);
		if(t[i].grade>=3){
		t[i].salaire=t[i].salaire+(t[i].salaire/10);
		}
	}
		if(t[i].grade>=3){
		t[i].salaire=t[i].salaire+(t[i].salaire/10);
		}
	}
	i=0;
	printf("who get upgrated is: \n");
	for(i=0;i<3;i++){
		if(t[i].grade>=3){
        printf("nom: %s\n",t[i].nom);
		printf("prenom: %s\n",t[i].prenom);
		printf("grade: %d\n",t[i].grade);
		printf("new salaire: %.3f\n\n\n",t[i].salaire);
		}
	}
	return 0;
}
