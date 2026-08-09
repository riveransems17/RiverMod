#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(RiverPlayLayer, PlayLayer) {
    bool menuOpen = false;
    CCLayer* menuLayer = nullptr;

    bool init(GJGameLevel* level) {
        if (!PlayLayer::init(level)) return false;
        this->setKeyboardEnabled(true);
        return true;
    }

    void keyDown(enumKeyCodes key) {
        PlayLayer::keyDown(key);

        if (key == KEY_Slash) {
            toggleMenu();
        }
    }

    void toggleMenu() {
        if (menuOpen) {
            if (menuLayer) {
                menuLayer->removeFromParent();
                menuLayer = nullptr;
            }
            menuOpen = false;
        } else {
            createMenu();
            menuOpen = true;
        }
    }

    void createMenu() {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        menuLayer = CCLayer::create();

        auto bg = CCLayerColor::create({0, 0, 0, 180});
        bg->setContentSize({350, 220});
        bg->setPosition({winSize.width/2 - 175, winSize.height/2 - 110});
        menuLayer->addChild(bg);

        auto title = CCLabelBMFont::create("River Mod Menu", "goldFont.fnt");
        title->setPosition({winSize.width/2, winSize.height/2 + 70});
        menuLayer->addChild(title);

        auto button = CCMenuItemFont::create("Test Button", [](CCObject*) {
            log::info("Button clicked!");
        });

        auto menu = CCMenu::create();
        menu->addChild(button);
        menu->setPosition({winSize.width/2, winSize.height/2});
        menuLayer->addChild(menu);

        this->addChild(menuLayer, 999);
    }
};