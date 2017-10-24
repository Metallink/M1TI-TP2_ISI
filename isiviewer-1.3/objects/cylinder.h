#ifndef CYLINDER_H
#define CYLINDER_H

#include <math.h>
#include "triMesh.h"


class Cylinder : public TriMesh {


public:

    void traceVertex(float niveau);
    void traceTrianglesCercles();
    void traceTrianglesPoly(float niveau);

    Cylinder();
    Cylinder (int inc);
    virtual ~Cylinder(){};

protected:

    float m_x;
    float m_y;
    float m_z;
    float m_rayon;
    int m_inc;
    float m_angle;
    int m_niveau;

};

#endif // CYLINDER_H
