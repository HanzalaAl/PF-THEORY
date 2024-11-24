#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    WeatherForecast* weather;
} Crop;

typedef struct {
    char equipmentName[50];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[100];
} Equipment;

typedef struct {
    float soilNutrients;
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    Crop* crops;
    int numCrops;
    Equipment* equipment;
    int numEquipment;
    Sensor* sensors;
    int numSensors;
} Field;

typedef struct {
    Field* fields;
    int numFields;
    float aggregateYieldPrediction;
    float resourceDistribution;
    char emergencyResponsePlan[200];
} RegionalHub;

WeatherForecast* createWeatherForecast(float temp, float rain, float wind) {
    WeatherForecast* wf = (WeatherForecast*)malloc(sizeof(WeatherForecast));
    wf->temperature = temp;
    wf->rainfall = rain;
    wf->windSpeed = wind;
    return wf;
}

Crop* createCrops(int numCrops) {
    Crop* crops = (Crop*)malloc(numCrops * sizeof(Crop));
    for (int i = 0; i < numCrops; i++) {
        printf("Enter details for Crop %d\n", i + 1);
        printf("Type: ");
        scanf(" %[^\n]", crops[i].cropType);
        printf("Growth Stage: ");
        scanf(" %[^\n]", crops[i].growthStage);
        printf("Expected Yield: ");
        scanf("%f", &crops[i].expectedYield);
        printf("Weather (Temp Rain Wind): ");
        float temp, rain, wind;
        scanf("%f %f %f", &temp, &rain, &wind);
        crops[i].weather = createWeatherForecast(temp, rain, wind);
    }
    return crops;
}

Equipment* createEquipment(int numEquipment) {
    Equipment* equipment = (Equipment*)malloc(numEquipment * sizeof(Equipment));
    for (int i = 0; i < numEquipment; i++) {
        printf("Enter details for Equipment %d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", equipment[i].equipmentName);
        printf("Operational Status (1=Active, 0=Inactive): ");
        scanf("%d", &equipment[i].operationalStatus);
        printf("Fuel Level: ");
        scanf("%f", &equipment[i].fuelLevel);
        printf("Activity Schedule: ");
        scanf(" %[^\n]", equipment[i].activitySchedule);
    }
    return equipment;
}

Sensor* createSensors(int numSensors) {
    Sensor* sensors = (Sensor*)malloc(numSensors * sizeof(Sensor));
    for (int i = 0; i < numSensors; i++) {
        printf("Enter details for Sensor %d\n", i + 1);
        printf("Soil Nutrients: ");
        scanf("%f", &sensors[i].soilNutrients);
        printf("pH Level: ");
        scanf("%f", &sensors[i].pHLevel);
        printf("Pest Activity (1=Present, 0=Absent): ");
        scanf("%d", &sensors[i].pestActivity);
    }
    return sensors;
}

Field* createFields(int numFields) {
    Field* fields = (Field*)malloc(numFields * sizeof(Field));
    for (int i = 0; i < numFields; i++) {
        printf("Enter details for Field %d\n", i + 1);
        printf("GPS Latitude: ");
        scanf("%f", &fields[i].gpsLatitude);
        printf("GPS Longitude: ");
        scanf("%f", &fields[i].gpsLongitude);
        printf("Soil Health: ");
        scanf("%f", &fields[i].soilHealth);
        printf("Moisture Level: ");
        scanf("%f", &fields[i].moistureLevel);
        printf("Number of Crops: ");
        scanf("%d", &fields[i].numCrops);
        fields[i].crops = createCrops(fields[i].numCrops);
        printf("Number of Equipment: ");
        scanf("%d", &fields[i].numEquipment);
        fields[i].equipment = createEquipment(fields[i].numEquipment);
        printf("Number of Sensors: ");
        scanf("%d", &fields[i].numSensors);
        fields[i].sensors = createSensors(fields[i].numSensors);
    }
    return fields;
}

RegionalHub* createRegionalHub(int numFields) {
    RegionalHub* hub = (RegionalHub*)malloc(sizeof(RegionalHub));
    printf("Creating fields for the hub...\n");
    hub->fields = createFields(numFields);
    hub->numFields = numFields;
    printf("Aggregate Yield Prediction: ");
    scanf("%f", &hub->aggregateYieldPrediction);
    printf("Resource Distribution: ");
    scanf("%f", &hub->resourceDistribution);
    printf("Emergency Response Plan: ");
    scanf(" %[^\n]", hub->emergencyResponsePlan);
    return hub;
}

void displayRegionalHub(RegionalHub* hub) {
    for (int i = 0; i < hub->numFields; i++) {
        printf("\nField %d:\n", i + 1);
        printf("GPS: (%f, %f)\n", hub->fields[i].gpsLatitude, hub->fields[i].gpsLongitude);
        printf("Soil Health: %f, Moisture Level: %f\n", hub->fields[i].soilHealth, hub->fields[i].moistureLevel);
        printf("Crops:\n");
        for (int j = 0; j < hub->fields[i].numCrops; j++) {
            printf("  Crop %d: %s, Growth: %s, Yield: %f\n", j + 1, hub->fields[i].crops[j].cropType, hub->fields[i].crops[j].growthStage, hub->fields[i].crops[j].expectedYield);
            printf("  Weather - Temp: %f, Rain: %f, Wind: %f\n", hub->fields[i].crops[j].weather->temperature, hub->fields[i].crops[j].weather->rainfall, hub->fields[i].crops[j].weather->windSpeed);
        }
        printf("Equipment:\n");
        for (int j = 0; j < hub->fields[i].numEquipment; j++) {
            printf("  Equipment %d: %s, Status: %d, Fuel: %f, Schedule: %s\n", j + 1, hub->fields[i].equipment[j].equipmentName, hub->fields[i].equipment[j].operationalStatus, hub->fields[i].equipment[j].fuelLevel, hub->fields[i].equipment[j].activitySchedule);
        }
        printf("Sensors:\n");
        for (int j = 0; j < hub->fields[i].numSensors; j++) {
            printf("  Sensor %d: Nutrients: %f, pH: %f, Pest: %d\n", j + 1, hub->fields[i].sensors[j].soilNutrients, hub->fields[i].sensors[j].pHLevel, hub->fields[i].sensors[j].pestActivity);
        }
    }
    printf("\nAggregate Yield Prediction: %f\n", hub->aggregateYieldPrediction);
    printf("Resource Distribution: %f\n", hub->resourceDistribution);
    printf("Emergency Response Plan: %s\n", hub->emergencyResponsePlan);
}

void freeRegionalHub(RegionalHub* hub) {
    for (int i = 0; i < hub->numFields; i++) {
        for (int j = 0; j < hub->fields[i].numCrops; j++) {
            free(hub->fields[i].crops[j].weather);
        }
        free(hub->fields[i].crops);
        free(hub->fields[i].equipment);
        free(hub->fields[i].sensors);
    }
    free(hub->fields);
    free(hub);
}

int main() {
    int numFields;
    printf("Enter the number of fields in the hub: ");
    scanf("%d", &numFields);

    RegionalHub* hub = createRegionalHub(numFields);
    displayRegionalHub(hub);
    freeRegionalHub(hub);

    return 0;
}
