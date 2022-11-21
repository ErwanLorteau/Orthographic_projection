#include "imageFormationUtils.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

struct camera {
    float* rotation_matrix  ;
    float* translation_matrix  ;
    float focal ;
}  ;




float* computeRigidTransformationMatrix(struct camera* cam) {
    //calculer la matrice selon la formule des slide
}
//Note that pointCloud* refer to an array of point3D
//Nv : number of point in the point cloud
void applyRigidYTransformation(struct camera* cam, struct point3d* pointCloud, int N_v) {
    //Pour tout les point, appliquer...
    //Stocker le resultat dans un nouveau nuage de points

    for (int i = 0 ;  i < N_v ; i++ ) {
        //appliquer la matrix rigid a chaque point (utiliser multi matrix) + stocker le resultat..

    }


}
/**
FILE *generateImage(char *name, int* matrix) {
    FILE* ifp = fopen(name, "w");
    if (ifp == NULL){
        printf("Error opening the file\n");
        exit(1);
    }
    //ajouter la matrice + respecter le format

    return ifp;
}
**/

struct camera* initializeCamera(float* rotation_matrix, float* translation_matrix, int focal) {
    struct camera* cam = malloc(sizeof(struct camera)) ;
    /**Static copy**/
    cam->rotation_matrix = rotation_matrix ;
    cam->translation_matrix = translation_matrix ;
    cam->focal = focal ;
    return cam ;
}

float* initializeRotationMatrix() {
    float* rotation_matrix = (float*) malloc(16*sizeof(float)) ;
    rotation_matrix = (float[16]) {0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0,  0, 0, 0,
                                    0, 0, 0, 1 } ;
    return rotation_matrix ;
}

float *initializeTranslationMatrix(float Tx, float Ty, float Tz) {
    float* translation = (float*) malloc(16*sizeof(float)) ;
    translation = (float[16]) {1, 0, 0, Tx,
                                   0, 1, 0, Ty,
                                   0,  0, 1, Tz,
                                   0, 0, 0, 1 } ;
    return translation ;
}


float *initializeRigidTransformationMatrix(float* rotationMatrix, float* translationMatrix) {
    float* rigid = (float*) malloc(16*sizeof(float)) ;
    rigid = (float[16]) {rotationMatrix[0], rotationMatrix[1], rotationMatrix[2], translationMatrix[2],
                                   rotationMatrix[3], rotationMatrix[4], rotationMatrix[5], translationMatrix[5],
                                   rotationMatrix[6], rotationMatrix[7], rotationMatrix[8], translationMatrix[8],
                                   0,                 0,                 0,                 1 } ;
    return rotationMatrix ;
}


int main(int argc, char* argv[]) {
    /**Reading the point cloud**/
    struct point3d *pointCloud;
    int N_v = 0;
    pointCloud = readOff(argv[1], &N_v);
    /**Center the origin of the cloud at the barycentre**/

    centerThePCL(pointCloud, N_v);

    /***Initializa a camera**/
    float* rotation_matrix = initializeRotationMatrix() ;
    float* translation_matrix = initializeTranslationMatrix(0,0,0) ;
    float focal = 1 ;
    struct camera* cam = initializeCamera(rotation_matrix, translation_matrix, focal) ;

    /**Apply a rigid transformation***/
    float* rigid_transformation_matrix = initializeRigidTransformationMatrix(rotation_matrix,translation_matrix) ;

    //For all point in the image, tranform
    for (int 111*Project**/

    /**Tranform in u'v

     /**Create file**/

}
