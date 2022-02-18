/** @file Week6-Demo6-LoadingState-main.cpp
 *  @brief AIn Paralell Task, we are using std thread and mutex as well as std:chrono!!!
 * 
 * //sf::Thread			mThread;
 * std::thread			mThread;
 * bool				mFinished;
 * 
 * //sf::Clock			mElapsedTime;
 * std::chrono::duration<double> mElapsedTime;
 * std::chrono::steady_clock::time_point start;
 * std::chrono::steady_clock::time_point end;
 * 
 * //sf::Mutex			mMutex;
 * std::mutex          mMutex;
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#pragma region step 10

#include <Application.hpp>

#include <stdexcept>
#include <iostream>


int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}

#pragma endregion