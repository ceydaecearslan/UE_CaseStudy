// Fill out your copyright notice in the Description page of Project Settings.


#include "CaseStudy/Public/GameplayAbilitySystem/AttributeSet/PlayerAttributeSet.h"
#include "GameplayEffectExtension.h" 
#include "CaseStudy/Public/BaseClasses/PlayerCharacter/PlayerCharacter.h"
#include "Net/UnrealNetwork.h"

UPlayerAttributeSet::UPlayerAttributeSet()
{
	Health.SetBaseValue(100);
	Health.SetCurrentValue(100);
	MaxHealth.SetBaseValue(100);
	MaxHealth.SetCurrentValue(100);
	
}

void UPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
}

void UPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UPlayerAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPlayerAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	
}

void UPlayerAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSet, Health, OldHealth);
	OnHealthChanged.Broadcast();
}

void UPlayerAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPlayerAttributeSet, MaxHealth, OldMaxHealth);
}