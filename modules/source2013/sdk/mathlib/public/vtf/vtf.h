//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//===========================================================================//

#ifndef VTF_H
#define VTF_H

#ifdef _WIN32
#pragma once
#endif

#include "../bitmap/imageformat.h"
#include "../tier0/platform.h"

// #define VTF_FILE_FORMAT_ONLY to just include the vtf header and none of the
// code declaration
#ifndef VTF_FILE_FORMAT_ONLY

//-----------------------------------------------------------------------------
// Forward declarations
//-----------------------------------------------------------------------------
class CUtlBuffer;
class Vector;
struct Rect_t;
class IFileSystem;

//-----------------------------------------------------------------------------
// Texture flags
//-----------------------------------------------------------------------------
enum CompiledVtfFlags {
    // flags from the *.txt config file
    TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
    TEXTUREFLAGS_TRILINEAR = 0x00000002,
    TEXTUREFLAGS_CLAMPS = 0x00000004,
    TEXTUREFLAGS_CLAMPT = 0x00000008,
    TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
    TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
    TEXTUREFLAGS_SRGB = 0x00000040,
    TEXTUREFLAGS_NORMAL = 0x00000080,
    TEXTUREFLAGS_NOMIP = 0x00000100,
    TEXTUREFLAGS_NOLOD = 0x00000200,
    TEXTUREFLAGS_ALL_MIPS = 0x00000400,
    TEXTUREFLAGS_PROCEDURAL = 0x00000800,

    // These are automatically generated by vtex from the texture data.
    TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
    TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,

    // newer flags from the *.txt config file
    TEXTUREFLAGS_ENVMAP = 0x00004000,
    TEXTUREFLAGS_RENDERTARGET = 0x00008000,
    TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
    TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
    TEXTUREFLAGS_SINGLECOPY = 0x00040000,

    TEXTUREFLAGS_STAGING_MEMORY = 0x00080000,
    TEXTUREFLAGS_IMMEDIATE_CLEANUP = 0x00100000,
    TEXTUREFLAGS_IGNORE_PICMIP = 0x00200000,
    TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,

    TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,

    TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,

    TEXTUREFLAGS_CLAMPU = 0x02000000,

    TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,  // Useable as a vertex texture

    TEXTUREFLAGS_SSBUMP = 0x08000000,

    TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,

    // Clamp to border color on all texture coordinates
    TEXTUREFLAGS_BORDER = 0x20000000,

    TEXTUREFLAGS_UNUSED_40000000 = 0x40000000,
    TEXTUREFLAGS_UNUSED_80000000 = 0x80000000,
};

enum VersionedVtfFlags {
    VERSIONED_VTF_FLAGS_MASK_7_3 =
        ~0xD1780400,  // For a ver 7.3 or earlier only these flags are valid
};

struct VtfProcessingOptions {
    uint32 cbSize;  // Set to sizeof( VtfProcessingOptions )

    //
    // Flags0
    //
    enum Flags0 {
        // Have a channel decaying to a given decay goal for the given last
        // number of mips
        OPT_DECAY_R = 0x00000001,  // Red decays
        OPT_DECAY_G = 0x00000002,  // Green decays
        OPT_DECAY_B = 0x00000004,  // Blue decays
        OPT_DECAY_A = 0x00000008,  // Alpha decays

        OPT_DECAY_EXP_R =
            0x00000010,  // Channel R decays exponentially (otherwise linearly)
        OPT_DECAY_EXP_G =
            0x00000020,  // Channel G decays exponentially (otherwise linearly)
        OPT_DECAY_EXP_B =
            0x00000040,  // Channel B decays exponentially (otherwise linearly)
        OPT_DECAY_EXP_A =
            0x00000080,  // Channel A decays exponentially (otherwise linearly)

        OPT_NOCOMPRESS = 0x00000100,   // Use uncompressed image format
        OPT_NORMAL_DUDV = 0x00000200,  // dU dV normal map
        OPT_FILTER_NICE = 0x00000400,  // Use nice filtering

        OPT_SET_ALPHA_ONEOVERMIP = 0x00001000,      // Alpha  = 1/miplevel
        OPT_PREMULT_COLOR_ONEOVERMIP = 0x00002000,  // Color *= 1/miplevel
        OPT_MIP_ALPHATEST = 0x00004000,  // Alpha-tested mip generation
    };

    uint32 flags0;  // A combination of "Flags0"

    //
    // Decay settings
    //
    uint8 clrDecayGoal[4];        // Goal colors for R G B A
    uint8 numNotDecayMips[4];     // Number of first mips unaffected by decay (0
                                  // means all below mip0)
    float fDecayExponentBase[4];  // For exponential decay the base number (e.g.
                                  // 0.75)
};

//-----------------------------------------------------------------------------
// Cubemap face indices
//-----------------------------------------------------------------------------
enum CubeMapFaceIndex_t {
    CUBEMAP_FACE_RIGHT = 0,
    CUBEMAP_FACE_LEFT,
    CUBEMAP_FACE_BACK,   // NOTE: This face is in the +y direction?!?!?
    CUBEMAP_FACE_FRONT,  // NOTE: This face is in the -y direction!?!?
    CUBEMAP_FACE_UP,
    CUBEMAP_FACE_DOWN,

    // This is the fallback for low-end
    CUBEMAP_FACE_SPHEREMAP,

    // NOTE: Cubemaps have *7* faces; the 7th is the fallback spheremap
    CUBEMAP_FACE_COUNT
};

//-----------------------------------------------------------------------------
// Enumeration used for spheremap generation
//-----------------------------------------------------------------------------
enum LookDir_t {
    LOOK_DOWN_X = 0,
    LOOK_DOWN_NEGX,
    LOOK_DOWN_Y,
    LOOK_DOWN_NEGY,
    LOOK_DOWN_Z,
    LOOK_DOWN_NEGZ,
};

//-----------------------------------------------------------------------------
// Use this image format if you want to perform tool operations on the texture
//-----------------------------------------------------------------------------
#define IMAGE_FORMAT_DEFAULT ((ImageFormat)-2)

//-----------------------------------------------------------------------------
// Interface to get at various bits of a VTF texture
//-----------------------------------------------------------------------------
class IVTFTexture {
   public:
    virtual ~IVTFTexture() {}

    // Initializes the texture and allocates space for the bits
    // In most cases, you shouldn't force the mip count.
    virtual bool Init(int nWidth, int nHeight, int nDepth, ImageFormat fmt,
                      int nFlags, int iFrameCount, int nForceMipCount = -1) = 0;

    // Methods to set other texture fields
    virtual void SetBumpScale(float flScale) = 0;
    virtual void SetReflectivity(const Vector &vecReflectivity) = 0;

    // Methods to initialize the low-res image
    virtual void InitLowResImage(int nWidth, int nHeight, ImageFormat fmt) = 0;

    // set the resource data (for writers). pass size=0 to delete data. if pdata
    // is not null, the resource data will be copied from *pData
    virtual void *SetResourceData(uint32 eType, void const *pData,
                                  size_t nDataSize) = 0;

    // find the resource data and return a pointer to it. The data pointed to by
    // this pointer will go away when the ivtftexture does. retruns null if
    // resource not present
    virtual void *GetResourceData(uint32 eType, size_t *pDataSize) const = 0;

    // Locates the resource entry info if it's present, easier than crawling
    // array types
    virtual bool HasResourceEntry(uint32 eType) const = 0;

    // Retrieve available resource types of this IVTFTextures
    //		arrTypesBuffer			buffer to be filled with resource types
    //available. 		numTypesBufferElems		how many resource types the
    //buffer can accomodate.
    // Returns:
    //		number of resource types available (can be greater than
    //"numTypesBufferElems" 		in which case only first "numTypesBufferElems" are
    //copied to "arrTypesBuffer")
    virtual unsigned int GetResourceTypes(uint32 *arrTypesBuffer,
                                          int numTypesBufferElems) const = 0;

    // When unserializing, we can skip a certain number of mip levels,
    // and we also can just load everything but the image data
    // NOTE: If you load only the buffer header, you'll need to use the
    // VTFBufferHeaderSize() method below to only read that much from the file
    // NOTE: If you skip mip levels, the height + width of the texture will
    // change to reflect the size of the largest read in mip level
    virtual bool Unserialize(CUtlBuffer &buf, bool bHeaderOnly = false,
                             int nSkipMipLevels = 0) = 0;
    virtual bool Serialize(CUtlBuffer &buf) = 0;

    // These are methods to help with optimization:
    // Once the header is read in, they indicate where to start reading
    // other data (measured from file start), and how many bytes to read....
    virtual void LowResFileInfo(int *pStartLocation,
                                int *pSizeInBytes) const = 0;
    virtual void ImageFileInfo(int nFrame, int nFace, int nMip,
                               int *pStartLocation,
                               int *pSizeInBytes) const = 0;
    virtual int FileSize(int nMipSkipCount = 0) const = 0;

    // Attributes...
    virtual int Width() const = 0;
    virtual int Height() const = 0;
    virtual int Depth() const = 0;
    virtual int MipCount() const = 0;

    // returns the size of one row of a particular mip level
    virtual int RowSizeInBytes(int nMipLevel) const = 0;

    // returns the size of one face of a particular mip level
    virtual int FaceSizeInBytes(int nMipLevel) const = 0;

    virtual ImageFormat Format() const = 0;
    virtual int FaceCount() const = 0;
    virtual int FrameCount() const = 0;
    virtual int Flags() const = 0;

    virtual float BumpScale() const = 0;

    virtual int LowResWidth() const = 0;
    virtual int LowResHeight() const = 0;
    virtual ImageFormat LowResFormat() const = 0;

    // NOTE: reflectivity[0] = blue, [1] = greem, [2] = red
    virtual const Vector &Reflectivity() const = 0;

    virtual bool IsCubeMap() const = 0;
    virtual bool IsNormalMap() const = 0;
    virtual bool IsVolumeTexture() const = 0;

    // Computes the dimensions of a particular mip level
    virtual void ComputeMipLevelDimensions(int iMipLevel, int *pMipWidth,
                                           int *pMipHeight,
                                           int *pMipDepth) const = 0;

    // Computes the size (in bytes) of a single mipmap of a single face of a
    // single frame
    virtual int ComputeMipSize(int iMipLevel) const = 0;

    // Computes the size of a subrect (specified at the top mip level) at a
    // particular lower mip level
    virtual void ComputeMipLevelSubRect(Rect_t *pSrcRect, int nMipLevel,
                                        Rect_t *pSubRect) const = 0;

    // Computes the size (in bytes) of a single face of a single frame
    // All mip levels starting at the specified mip level are included
    virtual int ComputeFaceSize(int iStartingMipLevel = 0) const = 0;

    // Computes the total size (in bytes) of all faces, all frames
    virtual int ComputeTotalSize() const = 0;

    // Returns the base address of the image data
    virtual unsigned char *ImageData() = 0;

    // Returns a pointer to the data associated with a particular frame, face,
    // and mip level
    virtual unsigned char *ImageData(int iFrame, int iFace, int iMipLevel) = 0;

    // Returns a pointer to the data associated with a particular frame, face,
    // mip level, and offset
    virtual unsigned char *ImageData(int iFrame, int iFace, int iMipLevel,
                                     int x, int y, int z = 0) = 0;

    // Returns the base address of the low-res image data
    virtual unsigned char *LowResImageData() = 0;

    // Converts the textures image format. Use IMAGE_FORMAT_DEFAULT
    // if you want to be able to use various tool functions below
    virtual void ConvertImageFormat(ImageFormat fmt, bool bNormalToDUDV) = 0;

    // NOTE: The following methods only work on textures using the
    // IMAGE_FORMAT_DEFAULT!

    // Generate spheremap based on the current cube faces (only works for
    // cubemaps) The look dir indicates the direction of the center of the
    // sphere NOTE: Only call this *after* cube faces have been correctly
    // oriented (using FixCubemapFaceOrientation)
    virtual void GenerateSpheremap(LookDir_t lookDir = LOOK_DOWN_Z) = 0;

    // Generate spheremap based on the current cube faces (only works for
    // cubemaps) The look dir indicates the direction of the center of the
    // sphere NOTE: Only call this *after* cube faces have been correctly
    // oriented (using FixCubemapFaceOrientation)
    virtual void GenerateHemisphereMap(unsigned char *pSphereMapBitsRGBA,
                                       int targetWidth, int targetHeight,
                                       LookDir_t lookDir, int iFrame) = 0;

    // Fixes the cubemap faces orientation from our standard to the
    // standard the material system needs.
    virtual void FixCubemapFaceOrientation() = 0;

    // Generates mipmaps from the base mip levels
    virtual void GenerateMipmaps() = 0;

    // Put 1/miplevel (1..n) into alpha.
    virtual void PutOneOverMipLevelInAlpha() = 0;

    // Computes the reflectivity
    virtual void ComputeReflectivity() = 0;

    // Computes the alpha flags
    virtual void ComputeAlphaFlags() = 0;

    // Generate the low-res image bits
    virtual bool ConstructLowResImage() = 0;

    // Gets the texture all internally consistent assuming you've loaded
    // mip 0 of all faces of all frames
    virtual void PostProcess(bool bGenerateSpheremap,
                             LookDir_t lookDir = LOOK_DOWN_Z,
                             bool bAllowFixCubemapOrientation = true) = 0;

    // Blends adjacent pixels on cubemap borders, since the card doesn't do it.
    // If the texture is S3TC compressed, then it has to do it AFTER the texture
    // has been compressed to prevent artifacts along the edges.
    //
    // If bSkybox is true, it assumes the faces are oriented in the way the
    // engine draws the skybox (which happens to be different from the way
    // cubemaps have their faces).
    virtual void MatchCubeMapBorders(int iStage, ImageFormat finalFormat,
                                     bool bSkybox) = 0;

    // Sets threshhold values for alphatest mipmapping
    virtual void SetAlphaTestThreshholds(float flBase, float flHighFreq) = 0;

#if defined(_X360)
    virtual int UpdateOrCreate(const char *pFilename,
                               const char *pPathID = NULL,
                               bool bForce = false) = 0;
    virtual bool UnserializeFromBuffer(CUtlBuffer &buf, bool bBufferIsVolatile,
                                       bool bHeaderOnly, bool bPreloadOnly,
                                       int nMipSkipCount) = 0;
    virtual int FileSize(bool bPreloadOnly, int nMipSkipCount) const = 0;
    virtual int MappingWidth() const = 0;
    virtual int MappingHeight() const = 0;
    virtual int MappingDepth() const = 0;
    virtual int MipSkipCount() const = 0;
    virtual bool IsPreTiled() const = 0;
    virtual unsigned char *LowResImageSample() = 0;
    virtual void ReleaseImageMemory() = 0;
#endif

    // Sets post-processing flags (settings are copied, pointer passed to
    // distinguish between structure versions)
    virtual void SetPostProcessingSettings(
        VtfProcessingOptions const *pOptions) = 0;
};

//-----------------------------------------------------------------------------
// Class factory
//-----------------------------------------------------------------------------
IVTFTexture *CreateVTFTexture();
void DestroyVTFTexture(IVTFTexture *pTexture);

//-----------------------------------------------------------------------------
// Allows us to only load in the first little bit of the VTF file to get info
// Clients should read this much into a UtlBuffer and then pass it in to
// Unserialize
//-----------------------------------------------------------------------------
int VTFFileHeaderSize(int nMajorVersion = -1, int nMinorVersion = -1);

//-----------------------------------------------------------------------------
// 360 Conversion
//-----------------------------------------------------------------------------
typedef bool (*CompressFunc_t)(CUtlBuffer &inputBuffer,
                               CUtlBuffer &outputBuffer);
bool ConvertVTFTo360Format(const char *pDebugName, CUtlBuffer &sourceBuf,
                           CUtlBuffer &targetBuf, CompressFunc_t pCompressFunc);

//-----------------------------------------------------------------------------
// 360 Preload
//-----------------------------------------------------------------------------
bool GetVTFPreload360Data(const char *pDebugName, CUtlBuffer &fileBufferIn,
                          CUtlBuffer &preloadBufferOut);

#include "../mathlib/vector.h"

#endif  // VTF_FILE_FORMAT_ONLY

//-----------------------------------------------------------------------------
// Disk format for VTF files ver. 7.2 and earlier
//
// NOTE: After the header is the low-res image data
// Then follows image data, which is sorted in the following manner
//
//	for each mip level (starting with 1x1, and getting larger)
//		for each animation frame
//			for each face
//				store the image data for the face
//
// NOTE: In memory, we store the data in the following manner:
//	for each animation frame
//		for each face
//			for each mip level (starting with the largest, and getting
//smaller) 				store the image data for the face
//
// This is done because the various image manipulation function we have
// expect this format
//-----------------------------------------------------------------------------
// Disk format for VTF files ver. 7.3
//
// NOTE: After the header is the array of ResourceEntryInfo structures,
// number of elements in the array is defined by "numResources".
// there are entries for:
//		eRsrcLowResImage	=	low-res image data
//		eRsrcSheet			=	sheet data
//		eRsrcImage			=	image data
// {
//	for each mip level (starting with 1x1, and getting larger)
//		for each animation frame
//			for each face
//				store the image data for the face
//
// NOTE: In memory, we store the data in the following manner:
//	for each animation frame
//		for each face
//			for each mip level (starting with the largest, and getting
//smaller) 				store the image data for the face
// }
//
//-----------------------------------------------------------------------------

#include "../datamap.h"

#pragma pack(1)

// version number for the disk texture cache
#define VTF_MAJOR_VERSION 7
#define VTF_MINOR_VERSION 4

//-----------------------------------------------------------------------------
// !!!!CRITICAL!!!! BEFORE YOU CHANGE THE FORMAT
//
// The structure sizes ARE NOT what they appear, regardless of Pack(1).
// The "VectorAligned" causes invisible padding in the FINAL derived structure.
//
// Each VTF format has been silently plagued by this.
//
// LOOK AT A 7.3 FILE. The 7.3 structure ends at 0x48 as you would expect by
// counting structure bytes. But, the "Infos" start at 0x50! because the PC
// compiler pads, the 360 compiler does NOT.
//-----------------------------------------------------------------------------

struct VTFFileBaseHeader_t {
    DECLARE_BYTESWAP_DATADESC();
    char fileTypeString[4];  // "VTF" Valve texture file
    int version[2];          // version[0].version[1]
    int headerSize;
};

struct VTFFileHeaderV7_1_t : public VTFFileBaseHeader_t {
    DECLARE_BYTESWAP_DATADESC();
    unsigned short width;
    unsigned short height;
    unsigned int flags;
    unsigned short numFrames;
    unsigned short startFrame;
#if !defined(POSIX) && !defined(_X360)
    VectorAligned reflectivity;
#else
    // must manually align in order to maintain pack(1) expected layout with
    // existing binaries
    char pad1[4];
    Vector reflectivity;
    char pad2[4];
#endif
    float bumpScale;
    ImageFormat imageFormat;
    unsigned char numMipLevels;
    ImageFormat lowResImageFormat;
    unsigned char lowResImageWidth;
    unsigned char lowResImageHeight;
};

struct VTFFileHeaderV7_2_t : public VTFFileHeaderV7_1_t {
    DECLARE_BYTESWAP_DATADESC();

    unsigned short depth;
};

#define BYTE_POS(byteVal, shft) \
    uint32(uint32(uint8(byteVal)) << uint8(shft * 8))
#if !defined(_X360)
#define MK_VTF_RSRC_ID(a, b, c) \
    uint32(BYTE_POS(a, 0) | BYTE_POS(b, 1) | BYTE_POS(c, 2))
#define MK_VTF_RSRCF(d) BYTE_POS(d, 3)
#else
#define MK_VTF_RSRC_ID(a, b, c) \
    uint32(BYTE_POS(a, 3) | BYTE_POS(b, 2) | BYTE_POS(c, 1))
#define MK_VTF_RSRCF(d) BYTE_POS(d, 0)
#endif

// Special section for stock resources types
enum ResourceEntryType {
    // Legacy stock resources, readin/writing are handled differently (i.e. they
    // do not have the length tag word!)
    VTF_LEGACY_RSRC_LOW_RES_IMAGE =
        MK_VTF_RSRC_ID(0x01, 0, 0),                      // Low-res image data
    VTF_LEGACY_RSRC_IMAGE = MK_VTF_RSRC_ID(0x30, 0, 0),  // Image data

    // New extended resource
    VTF_RSRC_SHEET = MK_VTF_RSRC_ID(0x10, 0, 0),  // Sheet data
};

// Bytes with special meaning when set in a resource type
enum ResourceEntryTypeFlag {
    RSRCF_HAS_NO_DATA_CHUNK =
        MK_VTF_RSRCF(0x02),  // Resource doesn't have a corresponding data chunk
    RSRCF_MASK = MK_VTF_RSRCF(0xFF)  // Mask for all the flags
};

// Header details constants
enum HeaderDetails {
    MAX_RSRC_DICTIONARY_ENTRIES = 32,  // Max number of resources in dictionary
    MAX_X360_RSRC_DICTIONARY_ENTRIES =
        4,  // 360 needs this to be slim, otherwise preload size suffers
};

struct ResourceEntryInfo {
    union {
        unsigned int eType;  // Use MK_VTF_??? macros to be endian compliant
                             // with the type
        unsigned char chTypeBytes[4];
    };
    unsigned int
        resData;  // Resource data or offset from the beginning of the file
};

struct VTFFileHeaderV7_3_t : public VTFFileHeaderV7_2_t {
    DECLARE_BYTESWAP_DATADESC();

    char pad4[3];
    unsigned int numResources;

#if defined(_X360) || defined(POSIX)
    // must manually align in order to maintain pack(1) expected layout with
    // existing binaries
    char pad5[8];
#endif

    // AFTER THE IMPLICIT PADDING CAUSED BY THE COMPILER....
    // *** followed by *** ResourceEntryInfo resources[0];
    // Array of resource entry infos sorted ascending by type
};

struct VTFFileHeader_t : public VTFFileHeaderV7_3_t {
    DECLARE_BYTESWAP_DATADESC();
};

#define VTF_X360_MAJOR_VERSION 0x0360
#define VTF_X360_MINOR_VERSION 8
struct VTFFileHeaderX360_t : public VTFFileBaseHeader_t {
    DECLARE_BYTESWAP_DATADESC();
    unsigned int flags;
    unsigned short width;   // actual width of data in file
    unsigned short height;  // actual height of data in file
    unsigned short depth;   // actual depth of data in file
    unsigned short numFrames;
    unsigned short
        preloadDataSize;  // exact size of preload data (may extend into image!)
    unsigned char mipSkipCount;  // used to resconstruct mapping dimensions
    unsigned char numResources;
    Vector reflectivity;  // Resides on 16 byte boundary!
    float bumpScale;
    ImageFormat imageFormat;
    unsigned char lowResImageSample[4];
    unsigned int compressedSize;

    // *** followed by *** ResourceEntryInfo resources[0];
};

///////////////////////////
//  Resource Extensions  //
///////////////////////////

// extended texture lod control:
#define VTF_RSRC_TEXTURE_LOD_SETTINGS (MK_VTF_RSRC_ID('L', 'O', 'D'))
struct TextureLODControlSettings_t {
    // What to clamp the dimenstions to, mip-map wise, when at picmip 0. keeps
    // texture from exceeding (1<<m_ResolutionClamp) at picmip 0.  at picmip 1,
    // it won't exceed (1<<(m_ResolutionClamp-1)), etc.
    uint8 m_ResolutionClampX;
    uint8 m_ResolutionClampY;

    uint8 m_ResolutionClampX_360;
    uint8 m_ResolutionClampY_360;
};

// Extended flags and settings:
#define VTF_RSRC_TEXTURE_SETTINGS_EX (MK_VTF_RSRC_ID('T', 'S', '0'))
struct TextureSettingsEx_t {
    enum Flags0  // flags0 byte mask
    { UNUSED = 0x01,
    };

    uint8 m_flags0;  // a bitwise combination of Flags0
    uint8 m_flags1;  // set to zero. for future expansion.
    uint8 m_flags2;  // set to zero. for future expansion.
    uint8 m_flags3;  // set to zero. for future expansion.
};

#define VTF_RSRC_TEXTURE_CRC (MK_VTF_RSRC_ID('C', 'R', 'C'))

#pragma pack()

#endif  // VTF_H
