//Disaster Emergency & Resource Management System
#include <stdio.h> //input,output
#include <string.h> //for string copy, comparing
#include <stdlib.h> //for exit(), malloc()
#include <math.h> //coordinate distance 
#include <time.h> //for timestamp
#include <unistd.h> //for sleep() simulation 

struct victim{
    char name[20];
    int age;
    char area[30];
    float latitude, longitude;
    char status[20];
    int severity;
};

struct volunteer{
    char name[20];
    char role[20];
    float latitude, longitude;
};

struct resource{
    char item[20];
    char type[20];
    int quantity;
};

void addvictim();
void addvolunteer();
void addresource();
void viewallrecords();
void assignvolunteerandresource();
void generatereport();

int main(){
    int choice;
    char disaster_type[15];
    printf("Enter Disaster Type (flood/earthquake/landslide :");
    scanf("%s", disaster_type);
    printf("\n=== Managing %s Relief Operations ===\n", disaster_type);

    do{
        printf("\n1. Add Victim\n2. Add Volunteer\n3. Add Resource\n4. View All Records\n5. Assign Volunteer & Resource\n6. View Summary\n7. Generate Report\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addvictim(); break;
            case 2: addvolunteer(); break;
            case 3: addresource(); break;
            case 4: viewallrecords(); break;
            case 5: assignvolunteerandresource(); break;
            case 6: viewsummary(); break;
            case 7: generatereport(); break;
        }
    }
    while(choice!=8);

    return 0;
}

void addvictim(){

}