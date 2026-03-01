#ifndef CTETRIMINO_NUMBER_H
#define CTETRIMINO_NUMBER_H

enum TetrisShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,
                   LShape,MirroredLShape};

class CTetrimino_Number
{
public:
    CTetrimino_Number();

    void setShape(TetrisShape shape);
    void setRandomShape();

    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;

    CTetrimino_Number rotatedLeft() const;
    CTetrimino_Number rotatedRight() const;

    int x(int index) const
    {
        return coords[index][0];
    }
    int y(int index) const
    {
        return coords[index][1];
    }

    int mun(int index)
    {
        return ntable[index];
    }

    TetrisShape shape()
    {
        return pieceShape;
    }

private:
    void setX(int index,int value){coords[index][0]=value;}
    void setY(int index,int value){coords[index][1]=value;}

    int num;
    TetrisShape pieceShape;//抽象的描述
    int coords[4][2];//具体的描述
    int ntable[4];

};
#endif // CTETRIMINO_NUMBER_H
