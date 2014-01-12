#ifndef _Kalman_h
#define _Kalman_h
extern int AccX, AccY, AccZ, GyroX, GyroY, GyroZ, Temp;
extern double accXangle, accYangle; // Angle calculate using the accelerometer
extern double temp; // Temperature
extern double gyroXangle, gyroYangle; // Angle calculate using the gyro
extern double compAngleX, compAngleY; // Calculate the angle using a complementary filter
extern double kalAngleX, kalAngleY; // Calculate the angle using a Kalman filter


/* Kalman filter variables */
double Q_angle; // Process noise variance for the accelerometer
double Q_bias; // Process noise variance for the gyro bias
double R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

double angle; // The angle calculated by the Kalman filter - part of the 2x1 state matrix
double bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state matrix
double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
double K[2]; // Kalman gain - This is a 2x1 matrix
double y; // Angle difference - 1x1 matrix
double S; // Estimate error - 1x1 matrix

void Filter(void);
void Init_Kalman(void);
double getAngle(double newAngle, double newRate, double dt);
void setAngle(double newAngle);
double getRate();

void setQangle(double newQ_angle);
void setQbias(double newQ_bias);
void setRmeasure(double newR_measure);

#endif

