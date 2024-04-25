/**
Dylan Jarvis, Catherine Tan 
ECE4180 Section B Spring 2024 Final Project 
Georgia Institute of Technology

Smart Water Fountain System
The Smart Water Fountain System is a solution designed to ensure our cats always have access to fresh, 
flowing water. Using Sparkfun Load Cells for water level monitoring, this system gives visual and audible
 cues to pet owners as a reminder to refill the fountain.
*/

#include "cmsis_os.h"
#include "mbed.h"
#include "rtos.h"
#include "SDFileSystem.h"       
#include "wave_player.h"        
#include "ML_HX711_LoadCell.h"

SDFileSystem sd(p11, p12, p13, p8, "sd"); //SD card DI, DO, SCK, CS

// load cell stuff 
ML_HX711_LoadCell loadcellamp(p5, p6);  // DAT, CLK p5, p6
float calibration_factor = -11; // a default value
int averageSamples = 150;

AnalogOut DACout(p18);       // connected Class D audio amp to p18
wave_player waver(&DACout);

// Assuming RGB LED is connected to PWM-capable pins
PwmOut rLed(p21); // Replace p21 with the actual pin connected to the red LED
PwmOut gLed(p22); // Replace p22 with the actual pin connected to the green LED
PwmOut bLed(p23); // Replace p23 with the actual pin connected to the blue LED

Mutex mutex;
bool playSound = false;
const char* wave_file_path = "/sd/low.wav";

void speakerThread() {
    printf("Speaker thread starting\n");
    fflush(stdout);  // Ensure the message is printed out immediately

    while (true) {
        mutex.lock();
        bool shouldPlaySound = playSound;
        mutex.unlock();

        if (shouldPlaySound) {
            FILE* wave_file = fopen(wave_file_path, "r");
            if (wave_file != NULL) {
                waver.play(wave_file);
                fclose(wave_file);
            } else {
                printf("Failed to open wave file!\n");
                fflush(stdout);
            } // if
        } // if

        Thread::wait(10000); // Wait before rechecking, adjust as needed for your use case
    } // while
} // speakerThread

int main(void) {

    printf("HX711 calibration sketch\n");
    printf("Place the thin metal sheet (97g) on the scale\n");
    printf("Wait for the scale to tare\n\n");

    loadcellamp.setScale(calibration_factor); // Set your calibration factor
    wait(1); // Wait for the scale to settle
    loadcellamp.tare(averageSamples); // Tare the scale with the metal sheet on it
    printf("Tare complete. Place known weight on scale\n");
    
    Thread spkrThread;
    spkrThread.start(speakerThread);

    while (true) {
        float weight = loadcellamp.getGram();
        printf("Weight: %.2fg, calib: %.2f\n", weight, calibration_factor);
        mutex.lock();
        if (weight <= 1420){
            rLed = 1.0; gLed = 0.0; bLed = 0.0;
            playSound = true;
        } else if (weight <= 1724 && weight >= 1520) {
            rLed = 0.0; gLed = 0.0; bLed = 1.0;
            playSound = false;
        } else if (weight >= 1800){
            rLed = 0.0; gLed = 1.0; bLed = 0.0;
            playSound = false;
        }
        mutex.unlock();
        Thread::wait(1000);
        Thread::yield(); // Explicitly yield the processor to other threads
    } //while
} // main
