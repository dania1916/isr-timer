#include <TimerOne.h>

bool finish=false;
static volatile uint16_t isr_timer_count = 0;

void isr_timer() {
  if((isr_timer_count % 200) == 0 || (isr_timer_count % 200) == 200){
    if((sensor_detect & (1 << 0)) && digitalRead(IRSensor)){
       gpio_isr_count[0]++;
       START_CAMERA_SERVER &= ~(1 << 0);
      }

    if((sensor_detect & (1 << 1)) && digitalRead(IRSensor)){
           gpio_isr_count[1]++;
           STOP_CAMERA_SERVER &= ~(1 << 1);
          }
        }

    //execute one every 1500ms
    if((isr_timer_count % 1500) == 0 || (isr_timer_count % 1500) == 1500){
        if((sensor_detect & (1 << 2)) && digitalRead(14)){
            teleValid() &= ~(1 << 2);
        }
        if((sensor_detect & (1 << 3)) && gpio_set_relay){
            teleInvalid() &= ~(1 << 3);
        }
    }

    // Executed once every 2ms
        if((isr_timer_count % 2) == 0){
            sensor_detect();
        }

    if(isr_timer_count <= 1000) isr_timer_count++;
    else isr_timer_count = 0;

}
        
void init_isr_timer(){
  Timer1.initialize(1000);
  Timer1.attachInterrupt(isr_timer);
  }
