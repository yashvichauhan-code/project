//Disaster Emergency & Resource Management System
#include <stdio.h> //input,output
#include <string.h> //for string copy, comparing
/*#include <stdlib.h> //for exit(), malloc()
#include <math.h> //coordinate distance 
#include <time.h> //for timestamp
#include <unistd.h> //for sleep() simulation*/

void coverpg(){
    printf("--------------------------------------------------\n");
    printf("      Disaster Emergency Management System        \n");
    printf("--------------------------------------------------\n\n");
    printf("Submitted by: \n");
    printf("Name        : Yashvi Singh \n");
    printf("Sap id      : 590022585 \n");
    printf("Course      : Btech CSE \n");
    printf("Batch       : 9\n\n");
    printf("Submitted to: \n");
    printf("Name        : Pankaj Badoni\n\n");
    char ans;
    printf("Press Enter to continue...");
    scanf("%c", &ans);
}

char disaster_type[20];

typedef struct{
    char name[20];
    int age;
    float latitude, longitude;
    char status[20];
    int severity;
}victim;

typedef struct{
    char name[20];
    char role[20];
    float latitude, longitude;
}volunteer;

typedef struct {
    char item[20];
    char type[20];
    int quantity;
}resource;

void showStatusSuggestions();
void showRoleSuggestions();
void addvictim();
void addvolunteer();
void addresource();
void viewallrecords();
void assignvolunteerandresource();
void viewsummary();
void generatereport();

void addvictim() {
    printf("\n------ Add New Victim ------\n");
    printf("\nDisaster Type: %s\n", disaster_type);

    if (strcmp(disaster_type, "flood") == 0) {
        printf("Suggested Status: drowned / trapped / hypothermia / stable\n");
    }
    else if (strcmp(disaster_type, "earthquake") == 0) {
        printf("Suggested Status: fracture / buried / bleeding / critical\n");
    }
    else if (strcmp(disaster_type, "landslide") == 0) {
        printf("Suggested Status: buried / trapped / injured / stable\n");
    }

    int v;
    printf("Enter number of victims you want to add: ");
    scanf("%d", &v);
    victim details[v];

    FILE *fp = fopen("victims.txt", "a");
    if (fp == NULL) {
        printf("Error Opening File\n");
        return;
    }
    for (int i = 0; i < v; i++) {

        printf("\nVictim %d:\n", i+1);

        printf("Enter name: ");
        scanf(" %[^\n]", details[i].name);

        printf("Enter age: ");
        scanf("%d", &details[i].age);

        printf("Enter latitude: ");
        scanf("%f", &details[i].latitude);

        printf("Enter longitude: ");
        scanf("%f", &details[i].longitude);

        printf("Enter status: ");
        scanf(" %[^\n]", details[i].status);

        printf("Enter severity (1=Stable, 2=Moderate, 3=Critical): ");
        scanf("%d", &details[i].severity);
        //Store full record in victims.txt
        fprintf(fp, "%s %d %.2f %.2f %s %d\n",
                details[i].name,
                details[i].age,
                details[i].latitude,
                details[i].longitude,
                details[i].status,
                details[i].severity);

        printf("Victim added successfully.\n");
    }
    fclose(fp);
}

void addvolunteer(){
    printf("\n------ Add New Volunteer ------\n");

    printf("\nDisaster Type: %s\n", disaster_type);

    if (strcmp(disaster_type, "flood") == 0) {
        printf("Suggested Roles: boat-operator / swimmer / rescuer / medic\n");
    }
    else if (strcmp(disaster_type, "earthquake") == 0) {
        printf("Suggested Roles: debris-removal / medic / structural-rescuer\n");
    }
    else if (strcmp(disaster_type, "landslide") == 0) {
        printf("Suggested Roles: excavation-team / rescuer / medic\n");
    }
    
    int v;
    printf("Enter the number of volunteers you want to add: ");
    scanf("%d", &v);
    volunteer details[v];

    FILE *fp = fopen("volunteers.txt", "a");
    if (fp == NULL) {
        printf("Error Opening File\n");
        return;
    }

    for(int i=0; i<v; i++){

        printf("\nVolunteer %d:\n", i+1);

        printf("Enter name: ");
        scanf(" %[^\n]", details[i].name);

        printf("Enter role: ");
        scanf(" %[^\n]", details[i].role);

        printf("Enter latitude: ");
        scanf("%f", &details[i].latitude);

        printf("Enter longitude: ");
        scanf("%f", &details[i].longitude);

        fprintf(fp, "%s %s %.2f %.2f\n",
                details[i].name,
                details[i].role,
                details[i].latitude,
                details[i].longitude);

        printf("Volunteer added successfully.\n");
    }
    fclose(fp);
}

void addresource(){

    printf("\n------ Add New Resource ------\n");
    printf("\nDisaster Type: %s\n", disaster_type);
    if (strcmp(disaster_type, "flood") == 0){
        printf("Suggested Resources: boats /ropes / life-jackets / blankets /water\n");
    }
    else if (strcmp(disaster_type, "landslide") == 0){
        printf("Suggested Resources: shovels / ropes / medical-kits / food packets\n");
    }
    
    int r;
    printf("\nEnter number of resources you want to add: ");
    scanf("%d", &r);

    resource details[r];

    FILE *fp =fopen("resource.txt", "a");
    if (fp == NULL){
        printf("Error Opening File!\n");
        return;
    }

    for (int i = 0; i < r; i++) {

        printf("\nResource %d:\n", i+1);

        printf("Enter item name: ");
        scanf(" %[^\n]", details[i].item);

        printf("Enter type: ");
        scanf(" %[^\n]", details[i].type);

        printf("Enter quantity: ");
        scanf("%d", &details[i].quantity);

        fprintf(fp, "%s %s %d\n",
                details[i].item,
                details[i].type,
                details[i].quantity);

        printf("Resource added successfully.\n");
    }

    fclose(fp);
}

void viewallrecords(){

    printf("\n\n------------- VIEW ALL RECORDS ------------\n");

    FILE *fp;

    printf("\n------- Victim Records --------\n");

    fp= foopen("victims.txt", "r");
    if(fp == NULL){
        printf("No vicim records found. \n");
    }
    else{
        
    }
}
int main(){
    coverpg();
    int choice;

    printf("Enter Disaster Type (flood/earthquake/landslide) :");
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
            /*case 4: viewallrecords(); break;
            case 5: assignvolunteerandresource(); break;
            case 6: viewsummary(); break;
            case 7: generatereport(); break;*/
        }
    }
    while (choice!=8);
    return 0;
}