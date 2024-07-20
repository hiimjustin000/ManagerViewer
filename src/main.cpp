#ifndef GEODE_IS_MACOS
#include <geode.custom-keybinds/include/Keybinds.hpp>
#endif
#include <imgui-cocos.hpp>
#include "OffsetManager.hpp"

static ImFont* openSans = nullptr;

static void createAddressLabelWithCopyButton(const char* label, uintptr_t address) {
    auto ptr = address != 0 ? fmt::format("0x{:x}", address) : "[NULL]";
    ImGui::Text("%s: %s", label, ptr.c_str());
    ImGui::SameLine();
    if (ImGui::Button(fmt::format("Copy##{}", label).c_str())) clipboard::write(ptr.c_str());
}

$execute {
    #ifndef GEODE_IS_MACOS
    using namespace keybinds;

    BindManager::get()->registerBindable({
        "view-managers"_spr,
        "View Managers",
        "Toggles the manager viewer window",
        { Keybind::create(KEY_Y, Modifier::Alt) },
        "Manager Viewer"
    });
    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown())
            ImGuiCocos::get().toggle();
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "view-managers"_spr));
    #endif
    ImGuiCocos::get()
        .setup([]{
            openSans = ImGui::GetIO().Fonts->AddFontFromFileTTF((Mod::get()->getResourcesDir() / "opensans.ttf").string().c_str(), 20.0f);
        })
        .draw([]{
            if (ImGui::Begin("Manager Viewer")) {
                ImGui::PushFont(openSans);

                auto offsetManager = OffsetManager::get();
                createAddressLabelWithCopyButton("Geometry Dash Base", offsetManager->getGD());
                createAddressLabelWithCopyButton("Cocos2d-x Base", offsetManager->getCocos());
                ImGui::NewLine();
                createAddressLabelWithCopyButton("AchievementManager", offsetManager->achievementManager());
                createAddressLabelWithCopyButton("AchievementNotifier", offsetManager->achievementNotifier());
                createAddressLabelWithCopyButton("AppDelegate", offsetManager->appDelegate());
                createAddressLabelWithCopyButton("BitmapFontCache", offsetManager->bitmapFontCache());
                createAddressLabelWithCopyButton("CCAnimateFrameCache", offsetManager->animateFrameCache());
                createAddressLabelWithCopyButton("CCDirector", offsetManager->director());
                createAddressLabelWithCopyButton("CCFileUtils", offsetManager->fileUtils());
                createAddressLabelWithCopyButton("CCIMEDispatcher", offsetManager->imeDispatcher());
                createAddressLabelWithCopyButton("CCShaderCache", offsetManager->shaderCache());
                createAddressLabelWithCopyButton("CCSpriteFrameCache", offsetManager->spriteFrameCache());
                createAddressLabelWithCopyButton("CCTextureCache", offsetManager->textureCache());
                createAddressLabelWithCopyButton("FMODAudioEngine", offsetManager->fmodAudioEngine());
                createAddressLabelWithCopyButton("GameLevelManager", offsetManager->gameLevelManager());
                createAddressLabelWithCopyButton("GameManager", offsetManager->gameManager());
                createAddressLabelWithCopyButton("GameStatsManager", offsetManager->gameStatsManager());
                createAddressLabelWithCopyButton("GJAccountManager", offsetManager->accountManager());
                createAddressLabelWithCopyButton("GJMultiplayerManager", offsetManager->multiplayerManager());
                createAddressLabelWithCopyButton("GJObjectDecoder", offsetManager->gjObjectDecoder());
                createAddressLabelWithCopyButton("GooglePlayManager", offsetManager->googlePlayManager());
                createAddressLabelWithCopyButton("KeybindingsManager", offsetManager->keybindingsManager());
                createAddressLabelWithCopyButton("LocalLevelManager", offsetManager->localLevelManager());
                createAddressLabelWithCopyButton("MusicDownloadManager", offsetManager->musicDownloadManager());
                createAddressLabelWithCopyButton("ObjectDecoder", offsetManager->objectDecoder());
                createAddressLabelWithCopyButton("ObjectToolbox", offsetManager->objectToolbox());

                if (ImGui::Button("Close")) ImGuiCocos::get().toggle();

                ImGui::PopFont();
            }
            ImGui::End();
        })
        .setVisible(false);
}

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto bottomMenu = getChildByID("bottom-menu");
        bottomMenu->addChild(CCMenuItemExt::createSpriteExtra(CircleButtonSprite::createWithSprite("MV_viewerBtn_001.png"_spr, 1.0f,
            CircleBaseColor::Green, CircleBaseSize::MediumAlt), [](auto) {
                ImGuiCocos::get().toggle();
            }));
        bottomMenu->updateLayout();

        return true;
    }
};
