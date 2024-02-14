#include <rog/action/special/SpeakWithBlacksmith.h>

#include <rog/player/Inventory.h>
#include <rog/ui/textoutput/TextOutput.h>

void SpeakWithBlacksmith::execute() {
    std::vector<std::string> text;

    if (!Inventory::hasItem(Inventory::ItemType::MagicalShard)) {

        text.emplace_back("Your eyes water from the smoke and smarmy heat inside the tent. The");
        text.emplace_back("huge man swipes sweat from his bald head and looks up from his work.\n");

        text.emplace_back("\"There's no shortage of work to be done with Grelok scarin' everyone");
        text.emplace_back("witless. Leave me to filling my orders, stranger.\" With that, the");
        text.emplace_back("blacksmith dismisses you from his tent and douses a hot blade in water,");
        text.emplace_back("hissing with steam.");

    } else {

        text.emplace_back("The blacksmith regards you gruffly and is about to dismiss you when");
        text.emplace_back("you produce the polished gemstone from your bag. He sets his hammer");
        text.emplace_back("aside and twirls his moustache.\n");

        text.emplace_back("\"A right fine stone, that is.\" He says, admiring the faceted stone,");
        text.emplace_back("\"What would you be needin', then?\"\n");

        text.emplace_back("Following your careful instructions, the smithy re-forges your rusty");
        text.emplace_back("sword with the magical shard at the center of the blade.");

        Inventory::removeItem(Inventory::ItemType::RustySword);
        Inventory::removeItem(Inventory::ItemType::MagicalShard);
        Inventory::addItem(Inventory::ItemType::MagicSword);

    }

    text.emplace_back(getDescription());

    TextOutput::writeText(text);
}

std::string SpeakWithBlacksmith::getDescription() const {
    return "Speak with blacksmith";
}
