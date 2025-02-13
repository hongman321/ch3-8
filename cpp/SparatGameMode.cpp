// Fill out your copyright notice in the Description page of Project Settings.


#include "SparatGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h" // PlayerController Ŭ������ ���
#include "SpartaGameState.h"
ASparatGameMode::ASparatGameMode()
{
    DefaultPawnClass = ASpartaCharacter::StaticClass();
    PlayerControllerClass = ASpartaPlayerController::StaticClass();
    GameStateClass = ASpartaGameState::StaticClass();
}