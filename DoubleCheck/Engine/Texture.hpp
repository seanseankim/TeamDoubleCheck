
#pragma once

#include <filesystem>

class Image;
class Color4ub;

class[[nodiscard]] Texture
{
public:
    Texture() = default;

    bool LoadFromPNG(const std::filesystem::path& file_path) noexcept;
    bool LoadFromImage(const Image& image) noexcept;
    bool LoadFromMemory(int image_width, int image_height, const Color4ub* colors) noexcept;

    static void SelectTextureForSlot(const Texture& texture, unsigned int slot = 0) noexcept;

    void DeleteTexture() noexcept;

    unsigned int GetTextureHandle() const noexcept { return textureHandle; }
    int          GetWidth() const noexcept { return width; }
    int          GetHeight() const noexcept { return height; }

    ~Texture() noexcept;
    Texture(Texture && other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

public:
    Texture(const Texture& other) = delete;
    Texture& operator=(const Texture& other) = delete;

private:
    unsigned int textureHandle = 0;
    int          width = 0;
    int          height = 0;
};

