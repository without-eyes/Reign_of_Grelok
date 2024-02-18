#include <rog/action/special/UseMagicalSwordGrelok.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <rog/action/special/LocationEvents.h>
#include <vector>

void UseMagicalSwordGrelok::execute() {
    std::vector<std::string> text;

    text.emplace_back("When you draw your sword, Grelok lowers his great horned head and");
    text.emplace_back("bellows laughter in your face. You grit your teeth and swing a mighty");
    text.emplace_back("bellows blow, the magical blade ringing clearly, even amid the tumult");
    text.emplace_back("bellows cackling.\n");

    text.emplace_back("You swing the sword so fiercely, it escapes your grip and hurtles into");
    text.emplace_back("bellows open maw of the monstrosity, lost from sight in the arid");
    text.emplace_back("darkness of Grelok's throat. You step back as Grelok jerks his mouth");
    text.emplace_back("shut and stands upright. He is still for a moment, then starts clawing");
    text.emplace_back("at his neck. Muffled, a ringing can be heard as if from a great");
    text.emplace_back("distance.\n");

    text.emplace_back("Suddenly, Grelok's chest bursts in a fount of viscous, green blood. The");
    text.emplace_back("Ringing can be heard clearly now, and as thick lifeblood oozes around");
    text.emplace_back("the protruding tip of the magic sword, the stormclouds swirling the peak");
    text.emplace_back("are already clearing. Grelok is defeated!\n");

    text.emplace_back("        THE END\n");
    text.emplace_back("        (Thanks for playing!)");

    text.emplace_back("");

    TextOutput::writeText(text);

    LocationEvents::changeValueKilledGrelok();
}

std::string UseMagicalSwordGrelok::getDescription() const {
    return "Use Magical Sword Grelok";
}
