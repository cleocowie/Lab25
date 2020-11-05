/** lab19functs.c
* ===========================================================
* Name: Cleo Cowie, 28SEPT2020
* Section: T1/2
* Project: LAB19
* Purpose: 
* ===========================================================
*/
#ifndef LAB25_H
#define LAB25_H

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct USAFBaseData {
    char baseName[50];
    int bldgsOwned;
    int structsOwned;
    char city[50];
    char state[30];
}   USAFBaseData;


void getPoints(Point*point1,Point*point2);

double getDistance(Point point1,Point point2);

int getNumLines(char filename[]);

void readFile(char filename[],USAFBaseData**baseStruct,int lines);
 
void printData(USAFBaseData**bases, int numBases);


#endif //LAB25_H