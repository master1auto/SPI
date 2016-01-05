void main() {
portb = 0b00000001;
sspstat =0b11000000;
sspcon =0b00000000  ;
pir1=0b00000000      ;
sspcon2=0b00000001    ;
sspbuf=portb           ;
sspcon2=0b00000001;
sspbuf=0b00010000 ;// speed = 10d
while(sspif!=1);


}
