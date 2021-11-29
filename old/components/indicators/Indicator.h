//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_INDICATOR_H
#define HONORSPROJECT_INDICATOR_H
class Indicator {
public:
    virtual void setOn() = 0;
    virtual void setOff() = 0;
    virtual bool isIndicatorLit() = 0;
};
#endif //HONORSPROJECT_INDICATOR_H
