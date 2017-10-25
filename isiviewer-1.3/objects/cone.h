#ifndef CONE_H
#define CONE_H

#include "triMesh.h"
#include <math.h>


class Cone : public TriMesh {

public:

    Cone(int);
    virtual ~Cone(){};
    void traceVertex();
    void traceTrianglesHaut();
    void traceTrianglesMilieu();
    void traceTrianglesBase();

protected:

    float m_x;
    float m_y;
    float m_z;

    float m_rayon;
    float m_angle;
    int m_inc;
    int m_niveau;
};

#endif // CONE_H
