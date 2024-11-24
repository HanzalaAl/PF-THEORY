#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CATEGORIES 5
#define NUM_DEVICES 3
#define NUM_CONTENT 10

typedef struct {
    char title[100];
    float rating;
    int runtime;
    char encodingFormat[50];
} ContentMetadata;

typedef struct {
    float engagementScore;
} UserEngagement;

typedef struct {
    int resolution;
    int playbackPosition;
    float bandwidthUsage;
} DevicePreferences;

UserEngagement** createEngagementMatrix(int numUsers) {
    UserEngagement** matrix = (UserEngagement**)malloc(numUsers * sizeof(UserEngagement*));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (UserEngagement*)malloc(NUM_CATEGORIES * sizeof(UserEngagement));
        for (int j = 0; j < NUM_CATEGORIES; j++) {
            matrix[i][j].engagementScore = 0.0f;
        }
    }
    return matrix;
}

DevicePreferences*** createDeviceMatrix(int numUsers) {
    DevicePreferences*** matrix = (DevicePreferences***)malloc(numUsers * sizeof(DevicePreferences**));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (DevicePreferences**)malloc(NUM_DEVICES * sizeof(DevicePreferences*));
        for (int j = 0; j < NUM_DEVICES; j++) {
            matrix[i][j] = (DevicePreferences*)malloc(sizeof(DevicePreferences));
            matrix[i][j]->resolution = 1080;
            matrix[i][j]->playbackPosition = 0;
            matrix[i][j]->bandwidthUsage = 5.0f;
        }
    }
    return matrix;
}

ContentMetadata** createContentMetadataMatrix() {
    ContentMetadata** matrix = (ContentMetadata**)malloc(NUM_CATEGORIES * sizeof(ContentMetadata*));
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        matrix[i] = (ContentMetadata*)malloc(NUM_CONTENT * sizeof(ContentMetadata));
        for (int j = 0; j < NUM_CONTENT; j++) {
            strcpy(matrix[i][j].title, "Content Title");
            matrix[i][j].rating = 5.0f;
            matrix[i][j].runtime = 120;
            strcpy(matrix[i][j].encodingFormat, "MP4");
        }
    }
    return matrix;
}

void updateEngagementScore(UserEngagement** engagementMatrix, int userIndex, int categoryIndex, float score) {
    engagementMatrix[userIndex][categoryIndex].engagementScore = score;
}

void updateDevicePreferences(DevicePreferences*** deviceMatrix, int userIndex, int deviceIndex, int resolution, int playbackPosition, float bandwidthUsage) {
    deviceMatrix[userIndex][deviceIndex]->resolution = resolution;
    deviceMatrix[userIndex][deviceIndex]->playbackPosition = playbackPosition;
    deviceMatrix[userIndex][deviceIndex]->bandwidthUsage = bandwidthUsage;
}

void displayUserEngagement(UserEngagement** engagementMatrix, int userIndex, int numCategories) {
    printf("User %d Engagement Scores:\n", userIndex);
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: %.2f\n", i + 1, engagementMatrix[userIndex][i].engagementScore);
    }
}

void displayDevicePreferences(DevicePreferences*** deviceMatrix, int userIndex, int numDevices) {
    printf("User %d Device Preferences:\n", userIndex);
    for (int i = 0; i < numDevices; i++) {
        printf("Device %d - Resolution: %d, Playback Position: %d, Bandwidth: %.2f Mbps\n", 
               i + 1, deviceMatrix[userIndex][i]->resolution, deviceMatrix[userIndex][i]->playbackPosition, deviceMatrix[userIndex][i]->bandwidthUsage);
    }
}

void displayContentMetadata(ContentMetadata** contentMatrix, int numCategories, int numContent) {
    printf("Content Metadata:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < numContent; j++) {
            printf("Title: %s, Rating: %.2f, Runtime: %d mins, Format: %s\n", 
                   contentMatrix[i][j].title, contentMatrix[i][j].rating, contentMatrix[i][j].runtime, contentMatrix[i][j].encodingFormat);
        }
    }
}

int main() {
    int numUsers = 2;
    UserEngagement** engagementMatrix = createEngagementMatrix(numUsers);
    DevicePreferences*** deviceMatrix = createDeviceMatrix(numUsers);
    ContentMetadata** contentMatrix = createContentMetadataMatrix();

    updateEngagementScore(engagementMatrix, 0, 0, 7.5f);
    updateEngagementScore(engagementMatrix, 1, 1, 8.2f);

    updateDevicePreferences(deviceMatrix, 0, 0, 1080, 100, 5.0f);
    updateDevicePreferences(deviceMatrix, 1, 1, 720, 200, 3.5f);

    displayUserEngagement(engagementMatrix, 0, NUM_CATEGORIES);
    displayUserEngagement(engagementMatrix, 1, NUM_CATEGORIES);
    
    displayDevicePreferences(deviceMatrix, 0, NUM_DEVICES);
    displayDevicePreferences(deviceMatrix, 1, NUM_DEVICES);

    displayContentMetadata(contentMatrix, NUM_CATEGORIES, NUM_CONTENT);

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
        for (int j = 0; j < NUM_DEVICES; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}
