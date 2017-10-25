#include "disk.h"


void Disk::traceVertex() {


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) */

    for (int i=0; i < m_inc; i++){

        addVertex((m_rayon*cos(i*(m_angle))),(m_rayon*sin(i*(m_angle))),m_z);
    }

    // on ajoute l'origine du cercle en 0 0 0
    addVertex(m_x,m_y,m_z);
}

void Disk::traceTriangles() {

    for(int i=0; i<m_inc; i++){

        addTriangle(m_inc,i%m_inc,(i+1)%m_inc);
    }
}


// CONSTRUCTEUR
Disk::Disk (int inc) {

    _name = "Disk";
    m_x = 0.f;
    m_y = 0.f;
    m_z = 0.f;
    m_rayon = 1.f;

    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;

    m_angle = ((2*M_PI)/m_inc);

    // construction des sommets
    traceVertex();
    // construction des triangles
    traceTriangles();


    computeNormalsT(); // to be fixed
    computeNormalsV(); // to be fixed
}
