#include <iostream>
#include <string>
#include <cmath>
#include "anomaly_detection_util.h"

// returns the expectation of value 
float valOfExpectation(float* x,int size);

float valOfExpectation(float* x,int size){
    float sum = 0;   // need to check if the defult is ok
    for (int i = 0; i < size; i++){
        sum += x[i];
    }
  
    return sum / size; 
}

float var(float* x, int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += std::pow(x[i] - valOfExpectation(x , size),2);

    }
    
    return sum / size;
}

float cov(float* x, float* y, int size){
    float multy = 0;
    float xMid = valOfExpectation(x ,size);
    float yMid = valOfExpectation(y , size);
    for (int i = 0; i < size; i++){
        multy += (x[i] - xMid) * (y[i] - yMid);
    }

    return multy / size;
}

float pearson(float* x, float* y, int size){
    
    return cov(x,y,size) / std::sqrt(var(x,size)*var(y,size));   
}

Line linear_reg(Point** points,int size){
    float arrX[size] , arrY[size];
    for(int i =0;i < size; i++){
        arrX[i] = points[i]->x;
        arrY[i] = points[i]->y;
    }

    float a = cov(arrX,arrY,size) / var(arrX,size);

    float xMid = valOfExpectation(arrX , size);
    float yMid = valOfExpectation(arrY , size);
    
    float b = yMid - a * xMid;

    return Line(a , b);
}

int main(){
    float x [5] = {20,30,50,66,77}; 
    //std::cout << var(x,5) << std::endl;
    float y [5] = {4,7,9,13,20};
    Point *points[5];
    for(int i = 0;i < 5;i++){
        points[i] = new Point(x[i],y[i]);
    }
    // Point points[5][];
    
    // std::cout << cov(x,y,5) << std::endl;
    // std::cout << pearson(x,y,5) << std::endl;
    Line l = linear_reg(points,5);
    std::cout << l.a << l.b << std::endl;
    return 0;
}
