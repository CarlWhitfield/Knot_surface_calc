//Constants.h
#include <string>
#define FROM_PHI_FILE 0
#define FROM_SURFACE_FILE 1
#define FROM_UV_FILE 2
#define FROM_FUNCTION 3
// the different boundary conditions
enum BoundaryType {ALLREFLECTING, ZPERIODIC, ALLPERIODIC};

/* CHANGE THESE OPTIONS */

// OPTION - // what kind of initialisation
/* the different initialisation options
Available options:
FROM_PHI_FILE: Skip initialisation, input from previous run.
FROM_SURFACE_FILE: Initialise from input file(s) generated in surface evolver.
FROM_UV_FILE: Skip initialisation, run FN dynamics from uv file
FROM_FUNCTION: Initialise from some function which can be implemented by the user in phi_calc_manual. eg using theta(x) = artcan(y-y0/x-x0) to give a pole at x0,y0 etc..:wq
 */
//if ncomp > 1 (no. of components) then component files should be separated to 'XXXXX.txt" "XXXXX2.txt", ....
const int option = FROM_UV_FILE;         //unknot default option
std::string knot_filename = "five1";      //if FROM_SURFACE_FILE assumed input filename format of "XXXXX.stl"
std::string B_filename = "uv_plot0.vtk";    //filename for phi field or uv field

// OPTION - what kind of boundary condition
const BoundaryType BoundaryType=ALLREFLECTING;

//OPTION - do you want the geometry of the input file to be exactly preserved, or can it be scaled to fit the box better
#define PRESERVE_RATIOS 1  //1 to scale input file preserving the aspect ratio

// OPTION - how long should it run, when do you want data printed, what time value should it start at 
const double TTime = 10000;       //total time of simulation (simulation units)
const double skiptime = 1;       //print out every # unit of time (simulation units)

// OPTION - what grid values do you want/ timestep
//Grid points
const double h = 0.5;            //grid spacing
const int initialNx = 256;   //No. points in x,y and z
const int initialNy = 256;
const int initialNz = 128;
// timestep
const double dtime = 0.02;         //size of each time step

// OPTION - how big should the knot be in the box, do you want it tilted or displaced?
//Size boundaries of knot (now autoscaled)
double xmax = 3*initialNx*h/4.0;
double ymax = 3*initialNy*h/4.0;
double zmax = 3*initialNz*h/4.0;
/** two rotation angles for the initial stl file, and a displacement vector for the file **/
const double initialthetarotation = 0;
const double initialphirotation = 0;
const double initialxdisplacement = 0;
const double initialydisplacement = 0;
const double initialzdisplacement = 0;

// OPTION - what system params do you want . Don't touch these usually
//System size parameters
const double lambda = 21.3;                //approx wavelength
const double epsilon = 0.3;                //parameters for F-N eqns
const double beta = 0.7;
const double gam = 0.5;
