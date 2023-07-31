#line 1 "E:/Youssef/Embeded/Traffic Lights/MikroC/TrafficLights.c"


int const Del=500;
int i, click=0 ;
void lightAuto (int ,int );
void CheckingManual (void) ;
int lightManual (void);
void ChangeLights( int x,int y );



char seg [] = {0,1,2,3,4,5,6,7,8,9,16,17,18,19,20,21,22,23,24,25,32,33,34,35};

void main() {
 trisb=0b00000000;
 trisd=0b00110000;
 trisc=0b00000000;



 loop :
 if (portd.B4==0)
 {
 lightAuto (15, 12);
 lightAuto (23 , 33);
 }
 else lightManual();

 goto loop;

}

void lightAuto (int x ,int y)
{
 portb=y;
 portd = 15 ;
 for ( i =x;i > 0;i--)
 {


 CheckingManual ();
 if (i==3&&x==15)
 portb=10;

 else if (i==3&&x==23)
 portb=17;

 portc = seg[i] ;
 delay_ms(Del);
 }
 }


 int lightManual (void)
 {
 portc=0;
 portd=0;

 loop2:

 if(portd.B4==1 && portd.B5==1)
 { ChangeLights(10,12);
 if (portd.B4==0)
 return 0;


 if(portd.B4==1 && portd.B5==1)
 {
 ChangeLights(17,33);
 if (portd.B4==0)
 return 0;
 }


 }

 if(portd.B4==0)
 { portd=15; return 0; }
 goto loop2 ;

 }


void CheckingManual (void)
 {
 if (portd.B4==1)
 lightManual();
 }



void ChangeLights( int x,int y )
 {
 portd=15;
 portb=x;
 for (i=3 ; i > 0 ; i--)
 {
 portc = seg[i] ;
 delay_ms(Del);
 }
 portd=0;
 portb=y;
 while(portd.B4==1 && portd.B5==0);

 }
