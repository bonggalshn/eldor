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

/**
 * Test: Pause Menu Visibility on Escape
 * Verifies pressing Escape during gameplay shows pause menu overlay
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorPauseMenuVisibilityTest,
    "Eldor.UI.PauseMenu.VisibilityOnEscape",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Game Logic Paused When Menu Shown
 * Verifies all game logic freezes when pause menu is displayed
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorGameLogicPausedTest,
    "Eldor.UI.PauseMenu.GameLogicPaused",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Return To Menu Button Click
 * Verifies clicking Return To Menu returns to title screen
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorReturnToMenuButtonClickTest,
    "Eldor.UI.PauseMenu.ReturnToMenuButtonClick",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Scene Transition from Pause Menu to Title Screen
 * Verifies transition back to main menu
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorSceneTransitionToTitleScreenTest,
    "Eldor.UI.PauseMenu.SceneTransitionToTitleScreen",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Exit To Desktop Button Click
 * Verifies clicking Exit To Desktop closes the application
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorExitToDesktopButtonClickTest,
    "Eldor.UI.PauseMenu.ExitToDesktopButtonClick",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

/**
 * Test: Application Clean Exit
 * Verifies application terminates cleanly without data loss
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEldorApplicationCleanExitTest,
    "Eldor.UI.PauseMenu.ApplicationCleanExit",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

#endif // WITH_DEV_AUTOMATION_TESTS