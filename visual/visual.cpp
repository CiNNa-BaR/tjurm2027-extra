/*本题目主要考查类的使用,不了解类的同学建议先去学习相关知识。

    背景介绍：在Robomaster比赛中，一个机器人在进行自瞄的时候有时会同时识别到多个敌方目标。此时机器人需要
    选择其中一个来作为最佳打击目标并进行打击。通常我们会锁定距离准心（操作手端的屏幕中心）最近的目标。
    示例    ————————————————————————————————————————————
            |                       T                  |
            |        H            (1,4)                |
            |      (-9,3)                              |         
            |                                          |
            |                     +                    |      此时应当锁定S目标
            |                S                         |
            |              (-3,1)                      |
            |                              I           |
            |                            (7,-3)        |
            ————————————————————————————————————————————

    题目：编写一个程序，记录4个敌方目标的二维坐标，锁定距离准心最近的目标并输出对应的兵种ID。
    
    要求：采用面向对象的方法，设计两个类：
    Enemy 类：包含敌人的坐标和兵种ID，以及相应的设置和获取函数。
    Target 类：包含一个 Enemy 类的对象数组，并具备选择并返回最佳打击目标和输出的功能。

    PS：获取输入数据的框架已经替各位实现好了，在对应的地方调用你们编写的设置函数即可。
*/

#include <iostream>
#include <cmath>

using namespace std;

// ==================== 在此处编写 Enemy和Target 类 ====================
class Enemy {
private://敌人的坐标和兵种ID
    char id=' '; //兵种id
    double x=0.0,y=0.0; //坐标
    
public://设置和获取和计算距离
    void setid(char id) { this->id=id; } //设置兵种id
    void setxy(double x,double y) { this->x=x;this->y=y; } //设置坐标
    char getid() const { return id; } //获取兵种id
    double getX() const { return x; } //获取x坐标
    double getY() const { return y; } //获取y坐标
    double distance() const { return sqrt(x*x+y*y); } //计算距离
};

class Target
{
private:
    Enemy enemies[4]; 
public:
    void getEnemy(char ID,double X,double Y,int i)
    {
        enemies[i].setid(ID);
        enemies[i].setxy(X,Y);
    }
    void findbest()
    {
        char best_id=enemies[0].getid();
        double best_distance=enemies[0].distance();
        for(int i=1;i<4;i++)
        {
            if(enemies[i].distance()<best_distance)
            {
                best_id=enemies[i].getid();
                best_distance=enemies[i].distance();
            }
        }
        cout<<"answer: "<<best_id<<endl;
    }
};

// ====================================================================



int main() {
    Target target;

    for (int i = 0; i < 4; i++) {   
        double x, y;
        char id;
        cout << "请输入第 " << i + 1 << " 个目标的兵种ID和坐标(x y): ";
        cin >> id >> x >> y;

        //在此处调用你的Enemy的设置函数，传入id,x,y
        target.getEnemy(id, x, y, i);
    }

    // 调用查找并输出最佳目标
    target.findbest();
    return 0;
}
