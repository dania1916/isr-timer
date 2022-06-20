#define IRSensor 15

void sensor_detect(){
    pinMode(15, INPUT);  
    digitalWrite(15,0); //0 objek terdeteksi
}

void sensor_not_detect(){
    pinMode(15, INPUT);  
    digitalWrite(15,1); //1 objek tdk terdeteksi
  }
