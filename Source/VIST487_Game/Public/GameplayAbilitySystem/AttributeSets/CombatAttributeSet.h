

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CombatAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class VIST487_GAME_API UCombatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UCombatAttributeSet();

	//BaseDamage Attribute
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData BaseDamage;
	ATTRIBUTE_ACCESSORS_BASIC(UCombatAttributeSet, BaseDamage);

public:
	UFUNCTION()
	void OnRep_Damage(const FGameplayAttributeData& OldValue) const {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, BaseDamage, OldValue);
	}

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
