#ifndef __WATER_H__
#define __WATER_H__
#define __DEBUG_GL_H__
/**
 * @file
 * Programmlogik und Datenhaltung
 *
 * @author Maurice Tollmien
 */

/* ---- System Header einbinden ---- */
#ifdef WIN32
#include <windows.h>
#endif

#ifdef MACOSX
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

#include <stdio.h>
#include <stdarg.h>

#include "types.h"
#include "terrain.h"

#define WATER_HEIGHT_INIT	0

Water * getWaterList(void);
void initWater(void);
GLuint * getWaterIndices (void);

#endif

