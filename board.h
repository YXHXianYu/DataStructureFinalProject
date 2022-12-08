#ifndef BOARD_H
#define BOARD_H

#include <math.h>

#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>

#include "stone.h"
class Board {
   private:
    static int start_y;                                           // 棋盘左上角y坐标
    static int start_x;                                           // 棋盘左上角x坐标
    static int length_;                                           // 宝石框的长度
    bool mouse_on_diamond, mouse_on_lightning, mouse_on_shuffle;  // 鼠标是否选中了宝石、十字(道具)
    int rest_diamond, rest_lightning, rest_shuffle;               // 剩下的宝石和十字
    int point_;                                                   // 分数
    double combo_base;                                            // combo对分数的加成
    std::pair<int, int> chosen_;                                  // 鼠标点击的宝石位置
    std::pair<int, int> positions_[8][8];                         // 宝石坐标矩阵
    std::pair<int, int> hint_[2];                                 // 提示：可交换的两个宝石的位置
    Stone stones_[8][8];                                          // 宝石矩阵
    std::vector<std::pair<int, int>> matches_;                    // 可消除的宝石

   public:
    Board();
    void Generate();                // 生成
    void Swap(Stone& a, Stone& b);  // 交换两个宝石
    void Clicked(int x, int y);     // 鼠标点击坐标(x,y)
    bool Check();                   // 检查是否有可以消除的宝石，若有则将位置记录在matches_中
    bool Check_Game_Over();
    void Remove();              // 消除matches_中的宝石
    void Fall();                // 宝石掉落并补齐
    bool ShowHint(bool show);   // 提示
    void Remove(int i, int j);  // 移除位置(i,j)上的宝石
    void Refresh();
    std::pair<int, int> GetChosen();  // 获取点击的宝石位置
};

#endif  // BOARD_H