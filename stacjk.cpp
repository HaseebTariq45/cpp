#include<iostream>
using namespace std;
struct stack
{
int top=-1;
int *arr;
int size;
   stack(){
cout<<"ENTER SIZE OF STACK"<<endl;
cin>>size;
arr=new int [size];

   }
}s1;

void push(){
if(s1.top<s1.size-1){
int x;
cout<<"ENTER ELEMENT"<<endl;
cin>>x;
s1.top++;
s1.arr[s1.top]=x;
}
else
{
cout<<"STACK IS FULL"<<endl;
}
}

void pop(){
if(s1.top!=-1)
{
cout<<"REMOVED ELEMENT "<<s1.arr[s1.top]<<endl;
s1.top--;
}
else{
    cout<<"STACK IS EMPLTY"<<endl;
}
}

void totalelement(){
   if(s1.top==-1)
   {
      cout<<"STACK IS EMPTY"<<endl;
   }
   else
   {
for(int i=0;i<=s1.top;i++){
cout<<s1.arr[i]<<" ";
}

   }
}


void topelement(){
   if(s1.top==-1)
   {
cout<<"STACK IS EMPTY"<<endl;
   }
   else{
cout<<"TOP ELEMENT "<<s1.arr[s1.top]<<endl;   

   }
}


int main(){
int choice;
up:
system("cls");
cout<<"PRESS 1 FOR PUSH ELEMENT"<<endl;
cout<<"PRESS 2 FOR POP ELEMENT"<<endl;
cout<<"PRESS 3 FOR DISPLAY ALL ELEMENTS"<<endl;
cout<<"PRESS 4 FOR DISPLAY TOP ELEMENT"<<endl;
cin>>choice;
switch (choice)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
totalelement();
break;
}
case 4:
{
topelement(); 
break;
}
default:
{
cout<<"WRONG CHOICE";
break;
}
}
cout<<"PRESS ENTER TO CONTINUE"<<endl;
cin.ignore();
cin.get();
goto up;

}