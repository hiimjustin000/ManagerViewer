#include <Geode/Geode.hpp>

using namespace geode::prelude;

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
public:
    static OffsetManager* get() {
        if (!instance) instance = new OffsetManager();
        return instance;
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
    uintptr_t objectToolbox();
};
