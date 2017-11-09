#include "off_loader.h"

using namespace std;

off_loader::off_loader(std::string cheminAcces) {

    _name="Off_loader";
    int i=0, j=0;
    string line;
    char recupLigne[200];
    char recupCoordxVt[20];
    char recupCoordyVt[20];
    char recupCoordzVt[20];
    char path[50];
    cheminAcces.copy(path,50);
    std::string identifiantOFF;
    long double CoordxVt;
    long double CoordyVt;
    long double CoordzVt;
    int nbCoordRecup;
    int nbCaractRecup;
    ifstream myfile (path);
    int nbVecteurs, nbFaces, nbEdges;
    int premierPointTriangle,deuxiemePointTriangle,troisiemePointTriangle,pointInutile;
    recupCoordxVt[0]=0;
    recupCoordyVt[0]=0;
    recupCoordzVt[0]=0;
    nbCoordRecup=0;
    nbCaractRecup=0;

    if (myfile.is_open()) {
        if (myfile) {

            myfile>>identifiantOFF;
            if((identifiantOFF.compare("OFF"))==0) { // on vérifie que que la 1ere ligne contienne OFF

                cout << "je suis un fichier OFF" << endl;

                myfile>>nbVecteurs>>nbFaces>>nbEdges;

                cout << nbVecteurs << " " << nbFaces << " " << nbEdges<<endl;

                for(i=0;i<nbVecteurs;i++) {

                    myfile>>recupCoordxVt>>recupCoordyVt>>recupCoordzVt;
                    cout<<recupCoordxVt<<" "<<recupCoordyVt<<" "<<recupCoordzVt<<endl;


                    for(int k=0;k<20;k++) {

                        if(recupCoordxVt[k]=='.') {
                            recupCoordxVt[k]=',';
                            break;
                        }
                    }

                    for(int k=0;k<20;k++) {

                        if(recupCoordyVt[k]=='.'){
                            recupCoordyVt[k]=',';
                            break;
                        }
                    }

                    for(int k=0;k<20;k++) {

                        if(recupCoordzVt[k]=='.'){
                            recupCoordzVt[k]=',';
                            break;
                        }
                    }

                    CoordxVt = strtold (recupCoordxVt, NULL);
                    CoordyVt = strtold (recupCoordyVt, NULL);
                    CoordzVt = strtold (recupCoordzVt, NULL);
                    this->addVertex(CoordxVt,CoordyVt,CoordzVt);


                    for(j=0;j<20;j++) {
                        recupCoordxVt[j]=0;
                        recupCoordyVt[j]=0;
                        recupCoordzVt[j]=0;
                    }
                }

                for(int ii=0;ii<nbFaces;ii++) {
                    myfile>>pointInutile>>premierPointTriangle>>deuxiemePointTriangle>>troisiemePointTriangle;

                    this->addTriangle(premierPointTriangle,deuxiemePointTriangle,troisiemePointTriangle);
                }
            }
        }

        myfile.close();
        computeNormalsT();  // to be fixed
        computeNormalsV();  // to be fixed
    }
    else {
        cout << "le fichier ne s'est pas ouvert proprement" << endl;
    }
}


/*


#include "off_loader.h"

#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;


off_loader::off_loader () {

    _name = "OffLoader";

string fileName = "../isiviewer-1.3/data/venus.off";


    // on ouvre le fichier
    ifstream fichierFigure((char*)fileName.c_str());

    if (fichierFigure) { // ouverture du fichier réussi


        string motLu, charLu, ligneLu;
        int numeroLigne = 0, nbVertex = 0, n = 0, tmp_n = 0;
        vector<float> tabCoordBuffer;
        vector<Vertex> tabVertexBuffer;
        vector<int> tabBufferTriangles;
        stringstream pStof, couleurs;
        float pointVertex;
        Vertex uneVertex;
        Triangle unTriangle;

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
                if ((strcmp((char*)charLu.c_str(), " ") !=0) &&  (strcmp((char*)charLu.c_str(), "#") !=0)) { // OK

                    numeroLigne++;

                    if (numeroLigne == 1) { // 2eme ligne qui contient les infos sur le nb de vertex, face poly

                        nbVertex = atoi(motLu.c_str()); // c_str car atoi est une fonction C
                    } else { // sinon on est au moins à la 3eme ligne

                        // on va s'occuper des lignes contenant les vertex (à partir de la 3eme ligne à nbVertex lignes)
                        if (numeroLigne <= nbVertex+1) {
                            // on s'occupe du mot que l'on a déjà lu et stocké dans motLu grace au getline au dessus

                            if (strcmp((char*)motLu.c_str(), " ") !=0) {

                                pStof.clear();
                                pStof.str(motLu);
                                pStof >>pointVertex;
                                tabCoordBuffer.push_back(pointVertex);

                            }

                            while (getline(iss, motLu, ' ')) {
                                if (strcmp((char*)motLu.c_str(), " ") !=0) {
                                    pStof.clear();
                                    pStof.str(motLu);
                                    pStof >>pointVertex;
                                    tabCoordBuffer.push_back(pointVertex);
                                }
                            }

                            uneVertex = Vertex(tabCoordBuffer[0], tabCoordBuffer[1], tabCoordBuffer[2]);
                            tabCoordBuffer.clear();
                            tabVertexBuffer.push_back(uneVertex);

                        } else {

                            // ici on s'occupe des triangles avec 3 indices de vertex par ligne
                            if (strcmp((char*)motLu.c_str(), " ") !=0) {

                                // nous allons nous occuper du premier mot, il s'agit de "n" le nombre de vertex par face => n v1 v2..vn
                                n = atoi(motLu.c_str());
                                tmp_n = n;
                            }
                            // et on va lire les vertex jusqu'à la fin de la ligne -> v1 v2..vn
                            while(getline(iss, motLu, ' ')) {

                                if (strcmp((char*)motLu.c_str(), " ") !=0) {
                                    if (n != 0) {
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
                                unTriangle.clear();
                            }
                        }
                    }
                }
            }
        }
        else { // il s'agit d'une ligne commenataire ou il y a un espace

            cout << "Pas un fichier OFF" << endl;
        }

        for (int i = 0; i<tabVertexBuffer.size(); i++) {
            addVertex(tabVertexBuffer[i]);
        }

        this->normalize();
        fichierFigure.close();

        computeNormalsT();  // to be fixed
        computeNormalsV();  // to be fixed
    } else {
        cout << "le fichier ne s'est pas ouvert connard" << endl;
    }
}

*/








