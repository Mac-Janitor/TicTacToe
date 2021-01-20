#include "Sprite.hpp"  

Sprite::Sprite()
{
    m_empty = true;
}

Sprite::Sprite(std::string imagePath)
{
    m_empty = false;
    image = LoadImage(imagePath.c_str());
    m_width = image.width * 0.35;
    m_height = image.height * 0.35;
    ImageResize(&image, m_width, m_height);   
    texture = LoadTextureFromImage(image);
    m_position = {0, 0};
}

Sprite::~Sprite()
{
    if (!m_empty)
    {
        UnloadImage(image);
        UnloadTexture(texture);
    }
}

void Sprite::Draw()
{
    DrawTexture(texture, m_position.x, m_position.y, WHITE);
}

void Sprite::Draw(int posX, int posY)
{
    m_position = {posX, posY};
    Draw();
}

int Sprite::GetWidth()
{
    return m_width;
}

int Sprite::GetHeight()
{
    return m_height;
}