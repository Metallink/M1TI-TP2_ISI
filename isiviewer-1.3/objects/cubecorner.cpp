#include "cubecorner.h"

CubeCorner::CubeCorner() : TriMesh() {

    _name = "CubeCorner";

    // vertex coordinates
    static const GLfloat v[14][3] = {
        {-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}, // 0-3
        {-1,-1, 1},{-1,1, 1},{1,1, 1},{1,-1, 1}, // 4-7
        {0,1,1},{1,0,1},{1,1,0}, //vertex corner angle / 8-10
        {0,0,1}, //avant / 11
        {1,0,0}, //droite / 12
        {0,1,0} //haut / 13
    };

    // triangles vertex indices
    static const GLint t[20][3] = {
        {1,2,0},{3,0,2},  // bottom triangles
        /*{1,5,6},{2,1,6},{2,6,3},{3,6,7}*/{3,7,0},{0,7,4},{0,4,1},{1,4,5},{7,3,2},{2,5,1},    // side triangles
        {4,7,5},/*{7,6,5}*/   // top triangles
        {8,9,10}, // corner triangle
        {5,11,8},{8,11,9},{9,11,7}, // remplissage de la face avant
        {7,9,12},{9,12,10},{10,12,2}, // remplissage de la face de droite
        {5,8,13},{8,13,10},{10,13,2}, // remplissage de la face du haut
    };

    // triangle normals
    static const GLint nt[12][3] = {
        {0,0,-1},{0,0,-1}, // bottom triangle normals
        {0,1,0},{0,1,0},{1,0,0},{1,0,0},{0,-1,0},{0,-1,0},{-1,0,0},{-1,0,0}, // side triangle normals
        {0,0,1},{0,0,1}    // top triangle normals
    };

    // triangle vertex normals
    static const GLint nv[36][3] = {
        {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1}, // bottom triangle vertex normals

        {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},       // side triangle vertex normals
        {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
        {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
        {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},

        {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}        // top triangle vertex normals
    };


    //--- Fill vertices and triangles vectors

    // Fill vertices vector
    for (int i=0; i<14 ; ++i)
        this->addVertex(v[i][0], v[i][1], v[i][2]);

    // Fill triangles vector
    for (int i=0; i<20; ++i)
        this->addTriangle(t[i][0], t[i][1], t[i][2]);

    // Fill normals vectors
    bool use_computed_normals = false;

    if (use_computed_normals) {

        computeNormalsT();  // to be fixed
        computeNormalsV();  // to be fixed

    } else { // use manually defined normals

        // set triangle normals
        for (int i=0; i<8; ++i) {
            Normal nT(nt[i][0], nt[i][1], nt[i][2]);
            this->addNormalT(nT);
        }
        // set triangle vertex normals
        for (int i=0; i<36; ++i) {
            Normal nV(nv[i][0], nv[i][1], nv[i][2]);
            this->addNormalV(nV);
        }
    }

}
