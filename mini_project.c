void main() 
{
   portbbit.RB0 = 0;             // Activate the SS SPI Select pin
   sspstat = 0;                  // Set SMP=0 and CKE=1. Notes: The lower 6 bit is read only
   sspcon1 = 0  ;                // Enable SPI Master with Fosc/4
   SSPBUF = SPI_SLAVE_ID | ((SPI_SLAVE_speed << 1) & 0x0E)| SPI_SLAVE_WRITE;// Start PIC16F887 OpCode transmission
while(!SSPSTATbits.BF);          // Wait for Data Transmit/Receipt complete
   SSPBUF = speed;               // Start PIC16F887 Register Address transmission                               
while(!SSPSTATbits.BF);          // Wait for Data Transmit/Receipt complete
   SSPBUF = portbbit.RB0;        // Start Data transmission        
while(!SSPSTATbits.BF);          // Wait for Data Transmit/Receipt complete
    portbbit.RB0 = 1;            // CS pin is not active  
}
