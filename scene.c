
/**
 * @file
 * Hier wird vll gezeichnet...
 *
 * @author Maurice Tollmien, Tilman Nedele
 */

/* ---- System Header einbinden ---- */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stringOutput.h>

#ifdef MACOSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <GL/glu.h>

/* ---- Eigene Header einbinden ---- */
#include "scene.h"
#include "logic.h"
#include "types.h"
#include "water.h"
#include "terrain.h"
#include "vector.h"


/* ---- Globale Variablen für die Farben der Wände ------ */
float G_R;
float G_G;
float G_B;
float G_Alpha;
float G_Shininess;
int G_Emission;


/* ---- Funktionen ---- */

/**
 * Wird aufgerufen, wenn "h" gedrückt worden ist.
 * Gibt einen Text auf einem schwarzen Hintergrund auf dem Bildschirm aus
 */
void printHelp (void)
{
    /* Textfarbe */
    GLfloat textColor[3] = { 0.0f, 0.0f, 0.0f };

    drawString (0.1f, 0.1f, textColor, HELP_OUTPUT_1);
    drawString (0.1f, 0.125f, textColor, HELP_OUTPUT_2);
    drawString (0.1f, 0.148f, textColor, HELP_OUTPUT_3);
    drawString (0.1f, 0.171f, textColor, HELP_OUTPUT_4);
    drawString (0.1f, 0.194f, textColor, HELP_OUTPUT_5);
    drawString (0.1f, 0.217f, textColor, HELP_OUTPUT_6);
    drawString (0.1f, 0.240f, textColor, HELP_OUTPUT_7);
    drawString (0.1f, 0.263f, textColor, HELP_OUTPUT_8);
    drawString (0.1f, 0.286f, textColor, HELP_OUTPUT_9);
    drawString (0.1f, 0.311f, textColor, HELP_OUTPUT_10);
    drawString (0.1f, 0.336f, textColor, HELP_OUTPUT_11);
    drawString (0.1f, 0.361f, textColor, HELP_OUTPUT_12);

}

void drawFPS (void)
{
	GLfloat textColor[3] = { 1.0f, 1.0f, 1.0f };
	char * string = calloc ((strlen ("FPS = ") + 4), sizeof(char));
	sprintf(string, "FPS = %d", getFPS());
	
	drawString (0.6, 0.1, textColor, string);
	
	free (string);
}

void drawAttributes(void) {
	GLfloat textColor[3] = { 1.0f, 1.0f, 1.0f };
	char * string1 = calloc ((strlen ("Range      = ") + 4), sizeof(char));
	char * string2 = calloc ((strlen ("Multiplier = ") + 4), sizeof(char));
	char * string3 = calloc ((strlen ("PixelDist  = ") + 4), sizeof(char));
	sprintf(string1, "Range      = %d", getRange());
	sprintf(string2, "Multiplier = %f", getMultiplier());
	sprintf(string3, "PixelDist  = %d", getPixelDistance());
	
	drawString (0.6, 0.13, textColor, string1);
	drawString (0.6, 0.16, textColor, string2);
	drawString (0.6, 0.19, textColor, string3);
	
	free (string1);
	free (string2);
	free (string3);
}

/**
 * Initialisierung der Lichtquellen.
 * Setzt Eigenschaften der Lichtquellen (Farbe, Oeffnungswinkel, ...)
 */
static void initLight (void)
{

    /* Farbe der zweiten Lichtquelle */
	CGPoint4f lightColor1[3] =
	{ {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f,
														   1.0f}
	};
    
    /* Farbe der ersten Lichtquelle */
    CGPoint4f lightColor2[3] =
    { {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f,
                                                           1.0f}
    };
    
	/* Oeffnungswinkel der zweiten Lichtquelle */
	GLdouble lightCutoff1 = 90.0f;
	/* Lichtverteilung im Lichtkegel der zweiten Lichtquelle */
	GLdouble lightExponent1 = 20.0f;
    
    float globalAmbientLight[] = {0.3, 0.3, 0.3, 1.0};
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);
    
    /* Farbe der zweiten Lichtquelle setzen */
	glLightfv (GL_LIGHT1, GL_AMBIENT, lightColor1[0]);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, lightColor1[1]);
	glLightfv (GL_LIGHT1, GL_SPECULAR, lightColor1[2]);
    
    /* Spotlight-Eigenschaften der zweiten Lichtquelle setzen */
	glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, lightCutoff1);
	glLightf (GL_LIGHT1, GL_SPOT_EXPONENT, lightExponent1);
    
    /* Farbe der zweiten Lichtquelle setzen */
	glLightfv (GL_LIGHT2, GL_AMBIENT, lightColor2[0]);
	glLightfv (GL_LIGHT2, GL_DIFFUSE, lightColor2[1]);
	glLightfv (GL_LIGHT2, GL_SPECULAR, lightColor2[2]);
	
	/* Spotlight-Eigenschaften der zweiten Lichtquelle setzen */
	glLightf (GL_LIGHT2, GL_SPOT_CUTOFF, lightCutoff1);
	glLightf (GL_LIGHT2, GL_SPOT_EXPONENT, lightExponent1);
}

/**
 * Bei SPIEelbegin wird das SPIEelfeld komplett initialisiert
 * mit einem Hintergrund, einer Zeichenfarbe, Linienbreite.
 * Außerdem wird die Datenhaltung initialisiert (siehe initField (), initStones ()).
 * @return Ob ein Fehler aufgetreten ist.
 */
int initScene (void)
{
	glEnable (GL_DEPTH_TEST);
	glCullFace (GL_BACK);
	glEnable (GL_CULL_FACE);
	glEnable (GL_NORMALIZE);
	glEnable (GL_LIGHTING);
	initLight ();
	initGame ();

	return 1;
}



/**
 * (De-)aktiviert den Wireframe-Modus.
 */
void
toggleWireframeMode (void)
{
    /* Flag: Wireframe: ja/nein */
    static GLboolean wireframe = GL_FALSE;

    /* Modus wechseln */
    wireframe = !wireframe;

    if (wireframe)
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
}

