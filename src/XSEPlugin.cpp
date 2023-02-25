#include "hooks.h"
#include "dataHandler.h"

void Load()
{
	dataHandler::readSettings();
	if (settings::noRegenOnBlock) {
		logger::info("no regen on block, installing hook!");
		staminaRegenHook::InstallHook();
	}
	hitEventHook::InstallHook();
}
