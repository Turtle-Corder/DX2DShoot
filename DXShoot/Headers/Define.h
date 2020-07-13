#pragma once

#ifndef __DEFINE_H__
#define __DEFINE_H__

#define WINCX 1280
#define WINCY 720

#define MAPCX 528
#define MAPCY 704

#define MAP_STARTX	376
#define MAP_ENDX	904
#define MAP_STARTY	9
#define MAP_ENDY	713

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

#define OBJ_DEAD 1
#define OBJ_NOEVENT 0

#endif // !__DEFINE_H__
