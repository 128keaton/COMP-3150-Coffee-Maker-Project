//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_VALVE_H
#define HONORSPROJECT_VALVE_H
class Valve {
public:
    virtual void open() = 0;
    virtual void close() = 0;

protected:
   bool isOpened;
};


#endif //HONORSPROJECT_VALVE_H
