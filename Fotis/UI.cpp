#include "UI.hpp"  
	
namespace Fotis
{
    UI::UI(std::string label, float fontSize)
    {
        // SDF font generation from TTF font
        m_label = label;
        m_fontSize = fontSize;
        m_font = { 0 };
        m_font.baseSize = 16;
        m_font.charsCount = 95;
        m_font.chars = LoadFontData("resources/fonts/AnonymousPro-Bold.ttf", 64, 0, 0, FONT_SDF);
        Image atlas = GenImageFontAtlas(m_font.chars, &m_font.recs, 95, 16, 0, 1);
        m_font.texture = LoadTextureFromImage(atlas);
        UnloadImage(atlas);
        SetTextureFilter(m_font.texture, FILTER_BILINEAR);    // Required for SDF font
        Vector2 textSize = { 0.0f, 0.0f };

    }
        
    UI::~UI()
    {
    }

    void UI::Draw(Vector2 position)
    {
        DrawTextEx(m_font, m_label.c_str(), position, m_fontSize, 0, BLACK);
    }

    Vector2 UI::GetTextSize()
    {
        return MeasureTextEx(m_font, m_label.c_str(), m_fontSize, 0);
    }
}