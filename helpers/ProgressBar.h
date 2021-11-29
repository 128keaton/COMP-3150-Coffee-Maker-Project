//
// Created by Keaton Burleson on 11/29/21.
//

#ifndef HONORSPROJECT_PROGRESSBAR_H
#define HONORSPROJECT_PROGRESSBAR_H


#include <iostream>
#include <iomanip>
#include <string>


using std::cout,
std::flush,
std::string,
std::endl,
std::fixed,
std::setprecision;

class ProgressBar {
public:
    static void percentage(int percentage, const string &title = "") {
        string progress = "[" + string(percentage, '*') + string(100 - percentage, ' ') + "]";
        cout << "\r\033[F" << progress << " " << percentage << "% " << title << flush;
    }

    static void temperature(double current, double max, const string &title = "") {
        double percentage = (current / max) * 100;
        string progress = "[" + string((int)percentage, '*') + string(100 - (int)percentage, ' ') + "]";
        cout <<
             "\r\033[F" <<
             progress <<
             " " <<
             fixed <<
             setprecision(2) <<
             current <<
             "°C" <<
             " / " <<
             fixed <<
             setprecision(0) <<
             max <<
             "°C " <<
             title <<
             flush;
    }
};

#endif //HONORSPROJECT_PROGRESSBAR_H
