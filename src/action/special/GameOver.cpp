#include <rog/action/special/GameOver.h>

#include <rog/action/special/LocationEvents.h>
#include <rog/ui/menu/Menu.h>
#include <windows.h>

void GameOver::execute() {
    if (!LocationEvents::hasPressedVictory()) {
        mciSendString(R"(play ..\other\sounds\ui_hacking_passgood.wav)", nullptr, 0, nullptr);
        LocationEvents::changeValuePressedVictory();
        Menu::setLowerText("Thanks for playing!");
    }

}

std::string GameOver::getDescription() const {
    if (!LocationEvents::hasPressedVictory()) {
        return "VICTORY!";
    } else {
        return "Game Over";
    }
}
