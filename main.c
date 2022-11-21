#include "imageFormationUtils.h"
#include "math.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

struct camera* initializeCamera(float* rotation_matrix, float* translation_matrix, int focal) {
    struct camera* cam = malloc(sizeof(struct camera)) ;
    /**Static copy**/
    cam->rotation_matrix = rotation_matrix ;
    cam->translation_matrix = translation_matrix ;
    cam->focal = focal ;
    return cam ;
}

/**
 *Compute [ Xp', Yp', 0, 1 + Zp' /f] the projected point on a 2D plan
 */
float* function2(float* projectionMatrix, struct point3d point) {
    float coordinates[4] = { point.x, point.y, point.z, 1 } ;
    float* result  ;
    matMul(projectionMatrix, coordinates, result) ;
    return result ;
}

/**
 * Compute the X and Y coordinates on the image of the projected point
 */
float* function3(float* point, float focal) {
    float* projectedPoint = malloc (sizeof (float )* 2) ;
    projectedPoint[0] = point[0] / (1+ point[2] / focal ) ;
    projectedPoint[1] = point[1] / (1+ point[2] / focal) ;
    return projectedPoint ;
}

/**
 *
 * Compute pixel coordinated in the final array
 */
float* function5(float* point, float alpha_u, float alpha_v, float u0, float v0){
    float* projectedPoint = malloc(sizeof (float) *2) ;
    projectedPoint[0] = point[0] / alpha_u + u0 ;
    projectedPoint[1] = point[1] / alpha_v +v0 ;
    return projectedPoint ;
}

/**
 * Project a point such that his new origin is the camera
 */
float* function1(float* point, float* rigid_matrix) {
    float* newPoint = malloc(4 * sizeof (float)) ;
    matMul(rigid_matrix, point, newPoint ) ; //not sur it work
    return newPoint ;
}



int main(int argc, char* argv[]) {
    /**Reading the point cloud**/
    struct point3d *pointCloud;
    int N_v = 0;
    pointCloud = readOff(argv[1], &N_v);

    /**Center the origin of the cloud at the barycentre**/
    centerThePCL(pointCloud, N_v);

    /**Apply a rigid transformation***/
    /**Tranform in u'v
     /**Create file**/
}
