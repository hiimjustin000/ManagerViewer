#include <Geode/Geode.hpp>

using namespace geode::prelude;

// OffsetManager stores the offsets of the base addresses of Geometry Dash and Cocos2d-x, along with the offsets of various managers.
// Originally, the manager offsets were not cached, but it made it run terribly on Android, so I added caching.

class OffsetManager {
private:
    inline static OffsetManager* instance = nullptr;

    OffsetManager() : m_gdBase(base::get()), m_cocosBase(
        #ifdef GEODE_IS_WINDOWS
        base::getCocos()
        #else
        base::get()
        #endif
    ) {}

    uintptr_t m_gdBase = 0;
    uintptr_t m_cocosBase = 0;
    uintptr_t m_achievementManager = -1;
    uintptr_t m_achievementNotifier = -1;
    uintptr_t m_appDelegate = -1;
    uintptr_t m_bitmapFontCache = -1;
    uintptr_t m_animateFrameCache = -1;
    uintptr_t m_director = -1;
    uintptr_t m_fileUtils = -1;
    uintptr_t m_imeDispatcher = -1;
    uintptr_t m_shaderCache = -1;
    uintptr_t m_spriteFrameCache = -1;
    uintptr_t m_textureCache = -1;
    uintptr_t m_fmodAudioEngine = -1;
    uintptr_t m_gameLevelManager = -1;
    uintptr_t m_gameManager = -1;
    uintptr_t m_gameStatsManager = -1;
    uintptr_t m_accountManager = -1;
    uintptr_t m_multiplayerManager = -1;
    uintptr_t m_gjObjectDecoder = -1;
    uintptr_t m_googlePlayManager = -1;
    uintptr_t m_keybindingsManager = -1;
    uintptr_t m_localLevelManager = -1;
    uintptr_t m_musicDownloadManager = -1;
    uintptr_t m_objectDecoder = -1;
    uintptr_t m_objectManager = -1;
    uintptr_t m_objectToolbox = -1;
public:
    static OffsetManager* get() {
        if (!instance) instance = new OffsetManager();
        return instance;
    }

    void refresh() {
        m_achievementManager = -1;
        m_achievementNotifier = -1;
        m_appDelegate = -1;
        m_bitmapFontCache = -1;
        m_animateFrameCache = -1;
        m_director = -1;
        m_fileUtils = -1;
        m_imeDispatcher = -1;
        m_shaderCache = -1;
        m_spriteFrameCache = -1;
        m_textureCache = -1;
        m_fmodAudioEngine = -1;
        m_gameLevelManager = -1;
        m_gameManager = -1;
        m_gameStatsManager = -1;
        m_accountManager = -1;
        m_multiplayerManager = -1;
        m_gjObjectDecoder = -1;
        m_googlePlayManager = -1;
        m_keybindingsManager = -1;
        m_localLevelManager = -1;
        m_musicDownloadManager = -1;
        m_objectDecoder = -1;
        m_objectManager = -1;
        m_objectToolbox = -1;
    }

    static uintptr_t dereference(uintptr_t ptr) { return *reinterpret_cast<uintptr_t*>(ptr); }

    uintptr_t getGD() { return m_gdBase; }
    uintptr_t getGDOffset(uintptr_t offset) { return m_gdBase + offset; }

    uintptr_t getCocos() { return m_cocosBase; }
    uintptr_t getCocosOffset(uintptr_t offset) { return m_cocosBase + offset; }

    uintptr_t achievementManager();
    uintptr_t achievementNotifier();
    uintptr_t appDelegate();
    uintptr_t bitmapFontCache();
    uintptr_t animateFrameCache();
    uintptr_t director();
    uintptr_t fileUtils();
    uintptr_t imeDispatcher();
    uintptr_t shaderCache();
    uintptr_t spriteFrameCache();
    uintptr_t textureCache();
    uintptr_t fmodAudioEngine();
    uintptr_t gameLevelManager();
    uintptr_t gameManager();
    uintptr_t gameStatsManager();
    uintptr_t accountManager();
    uintptr_t multiplayerManager();
    uintptr_t gjObjectDecoder();
    uintptr_t googlePlayManager();
    uintptr_t keybindingsManager();
    uintptr_t localLevelManager();
    uintptr_t musicDownloadManager();
    uintptr_t objectDecoder();
    uintptr_t objectManager();
    uintptr_t objectToolbox();
};
