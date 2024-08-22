#define F_CPU 8000000UL /* Define CPU Frequency as 8MHz */
#include <avr/io.h>		/* Include AVR standard library */
#include <util/delay.h> /* Include inbuilt delay functions */

#define IR_SENSOR_PIN PD3 // Pin where IR sensor is connected
#define LED_PIN PD7		  // Pin where the LED is connected

void initIRSensor(void)
{
	DDRD &= ~(1 << IR_SENSOR_PIN); // Set IR sensor pin as input
	PORTD |= (1 << IR_SENSOR_PIN); // Enable pull-up resistor for IR sensor
}

int isObstacleDetected(void)
{										   // Function to check if obstacle is detected
	return !(PIND & (1 << IR_SENSOR_PIN)); // Return 1 if obstacle detected, else 0
}

void initLED(void)
{
	DDRD |= (1 << LED_PIN);	  // Set LED pin as output
	PORTD &= ~(1 << LED_PIN); // Ensure LED is off initially
}

int main(void)
{
	initIRSensor(); // Initialize IR sensor
	initLED();		// Initialize LED

	while (1)
	{
		if (isObstacleDetected())
		{
			PORTD |= (1 << LED_PIN); // Turn on the LED when an obstacle is detected
		}
		else
		{
			PORTD &= ~(1 << LED_PIN); // Turn off the LED when no obstacle is detected
		}

		_delay_ms(100); // Small delay for sensor debounce and stability
	}

	return 0;
}
