#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * EldorGame Module
 * Main game module for Eldor - Open World RPG
 */
class FEldorGameModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

#ifndef ELDOR_GAME_MODULE_API
#define ELDOR_GAME_MODULE_API DLLEXPORT
#endif