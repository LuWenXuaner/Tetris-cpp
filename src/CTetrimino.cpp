#include "CTetrimino.h"
#include <QRandomGenerator>

//构造函数初始化（开始没有形状）
CTetrimino::CTetrimino()
{
    setShape(NoneShape);
}

//形状的建立
void CTetrimino::setShape(TetrisShape shape)
{
    //每种基础块的四个方块坐标
    //static使数据在整个程序运行周期内保持不变
    //constexpr 保证了数组在编译时就被初始化，提高程序的执行效率和安全性。
    static constexpr int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },   //NoneShape
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },  //ZShape
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },   //SShape
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },   //IShape
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },   //TShape
        { { 0, 0 },   { 1, 0 },   { 0, 1},   { 1, 1 } },   //OShape
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },   //JShape
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }    //LShape
    };

    //当需要某种形状基础块时可以直接从模版库里提取
    for(int i = 0;i < 4;++i)
    {
        for(int j = 0;j < 2;++j)
            coords[i][j] = coordsTable[shape][i][j];
    }

    //将需要的形状给块的形状
    pieceShape = shape;
}

//随机块形状确立函数
void CTetrimino::setRandomShape()
{
    setShape(TetrisShape(QRandomGenerator::global()->bounded(7) + 1));//生成0到7的随机数(不包括7)，因为模版库中有效块为1到7，所以需要加1
}

//边界确认函数（每一小块进行坐标比较）
int CTetrimino::minX() const
{
    int min = coords[0][0];

    for(int i = 1;i < 4;++i)
        min = qMin(min, coords[i][0]);

    return min;
}

int CTetrimino::maxX() const
{
    int max = coords[0][0];
    for(int i = 1;i < 4;++i)
        max = qMax(max, coords[i][0]);

    return max;
}

int CTetrimino::minY() const
{
    int min = coords[0][1];
    for(int i = 1;i < 4;++i)
        min = qMin(min, coords[i][1]);

    return min;
}

int CTetrimino::maxY() const
{
    int max = coords[0][1];
    for(int i = 1;i < 4;++i)
        max = qMax(max, coords[i][1]);

    return max;
}

//旋转函数

//逆时针旋转函数
CTetrimino CTetrimino::rotatedLeft() const
{

    if(pieceShape == OShape)
        return *this;//O块旋转后与原来相同，单独考虑

    CTetrimino result;//定义新的块类用于返回旋转后的结果
    result.setShape(pieceShape);//旋转后形状不变（广义）

    //运用矩阵旋转公式，求得旋转后的x, y
    for(int i = 0;i < 4; ++i)
    {
        result.setX(i,y(i));
        result.setY(i,-x(i));
    }
    return result;
}
//顺时针旋转函数
CTetrimino CTetrimino::rotatedRight() const
{

    if(pieceShape == OShape)
        return *this;

    CTetrimino result;
    result.setShape(pieceShape);

    for(int i = 0;i < 4; ++i){
        result.setX(i,-y(i));
        result.setY(i,x(i));
    }
    return result;
}


