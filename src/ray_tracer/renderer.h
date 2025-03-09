#include "../walnut/image.h"

#include <memory>

class Renderer
{
public:
    Renderer() = default;

public:
    std::shared_ptr<Walnut::Image> GetFinalImage() const { return m_FinalImage; }

    void OnResize(uint32_t width, uint32_t height);

    void Render();

private:
    std::shared_ptr<Walnut::Image> m_FinalImage;

    uint32_t *m_ImageData = nullptr;

    uint32_t m_ViewportWidth = 0;

    uint32_t m_ViewportHeight = 0;
};