#define echoPin 8
#define trigPin 9 
long duration; 
int distance; 
char x = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 

}

void loop() {
  digitalWrite(7,LOW); // buzzer

  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15)
  {
  
  if(Serial.available() >0)
  {
    x=Serial.read();
    Serial.println(x);
    if(x=='F')
    {
       //Forward
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);  
    }
    if(x=='B')
    {
       //Backward
              digitalWrite(3,HIGH);
              digitalWrite(4,LOW);
              digitalWrite(5,HIGH);
              digitalWrite(6,LOW);
  
    }
    if(x=='R')
     {
      //Right
              digitalWrite(3,LOW);
              digitalWrite(4,HIGH);
              digitalWrite(5,LOW);
              digitalWrite(6,LOW);
     }
  if(x=='L')
         {
                  //LEFT
                 digitalWrite(3,LOW);
                 digitalWrite(4,LOW);
                 digitalWrite(5,LOW);
                 digitalWrite(6,HIGH);
   

          }
  }

  if(x=='S')
  {

     //stop
                 digitalWrite(3,LOW);
                 digitalWrite(4,LOW);
                 digitalWrite(5,LOW);
                 digitalWrite(6,LOW);
    }
      if(x=='V')
  {

     
                 digitalWrite(7,HIGH);
                 
    }
     if(x=='v')
  {

     
                 digitalWrite(7,LOW);
                 
    }
  }
  else
  {
    //stop
                 digitalWrite(3,LOW);
                 digitalWrite(4,LOW);
                 digitalWrite(5,LOW);
                 digitalWrite(6,LOW);
                 digitalWrite(7,HIGH); // buzzer

                 if(Serial.available() >0)
  {
    x=Serial.read();
    Serial.println(x);
    if(x=='B')
    {
       //Backward
              digitalWrite(3,HIGH);
              digitalWrite(4,LOW);
              digitalWrite(5,HIGH);
              digitalWrite(6,LOW);
  
    }
  }
                 


                 

                 
    }
    
    }
