#ifdef GEODE_IS_WINDOWS
#include <geode.custom-keybinds/include/Keybinds.hpp>
#endif
#include <imgui-cocos.hpp>
#include "ModuleManager.hpp"

using namespace geode::prelude;

// ImGui Cocos is a library that initializes Dear ImGui for Cocos2d-x.
// Special thanks to Prevter for giving me the example code to use ImGui with Cocos2d-x.

static ImFont* openSans = nullptr;

$execute {
    #ifdef GEODE_IS_WINDOWS
    using namespace keybinds;

    BindManager::get()->registerBindable({
        "view-managers"_spr,
        "View Managers",
        "Toggles the manager viewer window",
        { Keybind::create(KEY_Y, Modifier::Alt) },
        "Manager Viewer"
    });
    new EventListener([=](InvokeBindEvent* event) {
        if (event->isDown()) {
            auto& imgui = ImGuiCocos::get();
            imgui.toggle();
            if (imgui.isVisible()) ModuleManager::get()->init();
        }
        return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "view-managers"_spr));
    #endif
    ImGuiCocos::get()
        .setup([]{
            openSans = ImGui::GetIO().Fonts->AddFontFromFileTTF((Mod::get()->getResourcesDir() / "opensans.ttf").string().c_str(), 20.0f);
        })
        .draw([]{
            if (ImGui::Begin("Manager Viewer", nullptr, ImGuiWindowFlags_HorizontalScrollbar)) {
                ImGui::PushFont(openSans);

                auto moduleManager = ModuleManager::get();
                for (auto& module : moduleManager->getModules()) {
                    auto ptr = module.address != 0 ? fmt::format("0x{:x}", module.address) : "[NULL]";
                    ImGui::Text("%s: %s", module.name.c_str(), ptr.c_str());
                    ImGui::SameLine();
                    if (ImGui::Button(fmt::format("Copy##{}", module.address).c_str())) clipboard::write(ptr);
                }

                if (ImGui::Button("Close")) ImGuiCocos::get().setVisible(false);

                ImGui::PopFont();
            }
            ImGui::End();
        })
        .setVisible(false);
}

#include <Geode/modify/MenuLayer.hpp>
class $modify(MVMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto bottomMenu = getChildByID("bottom-menu");
        auto managerViewerButton = CCMenuItemSpriteExtra::create(CircleButtonSprite::createWithSprite("MV_viewerBtn_001.png"_spr, 1.0f,
            CircleBaseColor::Green, CircleBaseSize::MediumAlt), this, menu_selector(MVMenuLayer::onManagerViewer));
        managerViewerButton->setID("manager-viewer-button"_spr);
        bottomMenu->addChild(managerViewerButton);
        bottomMenu->updateLayout();

        return true;
    }

    void onManagerViewer(CCObject*) {
        auto& imgui = ImGuiCocos::get();
        imgui.toggle();
        if (imgui.isVisible()) ModuleManager::get()->init();
    }
};
