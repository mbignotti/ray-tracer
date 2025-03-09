#include "renderer.h"
#include "../walnut/random.h"

void Renderer::OnResize(uint32_t width, uint32_t height)
{
    if (m_FinalImage)
    {
        // No resize necessary
        if (m_FinalImage->GetWidth() == width && m_FinalImage->GetHeight() == height)
            return;

        m_FinalImage->Resize(width, height);
    }
    else
    {
        m_FinalImage = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
    }

    delete[] m_ImageData;
    m_ImageData = new uint32_t[width * height];
}

void Renderer::Render()
{
    for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++)
 	{
 		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++)
 		{
            uint32_t idx = x + y * m_FinalImage->GetWidth();
            m_ImageData[idx] = Walnut::Random::UInt();
            m_ImageData[idx] |= 0xff000000;
 		}
 	}

    m_FinalImage->SetData(m_ImageData);
}