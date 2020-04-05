#include <iostream>
#include "route.h"

using namespace std;

void help() {
    cout << endl;
    cout << "1 - add stop" << endl;
    cout << "2 - show stops" << endl;
    cout << "3 - calculate length" << endl;
    cout << "4 - calculate time" << endl;
    cout << "5 - set speed" << endl;
    cout << "? - help" << endl;
    cout << "0 - exit" << endl;
    cout << endl;
}

void setSpeed(Route &list) {
    double speed;

    cout << "Set speed: ";
    cin >> speed;
    while(cin.get() != '\n');

    list.setSpeed(speed);
}
int main()
{
    Route list(50);

    char menu = ' ';

    setSpeed(list);

    help();

while(menu != '0') {
    cout << endl << "select action" << endl;

    cin >> menu;
    while(cin.get() != '\n');

    switch (menu) {
    case '1': {
        cout << endl;
        cout << "1 - add to start" << endl;
        cout << "2 - add by number" << endl;
        cout << "3 - add to end" << endl;
        cout << endl;

        cin >> menu;
        while(cin.get() != '\n');

        switch (menu) {
        case '1': {
            list.addElem(1);
            break;
        }
        case '2': {
            list.addElem(2);
            break;
        }
        case '3': {
            list.addElem(3);
            break;
        }
        default: {
            cout << "Invalid value" << endl;
        }
        }

        cout << "Returning to mein menu" << endl;
        break;
    }

    case '2': {
        list.showStops();
        break;
    }

    case '3': {
        double lenght = list.calculateLength();
        cout << "Route lenght is: " << lenght << "km" << endl;
        break;
    }

    case '4': {
        list.calculateTime();
        break;
    }

    case '5': {
        setSpeed(list);
        break;
    }

    case '?': {
        help();
        break;
    }

    case '0': {
        break;
    }

    default: {
        cout << "Invalid value" << endl;
    }
    }
}



    return 0;
}
