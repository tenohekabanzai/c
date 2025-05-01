#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main(){
    struct Student s1;
    strcpy(s1.name,"Hello World");
    strcpy(s1.major,"abc");
    s1.age = 19;
    s1.gpa = 4.4;

    printf("name -> %s\n",s1.name);
    printf("major -> %s\n",s1.major);
    printf("age -> %d\n",s1.age);
    printf("gpa -> %.2f\n",s1.gpa);
    return 0;
}