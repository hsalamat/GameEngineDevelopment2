#pragma region step 6
#pragma once

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/System/Clock.hpp>
#include <chrono>
#include <thread>
#include <mutex>
#include <iostream>


class ParallelTask
{
	public:
							ParallelTask();
		void				execute();
		bool				isFinished();
		float				getCompletion();
		
	private:
		void				runTask();

	private:
		//sf::Thread			mThread;
		std::thread			mThread;
		bool				mFinished;
		
		//sf::Clock			mElapsedTime;
		std::chrono::duration<double> mElapsedTime;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;

		//sf::Mutex			mMutex;
		std::mutex          mMutex;
};

#pragma endregion
