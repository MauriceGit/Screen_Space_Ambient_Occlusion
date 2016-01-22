
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
/* ---- Eigene Header einbinden ---- */
#include "water.h"
#include "logic.h"
#include "vector.h"
#include "types.h"
#include "terrain.h"

Water * G_WaterList;
Water * G_TmpWaterList;
float ** G_V;

GLuint * G_WaterIndices;

int normalList = 1;

Water * getWaterList(void){
	return G_WaterList;
}

GLuint * getWaterIndices (void) 
{
	return G_WaterIndices;
}

void initWaterIndices(void) {
	
	int i,j;
	int index = 0;
	for (i=0;i<WORLD_SIZE*WORLD_SIZE;i++) {		
		int atI = i % WORLD_SIZE;
		int atJ = i / WORLD_SIZE;
		
		if (atI == WORLD_SIZE-1 || atJ == WORLD_SIZE-1) {
			continue;
		}
		
		G_WaterIndices[index]   = i;
		G_WaterIndices[index+1] = i+1;
		G_WaterIndices[index+2] = i+WORLD_SIZE+1;
		
		G_WaterIndices[index+3] = i;
		G_WaterIndices[index+4] = i+WORLD_SIZE+1;
		G_WaterIndices[index+5] = i+WORLD_SIZE;
		
		index += 6;			
	}
	
}

void initWater(void) {
	
	int i,j;
	
	G_V = calloc(WORLD_SIZE, sizeof(*G_V));
	G_WaterList = calloc(WORLD_SIZE*WORLD_SIZE, sizeof(*G_WaterList));
	G_TmpWaterList = calloc(WORLD_SIZE*WORLD_SIZE, sizeof(*G_TmpWaterList));
	G_WaterIndices = calloc(WORLD_SIZE*WORLD_SIZE*2*3, sizeof(*G_WaterIndices));
	
	for (i=0;i<WORLD_SIZE;i++) {
		G_V[i] = calloc(WORLD_SIZE, sizeof(**G_V));
	}
	
	for (i=0;i<WORLD_SIZE*WORLD_SIZE;i++) {
		int xCoord = i / WORLD_SIZE;
		int zCoord = i % WORLD_SIZE;
		
		G_WaterList[i].x = xCoord - WORLD_SIZE/2;
		G_WaterList[i].y = WATER_HEIGHT_INIT;
		G_WaterList[i].z = zCoord - WORLD_SIZE/2;
		
		G_WaterList[i].s = (float)xCoord / (float)WORLD_SIZE;
		G_WaterList[i].t = (float)zCoord / (float)WORLD_SIZE;
		
		G_WaterList[i].nx = 0.0;
		G_WaterList[i].ny = 1.0;
		G_WaterList[i].nz = 0.0;
		
		G_WaterList[i].fix = 0;
		
		G_TmpWaterList[i].x = G_WaterList[i].x;
		G_TmpWaterList[i].y = G_WaterList[i].y;
		G_TmpWaterList[i].z = G_WaterList[i].z;
		
		G_TmpWaterList[i].s = G_WaterList[i].s;
		G_TmpWaterList[i].t = G_WaterList[i].t;		
		
		G_TmpWaterList[i].nx = G_WaterList[i].nx;		
		G_TmpWaterList[i].ny = G_WaterList[i].ny;		
		G_TmpWaterList[i].nz = G_WaterList[i].nz;	
		
		G_TmpWaterList[i].fix = 0;	
		
		G_V[xCoord][zCoord] = 0.0;
		
		
	}
	
	initWaterIndices();	
}
