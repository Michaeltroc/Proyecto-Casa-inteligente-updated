/* 
 * File:   Programa_principal.c
 * Author: medar
 *
 * Created on 15 de julio de 2022, 02:59 PM
 */

#include <pic18f4550.h>
#include "Configuracion.h"
#include "USART_libreria.h"

#define LED LATDbits.LATD0             
void main()
{
    OSCCON=0x72;              /* use internal oscillator frequency
                                 which is set to * MHz */
    char data_in;
    TRISD = 0;                /* set PORT as output port */
    USART_Init(9600);         /* initialize USART operation with 9600 baud rate */ 
    MSdelay(50);
    while(1)
    {
        data_in=USART_ReceiveChar();
        if((data_in=='B') || (data_in=='b'))
        {   
            LED = 1;                    /* turn ON LED */
            USART_SendString("LED_ON"); /* send LED ON status to terminal */
        }
        else if((data_in=='A') ||(data_in=='a'))
                
        {
            LED = 0;                    /* turn OFF LED */
            USART_SendString("LED_OFF");/* send LED ON status to terminal */
        }
        else
        {
            USART_SendString(" select a or b");/* send msg to select proper option */
        }
        MSdelay(100);
    
    }
    
}
