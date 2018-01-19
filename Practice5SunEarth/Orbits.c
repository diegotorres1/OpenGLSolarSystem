//Orbital functions for each planet
//Scale Astronomical Unit by factor of 6
//orbital velocities km/s Mer47.4	Ven35.0 	Ear29.8	  Mar24.1	Jup13.1	  Sat9.7	   
//Ura6.8	  Nep5.4  scaled by a factor of 2
#include <math.h>
#define M_PI 3.14159265358979323846
float current_Angle[8] = { 0 };
extern float x[8] = {0};
extern float y[8] = {0};
float rateMer = .948; float disMer = 2.34;
float rateVen = .7; float disVen = 4.338;
float rateEar = .596; float disEar = 6.00;
float rateMar = .482; float disMar = 9.144;
float rateJup = .261; float disJup = 31.28;
float rateSat = .194; float disSat = 57.234;
float rateUra = .136; float disUra = 115.08;
float rateNep = .108; float disNep = 180.36;

typedef struct CoordsofPlanets 
{
	float xMer; float yMer;
	float xVen; float yVen;
	float xEar; float yEar;
	float xMar; float yMar;
	float xJup; float yJup;
	float xSat; float ySat;
	float xUra; float yUra;
	float xNep; float yNep;
}Coords;
Coords CoordsPlanets = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void orbitMercury(Coords *Merc)
{
	if (current_Angle[0] >= 360)
		current_Angle[0] = 0;
	else
		current_Angle[0] += rateMer;
	x[0] = disMer * cos(current_Angle[0] * (M_PI) / (180));
	y[0] = disMer * sin(current_Angle[0] * (M_PI) / (180));
	Merc->xMer = x[0];
	Merc->yMer = y[0];

}
void orbitVenus(Coords *Venu)
{
	if (current_Angle[1] >= 360)
		current_Angle[1] = 0;
	else
		current_Angle[1] += rateVen;
	x[1] = disVen * cos(current_Angle[1] * (M_PI) / (180));
	y[1] = disVen * sin(current_Angle[1] * (M_PI) / (180));
	Venu->xVen = x[1];
	Venu->yVen = y[1];
}
void orbitEarth(Coords *Eart)
{
	if (current_Angle[2] >= 360)
		current_Angle[2] = 0;
	else
		current_Angle[2] += rateEar;
	x[2] = disEar * cos(current_Angle[2] * (M_PI) / (180));
	y[2] = disEar * sin(current_Angle[2] * (M_PI) / (180));
	Eart->xEar = x[2];
	Eart->yEar = y[2];
}
void orbitMars(Coords *Mars)
{
	if (current_Angle[3] >= 360)
		current_Angle[3] = 0;
	else
		current_Angle[3] += rateMar;
	x[3] = disMar * cos(current_Angle[3] * (M_PI) / (180));
	y[3] = disMar * sin(current_Angle[3] * (M_PI) / (180));
	Mars->xMar = x[3];
	Mars->yMar = y[3];
}
void orbitJupiter(Coords *Jupi)
{
	if (current_Angle[4] >= 360)
		current_Angle[4] = 0;
	else
		current_Angle[4] += rateJup;
	x[4] = disJup * cos(current_Angle[4] * (M_PI) / (180));
	y[4] = disJup * sin(current_Angle[4] * (M_PI) / (180));
	Jupi->xJup = x[4];
	Jupi->yJup = y[4];

}
void orbitSaturn(Coords *Satu)
{
	if (current_Angle[5] >= 360)
		current_Angle[5] = 0;
	else
		current_Angle[5] += rateSat;
	x[5] = disSat * cos(current_Angle[5] * (M_PI) / (180));
	y[5] = disSat * sin(current_Angle[5] * (M_PI) / (180));
	Satu->xSat = x[5];
	Satu->ySat = y[5];

}
void orbitUranus(Coords *Uran)
{
	if (current_Angle[6] >= 360)
		current_Angle[6] = 0;
	else
		current_Angle[6] += rateUra;
	x[6] = disUra * cos(current_Angle[6] * (M_PI) / (180));
	y[6] = disUra * sin(current_Angle[6] * (M_PI) / (180));
	Uran->xUra = x[6];
	Uran->yUra = y[6];
}
void orbitNeptune(Coords *Nept)
{
	if (current_Angle[7] >= 360)
		current_Angle[7] = 0;
	else
		current_Angle[7] += rateNep;
	x[7] = disNep * cos(current_Angle[7] * (M_PI) / (180));
	y[7] = disNep * sin(current_Angle[7] * (M_PI) / (180));
	Nept->xNep = x[7];
	Nept->yNep = y[7];
}
Coords* AllOrbits(void)
{
	orbitMercury(&CoordsPlanets);
	orbitVenus(&CoordsPlanets);
	orbitEarth(&CoordsPlanets);
	orbitMars(&CoordsPlanets);
	orbitJupiter(&CoordsPlanets);
	orbitSaturn(&CoordsPlanets);
	orbitUranus(&CoordsPlanets);
	orbitNeptune(&CoordsPlanets);
	return (&CoordsPlanets);
}

