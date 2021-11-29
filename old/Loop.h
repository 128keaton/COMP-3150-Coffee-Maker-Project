//
// Created by Keaton Burleson on 11/28/21.
//

#ifndef HONORSPROJECT_LOOP_H
#define HONORSPROJECT_LOOP_H

// Lambda!
template<typename Func>
void loop(double n, double k, const Func &f) {
    for (int i = (int) k; i < n; ++i) {
        f((double) i);
    }
}

#endif //HONORSPROJECT_LOOP_H
