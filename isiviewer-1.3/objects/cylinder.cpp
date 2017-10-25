#include "cylinder.h"


void Cylinder::traceVertex (float niveau){


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) */

    for (int i = 0; i < m_inc; i++){

        addVertex((m_rayon*cos(i*(m_angle))), (m_rayon*sin(i*(m_angle))), niveau);
    }
}

void Cylinder::traceTrianglesBase() {

    for(int i = 0; i<m_inc; i++){

        addTriangle(0.f,i%m_inc+1,(i+1)%m_inc+1);
    }
}

void Cylinder::traceTrianglesCentre () {

    float p1,p2,p3;

    for (int niveau = 0; niveau < m_niveau; niveau++) {

        for (int i = 0; i < m_inc; i++) {

            p1 = (i % m_inc + m_inc * niveau + 1);
            p2 = i % m_inc + m_inc * (niveau + 1) + 1;
            p3 = ((i+1) % m_inc + m_inc * niveau + 1);
            addTriangle(p1, p2, p3);

            p1 = (i % m_inc + m_inc * (niveau + 1) + 1);
            p2 = ((i + 1) % m_inc + m_inc * (niveau + 1) + 1);
            p3 = ((i + 1) % m_inc + m_inc * niveau + 1);
            addTriangle(p1, p2, p3);
        }
    }
}

void Cylinder::traceTrianglesHaut() {

    // le centre du cercle est le dernier sommet que l'on a ajouté au vector de sommets (ici 251)
    int centre = (m_niveau+1)*m_inc+1;
    // les sommets de la base sont les m_inc avant-derniers sommets, le dernier étant le centre du cercle de base (ici de 200 à 250)
    int rangeSommets = centre-m_inc;

    for(int i = 0; i<m_inc; i++){

        addTriangle(centre,(i+1)%m_inc+rangeSommets,i%m_inc+rangeSommets);
    }
}


Cylinder::Cylinder (int inc) {

    _name = "Cylinder";
    m_x = 0.f;
    m_y = 0.f;
    m_z = -1.f;
    m_rayon = 1.f;
    // je considere qu'il y a 4 "niveaux" dans ce polygone
    m_niveau = 4;

    // on ajoute le premier sommet qui sera le centre du cercle du "bas"
    addVertex(m_x, m_y, m_z);

    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;

    m_angle = ((2*M_PI)/m_inc);

    // nous avons 5 niveaux par palier de +0.5 (ici -1,-0.5,0,+0.5 et +1)
    for (float niveau = -1.f; niveau <= 1.f; niveau+=0.5f) {

        // calcule des sommets par niveau
        traceVertex(niveau);
        // donc niveau 0 (cercle du bas du cylindre) -> sommets 0(centre) à 50)
        // donc niveau 1 -> sommets 51 à 100)
        // etc..
        // niveau 5 (cercle du haut) -> sommets 200 à 251
    }

    m_z=1.f;
    // ajout du dernier point qui sera le centre du cercle du "haut" en 0 0 1
    this->addVertex(m_x,m_y,m_z);

    // on trace le premier cercle, celui du bas
    this->traceTrianglesBase();

    // on trace les triangles du polygone de la partie centrale du cylindre
    this->traceTrianglesCentre();

    // on trace le cercle du haut
    this->traceTrianglesHaut();


    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed
}
