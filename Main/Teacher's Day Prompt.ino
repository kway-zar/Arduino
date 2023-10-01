#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16,2);
    lcd.backlight();
    funcT();
}

void loop() {
  // put your main code here, to run repeatedly:
    int k;
    for(k = 16; k>=-45; k--) {

        lcd.setCursor(k,1);
        
        lcd.print("Sir Hector");
        
        delay(500);
        lcd.clear();
        
        }

    
}

void funcT() {

    int k,l;

    String frstWord = "Happy ";
    String scndWord = "Teacher's ";
    String thrdWord = "Day!";
    


    for(k = 16; k>=-45; k--) {

        lcd.cursor();
        lcd.setCursor(k,0);
        lcd.print(frstWord);
        lcd.print(scndWord);
        lcd.print(thrdWord);
        
        delay(500);
        lcd.clear();


        if(k == 0) {

          k = -25;
          
          
        }

       

   
  }

}
