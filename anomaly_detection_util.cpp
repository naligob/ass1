#include <iostream>
#include <string>
// returns the expectation of value 
float valOfExpectation(float* x,int size);

float valOfExpectation(float* x,int size){
    float sum = 0;   // need to check if the defult is ok
    for (int i = 0; i < size; i++){
        sum += x[i];
    }
  
    return sum / size; 
}

// func to math the power of 2
float powOfTwo(float x);

float powOfTwo(float x){

    return x * x;
}

float var(float* x, int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += powOfTwo(x[i] - valOfExpectation(x , size));
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





    return 0;   //defult
}
int main(){
    float x [5] = {5,12,18,23,45}; 
    //std::cout << var(x,5) << std::endl;
    float y [5] = {2,8,18,20,28};
    // std::cout << cov(x,y,5) << std::endl;
    std::cout << cov(x,y,5) << std::endl;
    return 0;
}
