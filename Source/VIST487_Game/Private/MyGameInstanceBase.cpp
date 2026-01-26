// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceBase.h"

#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/NavigationConfig.h"

void UMyGameInstanceBase::Init()
{
    Super::Init();

    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavigationConfig = MakeShared<FNavigationConfig>();
        NavigationConfig->bTabNavigation = false;
        NavigationConfig->bKeyNavigation = false;
        NavigationConfig->bAnalogNavigation = false;

        FSlateApplication::Get().SetNavigationConfig(NavigationConfig);
    }
}