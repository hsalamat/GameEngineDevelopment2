#pragma region Step 4
//The conatiner acts as the root for the GUI we want to show
//You create a GUI
#include <Container.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace GUI
{

	Container::Container()
		: mChildren()
		, mSelectedChild(-1)
	{
	}

	void Container::pack(Component::Ptr component)
	{
		mChildren.push_back(component);
		//checked if we have a currently selected child
		//if not, if incoming child is selectable, and if it is, select it
		if (!hasSelection() && component->isSelectable())
			select(mChildren.size() - 1);
	}

	//A Container is not a selectable component
	bool Container::isSelectable() const
	{
		return false;
	}

	void Container::handleEvent(const sf::Event& event)
	{
		// If we have selected a child then give it events
		if (hasSelection() && mChildren[mSelectedChild]->isActive())
		{
			//active component receives the event (Not the conatiner!)
			mChildren[mSelectedChild]->handleEvent(event);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
			{
				selectPrevious();
			}
			else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
			{
				selectNext();
			}
			else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
			{
				//If container is in focus, activate the selected component
				if (hasSelection())
					mChildren[mSelectedChild]->activate();
			}
		}
	}

	void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		for (const Component::Ptr& child : mChildren)
			target.draw(*child, states);
	}

	bool Container::hasSelection() const
	{
		return mSelectedChild >= 0;
	}


	void Container::select(std::size_t index)
	{
		if (mChildren[index]->isSelectable())
		{
			if (hasSelection())
				mChildren[mSelectedChild]->deselect();

			mChildren[index]->select();
			mSelectedChild = index;
		}
	}

	void Container::selectNext()
	{
		if (!hasSelection())
			return;

		// Search next component that is selectable, wrap around if necessary
		int next = mSelectedChild;
		do
			next = (next + 1) % mChildren.size();
		while (!mChildren[next]->isSelectable());

		// Select that component
		select(next);
	}

	void Container::selectPrevious()
	{
		if (!hasSelection())
			return;

		// Search previous component that is selectable, wrap around if necessary
		int prev = mSelectedChild;
		do
			prev = (prev + mChildren.size() - 1) % mChildren.size();
		while (!mChildren[prev]->isSelectable());

		// Select that component
		select(prev);
	}

}

#pragma endregion
