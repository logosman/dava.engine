#include "Render/PixelFormatDescriptor.h"
#include "Utils/Utils.h"
#include "Render/Renderer.h"

namespace DAVA
{
rhi::TextureFormat PixelFormatDescriptor::TEXTURE_FORMAT_INVALID = rhi::TextureFormat(-1);

UnorderedMap<PixelFormat, PixelFormatDescriptor, std::hash<uint8>> PixelFormatDescriptor::pixelDescriptors = {

    { FORMAT_INVALID, { FORMAT_INVALID, FastName("Invalid"), 0, TEXTURE_FORMAT_INVALID, false } },

    { FORMAT_RGBA8888, { FORMAT_RGBA8888, FastName("RGBA8888"), 32, rhi::TEXTURE_FORMAT_R8G8B8A8, false } },
    { FORMAT_RGBA5551, { FORMAT_RGBA5551, FastName("RGBA5551"), 16, rhi::TEXTURE_FORMAT_R5G5B5A1, false } },
    { FORMAT_RGBA4444, { FORMAT_RGBA4444, FastName("RGBA4444"), 16, rhi::TEXTURE_FORMAT_R4G4B4A4, false } },
    { FORMAT_RGB888, { FORMAT_RGB888, FastName("RGB888"), 24, rhi::TEXTURE_FORMAT_R8G8B8, false } },
    { FORMAT_RGB565, { FORMAT_RGB565, FastName("RGB565"), 16, rhi::TEXTURE_FORMAT_R5G6B5, false } },

    { FORMAT_A8, { FORMAT_A8, FastName("A8"), 8, rhi::TEXTURE_FORMAT_R8, false } },
    { FORMAT_A16, { FORMAT_A16, FastName("A16"), 16, rhi::TEXTURE_FORMAT_R16, false } },

    { FORMAT_RGBA16161616, { FORMAT_RGBA16161616, FastName("RGBA16161616"), 64, rhi::TEXTURE_FORMAT_A16R16G16B16, false } },
    { FORMAT_RGBA32323232, { FORMAT_RGBA32323232, FastName("RGBA32323232"), 128, rhi::TEXTURE_FORMAT_A32R32G32B32, false } },

    { FORMAT_PVR4, { FORMAT_PVR4, FastName("PVR4"), 4, rhi::TEXTURE_FORMAT_PVRTC_4BPP_RGBA, false } },
    { FORMAT_PVR2, { FORMAT_PVR2, FastName("PVR2"), 2, rhi::TEXTURE_FORMAT_PVRTC_2BPP_RGBA, false } },

    { FORMAT_DXT1, { FORMAT_DXT1, FastName("DXT1"), 4, rhi::TEXTURE_FORMAT_DXT1, false } },
    { FORMAT_DXT1A, { FORMAT_DXT1A, FastName("DXT1a"), 4, TEXTURE_FORMAT_INVALID, false } },
    { FORMAT_DXT3, { FORMAT_DXT3, FastName("DXT3"), 8, rhi::TEXTURE_FORMAT_DXT3, false } },
    { FORMAT_DXT5, { FORMAT_DXT5, FastName("DXT5"), 8, rhi::TEXTURE_FORMAT_DXT5, false } },
    { FORMAT_DXT5NM, { FORMAT_DXT5NM, FastName("DXT5nm"), 8, TEXTURE_FORMAT_INVALID, false } },

    { FORMAT_ETC1, { FORMAT_ETC1, FastName("ETC1"), 4, rhi::TEXTURE_FORMAT_ETC1, false } },

    { FORMAT_ATC_RGB, { FORMAT_ATC_RGB, FastName("ATC_RGB"), 4, rhi::TEXTURE_FORMAT_ATC_RGB, false } },
    { FORMAT_ATC_RGBA_EXPLICIT_ALPHA, { FORMAT_ATC_RGBA_EXPLICIT_ALPHA, FastName("ATC_RGBA_EXPLICIT_ALPHA"), 8, rhi::TEXTURE_FORMAT_ATC_RGBA_EXPLICIT, false } },
    { FORMAT_ATC_RGBA_INTERPOLATED_ALPHA, { FORMAT_ATC_RGBA_INTERPOLATED_ALPHA, FastName("ATC_RGBA_INTERPOLATED_ALPHA"), 8, rhi::TEXTURE_FORMAT_ATC_RGBA_INTERPOLATED, false } },

    { FORMAT_PVR2_2, { FORMAT_PVR2_2, FastName("PVR2_2"), 2, rhi::TEXTURE_FORMAT_PVRTC2_2BPP_RGBA, false } },
    { FORMAT_PVR4_2, { FORMAT_PVR4_2, FastName("PVR4_2"), 4, rhi::TEXTURE_FORMAT_PVRTC2_4BPP_RGBA, false } },

    { FORMAT_EAC_R11_UNSIGNED, { FORMAT_EAC_R11_UNSIGNED, FastName("EAC_R11"), 8, rhi::TEXTURE_FORMAT_EAC_R11_UNSIGNED, false } },
    { FORMAT_EAC_R11_SIGNED, { FORMAT_EAC_R11_SIGNED, FastName("EAC_R11_SIGNED"), 8, rhi::TEXTURE_FORMAT_EAC_R11_SIGNED, false } },
    { FORMAT_EAC_RG11_UNSIGNED, { FORMAT_EAC_RG11_UNSIGNED, FastName("EAC_RG11"), 8, rhi::TEXTURE_FORMAT_EAC_R11G11_UNSIGNED, false } },
    { FORMAT_EAC_RG11_SIGNED, { FORMAT_EAC_RG11_SIGNED, FastName("EAC_RG11_SIGNED"), 8, rhi::TEXTURE_FORMAT_EAC_R11G11_SIGNED, false } },

    { FORMAT_ETC2_RGB, { FORMAT_ETC2_RGB, FastName("ETC2_RGB"), 4, rhi::TEXTURE_FORMAT_ETC2_R8G8B8, false } },
    { FORMAT_ETC2_RGBA, { FORMAT_ETC2_RGBA, FastName("ETC2_RGBA"), 4, rhi::TEXTURE_FORMAT_ETC2_R8G8B8A8, false } },
    { FORMAT_ETC2_RGB_A1, { FORMAT_ETC2_RGB_A1, FastName("ETC2_RGB_A1"), 4, rhi::TEXTURE_FORMAT_ETC2_R8G8B8A1, false } }

#if defined(__DAVAENGINE_WIN32__)
    ,
    { FORMAT_BGR888, { FORMAT_BGR888, FastName("BGR888"), 24, TEXTURE_FORMAT_INVALID, false } }
#endif

#if (defined(__DAVAENGINE_WIN32__) || defined(__DAVAENGINE_MACOS__))
    ,
    { FORMAT_R16F, { FORMAT_R16F, FastName("R16F"), 16, rhi::TextureFormat::TEXTURE_FORMAT_R16F, false } },
    { FORMAT_RG16F, { FORMAT_RG16F, FastName("RG16F"), 32, rhi::TextureFormat::TEXTURE_FORMAT_RG16F, false } },
    { FORMAT_RGBA16F, { FORMAT_RGBA16F, FastName("RGBA16F"), 64, rhi::TextureFormat::TEXTURE_FORMAT_RGBA16F, false } },

    { FORMAT_R32F, { FORMAT_R32F, FastName("R32F"), 32, rhi::TextureFormat::TEXTURE_FORMAT_R32F, false } },
    { FORMAT_RG32F, { FORMAT_RG32F, FastName("RG32F"), 64, rhi::TextureFormat::TEXTURE_FORMAT_RG32F, false } },
    { FORMAT_RGBA32F, { FORMAT_RGBA32F, FastName("RGBA32F"), 128, rhi::TextureFormat::TEXTURE_FORMAT_RGBA32F, false } }
#endif
};

const PixelFormatDescriptor& PixelFormatDescriptor::GetPixelFormatDescriptor(const PixelFormat formatID)
{
    auto descrFound = pixelDescriptors.find(formatID);
    DVASSERT(descrFound != pixelDescriptors.end());
    return descrFound->second;
}

void PixelFormatDescriptor::SetHardwareSupportedFormats()
{
    for (auto& entry : pixelDescriptors)
    {
        PixelFormatDescriptor& descr = entry.second;
        if (descr.format != TEXTURE_FORMAT_INVALID)
        {
            descr.isHardwareSupported = rhi::TextureFormatSupported(descr.format);
        }
    }
}

const char* PixelFormatDescriptor::GetPixelFormatString(const PixelFormat formatID)
{
    return GetPixelFormatDescriptor(formatID).name.c_str();
}

PixelFormat PixelFormatDescriptor::GetPixelFormatByName(const FastName& formatName)
{
    for (const auto& entry : pixelDescriptors)
    {
        const PixelFormatDescriptor& descr = entry.second;
        if (formatName == descr.name)
        {
            return descr.formatID;
        }
    }

    return FORMAT_INVALID;
}

bool PixelFormatDescriptor::IsCompressedFormat(PixelFormat format)
{
    switch (format)
    {
    case FORMAT_PVR4:
    case FORMAT_PVR2:
    case FORMAT_ETC1:
    case FORMAT_PVR2_2:
    case FORMAT_PVR4_2:
    case FORMAT_EAC_R11_UNSIGNED:
    case FORMAT_EAC_R11_SIGNED:
    case FORMAT_EAC_RG11_UNSIGNED:
    case FORMAT_EAC_RG11_SIGNED:
    case FORMAT_ETC2_RGB:
    case FORMAT_ETC2_RGBA:
    case FORMAT_ETC2_RGB_A1:
    case FORMAT_DXT1:
    case FORMAT_DXT1A:
    case FORMAT_DXT3:
    case FORMAT_DXT5:
    case FORMAT_DXT5NM:
    case FORMAT_ATC_RGB:
    case FORMAT_ATC_RGBA_EXPLICIT_ALPHA:
    case FORMAT_ATC_RGBA_INTERPOLATED_ALPHA:
        return true;

    default:
        return false;
    }
}

Size2i PixelFormatDescriptor::GetPixelFormatBlockSize(PixelFormat formatID)
{
    switch (formatID)
    {
    case FORMAT_DXT1:
    case FORMAT_DXT1A:
    case FORMAT_DXT3:
    case FORMAT_DXT5:
    case FORMAT_DXT5NM:
    case FORMAT_ETC1:
    case FORMAT_ETC2_RGB:
    case FORMAT_ETC2_RGBA:
    case FORMAT_ETC2_RGB_A1:
    case FORMAT_EAC_R11_UNSIGNED:
    case FORMAT_EAC_R11_SIGNED:
    case FORMAT_EAC_RG11_UNSIGNED:
    case FORMAT_EAC_RG11_SIGNED:
        return Size2i(4, 4);

    case FORMAT_PVR4:
        return Size2i(8, 8);
    case FORMAT_PVR2:
        return Size2i(16, 8);

    case FORMAT_PVR4_2:
        return Size2i(4, 4);

    case FORMAT_PVR2_2:
        return Size2i(8, 4);

    case FORMAT_ATC_RGB:
    case FORMAT_ATC_RGBA_EXPLICIT_ALPHA:
    case FORMAT_ATC_RGBA_INTERPOLATED_ALPHA:
        DVASSERT(false && "Need check minimal block size for ATC")
        return Size2i(1, 1);

    default:
        return Size2i(1, 1);
    }

    return Size2i(1, 1);
}
};
