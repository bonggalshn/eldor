#include "Eldor.h"
#include "Modules/ModuleManager.h"
#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY(LogEldorGame);

void FEldorGameModule::StartupModule()
{
    UE_LOG(LogEldorGame, Log, TEXT("Eldor Game Module Starting..."));
}

void FEldorGameModule::ShutdownModule()
{
    UE_LOG(LogEldorGame, Log, TEXT("Eldor Game Module Shutting Down..."));
}

IMPLEMENT_MODULE(FEldorGameModule, Eldor)