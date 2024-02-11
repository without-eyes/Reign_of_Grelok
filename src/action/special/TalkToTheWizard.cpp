#include "rog/action/special/TalkToTheWizard.h"

void TalkToTheWizard::execute() {
    std::vector<std::string> vText;

    if (!Inventory::hasItem("Raw Gemstone")) {

        vText.emplace_back("The wizard beckons wildly at you from his balcony. \"You're here,");
        vText.emplace_back("you've arrived!\", he exclaims. After an awkward silence, he jabs");
        vText.emplace_back("an excited finger into a crystal ball, nearly knocking it into");
        vText.emplace_back("the bog.\n");

        vText.emplace_back("\"I've seen, you see. You're the one to defeat Grelok. Hoo-hoo!\"");
        vText.emplace_back("The little man hops onto the railing, spinning a pirouette. \"Now");
        vText.emplace_back("the time's come to play my part. Toss up the gem!\"\n");

        vText.emplace_back("The wizard's brow furrows. \"Got things a bit out of order, have I?");
        vText.emplace_back("Come back when you've got a powerful gemstone. Soon - I've never got");
        vText.emplace_back("to fulfill a prophecy before!\"");

    } else {

        vText.emplace_back("\"Hoo-hoo! The slayer of Grelok approaches, raw stone in hand, just");
        vText.emplace_back("as I've seen!\" The wizard's pointy hat bobs excitedly as he points");
        vText.emplace_back("a finger at you. Suddenly, a pale orange arc of light extends from the");
        vText.emplace_back("knobby finger and draws the gemstone from your bag before you can react.");
        vText.emplace_back("The gemstone halts and hovers in the air before the wizard's nose.\n");

        vText.emplace_back("\"Essence be true, powers renew, Fatty-Hoo-Do!\" With that, he slaps");
        vText.emplace_back("the hovering stone, smashing it against the smooth stone of the tower.");
        vText.emplace_back("In a burst of light, the stone splits into two, and one lands in each");
        vText.emplace_back("outstretched palm of the hopping little wizard.\n");

        vText.emplace_back("\"Shard for the sword. Wrap her in iron and she'll find Grelok's black");
        vText.emplace_back("heart for you. Take the chaff, too. You'll need payment for a smith to");
        vText.emplace_back("forge the weapon.\" He tosses the stones down which you leap forward to");
        vText.emplace_back("catch safely.");

    }

    vText.emplace_back("You acknowledge the wizard...");

    TextOutput::writeText(vText);
}

std::string TalkToTheWizard::getDescription() const {
    return "Talk to the wizard";
}
