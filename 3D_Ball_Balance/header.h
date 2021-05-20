#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <MMSystem.h>
#include<math.h>
#include <iostream>
#include<bits/stdc++.h>
#include <string.h>
using namespace std;

time_t st_time,end_time;
int ok_ball = false;
float area[100][6];
int port[20]= {0,0,0,0,0,0,0,0,0,0};
bool end_scen_enable = false;

float lig_4_pos = 0;

#include "cube.h"
#include "solidball.h"
#include "ball.h"
#include "ball_position.h"
#include "lighting_effect.h"

#include "axes.h"


#include "torch.h"


#include "normal_flr.h"
#include "floor.h"
#include "fog.h"
#include "key.h"
#include "up_down_flr.h"


#include "BmpLoader.h"
#include "load_texture.h"
#include "water_flr.h"
#include "moving_flr.h"

#include "back_side.h"
#include "front_side.h"
#include "side_wall.h"
#include "rain_fall.h"
#include "road.h"
#include "thunder_effect.h"
#include "curve.h"
#include "short_way.h"
#include "score_board.h"
#include "search_light_house.h"
#include "starting_view.h"
#include "ice_hill.h"
#include "end_scene.h"
#include "finishing_flr.h"
#include "control.h"
#include "display.h"




