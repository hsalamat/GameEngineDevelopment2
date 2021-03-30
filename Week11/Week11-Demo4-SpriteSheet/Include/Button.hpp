
#ifndef BOOK_BUTTON_HPP
#define BOOK_BUTTON_HPP

#include <Component.hpp>
#include <ResourceIdentifiers.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace GUI
{

class Button : public Component
{
    public:
        typedef std::shared_ptr<Button>		Ptr;
        typedef std::function<void()>		Callback;

#pragma region step 8 - 1
		enum Type
		{
			Normal,
			Selected,
			Pressed,
			ButtonCount
		};
#pragma endregion


	public:
								Button(const FontHolder& fonts, const TextureHolder& textures);

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
#pragma region step 8 - 2
		void					changeTexture(Type buttonType);
#pragma endregion

    private:
        Callback				mCallback;
#pragma region step 8 - 3
       /* const sf::Texture&		mNormalTexture;
        const sf::Texture&		mSelectedTexture;
        const sf::Texture&		mPressedTexture;*/
#pragma endregion

        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
};

}

#endif // BOOK_BUTTON_HPP
