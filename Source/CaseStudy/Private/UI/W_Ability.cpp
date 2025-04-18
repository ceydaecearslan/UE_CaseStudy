// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/W_Ability.h"

#include "AbilitySystemComponent.h"
#include "BaseClasses/PlayerCharacter/PlayerCharacter.h"

void UW_Ability::NativeConstruct()
{
	Super::NativeConstruct();
	BindOnCooldownTagChanged();
}

void UW_Ability::BindOnCooldownTagChanged()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetOwningPlayerPawn());
	if (PlayerCharacter)
	{
		PlayerCharacter->GetAbilitySystemComponent()->RegisterGameplayTagEvent(CooldownTag, EGameplayTagEventType::NewOrRemoved).AddUObject(this, &UW_Ability::OnCooldownTagChanged);
	}
}

void UW_Ability::OnCooldownTagChanged(const FGameplayTag Tag, int32 NewCount)
{
	if (NewCount > 0)
	{
		OnCooldownStarted();
	}
}
