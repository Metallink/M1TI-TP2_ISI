#include "cone.h"


void Cone::traceVertex() {


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) */

    for (float niveau = 0.5f; niveau >= -1.f; niveau -= 0.5f) {

        for (int i= 0; i < m_inc; i++){

            m_angle = 2*M_PI/m_inc;
            addVertex((m_rayon*cos(i*m_angle)),(m_rayon*sin(i*m_angle)), niveau);
        }
        m_rayon+=0.25f;
    }
}

void Cone::traceTrianglesHaut() {

    for(int i = 0; i<m_inc; i++){

        // on trace les triangles (0,1,2) (0,2,3) etc... avec 0 le sommet "pointe" du cone
        addTriangle(0.f,i%m_inc+1,(i+1)%m_inc+1);
    }
}


void Cone::traceTrianglesMilieu() {

    int point1Bas, point2Bas, pointHaut;
    // m_niveau-1 car je m'occupe des niveaux 1(base), 2 et 3. (le 4 etant deja fait avec la fonction traceTrianglesHaut)
    for(int niveau = 0; niveau<(m_niveau-1); niveau++){

        for (int i = 0; i<m_inc; i++) {
            // voir schema pour explication
            point1Bas = i%m_inc+m_inc*niveau+1;
            point2Bas = i%m_inc+m_inc*(niveau+1)+1;
            pointHaut = (i+1)%m_inc+m_inc*niveau+1;
            addTriangle(point1Bas, point2Bas, pointHaut);

            point1Bas = i%m_inc+m_inc*(niveau+1)+1;
            point2Bas = (i+1)%m_inc+m_inc*(niveau+1)+1;
            pointHaut = (i+1)%m_inc+m_inc*niveau+1;
            addTriangle(point1Bas, point2Bas, pointHaut);
        }
    }

}

void Cone::traceTrianglesBase() {

    // le centre du cercle est le dernier sommet que l'on a ajouté au vector de sommets (ici 201)
    int centre = m_niveau*m_inc+1;
    // les sommets de la base sont les m_inc avant-derniers sommets, le dernier étant le centre du cercle de base (ici de 150 à 200)
    int rangeSommets = centre-m_inc;

    for(int i = 0; i<m_inc; i++){

        // trace triangles du cercle de base: ici triangle (201,150,151) (201,151,152) etc...
        addTriangle(centre,i%m_inc+rangeSommets,(i+1)%m_inc+rangeSommets);
    }
}


Cone::Cone (int inc) {


    _name = "Cone";
    m_x = 0.f;
    m_y = 0.f;
    m_z = 1.f;
    m_rayon = 0.25f;
    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;
    // je considere qu'il y a 4 "niveaux" dans ce polygone
    m_niveau = 4;
    m_angle = ((2*M_PI)/m_inc);

    //on ajoute le sommet qui sera la "pointe" de notre cone
    addVertex(m_x,m_y,m_z);
    // on ajoute tous les sommets du cone
    traceVertex();
    m_z = -1.f;
    //on ajoute l'origine du cercle qui est la base du cone en 0 0 -1
    addVertex(m_x,m_y,m_z);
    //on trace le cone du "haut"
    traceTrianglesHaut();

    traceTrianglesMilieu();
    //on referme le cercle en tracant le cercle du bas
    traceTrianglesBase();

    // on dessine les normales
    computeNormalsT(); // to be fixed
    computeNormalsV(); // to be fixed
}

