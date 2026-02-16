// Fill out your copyright notice in the Description page of Project Settings.


#include "MG_CharacterBase.h"

// Sets default values
AMG_CharacterBase::AMG_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add the ability system component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(ASC_ReplicationMode);
}

// Called when the game starts or when spawned
void AMG_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMG_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMG_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMG_CharacterBase::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent) {
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AMG_CharacterBase::OnRep_PlayerState() {
	Super::OnRep_PlayerState();

	if (AbilitySystemComponent) {
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* AMG_CharacterBase::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}