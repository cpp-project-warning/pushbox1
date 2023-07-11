#ifndef _GET_H_
#define _GET_H_
#include "../COMMON/COMMON.h"

int get_box_number();
// int** get_wall();
void get_wall(int w[][MAXN]);
position* get_destination(int box_number);

position* get_box(int box_number);
position get_player();
#endif