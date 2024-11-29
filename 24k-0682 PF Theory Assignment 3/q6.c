/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 6
Pf Assignment 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct {
    char cropType[50];
    char growthStage[20];
    float expectedYield;
    Weather *weather;
} Crop;

typedef struct {
    char equipmentType[50];
    char operationalStatus[20];
    float fuelLevel;
    char activitySchedule[100];
} Equipment;

typedef struct {
    char nutrientType[50];
    float pHLevel;
    int pestActivity; 
} Sensor;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    Crop *crops;
    int numCrops;
    Equipment *equipment;
    int numEquipment;
    Sensor *sensors;
    int numSensors;
} Field;

typedef struct {
    char regionName[50];
    Field *fields;
    int numFields;
    float aggregatedYieldPrediction;
} RegionalHub;


Field* initializeFields(int numFields);
RegionalHub* initializeRegionalHubs(int numHubs, int *numFieldsPerHub);
void displayRegionalHubData(RegionalHub *hubs, int numHubs);
void freeResources(RegionalHub *hubs, int numHubs);

int main() {
    int numHubs, numFieldsPerHub[5]; 
    printf("Enter the number of regional hubs: ");
    scanf("%d", &numHubs);

    for (int i = 0; i < numHubs; i++) {
        printf("Enter the number of fields in hub %d: ", i + 1);
        scanf("%d", &numFieldsPerHub[i]);
    }

    RegionalHub *hubs = initializeRegionalHubs(numHubs, numFieldsPerHub);
    displayRegionalHubData(hubs, numHubs);

    freeResources(hubs, numHubs);

    return 0;
}

Field* initializeFields(int numFields) {
    Field *fields = malloc(numFields * sizeof(Field));
    for (int i = 0; i < numFields; i++) {
        printf("\nInitializing Field %d...\n", i + 1);
        printf("Enter GPS Latitude: ");
        scanf("%f", &fields[i].gpsLatitude);
        printf("Enter GPS Longitude: ");
        scanf("%f", &fields[i].gpsLongitude);
        printf("Enter Soil Health (0-100): ");
        scanf("%f", &fields[i].soilHealth);
        printf("Enter Moisture Level (0-100): ");
        scanf("%f", &fields[i].moistureLevel);

        printf("Enter the number of crops in this field: ");
        scanf("%d", &fields[i].numCrops);
        fields[i].crops = malloc(fields[i].numCrops * sizeof(Crop));
        for (int j = 0; j < fields[i].numCrops; j++) {
            printf("Enter Crop %d Type: ", j + 1);
            scanf("%s", fields[i].crops[j].cropType);
            printf("Enter Growth Stage: ");
            scanf("%s", fields[i].crops[j].growthStage);
            printf("Enter Expected Yield (in tons): ");
            scanf("%f", &fields[i].crops[j].expectedYield);
            fields[i].crops[j].weather = malloc(sizeof(Weather));
            printf("Enter Weather for Crop %d\n", j + 1);
            printf("  Temperature (°C): ");
            scanf("%f", &fields[i].crops[j].weather->temperature);
            printf("  Rainfall (mm): ");
            scanf("%f", &fields[i].crops[j].weather->rainfall);
            printf("  Wind Speed (km/h): ");
            scanf("%f", &fields[i].crops[j].weather->windSpeed);
        }

        printf("Enter the number of equipment in this field: ");
        scanf("%d", &fields[i].numEquipment);
        fields[i].equipment = malloc(fields[i].numEquipment * sizeof(Equipment));
        for (int j = 0; j < fields[i].numEquipment; j++) {
            printf("Enter Equipment %d Type: ", j + 1);
            scanf("%s", fields[i].equipment[j].equipmentType);
            printf("Enter Operational Status: ");
            scanf("%s", fields[i].equipment[j].operationalStatus);
            printf("Enter Fuel Level: ");
            scanf("%f", &fields[i].equipment[j].fuelLevel);
            printf("Enter Activity Schedule: ");
            getchar(); 
            fgets(fields[i].equipment[j].activitySchedule, 100, stdin);
            fields[i].equipment[j].activitySchedule[strcspn(fields[i].equipment[j].activitySchedule, "\n")] = '\0'; // Remove newline
        }

        printf("Enter the number of sensors in this field: ");
        scanf("%d", &fields[i].numSensors);
        fields[i].sensors = malloc(fields[i].numSensors * sizeof(Sensor));
        for (int j = 0; j < fields[i].numSensors; j++) {
            printf("Enter Sensor %d Nutrient Type: ", j + 1);
            scanf("%s", fields[i].sensors[j].nutrientType);
            printf("Enter pH Level: ");
            scanf("%f", &fields[i].sensors[j].pHLevel);
            printf("Is Pest Activity detected (1 for Yes, 0 for No): ");
            scanf("%d", &fields[i].sensors[j].pestActivity);
        }
    }
    return fields;
}

RegionalHub* initializeRegionalHubs(int numHubs, int *numFieldsPerHub) {
    RegionalHub *hubs = malloc(numHubs * sizeof(RegionalHub));
    for (int i = 0; i < numHubs; i++) {
        printf("\nInitializing Regional Hub %d...\n", i + 1);
        printf("Enter Region Name: ");
        scanf("%s", hubs[i].regionName);

        hubs[i].numFields = numFieldsPerHub[i];
        hubs[i].fields = initializeFields(hubs[i].numFields);

        hubs[i].aggregatedYieldPrediction = 0;
        for (int j = 0; j < hubs[i].numFields; j++) {
            for (int k = 0; k < hubs[i].fields[j].numCrops; k++) {
                hubs[i].aggregatedYieldPrediction += hubs[i].fields[j].crops[k].expectedYield;
            }
        }
    }
    return hubs;
}

void displayRegionalHubData(RegionalHub *hubs, int numHubs) {
    printf("\n--- Regional Hub Data ---\n");
    for (int i = 0; i < numHubs; i++) {
        printf("\nRegion: %s\n", hubs[i].regionName);
        printf("Number of Fields: %d\n", hubs[i].numFields);
        printf("Aggregated Yield Prediction: %.2f tons\n", hubs[i].aggregatedYieldPrediction);
    }
}
void freeResources(RegionalHub *hubs, int numHubs) {
    for (int i = 0; i < numHubs; i++) {
        for (int j = 0; j < hubs[i].numFields; j++) {
            for (int k = 0; k < hubs[i].fields[j].numCrops; k++) {
                free(hubs[i].fields[j].crops[k].weather);
            }
            free(hubs[i].fields[j].crops);
            free(hubs[i].fields[j].equipment);
            free(hubs[i].fields[j].sensors);
        }
        free(hubs[i].fields);
    }
    free(hubs);
}
