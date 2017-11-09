#include "off_loader.h"

#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;


off_loader::off_loader () {

    _name = "OffLoader";

    string fileName = "../isiviewer-1.3/data/venus.off";
    string motLu, charLu, ligneLu;
    int numeroLigne = 0, nbVertex = 0, n = 0, tmp_n = 0;
    vector<float> tabCoordBuffer;
    vector<Vertex> tabVertexBuffer;
    vector<int> tabBufferTriangles;
    float pointVertex;
    Vertex uneVertex;
    Triangle unTriangle;


    // on ouvre le fichier
    ifstream fichierFigure((char*)fileName.c_str());

    if (fichierFigure) { // ouverture du fichier réussi

        cout << "OUVERTURE REUSSI" << endl;

        // on vérifie qu'il s'agit bien d'un fichier .off en lisant OFF dès la première ligne
        getline(fichierFigure, motLu);

        // getline() prends toute la ligne, il nous faut juste les 3 premieres lettres
        motLu = motLu.substr(0,3);

        if (strcmp(motLu.c_str(), "OFF") == 0) { // on est bien dans un fichier OFF

            // nous allons récupérer les infos ligne par ligne jusq'à EOF
            while (getline(fichierFigure, ligneLu)) {

                // j'utilise le flux de chaine de car istringstream pour decomposer la ligne en mot
                istringstream iss (ligneLu, istringstream::in);
                getline(iss, motLu, ' '); // je lis dans la ligne qu'on a récupérer le 1er mot jusqu'à ce que je rencontre un espace

                // on récupérer la première lettre pour vérifier qu'il ne s'agit pas d'une ligne commentaire ou qu'il n'y ait pas d'espace
                charLu = ligneLu.substr(0,1);
                if ((strcmp(motLu.c_str(), " ") !=0) &&  (strcmp(motLu.c_str(), "#") !=0)) { // OK

                    numeroLigne++;

                    if (numeroLigne == 1) { // 2eme ligne qui contient les infos sur le nb de vertex, face poly

                        nbVertex = atoi(motLu.c_str()); // c_str car atoi est une fonction C
                    } else { // sinon on est au moins à la 3eme ligne

                        // on va s'occuper des lignes contenant les vertex (à partir de la 3eme ligne à nbVertex lignes)
                        if (numeroLigne <= nbVertex+1) {
                            // on s'occupe du mot que l'on a déjà lu et stocké dans motLu grace au getline au dessus

                            if (strcmp(motLu.c_str(), " ") !=0) {

                                //motLu >>pointVertex;
                                tabCoordBuffer.push_back(pointVertex);

                            }

                            while (getline(iss, motLu, ' ')) {
                                if (strcmp(motLu.c_str(), " ") !=0) {

                                    //motLu >>pointVertex;
                                    tabCoordBuffer.push_back(pointVertex);
                                }
                            }

                            uneVertex = Vertex(tabCoordBuffer[0], tabCoordBuffer[1], tabCoordBuffer[2]);
                            tabVertexBuffer.push_back(uneVertex);
                            tabCoordBuffer.clear();
                        } else {

                            // ici on s'occupe des triangles avec 3 indices de vertex par ligne
                            if (strcmp(motLu.c_str(), " ") !=0) {

                                // nous allons nous occuper du premier mot, il s'agit de "n" le nombre de vertex par face => n v1 v2..vn
                                n = atoi(motLu.c_str());
                                tmp_n = n;
                            }
                            // et on va lire les vertex jusqu'à la fin de la ligne -> v1 v2..vn
                            while(getline(iss, motLu, ' ')) {

                                if (strcmp(motLu.c_str(), " ") !=0) {
                                    while (n != 0) {
                                        tabBufferTriangles.push_back(atoi(motLu.c_str()));
                                        n--;
                                    }
                                }
                            }

                            for(int i = 0; i < tmp_n-2; i++) {

                                unTriangle.push_back(tabBufferTriangles[i]);
                                unTriangle.push_back(tabBufferTriangles[i+1]);
                                unTriangle.push_back(tabBufferTriangles[tmp_n-1]);
                                this->addTriangle(unTriangle);
                            }
                        }
                    }
                }
            }
        } else { // il s'agit d'une ligne commenataire ou il y a un espace

            cout << "Pas un fichier OFF" << endl;
        }

        for (int i = 0; i<tabVertexBuffer.size(); i++) {
            addVertex(tabVertexBuffer[i]);
        }

        normalize();
        fichierFigure.close();

        computeNormalsT();  // to be fixed
        computeNormalsV();  // to be fixed
    } else {
        cout << "le fichier ne s'est pas ouvert connard" << endl;
    }
}





