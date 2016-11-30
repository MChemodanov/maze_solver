#include "maze.h"
#include <iostream>

Point::Point(int x_, int y_)
    : x(x_), y(y_)
{}

Point Point::operator +(const Point &right)
{
    return Point(x + right.x, y+right.y);
}

Maze::Maze():
    maxWidth(0)
{
}

void Maze::addLine(std::string str)
{
    map.push_back(str);
    maxWidth = max(maxWidth, str.size());
}

bool Maze::getValue(Point position)
{
    if (position.x < 0 || position.x > maxWidth)
        return false;
    if (position.y < 0 || position.y > map.size())
        return false;

    return map[position.y][position.x] != ' ';
}

bool floatEqual(float value, float reference)
{
    return fabs(value-reference) < 0.1;
}

void Maze::printMaze(Point mark, float direction)
{
    for (unsigned int i =0; i< map.size();i++)
    {
        if (i != mark.y)
            cout << map[i].c_str() << endl;
        else
        {
            for (unsigned int j =0; j < map[i].size(); j++)
            {
                if (j!=mark.x)
                    cout << map[i][j];
                else
                {
                    if (floatEqual(direction, 0))
                        cout << 'v';
                    else if (floatEqual(direction, M_PI/2))
                        cout << '>';
                    else if (floatEqual(direction, M_PI))
                        cout << '^';
                    else if (floatEqual(direction, M_PI*3/2))
                        cout << '<';
                    else
                        cout << '*';
                }
            }
            cout << endl;
        }
    }
}
