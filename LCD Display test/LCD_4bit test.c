#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Data_Dir    DDRB         /* Define LCD data port direction */
#define LCD_Command_Dir DDRC         /* Define LCD command port direction register */
#define LCD_Data_Port   PORTB        /* Define LCD data port */
#define LCD_Command_Port PORTC       /* Define LCD data port */
#define RS PC7                         /* Define Register Select (data/command reg.) pin */
#define RW PC6                         /* Define Read/Write signal pin */
#define EN PC5                         /* Define Enable signal pin */

void LCD_Command(unsigned char cmnd)
{
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmnd & 0xF0);
    LCD_Command_Port &= ~(1 << RS);
    LCD_Command_Port &= ~(1 << RW);
    LCD_Command_Port |= (1 << EN);
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_us(200);

    LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmnd << 4);
    LCD_Command_Port |= (1 << EN);
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Char(unsigned char data)
{
    LCD_Data_Port = (LCD_Data_Port & 0x0F) | (data & 0xF0);
    LCD_Command_Port |= (1 << RS);
    LCD_Command_Port &= ~(1 << RW);
    LCD_Command_Port |= (1 << EN);
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_us(200);

    LCD_Data_Port = (LCD_Data_Port & 0x0F) | (data << 4);
    LCD_Command_Port |= (1 << EN);
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Init(void)
{
    LCD_Data_Dir = 0xFF;
    LCD_Command_Dir |= (1 << RS) | (1 << RW) | (1 << EN);
    _delay_ms(20);

    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_String(char *str)
{
    int i;
    for (i = 0; str[i] != 0; i++)
    {
        LCD_Char(str[i]);
    }
}

void LCD_String_xy(char row, char pos, char *str)
{
    if (row == 0 && pos < 16)
        LCD_Command((pos & 0x0F) | 0x80);
    else if (row == 1 && pos < 16)
        LCD_Command((pos & 0x0F) | 0xC0);
    LCD_String(str);
}

void LCD_Clear()
{
    LCD_Command(0x01);
    _delay_ms(2);
    LCD_Command(0x80);
}

int main()
{
    LCD_Init();

    LCD_String("ElectronicWINGS");
    LCD_Command(0xC0);
    LCD_String("Hello World");

    while (1);
}

