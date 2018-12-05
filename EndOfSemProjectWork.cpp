#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include<iomanip>

using namespace std;

//Structure defining

struct student
{
 string firstName;
 string lastName;
 int Id;
 string department;
}studentData;

struct teacher
{
 string first_name;
 string last_name;
 string qualification;
 string subj;
 string telephone;
}tech[50];

int main()
{

int i=0,j;
char sel;
string find;
string srch;

while(1)
{ 
 system("cls");


 cout<<"*************************************************************************************************************";
 cout<<"\n\t WELCOME TO THE UNIVERSITY OF GHANA MANAGEMENT SYSTEM\n\n";
 cout<<"**************************************************************************************************************";
 cout<<"\n\tMAIN SCREEN\n\n";
 cout<<"Enter The Action Your Want To Perform : "<<endl;
 cout<<"1.Students information"<<endl;
 cout<<"2.Teacher information"<<endl;
 cout<<"3.Exit program"<<endl;
 cin>>sel;
system("cls");

switch(sel)
{
 
case '1': 
 { 
while(1)
{ 
system("cls");
cout<<"\t STUDENTS INFORMATION AND BIO DATA SECTION\n";
cout<<"**************************************************"<<endl;
cout<<"Enter The Action You Want To Perform : "<<endl;
cout<<"1.Create new entry \t 2.Find and display entry\t 3.Jump to main\n";
cout<<"option : ";
cin>>sel;

switch (sel)

{
case '1':
{  ofstream output("student.txt",ios::app);

for( i=0;sel!='n';i++)
{

if((sel=='y')||(sel=='Y')||(sel=='1'))
{
 cout<<"Enter First name: ";
 cin>>studentData.firstName;
 cout<<"Enter Last name: ";
 cin>>studentData.lastName;
 cout<<"Enter Your Course Or Department : ";
 cin>>studentData.department;
 cout<<"Enter ID Number : ";
 cin>>studentData.Id;
 
 output<<studentData.lastName<<setw(13)<<studentData.firstName<<setw(13)<<studentData.department<<setw(13)<<studentData.Id<<endl;
 cout<<"Do you want to enter data: ";
 cout<<"Press Y for Continue and N to Finish:  ";
 cin>>sel;
}
} 
output.close();
}
continue;

case '2':
{  
ifstream edit("student.txt"); 

cout<<"Enter First name to be displayed: ";
cin>>find;
cout<<endl;
int notFound = 0;
for(j=0;(j<i)||(!edit.eof());j++)
{ 

getline(edit,studentData.firstName);

if(studentData.firstName==find)
{
 notFound = 1;
 cout<<"First name: "<<studentData.firstName<<endl;
  
  getline(edit,studentData.lastName);
  cout<<"Last name: "<<studentData.lastName<<endl;
  
//  getline(edit, studentData.Id);
  cout<<"Index Number : "<< studentData.Id <<endl;
  
  getline(edit,studentData.department);
  cout<<"Department: "<<studentData.department<<endl;
 
 /*getline(f2,studentData.Registration);
 cout<<"Registration No number: "<<studentData.Registration<<endl;
 getline(f2,studentData.classes);
 cout<<"Class: "<<studentData.classes<<endl<<endl;*/
}

}

if(notFound == 0){

cout<<"There Is No Record Of Student In The Database "<<endl;
}
edit.close();

cout<<"Press any key three times to proceed";
getch();
getch();
getch();

}
continue;                         //control back to inner loop -1

case '3':                         //Jump to main
{
break;                             //inner switch breaking
}

}

break;                              //inner loop-1 breaking
}
continue;                           //Control pass to 1st loop    
}

case '2':
{ 
while(1)
{ 
system("cls");
cout<<"\t TEACHERS INFORMATION AND BIODATA SECTION\n";
cout<<"*********************************************************"<<endl;
cout<<"Enter The Action Your Want To Perform : "<<endl;
cout<<"1.Create new entry \t 2.Find and display\t 3.Jump to main\n";
cin>>sel;

switch (sel);
{
case 1:
{ 
ofstream toutput("teacher.txt",ios::app);

for(i=0;sel!='n'&& sel!='N';i++)
{
 
 if((sel=='y')||(sel=='Y')||(sel=='1'))
 {
  cout<<"Enter First name: ";
  cin>>tech[i].first_name;
  cout<<"Enter Last name:: ";
  cin>>tech[i].last_name;
  cout<<"Enter qualification: ";
  cin>>tech[i].qualification;
  cout<<"Enter Subject You Teach: ";
  cin>>tech[i].subj;
  cout<<"Enter Phone Number: ";
  cin>>tech[i].telephone;

  cout<<"Do you want to enter data (Y/N ): ";
  cin>>sel;
 }
}
system("cls");



toutput.close();
break;
}

continue;//Control pass to inner loop-2

case 2 ://Display data
{ 
ifstream tedit("teacher.txt"); 

cout<<"Enter name to be displayed: ";
cin>>find;

cout<<endl;
int notFound = 0;
for( j=0;((j<i)||(!tedit.eof()));j++)
{ 
 
 getline(tedit,tech[j].first_name);
 
 if(tech[j].first_name==find)
 {
  notFound = 1;
  cout<<"First name: "<<tech[j].first_name<<endl;
  
  getline(tedit,tech[j].last_name);
  cout<<"Last name: "<<tech[j].last_name<<endl;
  
  getline(tedit,tech[j].qualification);
  cout<<"Qualification: "<<tech[j].qualification<<endl;
  
  getline(tedit,tech[j].subj);
  cout<<"Subject whos teach: "<<tech[j].subj<<endl;
  
  getline(tedit,tech[j].telephone);
  cout<<"Phone Number: "<<tech[j].telephone<<endl;
 }
 
}

tedit.close();
if(notFound == 0){

 cout<<"There Is No Data Of In The Database"<<endl;
}
cout<<"Press any key three times to proceed";
getch();
getch();
}

continue;              //Control pass to inner loop-2

case '3':      
{
break;                //inner switch
}

}

break;
}

continue;
}


case 3:
{
break;
}
}   
break;
}
return 0;
}
