/*
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
*/

/*
This sketch uses the buzzer to play songs.
The Arduino's tone() command will play notes of a given frequency.
We'll provide a function that takes in note characters (a-g),
and returns the corresponding frequency from this table:

  note 	frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz


*/




#include <DHT.h>
/*
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 */
// include the library code:
#include <LiquidCrystal.h>
const int songLength = 18;

#define DHTPIN 7
#define DHTTYPE DHT11
#define buttonPinS1 13
#define buttonPinS2 8
#define buttonPinS3 9
#define buttonPinS4 6
#define buzzerPin A0
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char notes1[] = "05,11,12,13,12,11,11, ,05,11,12,13,12,11,12,13,13"; // a space represents a rest


int beats1[] = {1,1,1,1,2,1,5,4, 1, 1, 1, 1, 2,1,2, 2, 1};


char notes2[] = "06,07,11, ,05,05,12,11,06,06,06,06,06,07,11"; // a space represents a rest


int beats2[] = {1,1,3,2,1,1,3,2,1,1,1,1,2,1,2,3};

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 150;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
    lcd.print(" Hello! Temp is ");
    pinMode(buttonPinS1, INPUT);
    digitalWrite(buttonPinS1, HIGH);  
    pinMode(buttonPinS2, INPUT);
    digitalWrite(buttonPinS2, HIGH);
    pinMode(buttonPinS3, INPUT);
    digitalWrite(buttonPinS3, HIGH);
    pinMode(buttonPinS4, INPUT);
    digitalWrite(buttonPinS4, HIGH);
    
    pinMode(buzzerPin,OUTPUT);
    
     Serial.begin(9600);
   dht.begin();
  delay(700);
  }








void loop()                                                                                  {
  //int t = 100;
  int t = dht.readTemperature();
  int a; //F
  int counter;
  a = 1.8*t+32;
  int k; //Kel
  k = t+273.15;
  int h = dht.readHumidity();
  
  for (counter=1;digitalRead(buttonPinS1) == LOW;counter++){
    
    
 if (digitalRead(buttonPinS1) == LOW && counter%3 == 1) 
                 {
   lcd.clear();
   lcd.print(" Hello! Temp is "); 
   lcd.setCursor(0,1);
   lcd.print("     ");   
   lcd.print(t);
    lcd.print((char)223);
    lcd.print("C");
    delay(1000);}
 else {};   
if (digitalRead(buttonPinS1) == LOW && counter%3 == 2) 
               {
   lcd.clear();
    lcd.print(" Hello! Temp is ");
   lcd.setCursor(0,1);
   lcd.print("     ");
   lcd.print(a, DEC);
    lcd.print((char)223);
    lcd.print("F");
  delay(1000);}
else {};
if(digitalRead(buttonPinS1) == LOW && counter%3 == 0)  
                  {
   lcd.clear(); 
    lcd.print(" Hello! Temp is ");
   lcd.setCursor(0,1);
   lcd.print("     ");
   lcd.print(k,DEC);
    lcd.print("K");
    delay(1000);}
    else {};
                                                  }
                                                  
 //temp end
//humid start


                                                  
     if (digitalRead(buttonPinS2) == LOW) {
   lcd.clear();
   lcd.print(" Hi! Humidity is"); 
   lcd.setCursor(0,1);
   lcd.print("     ");   
   lcd.print(h);
    lcd.print("%");
    delay(1000);
  


                                          }
     
     
     //end humid
     
     
     
     
     if(digitalRead(buttonPinS3) == LOW)
     
     {
     
     int i, duration;
  
  if (t>25)
  {
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats2[i] * tempo;  // length of note/rest in ms
    
    if (notes2[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes2[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  }
  
     if (t<=25)
  
  {
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats1[i] * tempo;  // length of note/rest in ms
    
    if (notes1[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else if (notes1[i] != ',')                         // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes1[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
     }
     } //music end
     
     
     
      if(digitalRead(buttonPinS4) == LOW){
   int counter2;
for (counter2=1;digitalRead(buttonPinS4) == LOW;counter2++)   {
  
  if (counter2%11 != 1)
  {
      if (t>20 && t<25)
      {
       lcd.clear();
   lcd.print(" A Great Day~ "); 
   lcd.setCursor(0,1);
   lcd.print("o(=0w0=)~~~");   
  
    delay(1000);
      }
      
      if ( t <= 10)

 {
       lcd.clear();
   lcd.print("  Frezzing ///"); 
   lcd.setCursor(0,1);
   lcd.print("   Q=A=Q /  ");   
  
    delay(1000);
      }
      if (t<=20 && t > 10)

 {
       lcd.clear();
   lcd.print(" A Little Cold? "); 
   lcd.setCursor(0,1);
   lcd.print("(/= _ =)/~┴┴ ");   
  
    delay(1000);
      }
      if ( t >= 25)

 {
       lcd.clear();
   lcd.print("  Getting Hot!"); 
   lcd.setCursor(0,1);
   lcd.print("   o(*//A//*)q   ");   
  
    delay(1000);
      }
  }//if
  
  else if (counter2%11 == 1 && counter2%2 == 0)
  {
  lcd.clear();
   lcd.print("  Hey dont touch me"); 
   lcd.setCursor(0,1);
   lcd.print("   (/￣3￣)/   "); 
  counter2=1;
  }
  else {
  
    lcd.clear();
   lcd.print(" Dude time to study!"); 
   lcd.setCursor(0,1);
   lcd.print("   (/=.=)/  DDL "); 
  
  }
      
} //forloop

                                         }
      
      
}
      
      
     
     
     
     

 


int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i, duration;
  const int numNotes = 8;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { '01', '03', '03', '04', '05', '06', '07', '11','12','13','14','15','16','17'};
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}
