#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct _ {
int batch;
int regNo;
char firstName[20];
char lastName[20];
float cGPA;
struct _* next;
}student_t;///creating a new type to store student information

void  addstudent();
void printstudent(int a,int b);
void printallstudents();
void deleterecord(int a,int b);

student_t * numbers = NULL; // to store the address of the first node
  student_t * current;	 // a temporary variable to keep the pointer to the current node

int main(){

	while(1){
	puts("--------------------------------------------");
	puts("A VOLATILE STUDENT RECORD MAINTENANCE SYSTEM");
	puts("--------------------------------------------");
	puts("0. Quit");
	puts("1. Insert a Student Record");
	puts("2. Print a Student Record");
	puts("3. Print all Student Records");
	puts("4. Delete a Student Record");

	int input;

	char a[20];//full registration number as a string
	scanf("%d",&input);
if(input==0){break;}//if input is 0 quit the programme
else if(input==1){//if input is one we add them to links

		addstudent();
       
		}
else if(input==2){//printing a student
		printf("Enter the Registration Number:");
		scanf("%s",&a);

	int n;
	char temp_arrray1[2],temp_arrray2[3];
  
  for(n=2;n<4;n++){
   temp_arrray1[n-2]=a[n];
  }

  temp_arrray1[2]='\0';  

int batch=atoi(temp_arrray1);//getting the value of ineteger value of batch from the string
   
   for(n=5;n<8;n++){
temp_arrray2[n-5]=a[n];
 }
temp_arrray2[3]='\0';
 
int regnum=atoi(temp_arrray2);//getting the value of ineteger value of regno from the string
	 printstudent(batch,regnum);}

else if(input==3){//print all students

             printallstudents();

		}

 else if(input==4){//to delete a record
               
            printf("Enter the Registration Number:");
		scanf("%s",&a);

	int n;
  char temp_arrray1[2],temp_arrray2[3];
  for(n=2;n<4;n++){
   temp_arrray1[n-2]=a[n];
  }
  temp_arrray1[2]='\0';

int batch=atoi(temp_arrray1);
   
   for(n=5;n<8;n++){
temp_arrray2[n-5]=a[n];
 }

temp_arrray2[3]='\0';
 
 int regnum=atoi(temp_arrray2);
           
            deleterecord(batch,regnum);
		}
	
}return 0;
	}
	
	

void addstudent(){//function to insert student

	    current=(student_t*)malloc(sizeof(student_t));
		printf("Enter the batch (11/12/13/14):");
		scanf("%d",&current -> batch);
		printf("Enter the registration number:");
		scanf("%d",&current -> regNo);
		printf("Enter the first name         :");
		scanf("%s",&current -> firstName);
		printf("Enter the last name          :");
		scanf("%s",&current -> lastName);
		printf("Enter the cumulative GPA     :");
		scanf("%f",&current -> cGPA);
        current -> next=numbers;
		numbers=current;
	}
void printstudent(int a,int b){//funtion to print the specified student

	for(current=numbers;current!=NULL;current=current -> next){
	
      if(a==current -> batch && b==current -> regNo ){//checking to what node the required student has been saved to

	printf("The student %s %s (E/%d/%d) has a cumulative GPA of %0.2f \n",current -> firstName,current -> lastName,current -> batch,current -> regNo,current -> cGPA);
	}}}

void printallstudents(){//function to print all students

for(current=numbers;current!=NULL;current=current -> next){
	

	printf("The student %s %s (E/%d/%d) has a cumulative GPA of %0.2f \n",current -> firstName,current -> lastName,current -> batch,current -> regNo,current -> cGPA);
	}}



void deleterecord(int a,int b){//function to delete a record

student_t *temp;
static student_t *previous=numbers;
int count=0,count1=0;
	for (current = numbers;current!= NULL; current = current -> next){// loop until the last node
	count++;//finding the number of nodes

 if(a==current -> batch && b==current -> regNo ){//checking what adress has to be freed
    	temp=current;
  }
  
}
for (current = numbers;current!= NULL; current = current -> next){// loop until the last node
	count1++;//finding what node has to be freed

 if(a==current -> batch && b==current -> regNo ){//checking what adress has to be freed
    	break;  }
  
}

if(count==1){numbers=NULL;}//if there is only ont node then we can just equalise it to NULL

else if(count==2 && count1==1){//if we want to remove the first node when there are only two nodes we can just equalise numbers to the next node 
numbers=numbers->next;         //and equalise the next of it to null so that the link end from there  
numbers->next=NULL; }
else if(count1==1){numbers=numbers->next;}//if we have to remove the first element in the structure
else{
 for (current = numbers; current!= temp; current = current -> next){// loop until the node we want to remove
		previous = current;//findiing the previous node we 
		}
	previous -> next =temp->next ;
	free(current);}



}


   


