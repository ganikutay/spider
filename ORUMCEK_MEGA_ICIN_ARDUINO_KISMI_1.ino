#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)


// our servo # counter
uint8_t servonum = 0;


int x = 20;
int y = 5;
double z = 4;  // eskiden 3 tu
//      BAKIS ACIM her zaman ON TARAFI SOLA BAKACAK sekilde
double sag_on_uc = 225;         //artinda disa gidiyor
double sag_on_yukselen = 300;   //artinca asagi gidiyor
double sag_on_donen = 500;      //artinca sola donuyor

double sol_on_donen = 375;      //artinca saga donuyor
double sol_on_yukselen = 450;   //artinca yukari gidiyor
double sol_on_uc = 525;         //artinca ice gidiyor

double sag_arka_uc = 500;       //artinca ice gidiyor
double sag_arka_yukselen = 450;//artinca yukari gidiyor
double sag_arka_donen = 250;   //artinca sola donuyor  

double sol_arka_donen = 375;   //artinca saga donuyor
double sol_arka_yukselen = 300;//artinca asagi gidiyor
double sol_arka_uc = 225;      //artinda disa gidiyor








// buton gibi dusun
int nodeMcuTetikleyiciButon1 = 10;  // ILERI    13 sari
int nodeMcuTetikleyiciButon2 = 11;  // SOL      14 turuncu
int nodeMcuTetikleyiciButon3 = 12;  // ZIPLAMA
int nodeMcuTetikleyiciButon4 = 13;  // SAG      15 mavi


int nodeMcuDurumu1;
int nodeMcuDurumu2;
int nodeMcuDurumu3;
int nodeMcuDurumu4;



void setup() 
{
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(60);
    



  
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  delay(100);
  
}

void loop() 
{
  Serial.println("BASLANGIC");
  nodeMcuDurumu1 = digitalRead(nodeMcuTetikleyiciButon1);
  nodeMcuDurumu2 = digitalRead(nodeMcuTetikleyiciButon2);
  nodeMcuDurumu3 = digitalRead(nodeMcuTetikleyiciButon3);
  nodeMcuDurumu4 = digitalRead(nodeMcuTetikleyiciButon4);
  delay(100);
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------
//------------DUZ GIDIS------------------------------DUZ GIDIS------------------



  
    if(nodeMcuDurumu1 == HIGH)
      {
        Serial.println("nodeMcu 111111");
        Serial.println(nodeMcuDurumu1);
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

//---------------- Sol on adim atar ----------------


//Ayak havaya kalkar ve one gider ayni anda uc disa gider
// SOL ON YUKSELEN 450=>550   ,   SOL ON DONEN  375=>275  ,  SON ON UC 525=>425
  


  

  while((sol_on_yukselen <= 550) & (sol_on_donen >= 275) & (sol_on_uc >= 425))
  {
    sol_on_yukselen = sol_on_yukselen + ((1)*(z));
    sol_on_donen = sol_on_donen - ((1)*(z));
    sol_on_uc = sol_on_uc - ((1)*(z));
 
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  //sol_on_donen = 275;      //artinca saga donuyor        BU 250 olmali?? cunku sag on donenle aralarinda 25lik fark oluyo
  //sol_on_yukselen = 550;   //artinca yukari gidiyor
  //sol_on_uc = 425;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 250;   //artinca sola donuyor      

  sol_arka_donen = 375;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);





//SOL ON AYAK INIYOR

// SOL ON YUKSELEN 550 => 450
while(sol_on_yukselen >= 450)
  {
    sol_on_yukselen = sol_on_yukselen - ((1)*(z));

    
 
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  //sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 425;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 250;   //artinca sola donuyor      

  sol_arka_donen = 375;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);



//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

/* sol on disinda 3 lu hareket
sol on ucu iceri
sag on 90 dereceye
sol arka geri carpraz a
sag arkada biraz kimildiyo geriye dogru ve 
sag arka uc disa gidiyor
//SOL ON UC 425=>525  ,  SOL ARKA DONEN  375=>525  ,  SAG ON DONEN 500=>375  ,  SAG ARKA DONEN 250=>225  ,  SAG ARKA UC 500=>400   
*/

while((sol_on_uc <= 525) & (sol_arka_donen <= 525) & (sag_on_donen >= 375) & (sag_arka_donen >= 225) & (sag_arka_uc >=400))
{
    // HEPSI 10 ile carpildi ve zaman 10 a bolundu
  sol_on_uc = sol_on_uc + ((1)*(z));  //           2          100
  sol_arka_donen = sol_arka_donen + (((1)+(0.5))*(z)); //  3          150
  sag_on_donen = sag_on_donen - (((1)+(0.25))*(z));//       3          125
  sag_arka_donen = sag_arka_donen - ((0.25)*(z));//    6          25
  sag_arka_uc = sag_arka_uc - ((1)*(z));//         2          100
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 375;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  //sol_on_uc = 525;         //artinca ice gidiyor

  //sag_arka_uc = 400;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 225;   //artinca sola donuyor      

  //sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);



//-------------- SAG ARKA ADIM ATAR -------------




//SAG ARKA YUKSELEN 450=>550  ,  SAG ARKA DONEN 225=>375  ,  SAG ARKA UC 400=>500
while((sag_arka_yukselen <= 550) & (sag_arka_donen <= 375) & (sag_arka_uc <=500))
{
  sag_arka_yukselen = sag_arka_yukselen + ((1)*(z));  //100
  sag_arka_donen = sag_arka_donen + (((1)+(0.5))*(z));        //150
  sag_arka_uc = sag_arka_uc + ((1)*(z));              //100
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 375;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  //sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 550;//artinca yukari gidiyor
  //sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);




//SAG ARKA AYAK INIYOR

//SAG ARKA YUKSELEN 550=>450  
while(sag_arka_yukselen >= 450)
{
  sag_arka_yukselen = sag_arka_yukselen - ((1)*(z));  

  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 375;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);





//-------------- SAG ON ADIM ATAR -------------




//SAG ON YUKSELEN 300=>200  ,  SAG ON DONEN 375=>500  ,  SAG ON UC 225=>325
while((sag_on_yukselen >= 200) & (sag_on_donen <= 500) & (sag_on_uc <= 325 ))
{
  sag_on_yukselen = sag_on_yukselen - ((1)*(z));               //100  *5
  sag_on_donen = sag_on_donen + (((1)+(0.25))*(z));          //125  *4  aradaki mesafe daha cok o yuzden ters oranti
  sag_on_uc = sag_on_uc + ((1)*(z));                           //100  *5
  
  //sag_on_uc = 325;         //artinca disa gidiyor
  //sag_on_yukselen = 200;   //artinca asagi gidiyor
  //sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);


//SAG ON AYAK INIYOR


//SAG ON YUKSELEN 200=>300
while(sag_on_yukselen <= 300)
{
  sag_on_yukselen = sag_on_yukselen + ((1)*(z));  
  
  sag_on_uc = 325;         //artinca disa gidiyor
  //sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);


//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
/*
sag on ucu ice dogru gelir
SOL ON 90 derece olur 
sag arka geriye gider
sol arka biraz geri gider ama uc kismi disa dogru ittirir
*/


//SAG ON UC 325=>225  ,  SOL ON DONEN 275=>375  ,  SAG ARKA DONEN 375=>225  ,  SOL ARKA DONEN 525=>550  , SOL ARKA UC 225=>325
while((sag_on_uc >= 225) & (sol_on_donen <= 375) & (sag_arka_donen >= 225) & (sol_arka_donen <= 550) & (sol_arka_uc <= 325))
{
  sag_on_uc = sag_on_uc - ((1)*(z));                      //100
  sol_on_donen = sol_on_donen + ((1)*(z));                //100      125lik fark olmali ve 12 olmali sol on donen 250 den  375 e gitmeli??!!
  sag_arka_donen = sag_arka_donen - (((1)+(0.5))*(z));  //150       250 ye giderse 125 olur??
  sol_arka_donen = sol_arka_donen + ((0.25)*(z));       //25
  sol_arka_uc = sol_arka_uc + ((1)*(z));                  //100
  
  //sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  //sol_on_donen = 375;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 225;   //artinca sola donuyor      BURASI 250 mi olmali??     

  //sol_arka_donen = 550;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  //sol_arka_uc = 325;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);





//sol arka 90 dereceye gelir ve dongu tekrar baslar

//-------------- SOL ARKA ADIM ATAR -------------


//SOL ARKA YUKSELEN 300=>200  , SOL ARKA DONEN 550=>375  , SOL ARKA UC 325=>225
while((sol_arka_yukselen >=200 ) & (sol_arka_donen >=375 ) & (sol_arka_uc >=225 ))
{
  sol_arka_yukselen = sol_arka_yukselen - ((1)*(z)) ;         //100
  sol_arka_donen = sol_arka_donen - (((1)+(0.75))*(z)) ;    //175    
  sol_arka_uc = sol_arka_uc - ((1)*(z)) ;                     //100
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 375;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 225;   //artinca sola donuyor      BURASI 250 mi olmali??     

  //sol_arka_donen = 375;   //artinca saga donuyor
  //sol_arka_yukselen = 200;//artinca asagi gidiyor
  //sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);

// SOL ARKA INER

//SOL ARKA YUKSELEN 200=>300
while(sol_arka_yukselen <=300 )
{
  sol_arka_yukselen = sol_arka_yukselen + ((1)*(z));   
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 375;      //artinca saga donuyor
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 225;   //artinca sola donuyor      BURASI 250 mi olmali??     

  sol_arka_donen = 375;   //artinca saga donuyor
  //sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  
}

delay(x);


       
        nodeMcuDurumu1;
        nodeMcuDurumu2;
        nodeMcuDurumu3;
        nodeMcuDurumu4;
        //nodeMcuDurumu1 = LOW;    //Dongu sonunda low atanir
      
      }

       
//--------------SOLA DONUS------------------------------SOLA DONUS---------------- 
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------      
//--------------SOLA DONUS------------------------------SOLA DONUS---------------- 
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
//--------------SOLA DONUS------------------------------SOLA DONUS----------------
         
        
    if(nodeMcuDurumu2 == HIGH)
      {
        Serial.println("nodeMcu 222222");
        Serial.println(nodeMcuDurumu2);

//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

//---------------- Sol arka adim atar ----------------


//
/* 
sol arka havaya kalkip tam carpraz oluyo
sol on 90 dereceden 1/3 carpraz oluyo
sag on carprazdan 90 oluyo ama soyleki; sol on donerken azicik carpraz sol arka donerken azicik carpraz , yani ikisinin toplami 90 derece ediyor
sag arka da az carprazdan ful carpraz
*/
// SOL ARKA YUKSELEN 300=>200 , SOL ARKA DONEN 375=>475 , SOL ON DONEN 375=>325 , SAG ON DONEN 500=>450 ,SAG ARKA DONEN 250=>200                            
while((sol_arka_yukselen >= 200) & (sol_arka_donen <= 475) & (sol_on_donen >= 325) & (sag_on_donen >= 450) & (sag_arka_donen >= 200))
  {
   sol_arka_yukselen = sol_arka_yukselen - ((1)*(z));     //100
   sol_arka_donen = sol_arka_donen + ((1)*(z));       //100
   sol_on_donen = sol_on_donen - ((0.50)*(z));           //50
   sag_on_donen = sag_on_donen - ((0.50)*(z));           //50
   sag_arka_donen = sag_arka_donen - ((0.50)*(z));       //50

    
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 450;      //artinca sola donuyor

  //sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 200;   //artinca sola donuyor      

  //sol_arka_donen = 475;   //artinca saga donuyor
  //sol_arka_yukselen = 200;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


//SOL ARKA ADIM INIYOR


// SOL ARKA YUKSELEN 200=>300 , SOL ARKA DONEN 475=>525
while((sol_arka_yukselen <= 300) & (sol_arka_donen <= 525))
  {
  sol_arka_yukselen = sol_arka_yukselen + ((1)*(z));    //100
  sol_arka_donen = sol_arka_donen + ((0.50)*(z));     //50
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 450;      //artinca sola donuyor

  sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 200;   //artinca sola donuyor      

  //sol_arka_donen = 525;   //artinca saga donuyor
  //sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);



// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN

  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 450;      //artinca sola donuyor

  sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 200;   //artinca sola donuyor      

  sol_arka_donen = 525;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  


delay(x);

//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

//--------------- Sag arka adim atar -----------------

/*
sag arka kalkarak 90 oluyor
sag on 90 oluyor
sol on sola gider carpraza dogru
sol arka sola gider tam carpraz olur
*/


// SAG ARKA YUKSELEN 450=>550 , SAG ARKA DONEN 200=>375 , SAG ON DONEN 450=>375 , SOL ON DONEN 325=>275 , SOL ARKA DONEN 525=>475
while((sag_arka_yukselen <= 550) & (sag_arka_donen <= 325) & (sag_on_donen >= 375) & (sol_on_donen >= 275) & (sol_arka_donen >= 475))
  {
  sag_arka_yukselen = sag_arka_yukselen + ((1)*(z));         //100
  sag_arka_donen = sag_arka_donen + ((1.25)*(z));          //125
  sag_on_donen = sag_on_donen - ((0.75)*(z));              //75
  sol_on_donen = sol_on_donen - ((0.50)*(z));               //50
  sol_arka_donen = sol_arka_donen - ((0.50)*(z));           //50

   
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 375;      //artinca sola donuyor

  //sol_on_donen = 275;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 550;//artinca yukari gidiyor
  //sag_arka_donen = 325;   //artinca sola donuyor      

  //sol_arka_donen = 475;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


// SAG ARKA ADIM INIYOR


// SAG ARKA YUKSELEN 550=>450 , SAG ARKA DONEN 325=>375
while((sag_arka_yukselen >= 450) & (sag_arka_donen <= 375))
  {
  sag_arka_yukselen = sag_arka_yukselen - ((1)*(z));       
  sag_arka_donen = sag_arka_donen + ((1)*(z));
   
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 375;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 475;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);




// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN       

   
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 375;      //artinca sola donuyor

  sol_on_donen = 275;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 375;   //artinca sola donuyor      

  sol_arka_donen = 475;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  


delay(x);

//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333


//--------------- Sag on adim atar -----------------
/*
sag on havaya kalkar ve carpraz olur
sol on full carpraz oldu belki biraz gecti
sol arka 90 dereceye cok yaklasti (belki 50 birimi kaldi)
sag arka carpraz gibi oldu
*/

// SAG ON YUKSELEN 300=>200 , SAG ON DONEN 375=>425 , SOL ON DONEN 275=>225 , SOL ARKA DONEN 475=>425 ,  SAG ARKA DONEN 375=>325
while((sag_on_yukselen >= 200) & (sag_on_donen <= 425) & (sol_on_donen >= 225) & (sol_arka_donen >= 425) & (sag_arka_donen >=325))
  {
  sag_on_yukselen = sag_on_yukselen - ((1)*(z));         //100    
  sag_on_donen = sag_on_donen + ((1)*(z));               //50    BURAYI BELKI TEKRAR 100 YAPARIZ ################################################
  sol_on_donen = sol_on_donen - ((0.5)*(z));           //50
  sol_arka_donen = sol_arka_donen - ((0.5)*(z));       //50
  sag_arka_donen = sag_arka_donen - ((0.5)*(z));       //50

  
  sag_on_uc = 225;         //artinca disa gidiyor
  //sag_on_yukselen = 200;   //artinca asagi gidiyor
  //sag_on_donen = 425;      //artinca sola donuyor      100 birim dondu yani digerki harekette 50, sonraki iki hareketinde 25, 25 olacak ve 375 e geri gelecek 

  //sol_on_donen = 225;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 325;   //artinca sola donuyor      digerinde de 50 dusecek 275 sonrasinda 100 

  //sol_arka_donen = 425;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);

//SAG ON ADIM INIYOR

// SAG ON YUKSELEN 200=>300 , SAG ON DONEN 425=>475 
while((sag_on_yukselen <= 300) & (sag_on_donen <= 475))
  {
  sag_on_yukselen = sag_on_yukselen + ((1)*(z));           
  sag_on_donen = sag_on_donen + ((1)*(z));
  
  sag_on_uc = 225;         //artinca disa gidiyor
  //sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 475;      //artinca sola donuyor      

  sol_on_donen = 225;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 325;   //artinca sola donuyor      

  sol_arka_donen = 425;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);





// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN

  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 475;      //artinca sola donuyor      

  sol_on_donen = 225;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 325;   //artinca sola donuyor      

  sol_arka_donen = 425;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  


delay(x);



//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444



//------------- Sol on adim atar ----------

/*
sol on yukselip iner ve 90 derece olur
sol arka da 90 derece olur
sag arka carpraz olur(saga doner, ama asiri donmez)
sag on 25 birim gibi saga gider 90 dereceye yaklasir, diger iki hareket sonrasi(sol arka ve sag arka)90 olur
*/

// SOL ON YUKSELEN 450=>550 , SOL ON DONEN 225=>325 , SOL ARKA DONEN 425=>375 , SAG ARKA DONEN 375=>250 , SAG ON DONEN 475=>500
while((sol_on_yukselen <= 550) & (sol_on_donen <= 325) & (sol_arka_donen >= 375) & (sag_arka_donen >= 250) & (sag_on_donen <= 500))
  {
  sol_on_yukselen = sol_on_yukselen + ((1)*(z));         //100         
  sol_on_donen = sol_on_donen + ((1)*(z));               //100
  sol_arka_donen = sol_arka_donen - ((0.50)*(z));      //50
  sag_arka_donen = sag_arka_donen - ((1.25)*(z));      //125
  sag_on_donen = sag_on_donen + ((0.25)*(z));          //25
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 500;      //artinca sola donuyor     

  //sol_on_donen = 325;      //artinca saga donuyor        
  //sol_on_yukselen = 550;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 250;   //artinca sola donuyor        

  //sol_arka_donen = 375;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


// SOL ON INIYOR

// SOL ON YUKSELEN 550=>450 , SOL ON DONEN 325=>375
while((sol_on_yukselen >= 450) & (sol_on_donen <= 375))
  {
  sol_on_yukselen = sol_on_yukselen - ((1)*(z)); //100
  sol_on_donen = sol_on_donen + ((0.50)*(z));  //50
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor     

  //sol_on_donen = 375;      //artinca saga donuyor        
  //sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 250;   //artinca sola donuyor        

  sol_arka_donen = 375;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);



  //BURASI BASLANGICLA CAKISIP, WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor     

  sol_on_donen = 375;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 250;   //artinca sola donuyor        

  sol_arka_donen = 375;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinca disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  


delay(x);



        nodeMcuDurumu1;
        nodeMcuDurumu2;
        nodeMcuDurumu3;
        nodeMcuDurumu4;
      //nodeMcuDurumu2 = LOW;    //Dongu sonunda low atanir
     
      
      }


//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
//----------------------- KABARMA - ZIPLAMA -------------------------
 
    if(nodeMcuDurumu3 == HIGH)
      {
        Serial.println("nodeMcu 333333");
        Serial.println(nodeMcuDurumu3);

        
        sag_on_uc = 450;         //artinda disa gidiyor
        sag_on_yukselen = 500;   //artinca asagi gidiyor
        sag_on_donen = 500;      //artinca sola donuyor

        sol_on_donen = 250;      //artinca saga donuyor
        sol_on_yukselen = 250;   //artinca yukari gidiyor
        sol_on_uc = 325;         //artinca ice gidiyor

        sag_arka_uc = 400;       //artinca ice gidiyor  montaj hatasindan oturu 500 yapilacak
        sag_arka_yukselen = 425;//artinca yukari gidiyor
        sag_arka_donen = 250;   //artinca sola donuyor  

        sol_arka_donen = 500;   //artinca saga donuyor
        sol_arka_yukselen = 325;//artinca asagi gidiyor
        sol_arka_uc = 325; 


        pwm.setPWM(0 ,0 , sag_on_uc);  //
        pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
        pwm.setPWM(2 ,0 , sag_on_donen);  //     
        pwm.setPWM(3 ,0 , sol_on_donen);
        pwm.setPWM(4 ,0 , sol_on_yukselen);        
        pwm.setPWM(5 ,0 , sol_on_uc);
        pwm.setPWM(6 ,0 , sag_arka_uc);  
        pwm.setPWM(7 ,0 , sag_arka_yukselen);  
        pwm.setPWM(8 ,0 , sag_arka_donen);  
        pwm.setPWM(9 ,0 , sol_arka_donen);  //
        pwm.setPWM(10 ,0 , sol_arka_yukselen); //
        pwm.setPWM(11 ,0 , sol_arka_uc); //

        delay(y);

        delay(x);
        

        nodeMcuDurumu1;
        nodeMcuDurumu2;
        nodeMcuDurumu3;
        nodeMcuDurumu4;

       }

    




//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------
//------------------------------- SAGA DONUS ------------------------






    if(nodeMcuDurumu4 == HIGH)
      {
        Serial.println("nodeMcu 444444");
        Serial.println(nodeMcuDurumu4);

//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111




//------------- Sol on adim atar ----------

/*   BENIM BAKIS ACIMA GORE (ON TARAF SOLA BAKIYOR)
 *    sol on kalkti sola gitti ( carpraz oldu)
 *    sag on hafif sola gider (carpraz olur
 *    sag arka sola gider 90 a cok yakin
 *    sol arka tam 90dan cok azicik saga gider
*/   

//   SOL ON YUKSELEN 450=>550 , SOL ON DONEN 375=>300 , SAG ON DONEN 500=>550 , SAG ARKA DONEN 250=>350 , SOL ARKA DONEN 375=>400 
while((sol_on_yukselen <= 550) & (sol_on_donen >= 300 ) & (sag_on_donen <= 550 ) & (sag_arka_donen <= 350 ) & (sol_arka_donen <= 400 ))
  {
  sol_on_yukselen = sol_on_yukselen + ((1)*(z));         //100       
  sol_on_donen = sol_on_donen - ((0.75)*(z));               //75
  sag_on_donen = sag_on_donen + ((0.50)*(z));          //50
  sag_arka_donen = sag_arka_donen + ((1)*(z));      //100
  sol_arka_donen = sol_arka_donen + ((0.25)*(z));      //25

  
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 550;      //artinca sola donuyor     

  //sol_on_donen = 300 ;      //artinca saga donuyor        
  //sol_on_yukselen = 550 ;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 350;   //artinca sola donuyor        

  //sol_arka_donen = 400;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


// SOL ON INIYOR

// SOL ON YUKSELEN 550=>450 , SOL ON DONEN 300=>275
while((sol_on_yukselen >= 450) & (sol_on_donen >= 275 ))
  {
  sol_on_yukselen = sol_on_yukselen - ((1)*(z)); //100
  sol_on_donen = sol_on_donen - ((0.25)*(z));  //25
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 550;      //artinca sola donuyor     

  //sol_on_donen = 275;      //artinca saga donuyor        
  //sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 350;   //artinca sola donuyor        

  sol_arka_donen = 400;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);



  //BURASI BASLANGICLA CAKISIP, WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN
  



  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 550;      //artinca sola donuyor     

  sol_on_donen = 275;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 350;   //artinca sola donuyor        

  sol_arka_donen = 400;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);



delay(x);







//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

//--------------- Sag on adim atar -----------------
/*
    sag on kalkar ve saga giderek tam 90 olur
    sag arka 90 i da asar ve sola gider, sag on un dibine
    sol arka, saga gider ama carpraz olmadi
    sol on saga gider
*/

//   SAG ON YUKSELEN 300=>200 , SAG ON DONEN 550=>425 , SAG ARKA DONEN 350=>400 , SOL ARKA DONEN 400=>450 , SOL ON DONEN 275=>300 
while((sag_on_yukselen >= 200) & (sag_on_donen >= 425) & (sag_arka_donen <= 400) & (sol_arka_donen <= 450) & (sol_on_donen <=300 ))
  {
  sag_on_yukselen = sag_on_yukselen - ((1)*(z));         //    100
  sag_on_donen = sag_on_donen - ((1.25)*(z));               // 125
  sag_arka_donen = sag_arka_donen + ((0.50)*(z));        //50
  sol_arka_donen = sol_arka_donen + ((0.50)*(z));       //50
  sol_on_donen = sol_on_donen + ((0.25)*(z));           //25

       

  
  sag_on_uc = 225;         //artinca disa gidiyor
  //sag_on_yukselen = 200;   //artinca asagi gidiyor
  //sag_on_donen = 425 ;      //artinca sola donuyor      100 birim dondu yani digerki harekette 50, sonraki iki hareketinde 25, 25 olacak ve 375 e geri gelecek 

  //sol_on_donen = 300;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 400;   //artinca sola donuyor      digerinde de 50 dusecek 275 sonrasinda 100 

  //sol_arka_donen = 450;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);

//SAG ON ADIM INIYOR

// SAG ON YUKSELEN 200=>300 , SAG ON DONEN 425=>375 
while((sag_on_yukselen <= 300) & (sag_on_donen >= 375))
  {
  sag_on_yukselen = sag_on_yukselen + ((1)*(z));           
  sag_on_donen = sag_on_donen - ((0.50)*(z));
  
  sag_on_uc = 225;         //artinca disa gidiyor
  //sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 375;      //artinca sola donuyor      

  sol_on_donen = 300;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 400;   //artinca sola donuyor      

  sol_arka_donen = 450;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);





// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN

  

  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 375;      //artinca sola donuyor      

  sol_on_donen = 300;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 400;   //artinca sola donuyor      

  sol_arka_donen = 450;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);







delay(x);




//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333


//--------------- Sag arka adim atar -----------------

/*
 * sag arka adim tam carpraz oluyor saga donuyor
   sol arka adim tam carpraz oluyor saga donuyo
   sol on cok az saga donuyo
   sag on sola 50 falan donuyo 375 i geciyo 425 falan on sol ve on sagnin konumlari ayni eger biri 425 ise digeri 325

*/


// SAG ARKA YUKSELEN 450=>550 , SAG ARKA DONEN 400=>325 , SOL ARKA DONEN 450=>500 , SOL ON DONEN 300=>325 , SAG ON DONEN 375=>425  
while((sag_arka_yukselen <= 550) & (sag_arka_donen >= 325) & (sol_arka_donen <= 500) & (sol_on_donen <= 325) & (sag_on_donen <= 425))
  {
  sag_arka_yukselen = sag_arka_yukselen + ((1)*(z));         //100
  sag_arka_donen = sag_arka_donen - ((0.75)*(z));             //75
  sol_arka_donen = sol_arka_donen + ((0.50)*(z));            //50
  sol_on_donen = sol_on_donen + ((0.25)*(z));                //25
  sag_on_donen = sag_on_donen + ((0.50)*(z));                //50



   
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 425;      //artinca sola donuyor

  //sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 550;//artinca yukari gidiyor
  //sag_arka_donen = 350;   //artinca sola donuyor      

  //sol_arka_donen = 500;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


// SAG ARKA ADIM INIYOR


// SAG ARKA YUKSELEN 550=>450 , SAG ARKA DONEN 325=>300
while((sag_arka_yukselen >= 450) & (sag_arka_donen >= 300))
  {
  sag_arka_yukselen = sag_arka_yukselen - ((1)*(z));       
  sag_arka_donen = sag_arka_donen - ((0.50)*(z));
   
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 425;      //artinca sola donuyor

  sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  //sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 300;   //artinca sola donuyor      

  sol_arka_donen = 500;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);




// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN       

   

  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 425;      //artinca sola donuyor

  sol_on_donen = 325;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 300;   //artinca sola donuyor      

  sol_arka_donen = 500;   //artinca saga donuyor
  sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);





  


delay(x);



//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

//---------------- Sol arka adim atar ----------------


//
/* 
sol arka 90 derece
sol on 90 derece
sag on azicik sola donuyo 50 yada 25
sag arka sola 50 
BUARADA ZATEN BASLANGIC DEGERLERINI ALACAKLAR ORAYA BAKIP YAPABILIRSIN

*/
// SOL ARKA YUKSELEN 300=>200 , SOL ARKA DONEN 500=>400 , SOL ON DONEN 325=>375 , SAG ON DONEN 425=>500 ,SAG ARKA DONEN 300=>250                            

while((sol_arka_yukselen >= 200) & (sol_arka_donen >= 400) & (sol_on_donen <= 375) & (sag_on_donen <= 500) & (sag_arka_donen >= 250))
  {
   sol_arka_yukselen = sol_arka_yukselen - ((1)*(z));     //100
   sol_arka_donen = sol_arka_donen - ((1)*(z));       //100
   sol_on_donen = sol_on_donen + ((0.5)*(z));           //50
   sag_on_donen = sag_on_donen + ((0.75)*(z));           //75
   sag_arka_donen = sag_arka_donen - ((0.50)*(z));       //50

    
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  //sag_on_donen = 500;      //artinca sola donuyor

  //sol_on_donen = 375;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  //sag_arka_donen = 250;   //artinca sola donuyor      

  //sol_arka_donen = 400;   //artinca saga donuyor
  //sol_arka_yukselen = 200;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);


//SOL ARKA ADIM INIYOR


// SOL ARKA YUKSELEN 200=>300 , SOL ARKA DONEN 400=>375
while((sol_arka_yukselen <= 300) & (sol_arka_donen >= 375))
  {
  sol_arka_yukselen = sol_arka_yukselen + ((1)*(z));    //100
  sol_arka_donen = sol_arka_donen - ((0.25)*(z));     //25
  
  sag_on_uc = 225;         //artinca disa gidiyor
  sag_on_yukselen = 300;   //artinca asagi gidiyor
  sag_on_donen = 500;      //artinca sola donuyor

  sol_on_donen = 375;      //artinca saga donuyor        
  sol_on_yukselen = 450;   //artinca yukari gidiyor
  sol_on_uc = 525;         //artinca ice gidiyor

  sag_arka_uc = 500;       //artinca ice gidiyor
  sag_arka_yukselen = 450;//artinca yukari gidiyor
  sag_arka_donen = 250;   //artinca sola donuyor      

  //sol_arka_donen = 375;   //artinca saga donuyor
  //sol_arka_yukselen = 300;//artinca asagi gidiyor
  sol_arka_uc = 225;      //artinda disa gidiyor
 
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);

  }


delay(x);



// BURASI BASLANGICLA CAKISIP WHILE DONGUSUNUN BOZULMASINI ENGELLEMEK ICIN





 sag_on_uc = 225;         //artinda disa gidiyor
 sag_on_yukselen = 300;   //artinca asagi gidiyor
 sag_on_donen = 500;      //artinca sola donuyor

 sol_on_donen = 375;      //artinca saga donuyor
 sol_on_yukselen = 450;   //artinca yukari gidiyor
 sol_on_uc = 525;         //artinca ice gidiyor

 sag_arka_uc = 500;       //artinca ice gidiyor
 sag_arka_yukselen = 450;//artinca yukari gidiyor
 sag_arka_donen = 250;   //artinca sola donuyor  

 sol_arka_donen = 375;   //artinca saga donuyor
 sol_arka_yukselen = 300;//artinca asagi gidiyor
 sol_arka_uc = 225;      //artinda disa gidiyor




delay(x);

        nodeMcuDurumu1;
        nodeMcuDurumu2;
        nodeMcuDurumu3;
        nodeMcuDurumu4;

      }








//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------
//--------------------- ELSE --------------------- ELSE -----------------------

      
     else
      {
        Serial.println("ELSE");
            
            
 sag_on_uc = 225;         //artinda disa gidiyor
 sag_on_yukselen = 300;   //artinca asagi gidiyor
 sag_on_donen = 500;      //artinca sola donuyor

 sol_on_donen = 375;      //artinca saga donuyor
 sol_on_yukselen = 450;   //artinca yukari gidiyor
 sol_on_uc = 525;         //artinca ice gidiyor

 sag_arka_uc = 500;       //artinca ice gidiyor
 sag_arka_yukselen = 450;//artinca yukari gidiyor
 sag_arka_donen = 250;   //artinca sola donuyor  

 sol_arka_donen = 375;   //artinca saga donuyor
 sol_arka_yukselen = 300;//artinca asagi gidiyor
 sol_arka_uc = 225;      //artinda disa gidiyor
      
  pwm.setPWM(0 ,0 , sag_on_uc);  //
  pwm.setPWM(1 ,0 , sag_on_yukselen);  //     
  pwm.setPWM(2 ,0 , sag_on_donen);  //     
  pwm.setPWM(3 ,0 , sol_on_donen);
  pwm.setPWM(4 ,0 , sol_on_yukselen);        
  pwm.setPWM(5 ,0 , sol_on_uc);
  pwm.setPWM(6 ,0 , sag_arka_uc);  
  pwm.setPWM(7 ,0 , sag_arka_yukselen);  
  pwm.setPWM(8 ,0 , sag_arka_donen);  
  pwm.setPWM(9 ,0 , sol_arka_donen);  //
  pwm.setPWM(10 ,0 , sol_arka_yukselen); //
  pwm.setPWM(11 ,0 , sol_arka_uc); //

  delay(y);
      
        nodeMcuDurumu1;
        nodeMcuDurumu2;
        nodeMcuDurumu3;
        nodeMcuDurumu4;
      
      //digitalWrite(8, LOW);
      }


delay(x);













    
}
