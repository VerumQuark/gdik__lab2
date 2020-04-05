#ifndef ROUTE_H
#define ROUTE_H


#include <iostream>
#include <string>

#include <fstream>

using namespace std;

struct stopCharacteristics {
    string stopName;
    double distFromPrevStop;
};

struct stop {
    stop *prevStop;
    stopCharacteristics sChar;
    stop *nextStop;
};

class Route
{
    double speedKmph;
    stop *plist = NULL;
    stop *pfirst;
    stop *plast;


    void createList (stop *tmp);

    void setStopDist (stop *tmp);

    void setStartStopDist (stop *tmp);

    void addEnd (stop* tmp);

    void addStart (stop* tmp);

    void addByOrder(stop* tmp);

public:
    int lenght = 0;

    Route(double speed);

    void addElem(int mode);

    void setSpeed (double speed);

    void showStops ();

    double calculateLength();

    void calculateTime();

};

#endif // ROUTE_H
