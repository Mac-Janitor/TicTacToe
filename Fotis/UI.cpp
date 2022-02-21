#include "UI.hpp"  
	
namespace Fotis
{
    UI::UI(std::string label, float fontSize, Vector2 centerOriginPosition)
    {
        // SDF font generation from TTF font
        m_label = label;
        m_fontSize = fontSize;
        m_font = { 0 };
        m_font.baseSize = 16;
        m_font.glyphCount = 95;

        // Loading file to memory
        unsigned int fileSize = 0;
        unsigned char *fileData = LoadFileData("resources/fonts/AnonymousPro-Bold.ttf", &fileSize);    

        m_font.glyphs = LoadFontData(fileData, 0, 64, 0, 0, FONT_SDF);
        Image atlas = GenImageFontAtlas(m_font.glyphs, &m_font.recs, 95, 0, 0, 1);
        m_font.texture = LoadTextureFromImage(atlas);
        UnloadImage(atlas);
        SetTextureFilter(m_font.texture, TEXTURE_FILTER_BILINEAR);    // Required for SDF font

        m_textSize = MeasureTextEx(m_font, m_label.c_str(), m_fontSize, 0);

        float scaleFactor = m_fontSize/(float)m_font.baseSize;
        m_textSize.y = (m_font.recs->height + 2.0f*m_font.glyphPadding)*scaleFactor;
        
        m_position = { centerOriginPosition.x - m_textSize.x/2, centerOriginPosition.y - m_textSize.y/2 };
    }
        
    UI::~UI()
    {
    }

    void UI::Draw(Color color)
    {
        DrawTextEx(m_font, m_label.c_str(), m_position, m_fontSize, 0, color);
    }

    bool UI::Hover(Vector2 mousePosition)
    {
        float scaleFactor = m_fontSize/(float)m_font.baseSize;
        float test = (m_font.recs->height + 2.0f*m_font.glyphPadding)*scaleFactor;

        if (mousePosition.x > m_position.x && 
            mousePosition.y > m_position.y &&
            mousePosition.x < m_position.x + m_textSize.x &&
            mousePosition.y < m_position.y + m_textSize.y)
        {
            return true;   
        }
        return false;
    }
}