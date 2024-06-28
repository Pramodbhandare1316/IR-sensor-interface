int val = 0 ;  
 void setup()  
 {  
   Serial.begin(9600);  
   pinMode(D5,OUTPUT);     
 }  
 void loop()   
 {  
  val = digitalRead(D1);   
  Serial.println(val);    
  delay(100);      
  if(val == 1 )  
  {  
   digitalWrite(D5,LOW); 
  }
  else  
  {  
   digitalWrite(D5,HIGH);   
  }  
  }  