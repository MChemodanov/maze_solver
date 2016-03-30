#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "maze.h"

class Robot
{
    std::vector<Point> sensors;
    Point position;
    float dir;

    Point relativePosToAbs(Point);
    Maze & maze;

    Point turnShift(Point originalPos, float originalDir, Point vector);
    void truncDir();

public:
    Robot(Maze & newMaze, Point initialPosition, float initialDirection);

    void moveStraight();
    void turnLeft();
    void turnRight();

    int addSensor(Point pos);
    bool getSensorValue(unsigned int id);
    int getSensorsCount();
    Point getSensorPosition(unsigned int id);

    Point getPosition();
    float getDirection();
};


#endif // ROBOT_H
