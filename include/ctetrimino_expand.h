#ifndef CTETRIMINO_EXPAND_H
#define CTETRIMINO_EXPAND_H

//枚举强化方块类型
enum TetrisShape_Expand { NoneShape, LJShape, ZSShape, IIShape, TTShape, OOShape,
                   JTShape, XShape}; //每个常量隐式赋予整数值，从0开始

class CTetrimino_Expand
{
public:
    CTetrimino_Expand();
    void setShape_Expand(TetrisShape_Expand shape);//根据给出形状建立方块
    void setRandomShape_Expand();//根据随机数种子建立下一个方块形状

    //获取一个方块的边界（边界值不需要修改，加const后可以被常量对象和const引用调用）
    int minX_Expand() const;//方块的横坐标的最小值
    int maxX_Expand() const;//方块的横坐标的最大值
    int minY_Expand() const; //方块的纵坐标的最小值
    int maxY_Expand() const; //方块的纵坐标的最大值

    //对方块进行旋转处理（加const后可以被常量对象和const引用调用）
    CTetrimino_Expand rotatedLeft_Expand() const;//逆时针旋转90度
    CTetrimino_Expand rotatedRight_Expand() const;//顺时针旋转90度

    //给出一个方块的第index块的坐标
    int x_Expand(int index) const
    {
        return coords_Expand[index][0];//二维数组第一列为表示该块的横坐标
    }
    int y_Expand(int index) const
    {
        return coords_Expand[index][1]; //二维数组第二列为表示该块的纵坐标
    }

    //获取私有成员形状信息的函数
    TetrisShape_Expand shape_Expand()
    {
        return pieceShape_Expand;
    }

    //设置第index块的横纵坐标
    void setX_Expand(int index, int value)
    {
        coords_Expand[index][0] = value;//设置横坐标为value
    }
    void setY_Expand(int index,int value)
    {
        coords_Expand[index][1] = value; //设置纵坐标为value
    }

private:
    //将方块的属性定义为私有成员变量
    TetrisShape_Expand pieceShape_Expand;//方块的形状
    int coords_Expand[8][2];//每个进阶方块由8个小方块组成，每块的坐标为二维平面内点
};

#endif // CTETRIMINO_EXPAND_H
