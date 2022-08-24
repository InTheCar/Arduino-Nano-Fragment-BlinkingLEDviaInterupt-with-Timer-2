void setup(){ 
  TCCR2A = 0x00; // Wave Form Generation Mode 0: Normal Mode; OC2A disconnected
  TCCR2B = (1<<CS22) + (1<<CS21) + (1<<CS20); // prescaler = 1024
  TIMSK2 = (1<<TOIE2); // interrupt when TCNT2 is overflowed
  DDRD |= (1<<PD7);  // Portmanipulation: replaces pinMode(7, OUTPUT);
} 
void loop() { 
 // do something else
}
ISR(TIMER2_OVF_vect){  // Interrupt Service Routine 
  static int counter = 0;
  counter++;
  if(counter==20){
    PORTD ^= (1<<PD7); 
    counter = 0; 
  }
}
  
