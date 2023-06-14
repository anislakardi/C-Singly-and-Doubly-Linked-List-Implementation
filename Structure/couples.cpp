#include<stdio.h>
typedef struct person{
	char first_name[20];
	char last_name[20];
}pr;
typedef struct couple{
	pr m;
	pr w;
}cpl;
int main(){
	cpl t[2];
	for(int i=0;i<2;i++){
		printf("Enter the first name of the man number %d: ",i+1);
		scanf("%s",&t[i].m.first_name);
		printf("Enter the last name of the man number %d: ",i+1);
		scanf("%s",&t[i].m.last_name);
		printf("Enter the first name of the women number %d: ",i+1);
		scanf("%s",&t[i].w.first_name);
		printf("Enter the last name of the women number %d: ",i+1);
		scanf("%s",&t[i].w.last_name);		
	}
FILE *couples;
couples=fopen("couple.txt","w");
for(int j=0;j<2;j++){
	fprintf(couples,"Mr %s %s is the husband of Mrs %s %s.\n",t[j].m.first_name,t[j].m.last_name,t[j].w.first_name,t[j].w.last_name);
}
fclose(couples);
	return 0;
}
