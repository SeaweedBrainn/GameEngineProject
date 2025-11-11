#include "Time.h"
#include <chrono>

const tUnit Time::SECOND = static_cast<tUnit>(1000000000);
double Time::delta = 0.0;

tUnit Time::getTime(){
    auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(
            now.time_since_epoch()
        ).count();
}

double Time::getDelta(){
    return Time::delta;
}

void Time::setDelta(double delta){
    Time::delta = delta;
}
