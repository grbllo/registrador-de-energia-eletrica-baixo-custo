# registrador-de-energia-eletrica-baixo-custo
# Projeto para meu TCC
# Auth: Gabriel Michels Rebello


Projeto de TCC com objetivo de criar um prototipo de registrador de energia de baixo custo com uma boa precisao

Itens usandos na V1.0
Arduino Uno
Pzem004-V3.0
Display grafico 128x64 com controlador ST7920
fonte 5v

conexao display:
GND do display no GND do arduino
VCC do display no 5V da fonte
RS do display no pino D10 do arduino
R/W do display no pino D11 do arduino
E do display no pino D13 do arduino
PSB do display no pino GND do arduino
BLA do display no pino 3.3V do arduino
BLk do display no pino GND do arduino

Conexao Pzem004-V3.0
GND do Pzem no GND do arduino
5V do Pzem no 5V da fonte
RX do pzem no pino D4 do arduino
TX do pzem no pino D7 do arduino

Bibliotecas usadas:
Biblioteca do pzem     ------>  https://github.com/mandulaj/PZEM-004T-v30
Biblioteca do display  ------>  https://github.com/olikraus/u8g2

![foto dele funcionando medindo uma lampada](https://user-images.githubusercontent.com/102438210/169173309-7d9c7756-7d62-417a-ab35-3e839be98f4f.jpeg)
![foto dele funcionando medindo outra lampada](https://user-images.githubusercontent.com/102438210/169173334-f138024e-14ad-4722-b19a-9e9a2185a30a.jpeg)
