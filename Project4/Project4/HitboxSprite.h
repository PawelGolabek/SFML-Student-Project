#pragma once
#include <SFML/Graphics.hpp>

class HitboxSprite : public sf::Sprite{
public:
    /// sets the hitbox
    void setHitbox(const sf::FloatRect& hitbox);
    /// gets the hitbox (use this instead of getGlobalBounds())
    sf::FloatRect getGlobalHitbox() const;
private:
    sf::FloatRect m_hitbox;
};