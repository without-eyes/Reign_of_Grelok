#include <rog/action/special/TalkToTheWizard.h>

#include <rog/player/Inventory.h>
#include <rog/ui/textoutput/TextOutput.h>

void TalkToTheWizard::execute() {
    std::vector<std::string> text;

    if (!Inventory::hasItem(Inventory::ItemType::RawGemstone)) {

        text.emplace_back("The wizard beckons wildly at you from his balcony. \"You're here,");
        text.emplace_back("you've arrived!\", he exclaims. After an awkward silence, he jabs");
        text.emplace_back("an excited finger into a crystal ball, nearly knocking it into");
        text.emplace_back("the bog.\n");

        text.emplace_back("\"I've seen, you see. You're the one to defeat Grelok. Hoo-hoo!\"");
        text.emplace_back("The little man hops onto the railing, spinning a pirouette. \"Now");
        text.emplace_back("the time's come to play my part. Toss up the gem!\"\n");

        text.emplace_back("The wizard's brow furrows. \"Got things a bit out of order, have I?");
        text.emplace_back("Come back when you've got a powerful gemstone. Soon - I've never got");
        text.emplace_back("to fulfill a prophecy before!\"");

    } else {

        text.emplace_back("\"Hoo-hoo! The slayer of Grelok approaches, raw stone in hand, just");
        text.emplace_back("as I've seen!\" The wizard's pointy hat bobs excitedly as he points");
        text.emplace_back("a finger at you. Suddenly, a pale orange arc of light extends from the");
        text.emplace_back("knobby finger and draws the gemstone from your bag before you can react.");
        text.emplace_back("The gemstone halts and hovers in the air before the wizard's nose.\n");

        text.emplace_back("\"Essence be true, powers renew, Fatty-Hoo-Do!\" With that, he slaps");
        text.emplace_back("the hovering stone, smashing it against the smooth stone of the tower.");
        text.emplace_back("In a burst of light, the stone splits into two, and one lands in each");
        text.emplace_back("outstretched palm of the hopping little wizard.\n");

        text.emplace_back("\"Shard for the sword. Wrap her in iron and she'll find Grelok's black");
        text.emplace_back("heart for you. Take the chaff, too. You'll need payment for a smith to");
        text.emplace_back("forge the weapon.\" He tosses the stones down which you leap forward to");
        text.emplace_back("catch safely.");

    }

    text.emplace_back("You acknowledge the wizard...");

    TextOutput::writeText(text);
}

std::string TalkToTheWizard::getDescription() const {
    return "Talk to the wizard";
}
