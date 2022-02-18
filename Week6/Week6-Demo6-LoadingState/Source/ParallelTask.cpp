#pragma region step 7
#include <ParallelTask.hpp>


ParallelTask::ParallelTask()
: 
	mThread(&ParallelTask::runTask, this), 
	mFinished(false)
{
	//mElapsedTime.restart();
	start = std::chrono::steady_clock::now();
}

void ParallelTask::execute()
{
	mFinished = false;
	//mElapsedTime.restart();
	//mThread.launch();
}

bool ParallelTask::isFinished()
{
	//sf::Lock lock(mMutex);
	std::lock_guard<std::mutex> guard(mMutex);
	return mFinished;
}

float ParallelTask::getCompletion()
{
	//sf::Lock lock(mMutex);
	std::lock_guard<std::mutex> guard(mMutex);

	// 100% at 10 seconds of elapsed time
	//return mElapsedTime.getElapsedTime().asSeconds() / 10.f;
	end = std::chrono::steady_clock::now();
	mElapsedTime = end - start;
	return mElapsedTime.count() / 10.f;
}

void ParallelTask::runTask()
{
	// Dummy task - stall 10 seconds
	std::cout << "Run task started" << std::endl;
	
	//the following link and while loop basically does the same thing
	std::this_thread::sleep_for(std::chrono::seconds(10));

	bool ended = false;
	while (!ended)
	{
		//sf::Lock lock(mMutex); // Protect the clock 
		std::lock_guard<std::mutex> guard(mMutex);
		//if (mElapsedTime.getElapsedTime().asSeconds() >= 10.f)
		if((std::chrono::steady_clock::now() - start).count() > 10.0f)
			ended = true;
	}

	{ // mFinished may be accessed from multiple threads, protect it
		//sf::Lock lock(mMutex);
		std::lock_guard<std::mutex> guard(mMutex);
		mFinished = true;
	}	


	end = std::chrono::steady_clock::now();
	mElapsedTime = end - start;
	std::cout << "Elapsed time: " << mElapsedTime.count() << "s\n";
	std::cout << "Run task Ended" << std::endl;

	//Separates the thread of execution from the thread object, 
	//allowing execution to continue independently. 
	//Any allocated resources will be freed once the thread exits.
	mThread.detach();
}

#pragma endregion