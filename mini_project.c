void myspi_init(){
sspstat = 0;                  // Set SMP=0 and CKE=0. Notes: The lower 6 bit is read only
sspcon = 0x20;                // Enable SPI Master with Fosc/4  
}
void myspi_write(char mydata){
portb.f0 = 0;             
SSPBUF = mydata;               // Start PIC16F887 Register Address transmission
while(!SSPIF_bit); // Wait for Data Transmit to complete
portb.f0 = 1;            
SSPIF_bit=0;
}
void main()
{
char speed=7;
ANSEL=0;
ANSELH=0;
TRISB=0;
TRISC=0;
myspi_init();
myspi_write(speed);
}
