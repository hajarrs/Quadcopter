#include "Arduino.h"


//-------------------
//IMU Test functions
//-------------------
void testAccOutput() 
{
    Serial.print("RAW: ");  
    Serial.print(accRaw[0]);  
    Serial.print(" ");          
    Serial.print(accRaw[1]);  
    Serial.print(" ");              
    Serial.print(accRaw[2]);  

    Serial.print("\t G: ");        
    Serial.print(accG[0]); 
    Serial.print(" ");    
    Serial.print(accG[1]); 
    Serial.print(" "); 
    Serial.print(accG[2]); 

    Serial.print("\t Ang: ");        
    Serial.print(accAngle[0]); 
    Serial.print(" ");    
    Serial.print(accAngle[1]); 
    Serial.print(" "); 
    Serial.println(accAngle[2]);
    //Serial.flush();
}

void testGyroOutput() 
{
//    Serial.print("RAW: ");  
    Serial.print(gyroRaw[0]);  
    Serial.print(",");          
    Serial.print(gyroRaw[1]);  
    Serial.print(",");              
    Serial.print(gyroRaw[2]);   


    Serial.print(",");        
    Serial.print(angle[0]);  
    Serial.print(",");          
    Serial.print(angle[1]);  
    Serial.print(",");              
    Serial.println(angle[2]); 
    //Serial.flush(); 

}

void testMagOutput() 
{
    Serial.print(magRaw[0]);
    Serial.print(",");
    Serial.print(magRaw[1]);
    Serial.print(",");    
    Serial.print(magRaw[2]);    
    
    Serial.print(",");              
    Serial.print(magAngle[0]);  
    Serial.print(",");          
    Serial.print(magAngle[1]);  
    Serial.print(",");              
    Serial.println(magAngle[2]);     
    //Serial.flush(); 
}

void testTiltOutput() 
{ 
  Serial.print(angle[1]);
  Serial.print(",");          
  Serial.print(accAngle[0]-tiltStart);
  Serial.print(",");          
  Serial.println(tiltAngle-tiltStart);
  //Serial.flush();
}

void testRollOutput() 
{
  Serial.print(angle[0]);
  Serial.print(",");          
  Serial.print(accAngle[1]-rollStart);
  Serial.print(",");          
  Serial.println(rollAngle-rollStart);
  //Serial.flush();  
}

void testPanOutput() 
{
  Serial.print(angle[2]);
  Serial.print(",");                  
  Serial.print(magAngle[2]);
  Serial.print(",");                  
  Serial.println(panAngle);
  //Serial.flush();
}

void headtrackerOutput() 
{
  Serial.print(tiltAngleLP-tiltStart+90);
  Serial.print(",");
  Serial.print(rollAngleLP-rollStart+90);
  Serial.print(",");  
  Serial.println(panAngleLP+180);
  //Serial.flush();
}

void calMagOutput() 
{
    Serial.print((int)magRaw[0]+3000);
    Serial.print(",");
    Serial.print((int)magRaw[1]+3000);
    Serial.print(",");    
    Serial.println((int)magRaw[2]+3000); 
    //Serial.flush();  
}

void calAccOutput() 
{
    Serial.print((int)accRaw[0]+3000);  
    Serial.print(",");          
    Serial.print((int)accRaw[1]+3000);  
    Serial.print(",");              
    Serial.println((int)accRaw[2]+3000);  
    //Serial.flush();
}

// All sensor output as "csv". 
void plot_all_sensors() 
{
    Serial.print(accRaw[0]);  
    Serial.print(",");          
    Serial.print(accRaw[1]);  
    Serial.print(",");              
    Serial.print(accRaw[2]);  

    Serial.print(",");            
    Serial.print(gyroRaw[0]);  
    Serial.print(",");          
    Serial.print(gyroRaw[1]);  
    Serial.print(",");              
    Serial.print(gyroRaw[2]);  

    Serial.print(",");               
    Serial.print(magRaw[0]);  
    Serial.print(",");          
    Serial.print(magRaw[1]);  
    Serial.print(",");              
    Serial.println(magRaw[2]); 
    //Serial.flush();    
}

// output calculated values, output as "csv"
void testAllData() 
{
 // x
  Serial.print(angle[1]);
  Serial.print(",");          
  Serial.print(accAngle[0]-90);
  Serial.print(",");          
  Serial.print(tiltAngle-90);
  Serial.print(",");      
  
 // y
  Serial.print(angle[0]);
  Serial.print(",");          
  Serial.print(accAngle[1]-90);
  Serial.print(",");          
  Serial.print(rollAngle-90);  
  Serial.print(",");     
    
 // z
  Serial.print(angle[2]);
  Serial.print(",");                  
  Serial.print(magAngle[2]-panStart);
  Serial.print(",");                  
  Serial.println(panAngle);
  //Serial.flush();
}

void quickTest() 
{
  Serial.println(quick_test);
  //Serial.flush();
}

//--------------
//Sensor update
//--------------


void accCalc() 
{       
    accRaw[0] += accOffset[0];
    accRaw[1] += accOffset[1];
    accRaw[2] += accOffset[2];   
  
    for (unsigned char i = 0; i<3; i++) 
    {
      accG[i]=(float)accRaw[i]/ACC_SENS;
    }
     
     // So, lets calculate R
     // R^2 = Rx^2+Ry^2+Rz^2    
     #if(ASSUME_1G_ACC == 0) 
       R = sqrt(accG[0]*accG[0]+accG[1]*accG[1]+accG[2]*accG[2]);
     
     // Otherwise, just assume total G = 1. 
     #else
       R = 1;
     
     #endif
      
     if (R < 1.3 && R > 0.7) 
     { 
       // Calculate final angles: 
       for (unsigned char i = 0; i<3; i++) 
       {
         accAngle[i]=acos(accG[i]/R)*57.3;
       }      
     }
}



// Filter / merge sensor data. 
void filter() 
{ 
 // Used to set initial values. 
   if (resetValues == 1) 
   {
      resetValues = 0; 
      
      tiltStart =0;
      panStart = 0;
      rollStart = 0;
  
        updateSensors();    
        gyroCalc();
        accCalc();
        magCalc();

      panAngle = 0;
      tiltStart = accAngle[0];
      panStart = magAngle[2];
      rollStart =accAngle[1];              
   }

  // Simple filter, uses mainly gyro-data, but uses accelerometer to compensate for drift
//  rollAngle = (rollAngle+((gyroRaw[0]-gyroOff[0]))/(SAMPLERATE*SCALING_FACTOR))*gyroWeight + accAngle[1]*(1-gyroWeight);

  rollAngle = (rollAngle+((gyroRaw[0]-gyroOff[0])*cos((tiltAngle-90)/57.3) + (gyroRaw[2]-gyroOff[2])*sin((tiltAngle-90)/57.3)  )/(SAMPLERATE*SCALING_FACTOR))*gyroWeight + accAngle[1]*(1-gyroWeight);

  // Simple filter, uses mainly gyro-data, but uses accelerometer to compensate for drift
//  tiltAngle = (tiltAngle+((gyroRaw[1]-gyroOff[1]))/(SAMPLERATE*SCALING_FACTOR))*gyroWeight + accAngle[0]*(1-gyroWeight);
  tiltAngle = (tiltAngle+((gyroRaw[1]-gyroOff[1])*cos((rollAngle-90)/57.3) + (gyroRaw[2]-gyroOff[2])*sin((rollAngle-90)/57.3)*(-1)  )/(SAMPLERATE*SCALING_FACTOR))*gyroWeight + accAngle[0]*(1-gyroWeight);
  
  //panAngle  = (panAngle +((gyroRaw[2]-gyroOff[2]))/(SAMPLERATE*SCALING_FACTOR))*0.997 + magAngle[2]*0.003;
  
  
//  panAngle  = (panAngle +(( (gyroRaw[2]-gyroOff[2])*(1/cos((tiltAngle-90)/57.3)) ))/(SAMPLERATE*(SCALING_FACTOR-2)))*0.99 + magAngle[2]*0.01;

//    panAngle  = (panAngle +(( (gyroRaw[2]-gyroOff[2])))/(SAMPLERATE*(SCALING_FACTOR-2)))*0.95 + magAngle[2]*0.05;
    
    

    panAngle  = (panAngle +( (gyroRaw[2]-gyroOff[2])*cos((tiltAngle-90)/57.3) + ( ((gyroRaw[0]-gyroOff[0])*(-1))* (sin((tiltAngle-90)/57.3)) ) + ( ((gyroRaw[1]-gyroOff[1])*(1))* (sin((rollAngle-90)/57.3)) )  )/(SAMPLERATE*(SCALING_FACTOR)))*GyroWeightPan + magAngle[2]*(1-GyroWeightPan);
  
 
 
 
   
if (TrackerStarted) 
{  
// All lowpass-filters.

  tiltAngleLP = tiltAngle * tiltBeta + (1-tiltBeta)*lastTiltAngle;
  lastTiltAngle = tiltAngleLP;
  
  rollAngleLP = rollAngle * tiltBeta + (1-tiltBeta)*lastRollAngle;
  lastRollAngle = rollAngleLP;
  
  panAngleLP = panAngle * panBeta + (1-panBeta)*lastPanAngle;
  lastPanAngle = panAngleLP;
  
  float panAngleTemp = (panAngleLP)*(panInverse);
    if(panAngleTemp*panFactor > -panMinPulse && panAngleTemp*panFactor < panMaxPulse) 
    {
    temp =servoPanCenter+panAngleTemp*panFactor;
    quick_test = temp;
    channel_value[htChannels[0]] = (int)temp;
    }    
      
  float tiltAngleTemp = (tiltAngleLP-tiltStart)*(tiltInverse);
    if(tiltAngleTemp*tiltFactor > -tiltMinPulse && tiltAngleTemp*tiltFactor < tiltMaxPulse) 
    {
      temp =servoTiltCenter+tiltAngleTemp*tiltFactor;
      channel_value[htChannels[1]] = temp;
    }   
    
  float rollAngleTemp = (rollAngleLP-rollStart)*(rollInverse);
    if(rollAngleTemp*rollFactor > -rollMinPulse && rollAngleTemp*rollFactor < tiltMaxPulse) 
    {
      temp =servoRollCenter+rollAngleTemp*rollFactor;
      channel_value[htChannels[2]] = temp;
    }    
  }  
}


//-------------------
//Initialise sensors
//-------------------
void init_sensors() 
{

 ReadFromI2C(ITG3205_ADDR, 0x00,1);
 ITG3205_ID = sensorBuffer[0];
 
#ifdef DEBUG     
 Serial.print("ITG3205: ");
 Serial.print(sensorBuffer[0]);
 //Serial.flush();
#endif 
  
 ReadFromI2C(ADXL345_ADDR, 0x00,1);
 ADXL345_ID = sensorBuffer[0];
 
#ifdef DEBUG      
 Serial.print("    ADXL: ");
 Serial.print(sensorBuffer[0]); 
 //Serial.flush();
#endif  

// Accelerometer increase G-range (+/- 16G)
 WriteToI2C(ADXL345_ADDR, 0x31, 0b00001011);        
   
 ReadFromI2C(HMC_ADDR, 0x00,1);    //Para el GY-85
 HMC_ID = sensorBuffer[0];
 
#ifdef DEBUG      
 Serial.print("    HMC: ");
 Serial.println(sensorBuffer[0]);
 //Serial.flush(); 
#endif  
  
WriteToI2C(ITG3205_ADDR, 22, 24);

   //  ADXL345 POWER_CTL
 WriteToI2C(ADXL345_ADDR, 0x2D, 0); 
 WriteToI2C(ADXL345_ADDR, 0x2D, 16);
 WriteToI2C(ADXL345_ADDR, 0x2D, 8);

   // HMC5883
   // Run in continuous mode
 WriteToI2C(HMC_ADDR, 0x00, 0x70);    //Para el GY-85
 WriteToI2C(HMC_ADDR, 0x01, 0xA0);    //Para el GY-85
 WriteToI2C(HMC_ADDR, 0x02, 0x00);    //Para el GY-85
 
 #if (ALWAYS_CAL_GYRO)    
 
   // Set sensor offset
   setSensorOffset();

 #endif 
 
}


void resetCenter() 
{
      resetValues = 0; 
    
    for (unsigned char k = 0; k< 250;k++) 
    {
      updateSensors();    
      gyroCalc();
      accCalc();
      magCalc();
      filter();    
    }
    
    tiltStart = accAngle[0];
    panStart = magAngle[2];
    rollStart =accAngle[1];  
  
    updateSensors();    
    gyroCalc();
    accCalc();
    magCalc();
    filter();    
  
    panAngle = magAngle[2];
    tiltAngle = accAngle[0];
    rollAngle = accAngle[1];
    
    TrackerStarted = 1;
}

void SensorInfoPrint() 
{ 
   Serial.print("Mag cal:");
   Serial.print(magNegOff[0]-magPosOff[0]);
   Serial.print(",");   
   Serial.print(magNegOff[1]-magPosOff[1]);
   Serial.print(",");      
   Serial.print(magNegOff[2]-magPosOff[2]);
   
   Serial.print(",");      
   Serial.print(magGain[0]);
   Serial.print(",");   
   Serial.print(magGain[1]);
   Serial.print(",");      
   Serial.println(magGain[2]);   
 
   Serial.print("ADXL345 ID: ");
   Serial.println((int)ADXL345_ID); 
   Serial.print("ITG3205 ID: ");
   Serial.println((int)ITG3205_ID); 
   Serial.print("HMC ID: ");
   Serial.println((int)HMC_ID); 
   //Serial.flush();   
}

int Corrected_IMU(int IMU_data)
{
  long IMU;
  if((IMU_data>=0)&&(IMU_data<1170))             //90º from 3500 to 1170 -> (((IMU_data+150)/(100+1170))*900)
   {
     IMU=(IMU_data+100);
     IMU*=30;
     IMU/=43;
     return (int)IMU;     
   }
  else if((IMU_data>=1170)&&(IMU_data<1800))     //90º from 1170 to 1800 -> 900+((IMU_data-1170)*(900/630))
   {
     IMU=(IMU_data-1170);
     IMU*=10;
     IMU/=7;
     IMU+=900;
     return (int)IMU;   
   }
  else if((IMU_data>=1800)&&(IMU_data<2300))     //90º from 1800 to 2300 -> 1800+((IMU_data-1800)*(900/500))
   {
     IMU=(IMU_data-1800);
     IMU*=9;
     IMU/=5;
     IMU+=1800;
     return (int)IMU;      
   }   
  else if((IMU_data>=2300)&&(IMU_data<3500))     //90º from 2300 to 3500 -> 2700+((IMU_data-2300)*(900/1200))
   {
     IMU=(IMU_data-2300);
     IMU*=3;
     IMU/=4;
     IMU+=2700;
     return (int)IMU;     
   }   
  else if((IMU_data>=3500)&&(IMU_data<=3600))    //90º from 3500 to 1170 -> (((IMU_data-3450)/(100+1170))*900)
   {
     IMU=(IMU_data-3500);
     IMU*=30;
     IMU/=43;
     return (int)IMU;     
   } 
}


long Corrected_gyro(float gyro_data)
{
  int i;
  i=(int)(10*gyro_data);
  i=i%3600;
  
  if(i<=0)
  {
    if(i<=-1800)
    {
      return (int)(-(1800+i));
    }
    else
    {
      return (int)(1800-i);
    }
  }
  
  else
  {
    if(i>1800)
    {
      return (int)(5400-i);
    }
    else
    {
      return (int)(1800-i);
    }
  }
}
