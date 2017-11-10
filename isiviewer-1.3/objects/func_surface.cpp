#include <math.h>
#include <time.h>
#include "func_surface.h"


// fonction contenant l'equation dans l'énoncé du TP
float func_expcos(float x, float y) {

   return exp(-(x*x/2+y*y/2))*cos(2*x*x+2*y*y);
}

// autre fonction utilisant des sinus et cos (ex bonus)
float autre_func_math (float x, float y) {

    return cos(x+2)*+sin(y*M_PI)/2*sin(x*x);
}

float func_rand(float min, float max) {

    return (rand()/(float)RAND_MAX * max*2 + min);
}

Func_surface::Func_surface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float (*pointeur)(float, float)) {

    _name ="Func_surface";

    m_nbx = nbx;
    m_nby = nby;
    m_minx = minx;
    m_maxx = maxx;
    m_miny = miny;
    m_maxy = maxy;

    float unCarre = 2*M_PI/50;//un élément de mon quadrillage


    for(float i=m_minx; i<m_maxx; i+=unCarre) { //On parcourt le quadrillage de longueur 2PI et de largeur 2PI pour créer les sommets.

        for(float j=m_miny; j<m_maxy; j+=unCarre) {

            float pointZ = pointeur(i, j);
            this->addVertex(i/m_maxx,j/m_maxy,pointZ);
        }
    }

    //Création des carrées qui composent mon quadrillage en créant des carrées à partir de deux triangles.
    for (int m = 0; m<49; m++) { //Parcours des points sur l'axe x.

        for (int n = 0; n<49; n++) { //Parcours des points sur l'axe y.

            this->addTriangle(m+n*m_nbx, (m+1)+(n+1)*m_nbx, (m+1)+n*m_nbx);
            this->addTriangle(m+n*m_nbx, m+(n+1)*m_nbx, (m+1)+(n+1)*m_nbx);
        }
    }

    computeNormalsT(); // to be fixed
    computeNormalsV(); // to be fixed
}

