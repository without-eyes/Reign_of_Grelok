#include <rog/action/special/SpeakWithPriest.h>

#include <rog/player/Inventory.h>
#include <rog/ui/textoutput/TextOutput.h>
#include <rog/action/special/LocationEvents.h>

void SpeakWithPriest::execute() {
    std::vector<std::string> text;

    if (!LocationEvents::hasZombieKilled() && !Inventory::hasItem(Inventory::ItemType::ZombieHead)) {

        text.emplace_back("The priest notices your approach and looks up from his swilling.");
        text.emplace_back("\"Grelok is come, and we are forsaken!\", he cries. \"Urp!\", he");
        text.emplace_back("continues.\n");

        text.emplace_back("As you recover from the stench of the priestly belch, you are told");
        text.emplace_back("that the priest has fled from his nearby chapel. When Grelok arrived");
        text.emplace_back("on the mountain, the dead in his cemetery began to rise, and his");
        text.emplace_back("congregation scattered.\n");

        text.emplace_back("\"If you could rid the place of the zombies\", he tells you, \"I'll");
        text.emplace_back("give you the key, and you can help yourself to the apothecary\"");

    } else if (LocationEvents::hasZombieKilled() && !Inventory::hasItem(Inventory::ItemType::BrassKey)) {

        text.emplace_back("The priest drunkenly curses the undead who have defiled his church.");
        text.emplace_back("You present him with the decapitated zombie head from your bag.\n");

        text.emplace_back("\"Praise you!\", he hiccups. \"Perhaps Grelok's influence isn't so");
        text.emplace_back("strong!\". With that, he turns his decanter over on the head and tosses");
        text.emplace_back("into a fireplace, where it bursts into purple flame and burns up almost");
        text.emplace_back("instantly.\n");

        text.emplace_back("\"I must gather the faithful.\" He presses a brass key into your palm,");
        text.emplace_back("\"Please, help yourself to what little may be of use at my chapel.\"");

        Inventory::removeItem(Inventory::ItemType::ZombieHead);
        Inventory::addItem(Inventory::ItemType::BrassKey);

    }

    text.emplace_back("You approach the clergyman...");

    TextOutput::writeText(text);
}

std::string SpeakWithPriest::getDescription() const {
    return "Speak with priest";
}
