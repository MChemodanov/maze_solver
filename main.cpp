#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "maze.h"
#include "robot.h"

using namespace std;

void initMaze(Maze & m)
{
    m.addLine("  E       ");
    m.addLine("  |  |    ");
    m.addLine("  |  |    ");
    m.addLine("  |--+--  ");
    m.addLine("     |    ");
    m.addLine("  |---    ");
    m.addLine("  |       ");
    m.addLine("  |---    ");
    m.addLine("  |       ");
    m.addLine("--|       ");
}

void solve(Robot & r)
{
    for (int i=0; i< r.getSensorsCount();i++)
        cout << "Sensor " << i << ":" << r.getSensorValue(i) << endl;

    switch(rand()%3)
    {
        case 0: r.moveStraight(); break;
        case 1: r.turnRight(); break;
        case 2: r.turnLeft(); break;
        default: break;
    }
}

int main()
{
    Maze maze;
    Robot robot(maze, Point(5,5), 0);
    robot.addSensor(Point(+1, 0));
    robot.addSensor(Point( 0, 0));
    robot.addSensor(Point(-1, 0));

    initMaze(maze);
    /* initialize random seed: */
    srand (time(NULL));

    while (true)
    {
        maze.printMaze(robot.getPosition(), robot.getDirection());
        solve(robot);
        _getch();
        system("cls");
    }

    return 0;
}
