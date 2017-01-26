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

	for (current = numbers;current->next!= NULL; current = current -> next){// loop until the last node
	

 if(a==current -> batch && b==current -> regNo ){//checking what adress has to be freed
    	temp=current;
  }
  
}

/*for(n=1;n<count;n++){//freeing the memory of what we to deleteC:\Users\user\Documents\Academic

	temp = numbers -> next;
	numbers=numbers->next;
}

numbers= tempnumbers;
for(n=1;n<count-1;n++){//giving the address of deleted to the previous node
    
    current = numbers -> next -> next;
	numbers -> next = current;
	numbers=numbers->next;
	}



   	free(temp);  
*/

 for (current = numbers; current!= temp; current = current -> next){// loop until the last node
		previous = current;
		}
	previous -> next =temp->next ;
	free(current);



}


   


