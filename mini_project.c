void main()
{
char speed=7;
ANSEL=0;
ANSELH=0;
TRISB=0;
TRISC=0;

sspstat = 0;                  // Set SMP=0 and CKE=1. Notes: The lower 6 bit is read only
sspcon = 0x20;                // Enable SPI Master with Fosc/4
while(1){
portb.f0 = 0;             // Activate the SS SPI Select pin
SSPBUF = speed;               // Start PIC16F887 Register Address transmission
while(!SSPIF_bit);          // Wait for Data Transmit/Receipt complete
portb.f0 = 1;            // CS pin is not active
SSPIF_bit=0;
delay_ms(100);
}
}
