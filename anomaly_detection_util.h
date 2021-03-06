#ifndef ANOMALY_DETECTION_UTIL_H
#define ANOMALY_DETECTION_UTIL_H
// returns the variance of X and Y
float var(float* x, int size);
// returns the covariance of X and Y
float cov(float* x, float* y, int size);
// returns the Pearson correlation coefficient if X and Y
float pearson(float* x, float* y, int size);

class Line
{
public:
        const float a,b;
        Line(float a, float b):a(a),b(b){}
        float f(float x){
                return a * x + b;
        }
};

class Point
{
public:
        const float x,y;
        Point(float x, float y):x(x),y(y){}
};

// performs a linear regression and returns the line equation of the line
Line linear_reg(Point** points,int size);
// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points,int size);
// returns the deviation between point Pand the line
float dev(Point p, Line l);

#endif