#include "ctetrimino_expand.h"
#include <QRandomGenerator>

CTetrimino_Expand::CTetrimino_Expand()
{
    setShape_Expand(NoneShape);
}

void CTetrimino_Expand::setShape_Expand(TetrisShape_Expand shape)
{
    //每种进阶块的八个方块坐标
    //static使数据在整个程序运行周期内保持不变
    //constexpr 保证了数组在编译时就被初始化，提高程序的执行效率和安全性。
    static constexpr int coordsTable_Expand[8][8][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },   //NoneShape
        { { -1, 2 },  { -1, 1 },   { -1, 0 },  { 0, 0 },  { 1, 0 },  { 2, 0 },   { 2, 1 },  { 2, 2 }},  //LJShape
        { { -1, 2 },  { 0, 2 },   { 0, 1 },  { 1, 1 },  { 0, 0 },  { 1, 0 },   { 0, -1 },  { -1, -1 }},   //ZSShape
        { { 0, 2 },  { 0, 1 },   { 0, 0 },  { 0, -1 },  { 1, -1 },  { 1, 0 },   { 1, 1 },  { 1, 2 }},   //IIShape
        { { -1, 2 },  { 0, 2 },   { 1, 2 },  { 0, 1 },  { 0, 0 },  { 0, -1 },   { -1, -1 },  { 1, -1 }},   //TTShape
        { { -1, 2 },  { 0, 2 },   { 0, 1 },  { -1, 1 },  { 1, 0 },  { 2, 0 },   { 1, -1 },  { 2, -1 }},   //OOShape
        { { -1, 0 },  { 0, 0 },   { 0, 1 },  { 0, 2 },  { 1, 2 },  { 1, 1 },   { 1, 0 },  { 2, 1 }},   //JTShape
        { { -1, 2 },  { 0, 1 },  { 1, 1 },   { 1, 0 }, { 2, -1 },  { 0, 0 },  { -1, -1 },   { 2, 2 }}    //XShape
    };

    //当需要某种形状进阶块时可以直接从模版库里提取
    for(int i = 0;i < 8;++i)
    {
        for(int j = 0;j < 2;++j)
            coords_Expand[i][j] = coordsTable_Expand[shape][i][j];
    }


    pieceShape_Expand = shape;
}

void CTetrimino_Expand::setRandomShape_Expand()
{
    setShape_Expand(TetrisShape_Expand(QRandomGenerator::global()->bounded(7) + 1));//生成0到7的随机数(不包括7)，因为模版库中有效块为1到7，所以需要加1
}

int CTetrimino_Expand::minX_Expand() const
{
    int min_Expand = coords_Expand[0][0];

    for(int i = 1;i < 8;++i)
        min_Expand = qMin(min_Expand, coords_Expand[i][0]);

    return min_Expand;
}

int CTetrimino_Expand::maxX_Expand() const
{
    int max_Expand = coords_Expand[0][0];

    for(int i = 1;i < 8;++i)
        max_Expand = qMax(max_Expand, coords_Expand[i][0]);

    return max_Expand;
}

int CTetrimino_Expand::minY_Expand() const
{
    int min_Expand = coords_Expand[0][1];

    for(int i = 1;i < 8;++i)
        min_Expand = qMin(min_Expand, coords_Expand[i][1]);

    return min_Expand;
}

int CTetrimino_Expand::maxY_Expand() const
{
    int max_Expand = coords_Expand[0][1];

    for(int i = 1;i < 8;++i)
        max_Expand = qMax(max_Expand, coords_Expand[i][1]);

    return max_Expand;
}

//旋转函数

//逆时针旋转函数
CTetrimino_Expand CTetrimino_Expand::rotatedLeft_Expand() const
{
    CTetrimino_Expand result;//定义新的块类用于返回旋转后的结果
    result.setShape_Expand(pieceShape_Expand);//旋转后形状不变（广义）

    //运用矩阵旋转公式，求得旋转后的x, y
    for(int i = 0;i < 8; ++i)
    {
        result.setX_Expand(i,y_Expand(i));
        result.setY_Expand(i,-x_Expand(i));
    }
    return result;
}
//顺时针旋转函数
CTetrimino_Expand CTetrimino_Expand::rotatedRight_Expand() const
{
    CTetrimino_Expand result;
    result.setShape_Expand(pieceShape_Expand);

    for(int i = 0;i < 8; ++i){
        result.setX_Expand(i,-y_Expand(i));
        result.setY_Expand(i,x_Expand(i));
    }
    return result;
}
