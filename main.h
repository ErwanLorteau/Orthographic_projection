//
// Created by erwan on 21/11/22.
//

#ifndef LAB_5_MAIN_H
#define LAB_5_MAIN_H

struct camera {
    float* rotation_matrix  ;
    float* translation_matrix  ;
    float focal ;
}  ;




float *initializeRigidTransformationMatrix(float* rotationMatrix, float* translationMatrix) ;
float *initializeTranslationMatrix(float Tx, float Ty, float Tz) ;
float *intializeRotationMatrix() ;



#endif //LAB_5_MAIN_H
