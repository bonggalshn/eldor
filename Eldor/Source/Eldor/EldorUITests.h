#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

/**
 * EldorUITests
 * TDD test class for Eldor UI components
 * Tests title screen visibility and exit button functionality
 */
#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test: Title Text Visibility
 * Verifies that "Eldor" text is displayed on title screen
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorTitleTextVisibilityTest, 
    "Eldor.UI.TitleScreen.TitleTextVisibility",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Exit Button Click
 * Verifies exit button triggers application termination
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorExitButtonClickTest,
    "Eldor.UI.TitleScreen.ExitButtonClick",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Rapid Exit Click Handling
 * Verifies rapid clicks are handled gracefully (only one exit call)
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorRapidExitClickTest,
    "Eldor.UI.TitleScreen.RapidExitClick",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Window Close Button
 * Verifies window close button terminates application
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorWindowCloseTest,
    "Eldor.UI.TitleScreen.WindowClose",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: New Game Button Visibility
 * Verifies NewGame button is present on title screen
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorNewGameButtonVisibilityTest,
    "Eldor.UI.TitleScreen.NewGameButtonVisibility",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: New Game Button Click
 * Verifies clicking NewGame button initiates level transition to World
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorNewGameButtonClickTest,
    "Eldor.UI.TitleScreen.NewGameButtonClick",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Scene Transition to World
 * Verifies transition from TitleScreen to World scene
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorSceneTransitionToWorldTest,
    "Eldor.UI.TitleScreen.SceneTransitionToWorld",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

#endif // WITH_DEV_AUTOMATION_TESTS