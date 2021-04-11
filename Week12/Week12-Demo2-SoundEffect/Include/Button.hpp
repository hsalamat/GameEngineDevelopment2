
#ifndef BOOK_BUTTON_HPP
#define BOOK_BUTTON_HPP

#include <Component.hpp>
#include <ResourceIdentifiers.hpp>

#pragma region step 11
//#include <ResourceHolder.hpp>
#include <State.hpp>
#pragma endregion



#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>

#pragma region step 12
class SoundPlayer;
#pragma endregion

namespace GUI
{

class Button : public Component
{
    public:
        typedef std::shared_ptr<Button>		Ptr;
        typedef std::function<void()>		Callback;

		enum Type
		{
			Normal,
			Selected,
			Pressed,
			ButtonCount
		};


	public:
#pragma region step 13
		//Button(const FontHolder& fonts, const TextureHolder& textures);
		Button(State::Context context);
#pragma endregion


        void					setCallback(Callback callback);
        void					setText(const std::string& text);
        void					setToggle(bool flag);

        virtual bool			isSelectable() const;
        virtual void			select();
        virtual void			deselect();

        virtual void			activate();
        virtual void			deactivate();

        virtual void			handleEvent(const sf::Event& event);


    private:
        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void					changeTexture(Type buttonType);


    private:
        Callback				mCallback;
        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
#pragma region step 14
		SoundPlayer&			mSounds;
#pragma endregion

};

}

#endif // BOOK_BUTTON_HPP
