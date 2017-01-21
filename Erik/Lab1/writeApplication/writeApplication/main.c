/*
 * writeApplication.c
 *
 * Created: 2017-01-18
 * Author : Erik Karlsson
 */

#include <avr/io.h>
#include <unistd.h>

void LCD_Init(void){
	/*
    TO-DO List:
		[x]drive time 300 microseconds,
		[x]contrast control voltage 3.35 V,
		[x]external asynchronous clock source,
		[x]1/3 bias,
		[x]1/4 duty cycle,
		[x]25 segments enabled,
		[x]prescaler setting N=16,
		[x]clock divider setting D=8,
		[x]LCD enabled,
		[x]low power waveform,
		[x]no frame interrupt,
		[x]no blanking
	*/

	/* Make the on-board processor run at its maximum speed */
	CLKPR = 0x80;
	CLKPR = 0x00;

	/* External asynchronous clock source, 1/3 Bias and 1/4 duty cycle, Segments 25 */
	LCDCRB = (1<<LCDCS) | (0<<LCD2B) | (1<<LCDMUX1) | (1<<LCDMUX0) | (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0);

	/* Using 16 as prescaler selection, 8 as LCD Clock Divide */
	LCDFRR = (0<<LCDPS2) | (0<<LCDPS1) | (0<<LCDPS0) | (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0);

	/* Set segment drive time to 300 ?s, set output voltage to 3.35V */
	LCDCCR = (0<<LCDDC2) | (0<<LCDDC1) | (0<<LCDDC0) | (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) | (1<<LCDCC0);

	/* Enable LCD, default waveform, no interrupt enabled and no blanking */
	LCDCRA = (1<<LCDEN) | (0<<LCDAB) | (0<<LCDIE) | (0<<LCDBL);

}

int main(void){
// LCD settings
LCD_Init();

// Lab1 part1
//writeChar(5,2);

//Just a print test
LCDDR0 = 0x0;
LCDDR5 = 0x4;
LCDDR10 = 0x4;
LCDDR15 = 0x0;
}

/*
public static writeChar(char ch, int pos){
	if (pos <= 6){

	} else {
		int charToInt = atoi(ch);

		if (charToInt <= 10){

		} else {

		}

	}
}
*/
