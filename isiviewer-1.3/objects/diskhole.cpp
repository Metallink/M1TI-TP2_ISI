#include "diskhole.h"

void DiskHole::traceVertex(){


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) */

    for (int i = 0; i < m_inc; i++){

        addVertex((m_rayon*cos(i*(m_angle))),(m_rayon*sin(i*(m_angle))),m_z);
    }
}

void DiskHole::traceTriangles() {

    float p1,p2,p3;

    for (int i = 0; i < 1; i++) {

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
}


DiskHole::DiskHole (float rayon, int inc) {

    _name = "DiskHole";
    m_x = 0.f;
    m_y = 0.f;
    m_z = 0.f;

    // on ajoute l'origine des cercles en (0,0,0)
    addVertex(m_x,m_y,m_z);

    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;

    /* ===== construction du premier disque, le plus petit ====== */

    // calcul de l'angle
    m_angle = ((2*M_PI)/m_inc);

    // on vérifie que l'on a pas un rayon > à 1 et négatif/non nul
    if (rayon > 1.f) {
        m_rayon = 1.f;
    } else if (rayon <= 0.f) { // si valeur rayon invalide, on impose un minimum qui est 0.2
        m_rayon = 0.2f;
    } else {
        m_rayon = rayon;
    }

    // on considére que le rayon du plus petit cercle sera égale à la moitié du plus grand.
    m_rayon/=2.f;
    // on ajoute les sommets du petit cercle
    traceVertex();

    /* ====== construction du deuxieme disque, le plus grand ====== */

    // on revient au rayon d'origine
    m_rayon*=2;
    // on ajoute les sommets
    traceVertex();

    // tracons les triangles maintenant en reliant les sommets du petit et grand disque
    this->traceTriangles();


    computeNormalsT(); // to be fixed
    computeNormalsV(); // to be fixed
}
