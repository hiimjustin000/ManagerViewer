#include "OffsetManager.hpp"

// To anyone reading this code and questioning what the hell I'm doing:
// I'm using the preprocessor to define offsets for each singleton in the game.
// This is because the offsets are different for each platform and architecture.
// You might think I could just use the creator functions, but they initialize
// the singletons if not already initialized, which is not what I want.

#if defined(GEODE_IS_WINDOWS)

#define ACHIEVEMENT_MANAGER_OFFSET 0x687d98
#define ACHIEVEMENT_NOTIFIER_OFFSET 0x687da0
#define APP_DELEGATE_OFFSET 0x1a5480
#define BITMAP_FONT_CACHE_OFFSET 0x687db0
#define CC_ANIMATE_FRAME_CACHE_OFFSET 0x687db8
#define CC_DIRECTOR_OFFSET 0x1a69f8
#define CC_FILE_UTILS_OFFSET 0x1a5470
#define CC_IME_DISPATCHER_OFFSET 0x1a69b0
#define CC_SHADER_CACHE_OFFSET 0x1a5670
#define CC_SPRITE_FRAME_CACHE_OFFSET 0x1a56b0
#define CC_TEXTURE_CACHE_OFFSET 0x1a6978
#define FMOD_AUDIO_ENGINE_OFFSET 0x687dc0
#define GAME_LEVEL_MANAGER_OFFSET 0x687e00
#define GAME_MANAGER_OFFSET 0x687e10
#define GAME_STATS_MANAGER_OFFSET 0x687e20
#define GJ_ACCOUNT_MANAGER_OFFSET 0x687e28
#define GJ_MULTIPLAYER_MANAGER_OFFSET 0x687e40
#define GJ_OBJECT_DECODER_OFFSET 0x687e48
#define GOOGLE_PLAY_MANAGER_OFFSET 0x687dd8
#define KEYBINDINGS_MANAGER_OFFSET 0x687e50
#define LOCAL_LEVEL_MANAGER_OFFSET 0x687e58
#define MUSIC_DOWNLOAD_MANAGER_OFFSET 0x687e60
#define OBJECT_DECODER_OFFSET 0x1a53c0
#define OBJECT_MANAGER_OFFSET 0x687de0
#define OBJECT_TOOLBOX_OFFSET 0x687e68

#elif defined(GEODE_IS_ANDROID32)

#define ACHIEVEMENT_MANAGER_OFFSET 0xa9afac
#define ACHIEVEMENT_NOTIFIER_OFFSET 0xa9af70
#define APP_DELEGATE_OFFSET 0xa9efac
#define BITMAP_FONT_CACHE_OFFSET 0xa9afe4
#define CC_ANIMATE_FRAME_CACHE_OFFSET 0xa9b120
#define CC_DIRECTOR_OFFSET 0xa9e930
#define CC_FILE_UTILS_OFFSET 0xa9ee50
#define CC_IME_DISPATCHER_OFFSET 0xaa0898
#define CC_SHADER_CACHE_OFFSET 0xa9f1ac
#define CC_SPRITE_FRAME_CACHE_OFFSET 0xa9f2a4
#define CC_TEXTURE_CACHE_OFFSET 0xaa095c
#define FMOD_AUDIO_ENGINE_OFFSET 0xa9b8c0
#define GAME_LEVEL_MANAGER_OFFSET 0xa9beb0
#define GAME_MANAGER_OFFSET 0xa9bacc
#define GAME_STATS_MANAGER_OFFSET 0xa9c134
#define GJ_ACCOUNT_MANAGER_OFFSET 0xa9c704
#define GJ_MULTIPLAYER_MANAGER_OFFSET 0xa9d490
#define GJ_OBJECT_DECODER_OFFSET 0xa9c5ec
#define GOOGLE_PLAY_MANAGER_OFFSET 0xa9b71c
#define KEYBINDINGS_MANAGER_OFFSET 0xa9c7d8
#define LOCAL_LEVEL_MANAGER_OFFSET 0xa9c3dc
#define MUSIC_DOWNLOAD_MANAGER_OFFSET 0xa9c664
#define OBJECT_DECODER_OFFSET 0xaa0c48
#define OBJECT_MANAGER_OFFSET 0xa9b578
#define OBJECT_TOOLBOX_OFFSET 0xa9c4e4

#elif defined(GEODE_IS_ANDROID64)

#define ACHIEVEMENT_MANAGER_OFFSET 0x11f61c8
#define ACHIEVEMENT_NOTIFIER_OFFSET 0x11f6180
#define APP_DELEGATE_OFFSET 0x11fa758
#define BITMAP_FONT_CACHE_OFFSET 0x11f6208
#define CC_ANIMATE_FRAME_CACHE_OFFSET 0x11f6360
#define CC_DIRECTOR_OFFSET 0x11fa068
#define CC_FILE_UTILS_OFFSET 0x11fa5b0
#define CC_IME_DISPATCHER_OFFSET 0x11fc0d8
#define CC_SHADER_CACHE_OFFSET 0x11fa988
#define CC_SPRITE_FRAME_CACHE_OFFSET 0x11faa88
#define CC_TEXTURE_CACHE_OFFSET 0x11fc1d0
#define FMOD_AUDIO_ENGINE_OFFSET 0x11f6ba0
#define GAME_LEVEL_MANAGER_OFFSET 0x11f7230
#define GAME_MANAGER_OFFSET 0x11f6de8
#define GAME_STATS_MANAGER_OFFSET 0x11f74e0
#define GJ_ACCOUNT_MANAGER_OFFSET 0x11f7b40
#define GJ_MULTIPLAYER_MANAGER_OFFSET 0x11f89e0
#define GJ_OBJECT_DECODER_OFFSET 0x11f7a38
#define GOOGLE_PLAY_MANAGER_OFFSET 0x11f69d8
#define KEYBINDINGS_MANAGER_OFFSET 0x11f7c28
#define LOCAL_LEVEL_MANAGER_OFFSET 0x11f77c0
#define MUSIC_DOWNLOAD_MANAGER_OFFSET 0x11f7a90
#define OBJECT_DECODER_OFFSET 0x11fc5a8
#define OBJECT_MANAGER_OFFSET 0x11f6810
#define OBJECT_TOOLBOX_OFFSET 0x11f7918

#elif defined(GEODE_IS_INTEL_MAC)

#define ACHIEVEMENT_MANAGER_OFFSET 0x9add28
#define ACHIEVEMENT_NOTIFIER_OFFSET 0x9ae0a0
#define APP_DELEGATE_OFFSET 0x9af200
#define BITMAP_FONT_CACHE_OFFSET 0x9a95c8
#define CC_ANIMATE_FRAME_CACHE_OFFSET 0x9acc88
#define CC_DIRECTOR_OFFSET 0x9abd58
#define CC_FILE_UTILS_OFFSET 0x9af220
#define CC_IME_DISPATCHER_OFFSET 0x9ac158
#define CC_SHADER_CACHE_OFFSET 0x9a93f8
#define CC_SPRITE_FRAME_CACHE_OFFSET 0x9aa838
#define CC_TEXTURE_CACHE_OFFSET 0x9ad298
#define FMOD_AUDIO_ENGINE_OFFSET 0x9ab5f8
#define GAME_LEVEL_MANAGER_OFFSET 0x9acb60
#define GAME_MANAGER_OFFSET 0x9aaf98
#define GAME_STATS_MANAGER_OFFSET 0x9a8ee8
#define GJ_ACCOUNT_MANAGER_OFFSET 0x9a9100
#define GJ_MULTIPLAYER_MANAGER_OFFSET 0x9ada60
#define GJ_OBJECT_DECODER_OFFSET 0x9adcc0
#define GOOGLE_PLAY_MANAGER_OFFSET 0x9abc88
#define KEYBINDINGS_MANAGER_OFFSET 0x9ac438
#define LOCAL_LEVEL_MANAGER_OFFSET 0x9ad4d8
#define MUSIC_DOWNLOAD_MANAGER_OFFSET 0x9aceb8
#define OBJECT_DECODER_OFFSET 0x9add90
#define OBJECT_MANAGER_OFFSET 0x9ade28
#define OBJECT_TOOLBOX_OFFSET 0x9adbc0

#elif defined(GEODE_IS_ARM_MAC)

#define ACHIEVEMENT_MANAGER_OFFSET 0x8c79f0
#define ACHIEVEMENT_NOTIFIER_OFFSET 0x8c7d80
#define APP_DELEGATE_OFFSET 0x8c8f00
#define BITMAP_FONT_CACHE_OFFSET 0x8c3140
#define CC_ANIMATE_FRAME_CACHE_OFFSET 0x8c68b0
#define CC_DIRECTOR_OFFSET 0x8c5950
#define CC_FILE_UTILS_OFFSET 0x8c8f20
#define CC_IME_DISPATCHER_OFFSET 0x8c5d80
#define CC_SHADER_CACHE_OFFSET 0x8c2f90
#define CC_SPRITE_FRAME_CACHE_OFFSET 0x8c43d0
#define CC_TEXTURE_CACHE_OFFSET 0x8c6ef0
#define FMOD_AUDIO_ENGINE_OFFSET 0x8c51d0
#define GAME_LEVEL_MANAGER_OFFSET 0x8c6780
#define GAME_MANAGER_OFFSET 0x8c4b50
#define GAME_STATS_MANAGER_OFFSET 0x8c2a30
#define GJ_ACCOUNT_MANAGER_OFFSET 0x8c2c50
#define GJ_MULTIPLAYER_MANAGER_OFFSET 0x8c76f0
#define GJ_OBJECT_DECODER_OFFSET 0x8c7980
#define GOOGLE_PLAY_MANAGER_OFFSET 0x8c5870
#define KEYBINDINGS_MANAGER_OFFSET 0x8c6040
#define LOCAL_LEVEL_MANAGER_OFFSET 0x8c7140
#define MUSIC_DOWNLOAD_MANAGER_OFFSET 0x8c6aa0
#define OBJECT_DECODER_OFFSET 0x8c7a60
#define OBJECT_MANAGER_OFFSET 0x8c7b00
#define OBJECT_TOOLBOX_OFFSET 0x8c7860

#endif

uintptr_t OffsetManager::achievementManager() {
    return m_achievementManager != UINTPTR_MAX ? m_achievementManager : m_achievementManager = dereference(getGDOffset(ACHIEVEMENT_MANAGER_OFFSET));
}

uintptr_t OffsetManager::achievementNotifier() {
    return m_achievementNotifier != UINTPTR_MAX ? m_achievementNotifier : m_achievementNotifier = dereference(getGDOffset(ACHIEVEMENT_NOTIFIER_OFFSET));
}

uintptr_t OffsetManager::appDelegate() {
    return m_appDelegate != UINTPTR_MAX ? m_appDelegate : m_appDelegate = dereference(getCocosOffset(APP_DELEGATE_OFFSET));
}

uintptr_t OffsetManager::bitmapFontCache() {
    return m_bitmapFontCache != UINTPTR_MAX ? m_bitmapFontCache : m_bitmapFontCache = dereference(getGDOffset(BITMAP_FONT_CACHE_OFFSET));
}

uintptr_t OffsetManager::animateFrameCache() {
    return m_animateFrameCache != UINTPTR_MAX ? m_animateFrameCache : m_animateFrameCache = dereference(getGDOffset(CC_ANIMATE_FRAME_CACHE_OFFSET));
}

uintptr_t OffsetManager::director() {
    return m_director != UINTPTR_MAX ? m_director : m_director = dereference(getCocosOffset(CC_DIRECTOR_OFFSET));
}

uintptr_t OffsetManager::fileUtils() {
    return m_fileUtils != UINTPTR_MAX ? m_fileUtils : m_fileUtils = dereference(getCocosOffset(CC_FILE_UTILS_OFFSET));
}

uintptr_t OffsetManager::imeDispatcher() {
    return m_imeDispatcher != UINTPTR_MAX ? m_imeDispatcher : m_imeDispatcher = dereference(getCocosOffset(CC_IME_DISPATCHER_OFFSET));
}

uintptr_t OffsetManager::shaderCache() {
    return m_shaderCache != UINTPTR_MAX ? m_shaderCache : m_shaderCache = dereference(getCocosOffset(CC_SHADER_CACHE_OFFSET));
}

uintptr_t OffsetManager::spriteFrameCache() {
    return m_spriteFrameCache != UINTPTR_MAX ? m_spriteFrameCache : m_spriteFrameCache = dereference(getCocosOffset(CC_SPRITE_FRAME_CACHE_OFFSET));
}

uintptr_t OffsetManager::textureCache() {
    return m_textureCache != UINTPTR_MAX ? m_textureCache : m_textureCache = dereference(getCocosOffset(CC_TEXTURE_CACHE_OFFSET));
}

uintptr_t OffsetManager::fmodAudioEngine() {
    return m_fmodAudioEngine != UINTPTR_MAX ? m_fmodAudioEngine : m_fmodAudioEngine = dereference(getGDOffset(FMOD_AUDIO_ENGINE_OFFSET));
}

uintptr_t OffsetManager::gameLevelManager() {
    return m_gameLevelManager != UINTPTR_MAX ? m_gameLevelManager : m_gameLevelManager = dereference(getGDOffset(GAME_LEVEL_MANAGER_OFFSET));
}

uintptr_t OffsetManager::gameManager() {
    return m_gameManager != UINTPTR_MAX ? m_gameManager : m_gameManager = dereference(getGDOffset(GAME_MANAGER_OFFSET));
}

uintptr_t OffsetManager::gameStatsManager() {
    return m_gameStatsManager != UINTPTR_MAX ? m_gameStatsManager : m_gameStatsManager = dereference(getGDOffset(GAME_STATS_MANAGER_OFFSET));
}

uintptr_t OffsetManager::accountManager() {
    return m_accountManager != UINTPTR_MAX ? m_accountManager : m_accountManager = dereference(getGDOffset(GJ_ACCOUNT_MANAGER_OFFSET));
}

uintptr_t OffsetManager::multiplayerManager() {
    return m_multiplayerManager != UINTPTR_MAX ? m_multiplayerManager : m_multiplayerManager = dereference(getGDOffset(GJ_MULTIPLAYER_MANAGER_OFFSET));
}

uintptr_t OffsetManager::gjObjectDecoder() {
    return m_gjObjectDecoder != UINTPTR_MAX ? m_gjObjectDecoder : m_gjObjectDecoder = dereference(getGDOffset(GJ_OBJECT_DECODER_OFFSET));
}

uintptr_t OffsetManager::googlePlayManager() {
    return m_googlePlayManager != UINTPTR_MAX ? m_googlePlayManager : m_googlePlayManager = dereference(getGDOffset(GOOGLE_PLAY_MANAGER_OFFSET));
}

uintptr_t OffsetManager::keybindingsManager() {
    return m_keybindingsManager != UINTPTR_MAX ? m_keybindingsManager : m_keybindingsManager = dereference(getGDOffset(KEYBINDINGS_MANAGER_OFFSET));
}

uintptr_t OffsetManager::localLevelManager() {
    return m_localLevelManager != UINTPTR_MAX ? m_localLevelManager : m_localLevelManager = dereference(getGDOffset(LOCAL_LEVEL_MANAGER_OFFSET));
}

uintptr_t OffsetManager::musicDownloadManager() {
    return m_musicDownloadManager != UINTPTR_MAX ? m_musicDownloadManager : m_musicDownloadManager = dereference(getGDOffset(MUSIC_DOWNLOAD_MANAGER_OFFSET));
}

uintptr_t OffsetManager::objectDecoder() {
    return m_objectDecoder != UINTPTR_MAX ? m_objectDecoder : m_objectDecoder = dereference(getCocosOffset(OBJECT_DECODER_OFFSET));
}

uintptr_t OffsetManager::objectManager() {
    return m_objectManager != UINTPTR_MAX ? m_objectManager : m_objectManager = dereference(getGDOffset(OBJECT_MANAGER_OFFSET));
}

uintptr_t OffsetManager::objectToolbox() {
    return m_objectToolbox != UINTPTR_MAX ? m_objectToolbox : m_objectToolbox = dereference(getGDOffset(OBJECT_TOOLBOX_OFFSET));
}
