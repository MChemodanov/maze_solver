#include "robot.h"
#include <iostream>

Point Robot::turnShift(Point originalPos, float originalDir, Point vector)
{
    int length = sqrt(vector.x*vector.x + vector.y*vector.y);
    float angle = atan2(vector.x, vector.y) + originalDir;
    Point shift (0,0);
    shift.x = round(length*sin(angle));
    shift.y = round(length*cos(angle));

    return originalPos + shift;
}

void Robot::truncDir()
{
    while (dir > 2*M_PI)
        dir -= 2*M_PI;

    while (dir < 0)
        dir += 2*M_PI;
}

Robot::Robot(Maze & newMaze, Point initialPosition, float initialDirection):
    maze(newMaze),
    position(initialPosition),
    dir(initialDirection)
{
}

void Robot::moveStraight()
{
    position = turnShift(position, dir, Point(0,1));
    cout << "moveStraight" << endl;
}

void Robot::turnLeft()
{
    dir += M_PI/2;
    truncDir();

    cout << "turnLeft" << endl;
}
void Robot::turnRight()
{
    dir -= M_PI/2;
    truncDir();

    cout << "turnRight" << endl;
}

int Robot::addSensor(Point pos)
{
    sensors.push_back(pos);
    return sensors.size() - 1;
}

bool Robot::getSensorValue(unsigned int id)
{
    return maze.getValue(turnShift(position, dir, getSensorPosition(id)));
}

int Robot::getSensorsCount()
{
    return sensors.size();
}

Point Robot::getSensorPosition(unsigned int id)
{
    if (id < sensors.size())
        return sensors[id];
    else
        return Point(0,0);
}

Point Robot::getPosition()
{
    return position;
}

float Robot::getDirection()
{
    return dir;
}
