/*
 * Platformer Game Engine by Wohlstand, a free platform for game making
 * Copyright (c) 2017 Vitaly Novichkov <admin@wohlnet.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OBJ_BG_H
#define OBJ_BG_H

#include <string>
#include <vector>
#include "../graphics/graphics.h"

struct obj_BG
{
    unsigned long id = 0;
    std::string name;

    std::string image_n;

    /*   OpenGL    */
    bool isInit = false;
    PGE_Texture *image = nullptr;
    GLuint textureID = 0;
    int textureArrayId = 0;
    int animator_ID = 0;
    PGEColor Color_upper;
    PGEColor Color_lower;
    /*   OpenGL    */

    unsigned int type;//convert from string
    double       repeat_h;
    unsigned int repead_v;
    unsigned int attached;
    bool editing_tiled;
    bool animated;
    unsigned int frames;
    unsigned int framespeed;
    unsigned int frame_h; //Hegth of the frame. Calculating automatically

    unsigned int display_frame;

    bool magic;
    uint32_t    magic_strips;
    std::string magic_splits;
    std::vector<uint32_t> magic_splits_i;
    std::string magic_speeds;
    std::vector<double> magic_speeds_i;

    std::string second_image_n;
    //QPixmap second_image;

    /*   OpenGL    */
    bool second_isInit;
    PGE_Texture *second_image;
    GLuint second_textureID;
    int second_textureArrayId;
    int second_animator_ID;
    PGEColor second_Color_upper;
    PGEColor second_Color_lower;
    /*   OpenGL    */

    double       second_repeat_h;
    unsigned int second_repeat_v;
    unsigned int second_attached;

};

#endif // OBJ_BG_H
