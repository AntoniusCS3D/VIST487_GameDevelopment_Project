


#include "CombatAttributeSet.h"
#include "Net/UnrealNetwork.h"


UCombatAttributeSet::UCombatAttributeSet()
{
	BaseDamage = 20.f;
}

void UCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, BaseDamage, COND_None, REPNOTIFY_Always);
}