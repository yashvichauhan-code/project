//Disaster Emergency & Resource Management System
#include <stdio.h> //input,output
#include <string.h> //for string copy, comparing
#include <stdlib.h> //for exit(), malloc()
#include <math.h> //coordinate distance 
char disaster_type[20];
void coverpg(){
    printf("------------------------------------------------------\n");
    printf("          DISASTER EMERGENCY MANAGEMENT SYSTEM         \n");
    printf("------------------------------------------------------\n\n");
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
void showHeader() {
    printf("\n-------------------------------------------------------\n");
    printf("    Disaster Emergency Management System - %s", disaster_type);
    printf("\n-------------------------------------------------------\n");
}
void getCurrentLocation(float *lat, float *lon) {

    // Step 1: call API using curl and save output into temp file
    system("curl -s \"http://ip-api.com/line/?fields=lat,lon\" > location.txt");

    // Step 2: open temp file
    FILE *fp = fopen("location.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to fetch location.\n");
        return;
    }

    // Step 3: read latitude and longitude
    fscanf(fp, "%f", lat);
    fscanf(fp, "%f", lon);

    fclose(fp);
}
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
        printf("Suggested Status: drowned / trapped / hypothermia / stable\n\n");
    }
    else if (strcmp(disaster_type, "earthquake") == 0) {
        printf("Suggested Status: fracture / buried / bleeding / critical\n\n");
    }
    else if (strcmp(disaster_type, "landslide") == 0) {
        printf("Suggested Status: buried / trapped / injured / stable\n\n");
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

        printf("\nFetching GPS coordinates automatically...\n");
        getCurrentLocation(&details[i].latitude, &details[i].longitude);
        printf("Location fetched: \nLat = %.4f, Lon = %.4f\n", details[i].latitude, details[i].longitude);


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
    printf("\nTotal %d victim(s) added in this session.\n", v);
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
        printf("Suggested Roles: excavation-team / rescuer / medic\n\n");
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

        printf("\nFetching GPS coordinates automatically...\n");
        getCurrentLocation(&details[i].latitude, &details[i].longitude);
        printf("Location fetched: Lat = %.4f, Lon = %.4f\n", details[i].latitude, details[i].longitude);


        fprintf(fp, "%s %s %.2f %.2f\n",
                details[i].name,
                details[i].role,
                details[i].latitude,
                details[i].longitude);

        printf("\n\nVolunteer added successfully.\n");
    }
    printf("\nTotal %d volunteer(s) added in this session.\n", v);
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

    printf("\n\n================== VIEW ALL RECORDS ==================\n");

    FILE *fp;

    //VICTIMS
    printf("\n------------------ VICTIM RECORDS ------------------\n");

    fp= fopen("victims.txt", "r");
    if(fp == NULL){
        printf("No vicim records found. \n");
    }
    else{
    char name[50], status[50];
    int age, severity;
    float lat,lon;
        
    printf("%-15s %-5s %-12s %-12s %-12s %-8s\n", "Name", "Age", "Lat","Lon", "Status", "Severity");
    printf("----------------------------------------------------------------------------\n");
    while (fscanf(fp, "%s %d %f %f %s %d",
              name, &age, &lat, &lon, status, &severity) == 6) {

        printf("%-15s %-5d %-12.4f %-12.4f %-12s %-8d\n",
           name, age, lat, lon, status, severity);

    }
        fclose(fp);  
        
    }

    //VOLUNTEERS
    printf("\n---------------- VOLUNTEER RECORDS -----------------\n");

    fp = fopen("volunteers.txt", "r");
    if (fp == NULL) {
        printf("No volunteer records found.\n");
    } else {

        char name[50], role[50];
        float lat, lon;

        printf("%-15s %-15s %-12s %-12s\n",
               "Name", "Role", "Lat", "Lon");
        printf("---------------------------------------------------\n");

        while (fscanf(fp, "%s %s %f %f",
                              name, role, &lat, &lon) == 4) {

            printf("%-15s %-15s %-12f %-12f\n",
                   name, role, lat, lon);
        }
        fclose(fp);
    }

    //RESOURCES
    printf("\n------------------ RESOURCE RECORDS -----------------\n");

    fp = fopen("resource.txt", "r");
    if (fp == NULL) {
        printf("No resource records found.\n");
    } else {

        char item[50], type[50];
        int qty;

        printf("%-15s %-15s %-10s\n",
               "Item", "Type", "Quantity");
        printf("-----------------------------------------------\n");

        while (fscanf(fp, "%s %s %d",
                      item, type, &qty) != EOF) {

            printf("%-15s %-15s %-10d\n",
                   item, type, qty);
        }
        fclose(fp);
    }

    printf("\n=====================================================\n");
}
int askReturnToMenu() {
    char ch;

    printf("\nDo you want to return to the main menu? (y/n): ");
    scanf(" %c", &ch); 

    if (ch == 'y' || ch == 'Y')
        return 1;   // go back to menu
    else
        return 0;   // exit program
}

int main() {
    coverpg();

    printf("Enter Disaster Type (flood/earthquake/landslide) : ");
    scanf("%s", disaster_type);

    int choice;
    int stayInMenu = 1;   // controls the loop

    do {
        showHeader();  // if you made this; else remove this line

        printf("\n1. Add Victim");
        printf("\n2. Add Volunteer");
        printf("\n3. Add Resource");
        printf("\n4. View All Records");
        printf("\n5. Assign Volunteer & Resource");
        printf("\n6. View Summary");
        printf("\n7. Generate Report");
        printf("\n8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addvictim();
                stayInMenu = askReturnToMenu(); break;
            case 2:
                addvolunteer();
                stayInMenu = askReturnToMenu(); break;
            case 3:
                addresource();
                stayInMenu = askReturnToMenu(); break;
            case 4:
                viewallrecords();
                stayInMenu = askReturnToMenu(); break;
            case 5:
                // assignvolunteerandresource();
                stayInMenu = askReturnToMenu(); break;
            case 6:
                // viewsummary();
                stayInMenu = askReturnToMenu(); break;
            case 7:
                // generatereport();
                stayInMenu = askReturnToMenu(); break;
            case 8:
                printf("\nExiting... Thank you for using the system.\n");
                stayInMenu = 0;   // stop loop
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                // stayInMenu remains 1 so menu shows again 
                break;
        }


    } while (stayInMenu == 1);

    return 0;
}