#include "route.h"
#include <string>
#include <iostream>
#include <cmath>

Route::Route(double speed)
{
    setSpeed(speed);
}

void Route::createList (stop *tmp) {

    tmp->sChar.distFromPrevStop = 0;

    tmp->prevStop = NULL;
    tmp->nextStop = NULL;

    plist = tmp;
    pfirst = plist;
    plast = plist;
}

void Route::setStopDist(stop* tmp) {

    cout << "Input distance from previusly stop (Km)" << endl;
    cin >> tmp->sChar.distFromPrevStop;

    if(tmp->sChar.distFromPrevStop < 0)
        tmp->sChar.distFromPrevStop *= -1;

    while(cin.get() != '\n');

}

void Route::setStartStopDist(stop* tmp) {

    tmp->sChar.distFromPrevStop = 0;

    cout << "Enter distance to next stop" << endl;
    cin >> tmp->nextStop->sChar.distFromPrevStop;
    while(cin.get() != '\n');
}

void Route::addEnd(stop* tmp) {
    plast->nextStop = tmp;

    tmp->nextStop = NULL;
    tmp->prevStop = plast;

    plast = tmp;

    setStopDist(tmp);
}

void Route::addStart(stop* tmp) {

    pfirst->prevStop = tmp;

    tmp->nextStop = pfirst;
    tmp->prevStop = NULL;

    pfirst = tmp;

    setStartStopDist(tmp);
}

void Route::addByOrder(stop* tmp ){
    int numOrder;

    cout << "Enter number from 1 to " << lenght << endl;
    cin >> numOrder;

    if (numOrder > lenght){
        cout << "Range error" << endl;
        lenght--;
        return;
    }

    if(numOrder == 1){
        addStart(tmp);
        return;
    }
    else if (numOrder == lenght ) {
        addEnd(tmp);
        return;
    }

    plist = pfirst;

    for (int i = 1; i < numOrder; i++){
        plist = plist->nextStop;
    }

    tmp->nextStop = plist;
    tmp->prevStop = plist->prevStop;

    plist->prevStop->nextStop = tmp;
    plist->prevStop = tmp;

    setStopDist(tmp);
}

void Route::addElem(int mode) {
    stop *tmp = new stop;

    cout << "Input name of stop" << endl;
    getline(cin, tmp->sChar.stopName);

    lenght++;

    if(!plist){
        createList(tmp);
    } else {
        switch (mode) {
        case 1: {
            addStart(tmp);
            break;
        }

        case 2: {
            addByOrder(tmp);
            break;
        }

        case 3 : {
            addEnd(tmp);
            break;
        }
        }

    }

}

void Route::setSpeed(double speed) {

    if(speed < 0) speed *= -1;

    speedKmph = speed;
}

void Route::showStops(){
    stop* p = pfirst;
    for(int i = 0; i < lenght; i++){


        cout << "Name: " << p->sChar.stopName << endl;
        cout << "Dist: " << p->sChar.distFromPrevStop << endl;

        p = p->nextStop;
    }
};

double Route::calculateLength() {

    stop* p = pfirst;
    string finalStop;
    double routeLength = 0;

    cout << "Enter the final stop" << endl;
    getline(cin, finalStop);

    while(p->sChar.stopName != finalStop){
        if(p == NULL){
            cout << "Final stop not found" << endl;
            return 0;
        }

        routeLength += p->sChar.distFromPrevStop;
        p = p->nextStop;
    }
    routeLength += p->sChar.distFromPrevStop;

    return routeLength;
}

void Route::calculateTime() {

    double lenght = calculateLength();
    double hours = 0;
    double minutes = round(modf((lenght / speedKmph), &hours) * 60);


    lenght
            ?   cout << hours << "h "
                     << minutes << 'm'  << endl
            :   cout << "0h";

}

