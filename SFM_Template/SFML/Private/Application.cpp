#include "stdafx.h"

#include "Application.h"
#include "Window.h"


const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application(std::string TitleName) :
	mTitleName{ std::move(TitleName) }
{
	mWindow = Window::GetInstance("SpaceWar");
}

sf::Time Application::GetElapsed()
{
	return mClock.getElapsedTime();
}

void Application::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (!mWindow->IsDone())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			Update();
			PostUpdate();
		}
		Render();
	}
}

void Application::Update()
{
	mWindow->Update();
}

void Application::Render()
{
	mWindow->BeginDraw();
	mWindow->EndDraw();
}

void Application::PostUpdate()
{
	RestartClock();
}

void Application::RestartClock()
{
	mElapsed = mClock.restart();
}

