#pragma region step 4

#include <State.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <ParallelTask.hpp>


class LoadingState : public State
{
public:
	LoadingState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

	void					setCompletion(float percent);

private:
	sf::Text				mLoadingText;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
};

#pragma endregion
