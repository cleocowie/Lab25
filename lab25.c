/** lab19functs.c
* ===========================================================
* Name: Cleo Cowie, 28SEPT2020
* Section: T1/2
* Project: LAB19
* Purpose: 
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lab25.h"

int main(void) {
   double distance;
   int numOfLines;
   Point*point1 = malloc(sizeof(Point));
   Point*point2 = malloc(sizeof(Point));

   getPoints(point1,point2);
   distance=getDistance(*point1,*point2);
   printf("Distance: %lf.\n",distance);

    numOfLines = getNumLines("lab25Data.csv");
    USAFBaseData**bases = malloc(sizeof(USAFBaseData)*numOfLines);

    for (int i = 0; i<numOfLines; i++) {
        bases[i] = malloc(sizeof(USAFBaseData));
    }

    readFile("lab25Data.csv",bases,numOfLines);
    printData(bases,numOfLines);
   
    system("pause");
    return 0;
}


void getPoints(Point*point1,Point*point2) {

    printf("Enter coordinates of point 1.\n");
    scanf("%lf %lf",&point1->x,&point1->y);

    printf("Enter coordinates of point 2.\n");
    scanf("%lf %lf",&point2->x,&point2->y);

    return;
}

double getDistance(Point point1,Point point2) {

    double distance = sqrt(pow((point2.x-point1.x),2.0) + pow((point2.y-point1.y),2.0));
    return distance;
}

int getNumLines(char filename[])  
{  
    char c;  
    int count = 0;  
    // Open the file  
    FILE* fp = fopen(filename, "r");  

    // Check if file exists  
    if (fp == NULL) {  
        fprintf(stderr, "Could not open file %s", filename);  
        return -1;  
    }  

    // Extract characters from file and store in character c  
    for (c = getc(fp); c != EOF; c = getc(fp)) {  
        // count newline chars 
        if (c == '\n') { 
           count++;
        }
    }  

    // Close the file  
    fclose(fp); 

    return count;  
} 

void readFile(char filename[],USAFBaseData**baseStruct,int lines){
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        printf("Error opening file.\n");
    }

    char buff[100];
    fgets(buff,100,in);

for (int i = 0; i < lines; i++)
{
        fscanf(in, "%[^\n,],", baseStruct[i]->baseName);
        fscanf(in, "%d,", &baseStruct[i]->bldgsOwned);
        fscanf(in, "%d,", &baseStruct[i]->structsOwned);
        fscanf(in, "%[^\n,],", baseStruct[i]->city);
        fscanf(in, "%[^\n,],", baseStruct[i]->state);
        fgets(buff,100,in);
}
        
    fclose(in);
    return;
}

void printData(USAFBaseData**bases, int numBases) {
    int numRead=0;
    while (numRead<numBases) {
        printf("%s, ", bases[numRead]->baseName);
        printf("%d, ", bases[numRead]->bldgsOwned);
        printf("%d, ", bases[numRead]->structsOwned);
        printf("%s, ", bases[numRead]->city);
        printf("%s\n", bases[numRead]->state);
        numRead++;
    }


    return;
}
