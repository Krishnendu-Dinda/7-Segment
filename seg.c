#include<reg51.h>
#define DATA P2

unsigned int seg[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
											0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};   //  number/character hex value of 7-segment display.
unsigned int i,j,k; 

 void delay(){  //  Create a delay of 50mS.
  TMOD=0X01;   // Declear TMOD Resister as Timer 0 Mode 1.
	TH0=0x4B;		 // Load 4B to the TH0 resister.
	TL0=0xFD;		// Load FD to the TL0 resister.
	TR0=1;			//Start Timer 0 resister.
	 while(TF0==0);  // Check if timer 0 is overflow or not.
	 TR0=0;					//Stop Timer 0 resister.
	 TF0=0;					//Reset Timer 0 Overflow flag.
 }

int main(){	
	while(1){
	for(i=0;i<16;i++){
		DATA= (seg[i]);    //Send the hex values one by one to the port 2 as an output.
	
		for(j=0;j<20;j++){   // Call 50mS delay 20 times that behaved as 1Sec delay.
			delay();
			}	
		}
	}
}
