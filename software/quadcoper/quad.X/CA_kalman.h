#ifndef _Kalman_h
#define _Kalman_h

void Filter(void);
void Init_Kalman(void);
double getAngle(double newAngle, double newRate, double dt);
void setAngle(double newAngle);
double getRate();

void setQangle(double newQ_angle);
void setQbias(double newQ_bias);
void setRmeasure(double newR_measure);

#endif

