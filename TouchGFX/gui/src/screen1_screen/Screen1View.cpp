#include <gui/screen1_screen/Screen1View.hpp>
#include<cmsis_os.h>
extern osMessageQId myQueue01Handle;
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	Screen1ViewBase::handleTickEvent();
    tickCount++;
    static uint32_t prevTick =0;
    float rad =0;
    uint8_t res=0;
    uint32_t count = osMessageQueueGetCount(myQueue01Handle);
    if(count >0){
    	osMessageQueueGet(myQueue01Handle, &res, NULL, osWaitForever);
    	if(res == 'P') // không vào được đoạn tiếp theo ???
    	{
    		rad = ((tickCount - prevTick)%360)*3.14f/180;
    		txtrhand.updateZAngle(rad);
    	}
    }
    else{
    	prevTick = tickCount;
    }
}
