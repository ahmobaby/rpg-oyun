#include "FrameRate.h"
#include<iostream>

FrameRate::FrameRate() :
    timer(0)
{   
}

FrameRate::~FrameRate()
{  
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    frameRateText.setFont(font);
    font.loadFromFile("Assets/Fonts/arial/ARIAL.TTF");

}


void FrameRate::Update(float deltaTime)
{
    timer += deltaTime;
    if (timer >= 100.0)
    {
        double fps = 1000.0 / deltaTime;
        frameRateText.setString("FPS: " + std::to_string(int(1000 / deltaTime)));
        timer = 0;
    }

}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(frameRateText);
}
