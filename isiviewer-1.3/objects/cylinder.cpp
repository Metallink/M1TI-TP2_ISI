#include "cylinder.h"


void Cylinder::traceVertex(float niveau){


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) */

    for (int i= 1; i < m_inc+1; i++){

        addVertex((m_rayon*cos(i*(m_angle))), (m_rayon*sin(i*(m_angle))), niveau);
    }
    //addVertex(m_x, m_y, m_z);
}

void Cylinder::traceTrianglesCercles() {

    for(int i = 0; i<m_inc; i++){

        addTriangle(m_inc,i%m_inc,(i+1)%m_inc);

    }
}

void Cylinder::traceTrianglesPoly (float niveau) {

    float p1;
    float p2;
    float p3;

    for (int i = 0; i < niveau; i++) {

        for (int j = 0; j < m_inc; j++) {

            p1 = (j % m_inc + m_inc * i + 1);
            p2 = j % m_inc + m_inc * (i + 1) + 1;
            p3 = ((j + 1) % m_inc + m_inc * i + 1);
            addTriangle(p1, p2, p3);

            p1 = (j % m_inc + m_inc * (i + 1) + 1);
            p2 = ((j + 1) % m_inc + m_inc * (i + 1) + 1);
            p3 = ((j + 1) % m_inc + m_inc * i + 1);
            addTriangle(p1, p2, p3);
        }
    }

    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}


// CONSTRUCTEUR
Cylinder::Cylinder (int inc) {

    _name = "Cylinder";
    m_x = 0.f;
    m_y = 0.f;
    m_z = -1.f;
    m_rayon = 1.f;
    m_niveau = 4;

    addVertex(m_x, m_y, m_z);

    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;

    //m_angle = ((2*M_PI)/m_inc);

    // IMPRO
    //this->addVertex(0.f,0.f,-1.f); // centre du cercle du "bas"

    for (float niveau = -1.f; niveau <= 1.00001f; niveau+=0.5f) {

        //rez l'angle
        m_angle = ((2*M_PI)/m_inc);
        // calcule des sommets par niveau
        traceVertex(niveau);
    }

    // ajout du dernier point
    //this->addVertex(0.f,0.f,1.f); // centre du cercle du "haut"

    // on trace le premier cercle, celui du bas
    //this->traceTrianglesCercles();

    // on trace les triangles du polygone qui fait le tour du cylindre
    this->traceTrianglesPoly(m_niveau);

    // on trace le cercle du haut
    this->traceTrianglesCercles();


    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}


// 1-0.5 = 0.5
// 0.5-0.5 = 0
// -0.5
// -1
