#pragma once

#include <SFML/Graphics.hpp>

#include "HitboxSprite.h"

    /// sets the hitbox
void HitboxSprite::setHitbox(const sf::FloatRect& hitbox) {
    m_hitbox = hitbox;
}
    /// gets the hitbox (use this instead of getGlobalBounds())
sf::FloatRect HitboxSprite::getGlobalHitbox() const {
    return getTransform().transformRect(m_hitbox);
}