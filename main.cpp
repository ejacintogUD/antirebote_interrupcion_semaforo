/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "InterruptIn.h"
#include "PinNames.h"
#include "Semaphore.h"
#include "Thread.h"
#include "mbed.h"
#include <cstdio>

InterruptIn btn (BUTTON1);

Thread hilo_rebote;
Semaphore semaforo_btn;

void rebote (void);
void btn_isr (void);


int main()
{
    printf("Arranque del programa \n\r");
    btn.fall(btn_isr);
    hilo_rebote.start(rebote);

    while (true) {
  
    }
}

void btn_isr(void)
{
 // instruccion atomica 
semaforo_btn.release();
}


void rebote(void)
{
    int i=0;
    while(true)
    {
        semaforo_btn.acquire();
      //  btn.disable_irq();
        //ThisThread::sleep_for(100ms);
        //if (!btn.read())
        //{
            printf("Se oprimio N: %u veces\n\r", i++);
        //}
    
     //   btn.enable_irq();



    }
}