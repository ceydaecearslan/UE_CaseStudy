// Fill out your copyright notice in the Description page of Project Settings.


#include "CaseStudy/Public/BaseClasses/PlayerCharacter/PlayerCharacter.h"
#include "CaseStudy/Public/GameplayAbilitySystem/AttributeSet/PlayerAttributeSet.h"
#include "Net/UnrealNetwork.h"

APlayerCharacter::APlayerCharacter()
{
	AttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("AttributeSet"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}


void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(APlayerCharacter, AttributeSet);
}
