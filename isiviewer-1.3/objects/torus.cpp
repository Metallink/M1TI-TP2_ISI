#include "torus.h"

Torus::Torus (int inc) {

    _name = "Torus";

    // on doit avoir un nb de points de 60 au minimum
    m_inc = inc < 60 ? 60 : inc;

    float angle= 2*M_PI/m_inc;


    for(float i=0; i<2*M_PI; i+=angle) { //création des vertexs à partir de la fonction mathématique pour faire le torus

        for(float j=0; j<2*M_PI; j+=angle) {

            float pointZ = (M_PI/2)*sin(j);
            this->addVertex((M_PI+(M_PI/2)*cos(j))*cos(i)/5, (M_PI+(M_PI/2)*cos(j))*sin(i)/5, pointZ/5);

        }

    }


    for(int ii=0; ii<m_inc; ii++) {

        for(int jj=0; jj<m_inc; jj++){

            this->addTriangle(ii+jj*(m_inc+1),(ii+1)+(jj+1)*(m_inc+1), (ii+1)+jj*(m_inc+1));
            this->addTriangle(ii+jj*(m_inc+1), ii+(jj+1)*(m_inc+1),(ii+1)+(jj+1)*(m_inc+1));
        }

    }

    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}

