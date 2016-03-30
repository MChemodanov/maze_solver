#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <math.h>

using namespace std;

struct Point
{
    int x; int y;
    Point(int x_, int y_);
    Point operator+ (const Point&);
};

class Maze
{
    std::vector <std::string> map;
    unsigned int maxWidth;
public:
    Maze();

    void addLine(std::string str);
    bool getValue(Point position);
    void printMaze(Point mark, float direction);
};


#endif // MAZE_H
