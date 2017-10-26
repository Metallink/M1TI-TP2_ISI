#include "sphere.h"


/*
 * http://www2.math.umd.edu/~petersd/241/html/ex25.html
 * https://fr.wikipedia.org/wiki/Coordonn%C3%A9es_sph%C3%A9riques */


void Sphere::traceVertex() {


    /* le point x se calcule suivant la formule suivante: x = rayon * cos (theta) * sin (phi)
     * le point y se calcule suivant la formule suivante: y = rayon * sin (theta) sin (phi)
     * le point z se calcule suivant la formule suivante: z = rayon * cos (phi) */

    float x, y, z;

    for(int niveau=1; niveau<m_inc; niveau++){

        /* rez l'angle phi à chaque itération de niveau */
        m_angle_phi = PI/m_inc;

        for(int i=0; i < m_inc; i++){

            x = m_rayon*cos(i*m_angle_theta)*sin(niveau*m_angle_phi);
            y = m_rayon*sin(i*m_angle_theta)*sin(niveau*m_angle_phi);
            z = m_rayon*cos (niveau*m_angle_phi);

            addVertex(x,y,z);
        }
    }
}

void Sphere::traceTrianglesHaut() {

    for(int i = 0; i<m_inc; i++){

        /* on trace les triangles (0,1,2) (0,2,3) etc... avec 0 le sommet "pole nord" de la sphere */
        addTriangle(0.f,i%m_inc+1,(i+1)%m_inc+1);
    }
}


void Sphere::traceTrianglesCentre () {

    float p1,p2,p3;

    for (int niveau = 0; niveau < m_inc-2; niveau++) {

        for (int i = 0; i < m_inc; i++) {
            // voir schema pour explication
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

void Sphere::traceTrianglesBas() {

    int centre = m_inc*(m_inc-1)+1;
    int rangeSommets = centre -m_inc;

    for(int i = 0; i<m_inc; i++){

        /* on trace les triangles (0,1,2) (0,2,3) etc... avec 0 le sommet "pole nord" de la sphere */
        addTriangle(centre,(i+1)%m_inc+rangeSommets,i%m_inc+rangeSommets);
    }
}


Sphere::Sphere (int inc) {

    _name = "Sphere";
    m_x = 0.f;
    m_y = 0.f;
    m_z = 1.f;
    m_rayon = 1.f;

    // la valeur de résolution doit être d'au minimum 4 et au plus inc
    m_inc = inc < 4 ? 4 : inc;

    // pour la sphere nous avons besoin de 2 angles theta et phi qui varient respecivement entre -2pi/2pi et -pi/pi
    m_angle_theta = ((2*M_PI)/m_inc);
    m_angle_phi = M_PI/m_inc;


    // on ajoute le premier sommet qui sera le sommet "pole nord"
    addVertex(m_x,m_y,m_z);

    // on met en place tous les sommets
    traceVertex();

    // on ajoute le dernier sommet qui sera le sommet "pole sud"
    m_z = -1.f;
    addVertex(m_x,m_y,m_z);

    // on trace le disque au premier "niveau", celui qui a pour centre le sommet "pole nord"
    traceTrianglesHaut();
    // on trace les triangles du contour de la sphere. Cela se fait par niveau du haut vers le bas jusq'à m_inc-1 niveau
    traceTrianglesCentre();
    // on trace le disque du dernier niveau, celui du "pole sud"
    traceTrianglesBas();

    computeNormalsT();  // to be fixed
    computeNormalsV();  // to be fixed

    //std::cout << this->_vertices.size() <<  endl; // pour voir le rang du dernier sommet ajouté


}

