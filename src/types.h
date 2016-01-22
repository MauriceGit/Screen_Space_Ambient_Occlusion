#ifndef __TYPES_H__
#define __TYPES_H__

/**
 * @file
 * Typenschnittstelle.
 * Das Modul kapselt die Typdefinitionen und globalen Konstanten des Programms.
 *
 * @author Maurice Tollmien
 */

/* ---- System Header einbinden ---- */
#ifdef WIN32
#include <windows.h>
#endif

#ifdef MACOSX
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

/* ---- Eigene Konstanten */

#define GROUND_HEIGHT	0.3

#define CAMERA_X        -50.1
#define CAMERA_Y        50.0
#define CAMERA_Z        75.0
#define CAMERA_SPEED    15.0

#define WAVE_SPEED		1.0

#define MULTIPLIER_DELTA	0.5
#define MAX_MULTIPLIER	25
#define MIN_MULTIPLIER	1

#define RANGE_DELTA		1
#define MAX_RANGE		15
#define MIN_RANGE		1

#define PIXEL_DISTANCE_DELTA	2
#define PIXEL_DISTANCE_MIN	1
#define PIXEL_DISTANCE_MAX	40

#define CAMERA_MOVEMENT_SPEED	4.0
#define CAMERA_ZOOM_SPEED 10.0

#define WORLD_SIZE 150

#define PI             3.14159265  
#define EPS		0.0001

/** Anzahl der Aufrufe der Timer-Funktion pro Sekunde */
#define TIMER_CALLS_PS      120

/* Text */
/** Textausgabe, wenn das SPIEel zu ende ist, weil kein Stein mehr verfuegbar ist */
#define HELP_OUTPUT_1       "====== U'r blinded by pure AWESOMENESS!!!!! ======"
#define HELP_OUTPUT_2       "|________________________________________________|"
#define HELP_OUTPUT_3       "q/Q/Esc    Beendet die Demo."
#define HELP_OUTPUT_4       "w/W        Veraendert den Typ der Welle (X-Y-Richungen/Diagonal/Aus)."
#define HELP_OUTPUT_5       "h/H        Oeffnet/schliesst den Hilfemodus."
#define HELP_OUTPUT_6       "+/-        Veraendert die Range, in der Ambient-Occlusion durchgefuehrt wird (linear zu #Pixel-Checks)."
#define HELP_OUTPUT_7       "Up/Down    Veraendert den Multiplier und damit die Intensität der Occlusion."
#define HELP_OUTPUT_8       "Left/Right Veraendert die Pixeldistanz, also die jew. wievielten Pixel betrachtet werden."
#define HELP_OUTPUT_9       "s/S        Schaltet zwischen den drei Ansichten (Ambient-Occlusion, Textur, Textur + Ambient-Occlusion) um."
#define HELP_OUTPUT_10      "f1         Schaltet den Wireframe-Modus ein/aus."
#define HELP_OUTPUT_11      "Maus-L     Kamerabewegung in einer Kugel um den Szenenmittelpunkt."
#define HELP_OUTPUT_12      "Maus-R     Kamerabewegung als Zoom vom/zum Szenenmittelpunkt."

/* Tastatur */
/** Keyboardtaste ESC definieren */
#define ESC     27
/** Keyboardtaste SPACE definieren */
#define SPACE   32

/** Datentyp fuer  den aktuellen SPIEelmodus */
enum e_gameIntiType { OFF, ON };
typedef enum e_gameIntiType InitType;

/** Mausereignisse. */
enum e_MouseEventType
{ mouseButton, mouseMotion, mousePassiveMotion };
/** Datentyp fuer Mausereignisse. */
typedef enum e_MouseEventType CGMouseEventType;

/** Mausereignisse. */
enum e_MouseInterpretType
{ NONE, MOVE, ZOOM};
/** Datentyp fuer Mausereignisse. */
typedef enum e_MouseInterpretType MouseInterpretType;

/** Datentyp fuer  den aktuellen SPIEelmodus */
enum e_gameModi { normal, help };
typedef enum e_gameModi GameMode;

/** Datentyp fuer die Verlaengerung/Verkuerzung des Kameravektors */
enum e_cameraVector { xAxis, xAxisNeg, zAxis, zAxisNeg, diagonal, diagonalNeg, nothing};
typedef enum e_cameraVector WaveDirection;

enum e_waveDir { closer, further };
typedef enum e_waveDir CameraVector;

/** Punkt im 3D-Raum (homogene Koordinaten) */
typedef GLfloat CGPoint4f[4];
typedef GLfloat CGPoint3f[3];

/** Datentyp fuer einen Vektor */
typedef double Vector4D[4];

/** Vektor im 3D-Raum */
typedef GLfloat CGVector3D[3];

typedef int Movement[3];

typedef struct {
	GLfloat x,y,z;
	GLfloat s,t;
	GLfloat nx, ny, nz;
	GLint fix;
} Water;

typedef struct {
	GLfloat x,y,z;
	GLfloat s,t;
	GLfloat nx, ny, nz;
} Terrain;


#endif
