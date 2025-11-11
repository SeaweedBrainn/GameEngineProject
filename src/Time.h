#pragma once
#define tUnit long long

class Time{
public:
    static const tUnit SECOND;

    static tUnit getTime();
    static double getDelta();
    static void setDelta(double delta);

private:
    static double delta;
};