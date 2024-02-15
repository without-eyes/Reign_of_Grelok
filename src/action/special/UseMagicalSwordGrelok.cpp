#include <rog/action/special/UseMagicalSwordGrelok.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <vector>

void UseMagicalSwordGrelok::execute() {
    std::vector<std::string> text;

    text.emplace_back("When you draw your sword, Grelok lowers his great horned head and bellows");
    text.emplace_back("laughter in your face. You grit your teeth and swing a mighty two-handed blow,");
    text.emplace_back("the magical blade ringing clearly, even amid the tumult of throaty cackling.\n");

    text.emplace_back("You swing the sword so fiercely, it escapes your grip and hurtles into the");
    text.emplace_back("open maw of the monstrosity, lost from sight in the arid darkness of Grelok's");
    text.emplace_back("throat. You step back as Grelok jerks his mouth shut and stands upright. He is");
    text.emplace_back("still for a moment, then starts clawing at his neck. Muffled, a ringing can be");
    text.emplace_back("heard as if from a great distance.\n");

    text.emplace_back("Suddenly, Grelok's chest bursts in a fount of viscous, green blood. The Ringing");
    text.emplace_back("can be heard clearly now, and as thick lifeblood oozes around the protruding tip");
    text.emplace_back("of the magic sword, the stormclouds swirling the peak are already clearing. Grelok");
    text.emplace_back("is defeated!\n");

    text.emplace_back("        THE END\n");
    text.emplace_back("        (Thanks for playing!)");

    text.emplace_back("");

    TextOutput::writeText(text);
}

std::string UseMagicalSwordGrelok::getDescription() const {
    return "Use Magical Sword Grelok";
}
